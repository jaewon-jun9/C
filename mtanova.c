#include "stdio.h"
#include "string.h"
 // ������ �ƽ�Ű �ڵ尪���� ���մϴ�.
 
#define MAX 500
     int in[MAX];
	 //double sample[MAX][MAX];
	 int a;
	 int i=0; // ���� �� �ʱ�ȭ
	 int t=0;
	 int ret;
	 char input[MAX]; // ���ڿ� ���� �迭 ����
	 FILE * fp;
 void main(void)
 {
	fp=fopen("data.txt", "rt");
	if(fp==NULL){
	puts("File open failed");
	return -1;
	}
fgets(input, sizeof(input), fp); // ���ڿ� �Է��Լ� gets ����Ͽ� ������ ����
while(input[i] != NULL) // ���� �� ��ŭ
{
switch(input[i]) // ������ �� ��
{
case ',' : t++; // �ĸ��� 1����
break; 
 default : break; // ����Ʈ�� �ƹ��͵� ������
}
i++; // i����
}
i=0;
printf ("head => %s\n", input);
printf ("ó���� �� => %d��\n",t+1);
fseek(fp, 0, SEEK_SET);
for(i=0;i<t+1;i++)
{
	fscanf(fp,"%d", &in[i]);
	}
printf("%d",in[2]);
fclose(fp);
return 0;
 }
 
