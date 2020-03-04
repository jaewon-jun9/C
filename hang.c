#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <time.h>

 

int main(void)
{


 char ch;
 int cnt = 0;

 char *dic[] = {"hello","world","student", "university", "desk", "computer", "kf94mask", "holiday" };
 int wnum = sizeof(dic)/sizeof(char *);
 int i;
 int sel;
 char *word;
 char *pword;
 int len;

 

 srand(time(NULL));    
 sel = rand() % wnum;  
 word = dic[sel];      

 len = strlen(word);   

 pword = (char *)malloc(len + 1); 

 for(i=0; i <len; i++)
      pword[i] = '_';     
 pword[len] = '\0';

 

 printf("== 단어 맞추기 게임 ==\n");

 while (1) {
      printf("\n맞출단어 : %s  ", pword);
      printf(" 빈칸에 들어갈 문자 입력 :");  
      scanf("%c", &ch);fflush(stdin);  
      cnt++;                                 

 

      for(i=0; i <len; i++)
           if(pword[i] == '_' && word[i] == ch)
                pword[i] = ch;                 

 

     for(i=0; i <len; i++)

         if(pword[i] == '_') break;       

     if(i == len) {   
           printf("\n%d 번만에 %s를 맞추었습니다.\n\n", cnt, pword);
           return 0;
     }

         }
        return 0;
}
