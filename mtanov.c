#include "stdio.h"
#include "string.h"
 // 문자의 아스키 코드값으로 비교합니다.
 
#define MAX 500
     int in[MAX];
	 //double sample[MAX][MAX];
	 int a;
	 int i=0; // 선언 및 초기화
	 int t=0;
	 int ret;
	 char input[MAX]; // 문자열 저장 배열 선언
	 FILE * fp;
 void main(void)
 {
	fp=fopen("data.txt", "rt");
	if(fp==NULL){
	puts("File open failed");
	return -1;
	}
fgets(input, sizeof(input), fp); // 문자열 입력함수 gets 사용하여 변수에 저장
while(input[i] != NULL) // 글자 수 만큼
{
switch(input[i]) // 글자의 값 비교
{
case ',' : t++; // 컴마면 1증가
break; 
 default : break; // 디펄트면 아무것도 하지마
}
i++; // i증가
}
i=0;
printf ("head => %s\n", input);
printf ("처리의 수 => %d개\n",t+1);
fseek(fp, 0, SEEK_SET);
for(i=0;i<t+1;i++)
{
	fscanf(fp,"%d", &in[i]);
	}
printf("%d",in[2]);
fclose(fp);
return 0;
 }
 
