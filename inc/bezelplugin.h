#ifndef _BEZELPLUGIN_H_
#define _BEZELPLUGIN_H_

#include <stdbool.h>
#include <tizen.h>
#include <efl_extension.h>
#include <dlog.h>


Eina_Bool _rotary_handler_cb(void *data, Eext_Rotary_Event_Info *ev);

#ifdef __cplusplus
extern "C" {
#endif



// These methods are exported from bezelplugin.so
EXPORT_API bool tizenSetup(void);
EXPORT_API int getDir(void);
EXPORT_API void resetDir(void);


#ifdef __cplusplus
}
#endif
#endif // _BEZELPLUGIN_H_

