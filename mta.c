//�л�м� ���α׷�//
#include "stdio.h"
#include "string.h"
 // ������ �ƽ�Ű �ڵ尪���� ���մϴ�.
 
#define MAX 9000
     int sample[MAX][MAX]; //������ �����ϴ� 2���� �迭
	 int i=0; //�����迭 �ٷ�� ����
	 int j=0; //�����迭 �ٷ�� ����
	 int t=0; //ó���� ����
	 int ret;//���� Ż�� ���ǿ� ����
	 int n=0;
	 double av[MAX];//����� �����ϱ� ���� �迭
	 double SSt[MAX];//SSt ���� �迭
	 double SSE[MAX];//SSt ���� �迭
	 double F;
	 char input[MAX]; // ���ڿ� ���� �迭 ����
	 FILE * fp;
 void main(void)
 {
	fp=fopen("data.csv", "rt");//������ ���� ����, �����ʹ� �ĸ��� ���еǸ� �� ó���� ���η� �迭
	if(fp==NULL){
	puts("File open failed");//������ ������ ����
	return -1;
	}
fgets(input, sizeof(input), fp); //ó���� ���� �˱����� ù°�� �б�, ���ڿ� �Է��Լ� gets ����Ͽ� ������ ����
while(input[i] != NULL) // ���� �� ��ŭ
{
switch(input[i]) // ������ �� ��
{
case ',' : t++; // �ĸ��� 1����, �ĸ� �� +1 �� ó���� ��, �ĸ� ���� ó���� ������
break; 
 default : break;//�ĸ� ������ ��ī��Ʈ
}
i++; // i����
}
i=0;
printf ("head => %s\n", input);//Ȯ�ο� ù��° �� ���
printf ("ó���� �� => %d��\n",t+1);//ó���� ���� Ȯ��
fseek(fp, 0, SEEK_SET);//ù���� �о����Ƿ� �ٽ� ���������� ���ư�
while(1){
for(i=0;i<t;++i)
{
	fscanf(fp,"%d,",&sample[j][i]);//�ĸ��� ���������� ������ �Է¹���
	}
ret=fscanf(fp, "%d\n",&sample[j][t]);//�� ���� �������� �ĸ��� ���� \n���� ����
if(ret==EOF)//������ �� �� ������ ���������� ����
	break;
j++;//���� ������ ���� ��� �������� ����
}
n=j;//�� ������ n�� ����
//���� �����͸� ����Ͽ� Ȯ��//
for(j=0;j<n;j++){
	for(i=0;i<t+1;i++){
		printf("%d ",sample[j][i]);}
	printf("\n");
}
//������ ó���� �� ���//
for(i=0;i<t+1;i++){
for(j=0;j<n;j++){
	sample[n+1][i]+=sample[j][i];
}
}
printf("�� ó���� ��\n");//ó���� �� Ȯ��//
for(i=0;i<t+1;i++)
printf("%d ",sample[n+1][i]);
//ó���� ���� ��� ����//
for(i=0;i<t+1;i++)
	sample[n+1][t+2]+=sample[n+1][i];
printf("\n�� ǥ���� ����\n%d\n", sample[n+1][t+2]);//���� Ȯ��//
//�� ó���� ��� ���//�������� ���� ���� ������ ��ȯ�Ͽ� av�迭�� �־��� �� ������//
for(i=0;i<t+1;i++){
	av[i]=sample[n+1][i];
	av[i]=av[i]/n;
}
printf("�� ó���� ���\n");
for(i=0;i<t+1;i++)
printf("%f ",av[i]);
printf("�����\n");
av[t+2]=sample[n+1][t+2];//����� ����� ���� ��հ��� ������ ���ڸ��� ������ �־���
av[t+2]=av[t+2]/n/(t+1);//������ �� ǥ������ ������
printf("%f\n",av[t+2]);
for(i=0;i<t+1;i++){
	SSt[i]=(av[i]-av[t+2])*(av[i]-av[t+2]);//ó������ ���
}
for(i=0;i<t+1;i++){
	SSt[t+2]+=SSt[i];//ó������ ��
}
for(j=0;j<n;j++){
	for(i=0;i<t+1;i++){
		SSE[j]+=(sample[j][i]-av[i])*(sample[j][i]-av[i]);//�������� ���
	}
	SSE[n+1]+=SSE[j];//����������
}
printf("SSt %f ������ %d \n",SSt[t+2]*n,t);
printf("SSE %f ������ %d \n",SSE[n+1],(t+1)*(n-1));
printf("SST %f ������ %d \n",SSE[n+1]+SSt[t+2]*n,(t+1)*(n-1)+t);
fclose(fp);
F=SSt[t+2]*n/t/SSE[n+1]*(t+1)*(n-1);//f�� ���
printf("F�� %f\n", F);//���� �޼�~~ �̳���~~~~
return 0;//��~~~~~
 }
 
