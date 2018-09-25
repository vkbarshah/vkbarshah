//==============================================================================
//
// Title:		userFunc.h
// Purpose:		A short description of the interface.
//
// Created on:	4/12/2018 at 3:27:13 PM by .
// Copyright:	. All Rights Reserved.
//
//==============================================================================

#ifndef __userFunc_H__
#define __userFunc_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"
#include "toolbox.h"		

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// External variables
extern int panelHandle;
extern int fastCashFlg;
extern int depositFlg;
extern int withDrawFlg;
extern int sessionTime;
//==============================================================================
// Global functions

int Declare_Your_Functions_Here (int x);

//int OpenGUI(void);
//int CloseGUI(void);
int timerFunc(void);
int userInput(void);
int writeFile(void);
//int readFile(char*);
int display(char*);  
int inits(void);
int insCardFunc(void);
int enableMenu(void);
int balInqFunc(void);
int returnCardFunc(void);
int depositeFunc(void);
int withdrawFunc(void);
int fastChashFunc(void);
int readF(char*);
int enterFunc(void);
int enableUserIn(void);
int disableUserIn(void); 

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __userFunc_H__ */
