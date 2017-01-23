/* enemy.c */
#include<enemy.h>
#include<movingobject.h>
#include<object.h>

static object* objp[2];

static void onesteppm(movingobject* mobj){
  if(((mobj->cnt)/6)%4){
    mobj->pos.y = mobj->pos.y +mobj->vel.y;
  }else{
    mobj->pos.y = mobj->pos.y -mobj->vel.y;
  }
  mobj->cnt = (mobj->cnt +1)%48;
}

static void dispa(movingobject* mobj){
  int l = (mobj->cnt/12)%2;
  putobject((mobj->obj)[l], mobj->id, mobj->pos.x, mobj->pos.y);
}

static int bomba(movingobject* mobj){
  return 1;
}

movingobject* newenemy(void){
  objp[0] = newobject(3,3," : ::: : ");
  objp[1] = newobject(3,3," : :*: : ");
  return newmovingobject(&objp[0], onesteppm, dispa, bomba, "enemy");
}
