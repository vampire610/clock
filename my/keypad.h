#ifndef __KEYPAD_H_
#define __KEYPAD_H_

#define KEYDEBOUNCE 0x05             //消抖动，按键扫描次数。如果连续5次都是扫描的都是相同键值，则认为是有效键值，否则是误触发

#include "main.h"

extern void Int_Key_Scan(void);
extern void keypad(void);