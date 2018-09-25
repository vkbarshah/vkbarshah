//==============================================================================
//
// Title:		ATM_panel
// Purpose:		A short description of the application.
//
// Created on:	4/12/2018 at 2:30:29 PM by Ajay kumar.
// Copyright:	. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "ATM_panel.h"
#include "toolbox.h"
#include "userFunc.h"
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

    int panelHandle = 0;

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

/// HIFN The main entry-point function.
int main (int argc, char *argv[])
{
	int error = 0;
	
	/* initialize and load resources */
	nullChk (InitCVIRTE (0, argv, 0));
	 //errChk(OpenGUI());
     //errChk(CloseGUI());
	 	/* initialize and load resources */  
   	errChk (panelHandle = LoadPanel (0, "ATM_panel.uir", PANEL));
	
	/* display the panel and run the user interface */
	errChk(DisplayPanel (panelHandle));
	errChk(inits());
	errChk (RunUserInterface ());

Error:
	  	/* clean up */
	if (panelHandle > 0)
		DiscardPanel (panelHandle);  
	return 0;
}

//==============================================================================
// UI callback function prototypes

/// HIFN Exit when the user dismisses the panel.
int CVICALLBACK panelCB (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	if (event == EVENT_CLOSE)
		QuitUserInterface (0);
	return 0;
}

int CVICALLBACK timerC (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	
	switch(event)
	{
		case EVENT_TIMER_TICK: 
			         timerFunc();
			break;
		
	
	
	}
	
	
	return 0;
}

int CVICALLBACK insertCard (int panel, int control, int event,
							void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					 display("");
					insCardFunc();
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}

int CVICALLBACK enterFunCll (int panel, int control, int event,
							 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			sessionTime=1; 
			enterFunc();

			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}

int CVICALLBACK noneBttn (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}

int CVICALLBACK balInquiryBttn (int panel, int control, int event,
								void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					  disableUserIn();	
					  balInqFunc();
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}

int CVICALLBACK returnCardBttn (int panel, int control, int event,
								void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 returnCardFunc();

			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}

int CVICALLBACK depositeBttn (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					   depositFlg=1;
					   sessionTime=1;
					   display("\n\n\nPlease enter amount to deposit and\n\npress Enter (E) when done");
					   enableUserIn();
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}

int CVICALLBACK withdrawBttn (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					 withDrawFlg=1;
					 sessionTime=1;
					 display("\n\n\nPlease enter amount to withdraw and press \n\nEnter (E) when done");
					 enableUserIn();
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}

int CVICALLBACK fastCashBttn (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
						  sessionTime=1;
						  disableUserIn();
						  fastChashFunc();
			break;
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}
