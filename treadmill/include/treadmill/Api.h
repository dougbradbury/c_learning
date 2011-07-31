#ifndef D_Api_H
#define D_Api_H

/**********************************************************************
 *
 * Api is the main API for the treadmill program controller
 *
 **********************************************************************/

typedef struct ApiStruct * Api;

Api Api_Create(void);
void Api_Destroy(Api);
double Api_GetTargetSpeed(Api);
void Api_SetTargetSpeed(Api, double);
void Api_IncrementTargetSpeed(Api);

#endif  /* D_FakeApi_H */
