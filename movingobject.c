/* movingobject.c */
#include<stdlib.h>
#include<vector2.h>
#include<movingobject.h>
#include<movingobjectmanager.h>
#include<screen.h>

movingobject* newmovingobject(object** shape, 
                              void(*onestep)(movingobject* obj),
                              void(*display)(movingobject* obj), 
                              int(*bomb)(movingobject* obj), 
                              char* name){
  movingobject* ret = (movingobject*)malloc(sizeof(movingobject));
  ret->obj = shape;
  ret->currentobj = *shape;
  ret->onestep = onestep;
  ret->display = display;
  ret->bomb = bomb;
  ret->cnt = 0;
  ret->flag = 0;
  ret->name = name;
  return ret;
}

void deletemovingobject(movingobject* mobj){
  free(mobj);
}

void setinitposition(movingobject* mobj, vector2 pos){
  mobj->pos = pos;
}

void putmovingobject(movingobject* mobj){
  mobj->display(mobj);
}





