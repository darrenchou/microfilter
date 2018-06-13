#include "osaut.h"
#include "shamemchl.h"
#include "oscadaserv.h"
#include "osornoconf.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <sys/wait.h>    

#define IP_FIRST_DIGIT   192 
#define IP_SECOND_DIGIT  168
#define IP_THIRD_DIGIT   43 
#define IP_FOURTH_DIGIT   23

extern void read_config();

int serv_sock = 0;
int client_sock = 0;
unsigned int ip_part [4];

static int get_mscada_ip(char *str_in, char *str_out)
{
  struct in_addr  ipv4addr;
  struct in6_addr ipv6addr;
  
  char *p    = NULL;
  char *sep  = NULL;

  int suceed = 0;
  
  if (str_in != NULL && str_out != NULL){

     strcpy(str_out, "");
     p = strchr(str_in, '/');    //! corresponds for existing port number
     sep = strchr(str_in, ':');  //! corresponds for IPv6 representation

     if (p == NULL) {            // port number is not present
        if (sep == NULL) {       // IPv4 
           suceed = inet_pton(AF_INET, str_in, &ipv4addr);
        } else {                 // IPv6
           suceed = inet_pton(AF_INET6, str_in, &ipv6addr);
        }
        if (suceed) {
           strcpy(str_out, str_in);
        }
     } else {                    // port number is present
        strncat(str_out, str_in, (int)(p - str_in));
        if (sep == NULL) {       // IPv4 
           suceed = inet_pton(AF_INET, str_out, &ipv4addr);
        } else {                 // IPv6
           suceed = inet_pton(AF_INET6, str_out, &ipv6addr);
        }
     }
  } else {
     if (str_in == NULL){
        printf("get_mscada_ip(): str_in parameter is NULL\n");
     }
     if (str_out == NULL){
        printf("get_mscada_ip(): str_out parameter is NULL\n");
     }
  }
  
  if (suceed) {
     printf("get_mscada_ip(): found ip adress = %s\n", str_out);
  } else {
     printf("get_mscada_ip(): 'str_in' is not valid ip adress: %s\n", str_in);
  }
  
  return suceed;
}

//!****************************************************************************
//! function parces income string for valid port number and returns this value
//! 'str_in' - input string, expected to have format 'ip-adress/port-num'
//! returns: '-1', if valid port number wasn't found or port number if suceed.
//!****************************************************************************
static long int get_port_num(char *str_in)
{
  long int port_num = -1;
  char *p;
  
  if (str_in != NULL){
     p = strchr(str_in, '/');
     if (p != NULL){
        port_num = atoi(p+1);
        if (port_num > 0 && port_num < 65535){
           printf("get_port_num(): found valid port number = %ld\n",port_num);
        } else {
           port_num = -1;
        }
     }
  } else {
     printf("get_port_num(): str_in parameter is NULL !\n");
  }
  
  if (port_num == -1){
     printf("get_port_num(): 'str_in' has not valid port number !\n");
  }

  return port_num;
}

//!****************************************************************************
//! 'str_in' - input string, expected to have format 'ip-adress/port-num'
//! returns: '-1', if valid port number wasn't found or port number if suceed;
//! output : 'str_out' expected to be pre-allocated char[n] array (n >= 12).
//!****************************************************************************
static long int port_num_and_str(char *str_in, char *str_out)
{
   long int port_num = -1;
   
   port_num = get_port_num(str_in);
   
   if (str_out != NULL && port_num != -1){
      sprintf(str_out, "%ld", port_num);
   }
   return port_num;
}


void read_from_osaut_msg(osaut_msg0x17_t *msg)
{
  stp2pvs->plc_magmeter_flow = msg->par_6.magmeter_flow; 
  stp2pvs->plc_totalizer_low = msg->par_6.totalizer_low;
  stp2pvs->plc_totalizer_high = msg->par_6.totalizer_high;
  stp2pvs->plc_flow_dependant = msg->par_6.flow_dependant;
  stp2pvs->plc_pH_dependant = msg->par_6.pH_dependant;
  stp2pvs->plc_save_config = msg->par_6.save_config;
  stp2pvs->no_connection = 0;
  //++++++++
  
  
}


//!****************************************************************************
void write_to_osaut_msg(osaut_msg0x17_t *msg)
{
  msg->par_6.flow_dependant  = pvs2stp->pvs_flow_dependant;
  msg->par_6.pH_dependant    = pvs2stp->pvs_pH_dependant;
  msg->par_6.save_config    = pvs2stp->pvs_save_config;
  //msg->par_6.pH_dependant    = pvs2stp->pvs_serverip_first;
  //msg->par_6.pH_dependant    = pvs2stp->pvs_serverip_second;
  ////++++++
  //new added


}


void copy_osaut_msg(char *copy_from, char *copy_to, int size)
{
  if (copy_from != NULL && copy_to != NULL && size > 0){
     for (int i = 0; i < size; i++){
         copy_to[i] = copy_from[i];
     }
  }
}


void printhex(const char * data, int sizeofdata){
  int byte;
  for(byte=0;byte<sizeofdata;byte++){
    printf(" 0x%02x",(unsigned char)data[byte]);
  }
  //printf("\n");
  }
  void printbin(const char * data, int sizeofdata){
    int byte,bit;
    for(byte=0;byte<sizeofdata;byte++){
      printf(" ");
      for (bit=7; bit >= 0; --bit){
        if(data[byte] & (1 << bit)) // can bee shorter: putchar((data[byte] & 1 << bit) ? '1' : '0');
          printf("1");
        else
          printf("0");
      }
    }
    //printf("\n");
  }
void error(const char *msg){
  perror(msg);
  exit(1);
}

//!****************************************************************************
void close_plc_session()
{
  close(client_sock);
  printf("\nThe client session clossing ... ");

  close(serv_sock);
  printf("\nThe server session clossing ... ");
}

//!****************************************************************************
void plc_sighandler(int param)
{
  printf("Received termination signal for %i....\n", getpid());
  
  kill(getppid(), SIGTERM);
  close_plc_session();
}

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}



//Convert a struct sockaddr address to a string, IPv4 and IPv6:

char *get_ip_str(const struct sockaddr *sa, char *s, size_t maxlen)
{
    switch(sa->sa_family) {
        case AF_INET:
            inet_ntop(AF_INET, &(((struct sockaddr_in *)sa)->sin_addr),
                    s, maxlen);
            break;

        case AF_INET6:
            inet_ntop(AF_INET6, &(((struct sockaddr_in6 *)sa)->sin6_addr),
                    s, maxlen);
            break;

        default:
            strncpy(s, "Unknown AF", maxlen);
            return NULL;
    }

    return s;
}

void plc_server_new()
{
  struct addrinfo hints, *servinfo, *p;
  struct sockaddr_storage   cli_addr;          //! connector's address info
  //struct sockaddr_in *server_ip;
  char ip[INET6_ADDRSTRLEN];
  char read_config_ip[INET6_ADDRSTRLEN];
  char read_config_serverip[INET6_ADDRSTRLEN];

  int sockfd;           //! listen on sock_fd (our socket descriptor)
  int new_fd;           //! new connection on new_fd (client socket descriptor) 
  int opt             = 1;
  socklen_t optlen    = sizeof(opt);
  socklen_t clilen    = sizeof(cli_addr);
  char port[12];
  int err             = 0;
  int num             = 0;
  int recnum          = 0;
  uint send_update    = 0;
  uint ip_len = sizeof(ip);

  bool delay_flag = true;
  
  struct timeval t0, t1, t2, t3;
  
  char osaut_buff_R[MAX_BUFFER_SIZE];
  char osaut_buff_W[MAX_BUFFER_SIZE];

  osaut_msg0x17_t *msg_R = (osaut_msg0x17_t *)osaut_buff_R;
  osaut_msg0x17_t *msg_W = (osaut_msg0x17_t *)osaut_buff_W;;

  stp2pvs->no_connection = 1;         //!!!!!!

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;//socket parameters
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;          //! use my IP 

  if (port_num_and_str(config.client_ip, port) == -1) {
     strcpy(port, OSAUT_PORT_STR);    
  }

  printf("PLC port number is %s\n", port);
  
  if ((err = getaddrinfo(NULL, port, &hints, &servinfo)) != 0) {   //!!!!!! OSAUT_PORT_STR
      fprintf(stderr, "plc_server(): getaddrinfo: %s\n", gai_strerror(err));
      return;
  }

  //! loop through all the results and bind to the first we can
  for (p = servinfo; p != NULL; p = p->ai_next) {
      printf("plc_server(): opening server socket....\n");
      if ((sockfd = socket(p->ai_family,p->ai_socktype,p->ai_protocol)) == -1){
          printf("plc_server(): checking next socket...\n");
          continue;
      }

      if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, optlen) == -1){
          perror("plc_server(): setsockopt failed !\n");
          exit(1);
      }

      printf("plc_server(): binding server socket....\n");
      if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
          close(sockfd);
          perror("plc_server(): bind failed !\n");
          continue;
      }
      break;
  }
    

  freeaddrinfo(servinfo);

  if (p == NULL)  {
      fprintf(stderr, "plc_server(): failed to bind !\n");
      exit(1);
  }

  serv_sock = sockfd;//equal

  printf("plc_server(): listening....\n");
  if (listen(serv_sock, BACKLOG) == -1) {
      perror("plc_server(): listen failed !\n");
      exit(1);
  }

  struct sigaction sa;
  sa.sa_handler = plc_sighandler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_RESTART;
  //! reap all dead processes
  if (sigaction(SIGCHLD, &sa, NULL) == -1) {
      perror("plc_server(): sigaction !\n");
      exit(1);
  }

  printf("plc_server(): waiting for connections...\n");

  while (1) {            //accept while
    printf("accept will start\n");

    new_fd = accept4(serv_sock, (struct sockaddr *)&cli_addr, &clilen, SOCK_NONBLOCK); //client socket    
    read_config();   
    if (new_fd < 0) {

        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            if (client_sock == 0) { //! first entry into the cycle
                continue;
            }
        }
    } else {

            if(get_mscada_ip(config.client_ip, read_config_ip)){
              printf("get read config client ip from configuration file %s\n",read_config_ip);
            }
            else 
              printf("DO NOT get read config client ip from configuration file");
            
            if(get_mscada_ip(config.server_ip, read_config_serverip)){
              printf("get read config server ip from configuration file %s\n",read_config_ip);
            }
            else 
              printf("DO NOT get read config server ip from configuration file");
            /*printf("the num is %s\n", read_config_serverip);
            printf("the ip num is %d\n", (char)IP_FOURTH_DIGIT);
            for(int i = 0; i<45; i++)
            {
              printf("the num is %c\n", read_config_serverip[i]);
	    }*/   

            /*
            * get the client ip parts from config file
            *
            */
            int count = 0;
            int times = 0;
            unsigned int ip_num = 0;
            for(int j = 0; j <20; j++)
            {
            	if(read_config_serverip[j] == '.')
          		{
          		  char temp[4] = "";
                strncpy(temp, read_config_serverip + j -count, count);
      		      //printf("the part of ip is %s\n", temp);
      		      //printf("length of part ip is%d\n", sizeof(temp));
                ip_num = atoi(temp);
                //printf("converted ip num is %d\n ", ip_num);
	              count = -1;
                ip_part[times] = ip_num;
                times++;
          		}
          		count++;
              if(times == 3)
          		{
                 char last_ip_part[3] = "";
                 strncpy(last_ip_part, read_config_serverip + j +1 -count, 3);
	               //printf("the last part of ip is %s\n", last_ip_part);
	               ip_num = atoi(last_ip_part);
                 ip_part[3] = ip_num;
                 break;
          		}
            }
             
            inet_ntop(cli_addr.ss_family,
               get_in_addr((struct sockaddr *)&cli_addr), ip, ip_len);
            printf("get client ip from %s\n", ip);

            if(strcmp(ip, read_config_ip) == 0){
              printf("accepted client matches the client ip in configuration file\n");

            }
            else {
              printf("accepted client DO NOT matches the client ip in configuration file\n");
              continue;
            }

            printf("plc_server():Client connected.\n");
            
            if (client_sock) {
                close(client_sock);
                printf("plc_server():The session continues.\n");
            }

            client_sock = new_fd;
      }
      memset(osaut_buff_R, 0, sizeof(osaut_buff_R)); //! clear buffer 
      memset(osaut_buff_W, 0, sizeof(osaut_buff_W)); //! clear buffer 
      int d = 0;
      while(1) {    //continuously receive and send messages
        printf("receiving message\n");
          gettimeofday(&t0, 0);
          do {    //receive message loop, if renum < 0, then count time until time out, and then break this do while loop
                recnum = recv(client_sock, osaut_buff_R, sizeof(osaut_buff_R), 0);
                //printf("recnum is %d\n", recnum);
                //printf("error number is %d\n", errno);
                
                //if (num > 0){//
                   //! Recording OSAUT message into a database:
                   //print_osaut_db_record((const char *)osaut_buff_R, 224, "PLC");
                //}
                
                if (recnum > 0){ // swich to '1' for testing purposes
                      /*printf("Hex & Bin:(start: msg_R)..%d\n", recnum);
                      print_osaut_hex_and_bin((const char *)osaut_buff_R, 64, PRINT_HEX);
                      printf("Hex & Bin:(finish: msg_R)\n\n");
  	            */
                send_update = 1;
  	            stp2pvs->no_connection = 0;//PLC is running
                      if(osaut_buff_R[38] == 1){
                        pvs2stp->pvs_save_config = 0;
                        osaut_buff_R[38] = 0;
                      }
                }

                if(errno == ECONNRESET){
                  pvs2stp->pvs_save_config = 0;
                  osaut_buff_R[38] = 0;
                }
                //usleep(500000);
                gettimeofday(&t1, 0);

                //if (!ignore_time_out && t1.tv_sec - t0.tv_sec > TIME_OUT) {   
                //printf("t1 - t0 is %d\n", t1.tv_sec - t0.tv_sec);
                
                if (t1.tv_sec - t0.tv_sec > TIME_OUT) {  
                   usleep(50000);
                   printf("plc_server():TIMED OUT when reading from socket... %d sec", TIME_OUT);
                   break;
                }

                if ((t1.tv_sec - t0.tv_sec >= MESSAGE_DELAY && delay_flag)){
                   printf("Button is activeted. %d sec", TIME_OUT);
                   pvs2stp->pvs_save_config = 0;
                   delay_flag = false;
                }                               
                usleep(50000);

                //unsigned int testnum = 129;
                osaut_buff_R[20] = (char)ip_part[0];
                osaut_buff_R[21] = (char)ip_part[1];
                
                osaut_buff_R[22] = (char)ip_part[2];
                osaut_buff_R[23] = (char)ip_part[3];

                copy_osaut_msg(osaut_buff_R, osaut_buff_W, 64);

                write_to_osaut_msg(msg_W); //message to pvs2stp
                gettimeofday(&t2, 0);
                //usleep(1000000);
                do {
                      num = send(client_sock, msg_W, sizeof(osaut_buff_W), 0);
                      
                      if (num>0) { //! swich to '1' for testing purposes
                          /*printf("=SEND BEG=[Packeg=%d]============[size=%d]\n",++d,num);
                          printf("Hex & Bin:(start: msg_W)\n");
                          print_osaut_hex_and_bin((const char *)msg_W, 64, PRINT_HEX);
                          printf("Hex & Bin:(finish: msg_W)\n");
                          printf("\n=SEND END=[Packeg=%d]============[size=%d]\n",d,num); 
                          */
                      }
                      
                      gettimeofday(&t3, 0);
                      int i = 0;
                      i = t3.tv_sec - t2.tv_sec;
                      //printf("Time difference is %d", i);
                      if ( i > TIME_OUT) {
                        printf("Time out in send message do while loop\n");
                        break;
                      }
               
                } while ((num < 0) && ((errno == EAGAIN || errno == EWOULDBLOCK)));
                if (num <= 0) {
                      perror("plc_server():TIME OUT ERROR writing to socket, closing connection.");
                      memset(pvs2stp, 0, sizeof(pvs_to_plc_t));
                      close(client_sock);
                      client_sock = 0;
                      stp2pvs->no_connection = 1;
                      break;
                } else {
                      send_update = 0;

                }
          
          } while ((recnum <= 0) && ((errno == EAGAIN || errno == EWOULDBLOCK || errno == ECONNRESET)));
          if (recnum <= 0) {
             printf("plc_server():ERROR reading from socket, closing connection...");
             perror("plc_server():ERROR reading from socket, closing connection.");
              memset(stp2pvs, 0, sizeof(plc_to_pvs_t));
              if (errno == ECONNRESET) {
                  ///memset(pvs2stp, 0, sizeof(pvs_to_plc_t));
                  printf("ECONNRESET error!!\n");
              }
             pvs2stp->pvs_save_config = 0;
             delay_flag = true;
              stp2pvs->no_connection = 1;
              close(client_sock);
              client_sock = 0;
              break;
          } else {
              msg_R = (osaut_msg0x17_t *) osaut_buff_R;//---------
              read_from_osaut_msg(msg_R);//-------
              //ignore_time_out = stp2pvs->run_service;  //_________________
              
              //! Recording OSAUT message into a database:
              //print_osaut_db_record((const char *)osaut_buff_W, 224, "PLC");

              if (0) { //! swich to '1' for testing purposes
                  printf("=BEG=[Packeg=%d]============[size=%d]\n",++d,num);
                  char *start_check = &osaut_buff_R[0];
                  print_osaut_hex_and_bin(start_check, 64, PRINT_HEX);
                  printf("\n=END=[Packeg=%d]============[size=%d]\n",d,num); 
              }
          }

          /*
          if (recnum <= 0) {
             printf("plc_server():ERROR reading from socket, closing connection...");
             perror("plc_server():ERROR reading from socket, closing connection.");
            if (errno == ECONNRESET) {
            ///memset(pvs2stp, 0, sizeof(pvs_to_plc_t));
                printf("ECONNRESET error!!\n");
            }
            memset(stp2pvs, 0, sizeof(plc_to_pvs_t));
          }
          if(recnum <=0 || num <=0){
            stp2pvs->no_connection = 1;
            //
            pvs2stp->pvs_save_config = 0;

            delay_flag = true;
            close(client_sock);
            client_sock = 0;
            break;// break out continiously receive while loop, will go to the beginning of the accept while loop
          } 
          */

      }       
  }
  
  close_plc_session();
}



//!****************************************************************************
void print_osaut_hex_and_bin(const char *data, int sizeofdata, int print_flag)
{
  printf("Hex & Bin:\n");
    
  int par,word,byte,bit;//! run time values
  int absolut_byte; //! byte position from '0' up to 'sizeofdata'
  int par_word_byte;  //! absolut position word in paragraph
  int print_par;  //! amount paragraphs will be printed
  int b_in_w = 2; //! bytes in one word
  int w_in_p = 16;  //! words number in one paragraph in OSAUT protocol

  if (sizeofdata % w_in_p == 0)
  print_par = sizeofdata / w_in_p / b_in_w;
  else
  print_par = sizeofdata / w_in_p / b_in_w + 1;


  for (par = 0; par < print_par; par++) {
    
  for (word = 0; word < w_in_p; word++) {
    printf("Paragraph=%02d Word=%02d ",par,word);
    par_word_byte =
        (par * w_in_p * b_in_w) + (word * b_in_w);

    //! print HEX:
        if (print_flag & PRINT_HEX){
       for (byte = 0; byte < b_in_w; byte++) {
         absolut_byte = par_word_byte + byte;
         printf(" 0x%02x", (unsigned char)data[absolut_byte]);
       }
        }
        //! print BIN:
        if (print_flag & PRINT_BIN){
       for (byte = 0; byte < b_in_w; byte++) {
        absolut_byte = par_word_byte + byte;
        printf(" ");
      
        for (bit = 7; bit >= 0; --bit) {
         if (data[absolut_byte] & (1 << bit))
          printf("1");
         else
          printf("0");
        }
           }
        }
    printf("\n");
  }
  }
}
