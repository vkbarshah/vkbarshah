/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1       /* callback function: panelCB */
#define  PANEL_USER_INPUT                 2       /* control type: string, callback function: (none) */
#define  PANEL_BTTN_RT_3                  3       /* control type: command, callback function: fastCashBttn */
#define  PANEL_BTTN_RT_2                  4       /* control type: command, callback function: withdrawBttn */
#define  PANEL_BTTN_RT_1                  5       /* control type: command, callback function: depositeBttn */
#define  PANEL_BTTN_LT_3                  6       /* control type: command, callback function: returnCardBttn */
#define  PANEL_BTTN_LT_2                  7       /* control type: command, callback function: balInquiryBttn */
#define  PANEL_BTTN_LT_1                  8       /* control type: command, callback function: noneBttn */
#define  PANEL_DISPLAY_BOX                9       /* control type: textBox, callback function: (none) */
#define  PANEL_MENU_LT_3                  10      /* control type: textBox, callback function: (none) */
#define  PANEL_MENU_LT_2                  11      /* control type: textBox, callback function: (none) */
#define  PANEL_MENU_LT_1                  12      /* control type: textBox, callback function: (none) */
#define  PANEL_MENU_RT_3                  13      /* control type: textBox, callback function: (none) */
#define  PANEL_MENU_RT_2                  14      /* control type: textBox, callback function: (none) */
#define  PANEL_MENU_RT_1                  15      /* control type: textBox, callback function: (none) */
#define  PANEL_ENTER                      16      /* control type: command, callback function: enterFunCll */
#define  PANEL_TEXT_RT_BTTN               17      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXT_RT_MENU               18      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXT_LFT_BTTN              19      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXT_ENTER                 20      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXT_LFT_MENU              21      /* control type: textMsg, callback function: (none) */
#define  PANEL_CARD_BTTN                  22      /* control type: textButton, callback function: insertCard */
#define  PANEL_TIMERC                     23      /* control type: timer, callback function: timerC */
#define  PANEL_TEXTMSG                    24      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_2                  25      /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK balInquiryBttn(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK depositeBttn(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK enterFunCll(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK fastCashBttn(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK insertCard(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK noneBttn(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK returnCardBttn(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK timerC(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK withdrawBttn(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
