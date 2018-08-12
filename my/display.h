#ifndef __DISPLAY_H_
#define __DISPLAY_H_

#define xx 0xff
#define seg P0 

#include"main.h"

extern uint t;
extern uchar w;
extern uchar flash;
extern uint flashtime;
extern char flashwei;

extern void display(uchar *psss);
extern void display_flash(uchar *pss);