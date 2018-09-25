#include <userint.h>
//==============================================================================
//
// Title:		userFunc.c
// Purpose:		A short description of the implementation.
//
// Created on:	4/12/2018 at 3:27:13 PM by .
// Copyright:	. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files
#include "toolbox.h"
#include "userFunc.h"
#include "ATM_panel.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables
   
//==============================================================================
// Static functions

//==============================================================================
// Global variables
   int sessionTime=1;
   char *bal[5];
//==============================================================================
// Global functions

/// HIFN  What does your function do?
/// HIPAR x/What inputs does your function expect?
/// HIRET What does your function return?

struct data { 
      

     char firstnames[200];

} ;        
 struct data mydata[4]; 

 
   int Define_Your_Functions_Here (int x)
{
	return x;
}

//int OpenGUI()
//{	
//	int error=0;


//Error:
//	return error;

//}
//int CloseGUI()
//{
//	 	int error=0;

//Error:
//	
//	return error;
//}
int inits()
{
	int error = 0;
			/* User Input and Enter controls */
	SetCtrlAttribute(panelHandle,PANEL_USER_INPUT,ATTR_DIMMED,1);
	SetCtrlAttribute(panelHandle,PANEL_ENTER,ATTR_DIMMED,1);
 	
            	/* Left  Menu and Buttons controls */
	SetCtrlAttribute(panelHandle,PANEL_MENU_LT_1,ATTR_DIMMED,1);
	SetCtrlAttribute(panelHandle,PANEL_MENU_LT_2,ATTR_DIMMED,1);
	SetCtrlAttribute(panelHandle,PANEL_MENU_LT_3,ATTR_DIMMED,1);
	SetCtrlAttribute(panelHandle,PANEL_BTTN_LT_1,ATTR_DIMMED,1);
	SetCtrlAttribute(panelHandle,PANEL_BTTN_LT_2,ATTR_DIMMED,1);
	SetCtrlAttribute(panelHandle,PANEL_BTTN_LT_3,ATTR_DIMMED,1);
	
				/* Right Menu and Buttons controls */
	SetCtrlAttribute(panelHandle,PANEL_MENU_RT_1,ATTR_DIMMED,1);
	SetCtrlAttribute(panelHandle,PANEL_MENU_RT_2,ATTR_DIMMED,1);
	SetCtrlAttribute(panelHandle,PANEL_MENU_RT_3,ATTR_DIMMED,1);
	SetCtrlAttribute(panelHandle,PANEL_BTTN_RT_1,ATTR_DIMMED,1);
	SetCtrlAttribute(panelHandle,PANEL_BTTN_RT_2,ATTR_DIMMED,1);
	SetCtrlAttribute(panelHandle,PANEL_BTTN_RT_3,ATTR_DIMMED,1);
	
					/* Timer controls */
	sessionTime=1;
	SetCtrlAttribute(panelHandle,PANEL_TIMERC,ATTR_ENABLED,0);
	display(); 
	
Error:
	
	return error;
}

int enableMenu()
{
	char *mainMsg="\t\tWelcome to Acme Bank \nFirst Name, Last Name (from file)\n\
\t\tPlease select transaction\n\t\t by using the buttons.";
        /* Left  Menu and Buttons Attribute controls */
	SetCtrlAttribute(panelHandle,PANEL_MENU_LT_1,ATTR_DIMMED,0);
	SetCtrlAttribute(panelHandle,PANEL_MENU_LT_2,ATTR_DIMMED,0);
	SetCtrlAttribute(panelHandle,PANEL_MENU_LT_3,ATTR_DIMMED,0);
	SetCtrlAttribute(panelHandle,PANEL_BTTN_LT_1,ATTR_DIMMED,0);
	SetCtrlAttribute(panelHandle,PANEL_BTTN_LT_2,ATTR_DIMMED,0);
	SetCtrlAttribute(panelHandle,PANEL_BTTN_LT_3,ATTR_DIMMED,0);
	
		/* Right Menu and Buttons Attribute controls */
	SetCtrlAttribute(panelHandle,PANEL_MENU_RT_1,ATTR_DIMMED,0);
	SetCtrlAttribute(panelHandle,PANEL_MENU_RT_2,ATTR_DIMMED,0);
	SetCtrlAttribute(panelHandle,PANEL_MENU_RT_3,ATTR_DIMMED,0);
	SetCtrlAttribute(panelHandle,PANEL_BTTN_RT_1,ATTR_DIMMED,0);
	SetCtrlAttribute(panelHandle,PANEL_BTTN_RT_2,ATTR_DIMMED,0);
	SetCtrlAttribute(panelHandle,PANEL_BTTN_RT_3,ATTR_DIMMED,0);
	
	            /* Left  Menu Value controls */
	SetCtrlVal(panelHandle,PANEL_MENU_LT_1,"\tNone");
	SetCtrlVal(panelHandle,PANEL_MENU_LT_2,"\tBalance\n\tInquiry");
	SetCtrlVal(panelHandle,PANEL_MENU_LT_3," Return card \n & Terminate ");

	 		/* Right Menu Value controls */
	SetCtrlVal(panelHandle,PANEL_MENU_RT_1,"\tDeposit");
	SetCtrlVal(panelHandle,PANEL_MENU_RT_2,"\tWithdraw");
	SetCtrlVal(panelHandle,PANEL_MENU_RT_3,"\tFast Cash\n\t\t$50");
	SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,mainMsg);
}



int display()
{
	 int error = 0; 
 	 char *welcomeMsg="Welcome to Acme Bank.\nPlease insert your card\nand enter your account \n number in the User Input.\n\nPress Enter (E) when done.";
//	 SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,welcomeMsg);

Error:
	
	return error;

}

int timerFunc()
{
	int error=0;

	++sessionTime;
	//SetCtrlVal(panelHandle,PANEL_COUNTER,sessionTime);
	if(sessionTime>=10)
	{
	
	  SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"\nYour session has been terminated due to inactivity or menu selection. Please take your car \n\t\t\tGoodbye! \r"); 
	   inits(); 
	}

Error:
	
	return error;
}


int insCardFunc()
{
	int error=0; 
	static int cardBttnVal=0;
	GetCtrlVal(panelHandle,PANEL_CARD_BTTN,&cardBttnVal);
	if(cardBttnVal)
	{
			SetCtrlAttribute(panelHandle,PANEL_USER_INPUT,ATTR_DIMMED,0);
			SetCtrlAttribute(panelHandle,PANEL_ENTER,ATTR_DIMMED,0);
			SetCtrlAttribute(panelHandle,PANEL_TIMERC,ATTR_ENABLED,1);

	}
	else
	{
	  SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"\nYour session has been terminated due to inactivity or menu selection. Please take your car \n\t\t\tGoodbye! \r"); 
	   inits(); 
	}
Error:
	
	return error;
}
int userInput()
{
   int error=0;
   char buff[10];
     	GetCtrlVal(panelHandle,PANEL_USER_INPUT,buff); 
		//SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,buff);
		//SetCtrlVal(panelHandle,PANEL_COUNTER,strlen(buff));
	//	if(sessionTime <= 10)
	//	{   

			if(strlen(buff)==5)
			{
		 	//SetCtrlVal(panelHandle,PANEL_COUNTER,strlen(buff));
		 	sessionTime=1;
			//readFile(buff);
				readF(buff);
			}else
			{
		  		SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"invalid account");
		
			}
	//	}
	//	else
	//	{
		//session Expire
	//	   SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"\nsession Expire \n");
	//	}
Error:
	
	return error;
}

int writeFile(){return 0;}




int balInqFunc()
{
  int error=0,currBal=3;
        SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"Your Balance Is:\n\t\t$");
     	SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX, bal[currBal]);
Error:
	
	return error;

}
int returnCardFunc()
{
 int error=0;
 Error:
	
	return error;
}
int depositeFunc()
{
    char *buff=NULL;
	char depAmount[10];
	int error=0,len=0;
	
	SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"Please enter amount to deposit and press Enter (E) when done"); 
	userInput();

	 
	 sprintf(depAmount," $(%s) Deposited",buff);
	 SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,depAmount);


Error:	
	 return error;

}
int withdrawFunc()
{
   int error=0,position=15;
   char buffe[10]="testing";
   	char pathname[MAX_PATHNAME_LEN];
	char dirname[MAX_PATHNAME_LEN];
	GetProjectDir(dirname);
	MakePathname(dirname,"Accounts.txt",pathname);
	FILE *fp = fopen("Accounts.txt","r+") ;
	 fseek(fp,position,SEEK_SET);
	  //fwrite(buffe,1,10,fp);
	  //fputs("123",fp);
	   fprintf(fp, "%s", "999");
	  fclose(fp);
   
   
   
     /*SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"  Please enter amount to withdraw and press\n\t\t Enter (E) when done\n");
     SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"  Insufficient funds in account \n\tPlease check your balance\n\t and try again"); 
	 SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX," $ (Amount) Withdrawn"); */
Error:
	
	return error;
}
int fastChashFunc()
{

  int error=0;
  
     SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"  Insufficient funds in account \n\tPlease check your balance\n\t and try again"); 
	 SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX," $ (Amount) Withdrawn");
Error:
	
	return error;
}


int readF(char *cmpstr)
{
  	const char token[2] = ",";
  	char *balance;
	
	int k=0,i=0,lineNum=0,findStr=0; 
	char pathname[MAX_PATHNAME_LEN];
	char dirname[MAX_PATHNAME_LEN];
	GetProjectDir(dirname);
	MakePathname(dirname,"Accounts.txt",pathname);

	FILE *fp = fopen("Accounts.txt", "r") ;
 	if ( fp != NULL ) 
 	{ 
                    
    	for(i=0; i<4; i++)  
   		{                                      
       		fscanf(fp,"%s \n", mydata[i].firstnames );             
        	if(strstr(mydata[i].firstnames,cmpstr)!=NULL)
				{		
				   //SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"\nreadFile:");
				   //SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,mydata[i].firstnames);
				   
				   findStr++;
				}
				if(!findStr)
				{ 
					lineNum++;
					//SetCtrlVal(panelHandle,PANEL_COUNTER,lineNum);
				}            
   		 }     
	}     
   
 
  	 if(findStr)
	 {  
	 	SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"\nverified account\n");
	 }
	 else
	 {
	 	SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"\nAccount Verification Failed Message\n\n re-enter Account Number\n");
	 }


 	 	balance = strtok (mydata[lineNum].firstnames,token);
  		bal[k]=balance;k++;
  	while (balance != NULL)
  		{
   			balance = strtok (NULL,token);
			bal[k]=balance;

			if(balance!= NULL)
			{
				SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"\nBalance:");
				SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX, bal[k]);
			}	
			k++;
  		}
		    int r=0;
   			SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX,"\nACC:");
			SetCtrlVal(panelHandle,PANEL_DISPLAY_BOX, bal[r]);
  			 
          
return 0;   
  
}

 void posFun()
 {   int len=0;
	 
    char strMsg="12345,John,Doe,550";
	char strCmp="550";
	len =strlen(strMsg);
 
//	while(strMsg[]==strCmp[])
 
 
 }

