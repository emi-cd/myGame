/* log.c */
#include<log.h>

FILE* logp;

void initlog(void){
  logp = fopen("log.txt","w");
}

int closelog(void){
  return fclose(logp);
}
