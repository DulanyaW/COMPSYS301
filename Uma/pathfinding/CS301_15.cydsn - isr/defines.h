/* ========================================
 *
 * Copyright Univ of Auckland, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
// Code setup
#define USE_USB

//* ========================================
#define FALSE 0
#define TRUE 1
#define UNKNOWN 10
//* ========================================
#define TS 100 // sample time = 100kHz * TS
#define DECIMATE_TS_ENC     1000    // decimation factor for quad decoder
#define DECIMATE_TS_UPDATE  2000    // decimation factor for update action
#define DECIMATE_TS_SPEED   100
#define DECIMATE_TS_DISPLAY 1000
//* ========================================
// General Debug
#define LED_ON          LED_Write(1)
#define LED_OFF         LED_Write(0)
#define LED_TOGGLE      LED_Write(~LED_Read())

#define DB0_ON          DB0_Write(1)
#define DB0_OFF         DB0_Write(0)
#define DB0_TOGGLE_LED  DB0_Write(~DB0_Read())

#define DB1_ON          DB1_Write(1)
#define DB1_OFF         DB1_Write(0)
#define DB1_TOGGLE_LED  DB1_Write(~DB1_Read())

#define DB2_ON          DB2_Write(1)
#define DB2_OFF         DB2_Write(0)
#define DB2_TOGGLE_LED  DB2_Write(~DB2_Read())
//* ========================================
// Motor
#define COAST_OFF CONTROL_Write(0);
#define COAST_ON CONTROL_Write(0b11);

#define PWM_MAX 255     // maximum value of duty cycle
#define PWM_MIN 0       // minimum value of duty cycle
//* ========================================
// USBUART
#define BUF_SIZE 64 // USBUART fixed buffer size
#define CHAR_NULL '0'
#define CHAR_BACKSP 0x08
#define CHAR_DEL 0x7F
#define CHAR_ENTER 0x0D
#define LOW_DIGIT '0'
#define HIGH_DIGIT '9'
//* ========================================
//RF 
#define SOP 0xaa
#define PACKETSIZE 32    
#define RXSTRINGSIZE 64 // 4+3+[4+4+4]+[4+4+4+4]+[4+4+4+4]+[4+4+4+4]+delimiters, i.e. no more than 64
/* [] END OF FILE */
