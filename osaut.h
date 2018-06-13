#ifndef _OSAUT_H_
#define _OSAUT_H_

#include <stdbool.h>

#define MAX_BUFFER_SIZE 64

typedef unsigned int bool;
typedef unsigned char byte;
typedef unsigned short int word;
typedef unsigned int dword;


/****************************************************************************
 * OSAUT header: common for all OPCODEs: definitions start
 ****************************************************************************/
#if 0
/* compiler's optimization example */
struct example {
    int status;
    char state; 
[char pad001[3]]; /* hidden fields for memmory alignment by gcc optimization */
    char name[7];
[char pad002[1]]; /* hidden fields for memmory alignment by gcc optimization */
};
#endif

// attibute pack - disables gcc optimizations
// example above explaines this issue:
typedef struct __attribute__ ((__packed__)) osaut_header {
  /* Paragraph-0, Header */
  
  /* INIT Word, two identical bytes for identification of endianness
   * bit 7   - endian flag; if set, big endian (high order byte first) is used, 
   *           if reset, little endian (low order byte first) is used
   * bit 5-6 - length modifier
   * bit 4   - reserved
   * bit 3   - error flag, set by PLC to raise awareness of an alarm condition
   * bit 2   - update flag, if bit is set, PLC flags that this message is 
   *           intended for screen update
   * bit 1   - request/response identifier, if bit is set, it is a request, if
   *           it is reset, it is a response
   * bit 0   - broadcast flag
   */
  word  init_word;  
  /* SYS Word
   * nibble 3 - OSAUT major version
   * nibble 2 - OSAUT minor version
   * nibble 1 - release number
   * nibble 0 - build number
   */
  word  osaut_ver;  
  /* OPCODE Word
   * 0 - error condition encountered - message body contains error code
   * 1 - generic acknowledgement (request received), message body is empty
   * 2 - request data read from absolute address, message body contains DWORD
   *     with address
   * 3 - reserved
   * 0x0A - 0x0F - test operation - these are volatile OPCODEs
   * 0x10 - first defined OPCODE  
   */
  
  word  opcode;
  /* intended as an additional descriptor for OPCODE, if required. */
  
  word  opcode_aux;
  /* used to keep track and find unanswered request and orphaned responses 
   */  
  word  msg_numb;
  /* Byte 1 - LOC_ID (location ID) Byte 0 - EQ_ID (equipment ID) */
  
  word  abs_id; 
  
  dword timestamp;
  dword node_addr; /* sender IP (PLC) */
  dword srv_addr;  /* reciever IP */
  dword gw_addr;   /* gateway IP */
  dword netmask;   /* 255 255 255 0 */

} osaut_header_t;
/****************************************************************************
 * OSAUT header: common for all OPCODEs: end of definitions 
 ***************************

*/


typedef struct __attribute__ ((__packed__)) opcode0x17_p6 {
  /* Paragraph-1: process image - input channels, RO for server */ 
  word    magmeter_flow; //0
  word		flow_dependant;
  word		pH_dependant;
  word    save_config;
  //for testing
  bool    bl1a_started:1;
  bool    lift_station:1;
  bool    lift_eth:1;
  bool    undef_00:1;
  bool    undef_01:1;
  bool    undef_02:1;
  bool    undef_03:1;
  bool    undef_04:1;

  char    reserved[19];   
  word    totalizer_low;
  word    totalizer_high;
  
} opcode0x17_p6_t;

typedef struct __attribute__ ((__packed__)) opcode0x17_p1 {
  /* Paragraph-2: process image - input channels*/
  //word 0 
  word magmeter_IN;
  //word 1
  word magmeter_OUT;
  //word 2 - 3
  word reserved1;
  word reserved2;
  //word 4
  bool auto_mode:1;
  bool service_mode:1;
  bool err_ack:1;
  bool AC_state:1;
  bool undef_00:1;
  bool undef_01:1;
  bool undef_02:1;
  bool undef_03:1;
  bool PS1:1;
  bool PS2:1;
  bool PS_AIR:1;
  bool MagmIN_pulse:1;
  bool MagmOUT_pulse:1;
  bool CIP_Hlvl:1;
  bool CIP_Llvl:1;
  bool Ext_Hlvl:1;
  //word 5
  bool Ext_Llvl:1;
  bool NC_DIE_1:1;
  bool NC_DIE_2:1;
  bool NC_DIE_3:1;
  bool NC_DIE_4:1;
  bool NC_DIE_5:1;
  bool NC_DIE_6:1;
  bool NC_DIE_7:1;
  //word 6 - 15 + high word 5
  char reserved[21];

} opcode0x17_p1_t;

typedef struct __attribute__ ((__packed__)) opcode0x17_p2 {
  /* Paragraph-2: process image - output channels*/
  //word 0 
  bool LED_run:1;
  bool LED_err:1;
  bool sol_S1:1;//solenoid 1
  bool sol_S2:1;//solenoid 2
  bool sol_S3:1;//solenoid 3
  bool sol_S4:1;//solenoid 4
  bool sol_S5:1;//solenoid 5
  bool sol_S6:1;//solenoid 6
  bool sol_S7:1;//solenoid 7
  bool sol_S8:1;//solenoid 8
  bool sol_S9:1;//solenoid 9
  bool sol_SA1:1;//solenoid A1, first solenoid for the first two membranes
  bool sol_SA2:1;//solenoid A2, second solenoid for the second two membranes
  bool dosing_pump:1;
  bool NC_DOI_1:1;
  bool NC_DOI_2:1;
  //word 1
  bool pump_CIP:1;
  bool NC_DOE_1:1;
  bool NC_DOE_2:1;
  bool NC_DOE_3:1;
  bool NC_DOE_4:1;
  bool NC_DOE_5:1;
  bool NC_DOE_6:1;
  bool NC_DOE_7:1;
  //bit 8 - 15
  char reserved1;
  //word 2 to word 15
  char    reserved[28];
  
} opcode0x17_p2_t;

typedef struct __attribute__ ((__packed__)) opcode0x17_p3 {
  /* Paragraph-3: r/w area */ 
  
  //word 0
  bool system_auto_mode:1;
  bool system_service_mode:1;
  //bit 2 - 9
  char reserved1;
  //bit 10 - 13
  bool undef_00:1;
  bool undef_01:1;
  bool undef_02:1;
  bool undef_03:1;
  //bit 14 - 15   
  bool service_accept:1;
  bool service_required:1;
  //word 1
  word operation_submode;
  //word 2
  char reserved2; 
  //word 3
  bool PS1_present:1;
  bool PS2_present:1;
  bool PS_AIR_present:1;
  bool MagmIN_present:1;
  bool MagmOUT_present:1;
  bool CIP_present:1;
  bool reservoir_present:1;
  bool sol_S1_present:1;
  bool sol_S2_present:1;
  bool sol_S3_present:1;
  bool sol_S4_present:1;
  bool sol_S5_present:1;
  bool sol_S6_present:1;
  bool uF1_present:1;
  bool uF2_present:1;
  bool dp_present:1;//dosing pump present
  //word 4
  word max_magmIN_flow;//in cubic meters per hour
  //word 5
  word magmIN_pulse_value;// in L
  //word 6
  word max_magmOUT_flow;//in cubic meters per hour
  //word 7
  word magmOUT_pulse_value;// in L
  //word 8
  word short_flush_time;//in seconds
  //word 9
  word long_flush_time;//in seconds

  char reserved[12]; 

} opcode0x17_p3_t;

typedef struct __attribute__ ((__packed__)) opcode0x17_p4 {
 /* Paragraph-4: r/w area */ 
  word reserved1;
  //word 1
  bool sol_S1_Man:1;// solenoid 1 on in manual mode
  bool sol_S2_Man:1;
  bool sol_S3_Man:1;
  bool sol_S4_Man:1;
  bool sol_S5_Man:1;
  bool sol_S6_Man:1;
  bool sol_S7_Man:1;
  bool sol_S8_Man:1;
  bool sol_S9_Man:1;
  bool sol_SA1_Man:1;// solenoid A1(first set including two solenoids) in manual mode
  bool sol_SA2_Man:1;
  bool dp_Man:1;// dosing pump in manual mode
  bool undef_00:1;
  bool undef_01:1;
  bool undef_02:1;
  //word 2 - 8
  char reserved[14];
  //word 9 low word
  bool pump1_err:1;
  bool pump2_err:1;
  bool tank_empty_err:1;
  bool ext_tank_contr_err:1;
  bool ext_tank_alarm:1;
  bool magmIN_sig_absent:1;
  bool magmOUT_sig_absent:1;
  bool undef_03:1;
  char reservedA[5];
  //word 12
  word totalizerIN_low;
  //word 13
  word totalizerIN_high;
  //word 14
  word totalizerOUT_low;
  //word 15
  word totalizerOUT_high;

} opcode0x17_p4_t;

typedef struct __attribute__ ((__packed__)) osaut_msg0x17 {
  /* OSAUT mesage main structure: paragraphs/cmd's/values */
    osaut_header_t  header;
    opcode0x17_p6_t par_6;  /* communication chanels : read/write */    
    opcode0x17_p2_t par_2;
    opcode0x17_p3_t par_3;
    opcode0x17_p4_t par_4;
} osaut_msg0x17_t;

#endif