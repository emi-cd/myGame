/* scenario.c */
#include<scenario.h>
#include<bidlist.h>
#include<stdio.h>

static bidlist* scenario;
static int mark;

void initscenario(void){
  scenario = newbidlist();
  mark = 0;
} 

void addevent(event* ev){
  bidlistadd(scenario, ev);
}

void resetmark(void){
  bidlistreset(scenario); 
  mark = 0;
}

int getcurrentmark(void){
  return mark;
}

void setmark(int pos){
  int cnt = bidlistcount(scenario);
  if(pos<cnt){
    mark = pos;
    bidlistsetmark(scenario, bidlistget(scenario, mark)); 
  }else{
    mark = cnt;
    bidlistsetmark(scenario, scenario->tail); 
  }
}

event* getnextevent(void){
  event* ret = NULL;
  bidnode* node = bidlistnext(scenario); 
  if(node != NULL){
    ret = (event*)(node->data);
  }
  return ret;
}
