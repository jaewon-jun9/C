#include <stdio.h>
int main (void)
{
int i;//�ܿ� ���� ���ڸ� ����
int k=1;//���?
while(k>0)//0�� �Է��ϸ� ���α׷� ���Ḧ ���� ����
{
i=1;//���� �� 1�� �ʱ�ȭ
printf("���ϴ� ������?\n %d������\n",0);
scanf("%d",&k);//���ϴ� �� �� �Է� ����
if(k>0)//0�� �ƴ� ���� ��� �Ʒ� ���� ����, 0 �� ��� else��
{
printf("%d��\n",k);
while(i<10)
{
printf("%dx%d=%d  \n",k,i,k*i);
i++;
}
}
else
printf("bye!");//0�̹Ƿ� bye ����� ���Ϸ� ���ư��� 0�̹Ƿ� �ݺ����� �ʰ� ����
}
return 0;
}