/* movingobjectmanager.h */
#ifndef _MOVINGOBJECTMANAGER_H_
#define _MOVINGOBJECTMANAGER_H_

#include<movingobject.h>
void initmom(void);
void addmo(movingobject* mobj, vector2 pos, vector2 vel);
void removemo(int num);
void putmo(void);
void onestepmo(void);

#endif
