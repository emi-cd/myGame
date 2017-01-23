/* movingobjectmanager.c */
#include<movingobjectmanager.h>
#include<screen.h>
#include<bidlist.h>
#include<stdlib.h>
#ifdef DEBUG
#include<log.h>
#endif

#define MAXOBJCNT 250

static bidlist* objlist;
static bidnode* nodes[MAXOBJCNT];
static int count=0;

void initmom(void){
  objlist = newbidlist();
}

void addmo(movingobject* mobj, vector2 pos, vector2 vel){
  movingobject* tmp;
  if(count<MAXOBJCNT){
    tmp = (movingobject*)malloc(sizeof(movingobject));
    *tmp = *mobj;
    tmp->pos = pos;
    tmp->vel = vel;
    bidlistadd(objlist,tmp);
    count++;
  }
} 

/* call just after putmo */
void removemo(int num){
  count--;
  deletemovingobject(nodes[num]->data);
  bidlistremove(objlist,nodes[num]);
}

/* put objects on dispbuffer and checkbuffer */
void putmo(void){ 
  movingobject* mobj;
  bidnode* node;
  int num=0;
  int id;
  bidlistreset(objlist);
  while((node = bidlistnext(objlist))){
    nodes[num] = node;
    mobj =(movingobject*)(node->data);
    mobj->id = num;
    id = checkcollision(mobj->pos, mobj->currentobj);
    if(id == BORDER){
      removemo(num);
    }else if(id<MAXOBJCNT){
      if(mobj->bomb(mobj)){
        removemo(num);
      }
      if(((movingobject*)(nodes[id]->data))
         ->bomb((movingobject*)(nodes[id]->data))){
        removemo(id);
      }
    }else{
      putmovingobject(mobj);
      num++;
    }
  }
}

/* put objects on dispbuffer and checkbuffer */
void onestepmo(void){
  movingobject* mobj;
  bidnode* node;
  int num=0;
  bidlistreset(objlist);
  while((node = bidlistnext(objlist))){
    mobj = (node->data);
    mobj->onestep(mobj);
  }
}
