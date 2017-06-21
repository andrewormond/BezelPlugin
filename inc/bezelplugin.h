#ifndef _BEZELPLUGIN_H_
#define _BEZELPLUGIN_H_

/**
 * This header file is included to define _EXPORT_.
 */
#include <stdbool.h>
#include <tizen.h>
#include <efl_extension.h>
#include <dlog.h>



#ifdef __cplusplus
extern "C" {
#endif

// This method is exported from bezelplugin.so
EXPORT_API bool tizenSetup(void);
EXPORT_API int getDir(void);
EXPORT_API void resetDir(void);
Eina_Bool _rotary_handler_cb(void *data, Eext_Rotary_Event_Info *ev);


#ifdef __cplusplus
}
#endif
#endif // _BEZELPLUGIN_H_

