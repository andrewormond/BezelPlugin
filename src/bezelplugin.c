#include "bezelplugin.h"
#define PR_TAG "bezelplugin"

int dir = 0;

/*
 * Initializes Plugin
 */
EXPORT_API bool tizenSetup(void)
{
//	dlog_print(DLOG_DEBUG, PR_TAG, "Setup started");
	eext_rotary_event_handler_add(_rotary_handler_cb, NULL);
	return true;
}

/*
 * Returns internal tracker
 */
EXPORT_API int getDir(void){
	return dir;
}

/*
 * Resets internal tracker
*/
EXPORT_API void resetDir(void){
	dir = 0;
}

/*
 * Function for handling native rotation events
 */
Eina_Bool _rotary_handler_cb(void *data, Eext_Rotary_Event_Info *ev)
{
   if (ev->direction == EEXT_ROTARY_DIRECTION_CLOCKWISE)
   {
//      dlog_print(DLOG_DEBUG, PR_TAG, "ROTARY HANDLER: Rotary device rotated in clockwise direction");
      dir = -1;
   }
   else
   {
//      dlog_print(DLOG_DEBUG, PR_TAG, "Rotary device rotated in counter clockwise direction");
      dir = 1;
   }

   return EINA_FALSE;
}
