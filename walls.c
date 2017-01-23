/* walls.c */

#include <string.h>
#include <walls.h>
#include <screen.h>

#define WALLLOOP 40
#define UNITS 8
#define UNITLINES  7

static int count = 0;

static char walldata[UNITS*UNITLINES][WIDTH+1] ={
  "OOOOO                             OOOOOO",
  "OOOOOO       O          O        OOOOOOO",
  "OOOOOO      OOO        OOO       OOOOOOO",
  "OOOOOO     OOOO       OOOOO      OOOOOOO",
  "OOOOOO      OOO       OOOO      OOOOOOOO",
  "OOOOOOO      OO        O       OOOOOOOOO",
  "OOOOOOOO                      OOOOOOOOOO",
  /*   ,    |    ,    |    ,    |    ,    */
  "OOOOOOOOOO                  OOOOOOOOOOOO",
  "OOOOOOOOO                  OOOOOOOOOOOOO",
  "OOOOOOO                   OOOOOOOOOOOOOO",
  "OOOO                     OOOOOOOOOOOOOOO",
  "OOO                     OOOOOOOOOOOOOOOO",
  "OOO                   OOOOOOOOOOOOOOOOOO",
  "OO                   OOOOOOOOOOOOOOOOOOO",
  /*   ,    |    ,    |    ,    |    ,    */
  "OO                    OOOOOOOOOOOOOOOOOO",
  "OOO                   OOOOOOOOOOOOOOOOOO",
  "OOO                    OOOOOOOOOOOOOOOOO",
  "OOOO                     OOOOOOOOOOOOOOO",
  "OOOOOOO                    OOOOOOOOOOOOO",
  "OOOOOOOOO                    OOOOOOOOOOO",
  "OOOOOOOOOOO                   OOOOOOOOOO",
  /*   ,    |    ,    |    ,    |    ,    */
  "OOOOOOOOOOOOOO                 OOOOOOOOO",
  "OOOOOOOOOOOOOOOO                OOOOOOOO",
  "OOOOOOOOOOOOOOOOOO               OOOOOOO",
  "OOOOOOOOOOOOOOOOOOOO              OOOOOO",
  "OOOOOOOOOOOOOOOOOOOOO               OOOO",
  "OOOOOOOOOOOOOOOOOOOOOO               OOO",
  "OOOOOOOOOOOOOOOOOOOOOOO               OO",
  /*   ,    |    ,    |    ,    |    ,    */
  "OOOOOOOOOOOOOOOOOOOOO                 OO",
  "OOOOOOOOOOOOOOOOOOOO                 OOO",
  "OOOOOOOOOOOOOOOOOOO                 OOOO",
  "OOOOOOOOOOOOOOOOO                  OOOOO",
  "OOOOOOOOOOOOOO                    OOOOOO",
  "OOOOOOOOOOOO                    OOOOOOOO",
  "OOOOOOOOO                      OOOOOOOOO",
  /*   ,    |    ,    |    ,    |    ,    */
  "OOOOOOO            OOOOO        OOOOOOOO",   
  "OOOOOO          OOOOOOOOOO        OOOOOO",
  "OOOOOO         OOOOOOOOOOOO        OOOOO",
  "OOOOOO         OOOOOOOOOOOO          OOO",   
  "OOOOOOO        OOOOOOOOOOO          OOOO",   
  "OOOOOOO         OOOOOOOOO         OOOOOO",   
  "OOOOOOOO          OOOOO          OOOOOOO",   
  /*   ,    |    ,    |    ,    |    ,    */
  "OOOOOO                            OOOOOO",   
  "OOOOO       OO            OO       OOOOO",   
  "OOOO       OOO     OO     OOO       OOOO",   
  "OOOO        O     OOOO     O        OOOO",   
  "OOOOO              OO              OOOOO",   
  "OOOOO                              OOOOO",   
  "OOOOO                              OOOOO",   
  /*   ,    |    ,    |    ,    |    ,    */
  "OOOOO                              OOOOO",   
  "OOOOO                              OOOOO",   
  "OOOOO      O                O      OOOOO",   
  "OOOOO      O    OO    OO    O      OOOOO",   
  "OOOOO       O   O      O   O       OOOOO",   
  "OOOOOO                            OOOOOO",   
  "OOOOOOO                          OOOOOOO",   
  /*   ,    |    ,    |    ,    |    ,    */
};

static char collisioncheckdata[UNITS*UNITLINES][WIDTH];

static int wallorder[WALLLOOP] ={
  0,1,2,3,4, 5,6,7,6,7, 0,1,2,3,4, 5,6,7,6,7,
  0,1,2,1,2, 7,6,7,6,7, 0,3,4,3,4, 5,5,5,0,5,
};


void initwalls(void){
  int i,j;
  for(i=0;i<UNITS*UNITLINES;i++){
    for(j=0;j<WIDTH;j++){
      if(walldata[i][j] ==' '){ 
        collisioncheckdata[i][j] = NONOBJ;//non object
      }else{
        collisioncheckdata[i][j] = WALL;//wall
      }
    }
  }
}

void scrollwall(void){
  count++;
}

void putwalls(int lines){
  int unit,lline;
  int i,j;
  for (i=lines;i>0;i--){
    unit = ((count+i) / UNITLINES) % WALLLOOP; 
    lline = ((count+i) % UNITLINES); 
    for(j=0;j<WIDTH;j++){
      putdata(j,lines-i,walldata[wallorder[unit]*UNITLINES+lline][j],
              collisioncheckdata[wallorder[unit]*UNITLINES+lline][j]);
    }
  }
  for(j=0;j<WIDTH;j++){
    putdata(j,0,'+',BORDER);
    putdata(j,lines-1,'+',BORDER);
  }            
  for(j=0;j<lines;j++){
    putdata(0,j,'+',BORDER);
    putdata(WIDTH-1,j,'+',BORDER);
  }            
}
