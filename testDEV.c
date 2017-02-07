/* strtok example */
#include <stdio.h>
#include <string.h>
#define LENGH(x)  (sizeof(x) / sizeof((x)[0]))

char inString[] = "CONTROL-ALT DELETE\nPRINTSCREEN\nCONTROL C\nSTRING blablablbasldbasbd";

char liness[50][50] = {"CONTROL-ALT DELETE", "PRINTSCREEN", "CONTROL C", "STRING blablablbasldbasbd"};
char lines[50][50];




/*void createLines(char instring[]){
  int split=0;
  int l=0;
  int j=0;
  int i=0;
  //for (int i = 0; i < LENGH(inString); i=i+2)
  while(i<LENGH(inString))
  {
    while(inString[i+1] != '\\' && inString[i+2] != 'n'){
      lines[j][l] = inString[i];
    }
    j++;
    l=0;
    i=i+2;

}

}
*/








static int nextIsString;

void pressKey(char key[]){
  char mask[] = "STRING";

  if (strcmp(key,mask) != 0 && nextIsString == 0)
  {
    printf("*Key %s pressed\n", key);

  }
  else if(strcmp(key,"STRING") != 0 && nextIsString == 1){
    printf("%s\n", "print a string");
    nextIsString == 0;
  }
  else if(strcmp(key,"STRING") == 0){
    nextIsString ==1;
    printf("Next is a string\n");
  }
  
}

void releaseKeys(){printf("All keys released\n");}

void executeCommand(char linha[]){
  char * pch;
  pch = strtok (linha," -");
  while (pch != NULL)
  {
    pressKey(pch);
    //printf("%s\n", pch);
    pch = strtok (NULL, " -");
  }
  releaseKeys();
}

void splitLines(char inString[]){
    char * pch;
  pch = strtok (inString,"\n");
  while (pch != NULL)
  {
    executeCommand(pch);

    pch = strtok (NULL, "\n");
    printf("Nova Linha\n");
  }
  
    
    
}

int main ()
{
  //words(lines[0]);
  
  //executeCommand(liness[0]);
  //executeCommand(liness[1]);
  //executeCommand(liness[2]);
  //executeCommand(liness[3]);
  

  splitLines(inString);
  
  return 0;
}










/*


void words(char instr[]){
  //char str[] ="CONTROL-ALT DELETE";
  char * pch;
  pch = strtok (instr," -");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " -");
  }
}
*/
