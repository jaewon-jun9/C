#include <stdio.h>
int main (void)
{
int i;//단에 곱할 숫자를 위함
int k=1;//몇단?
while(k>0)//0을 입력하면 프로그램 종료를 위한 조건
{
i=1;//곱할 수 1로 초기화
printf("원하는 구구단?\n %d는종료\n",0);
scanf("%d",&k);//원하는 단 수 입력 받음
if(k>0)//0이 아닌 수의 경우 아래 내용 실행, 0 인 경우 else로
{
printf("%d단\n",k);
while(i<10)
{
printf("%dx%d=%d  \n",k,i,k*i);
i++;
}
}
else
printf("bye!");//0이므로 bye 출력후 와일로 돌아가나 0이므로 반복되지 않고 종료
}
return 0;
}
