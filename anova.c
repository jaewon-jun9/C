//3���� ó���� ����ϴ� �л�м� ���α׷�
#include <stdio.h>

int main(void)
{
	FILE*src=fopen("src.txt","rt");//�о���� ������ ����
	FILE*des=fopen("f.txt","wt");//����� �� f�� ���� ����
	int ret;//while�� ����üũ
	int A,B,C;//������ �Է¿� �ӽ� ����
	int a[65536],b[65536],c[65536];//�� ó���� ������ �����
	int i=0;//while, for �ݺ����� ����
	int n=0;//������ �� ��
	int df=0;//������
	double abar=0;//ó��1 ���
	double bbar=0;//ó��2 ���
	double cbar=0;//ó��3 ���
	double total=0;//�����
	double sst=0;//��������
	double ssta=0;
	double sstb=0;
	double sstc=0;
	double tss=0;//ó��������
	double sse=0;//����������
	double ssea=0;
	double sseb=0;
	double ssec=0;
	double f=0;//f�� ���ġ
	if(src==NULL){
		puts("���Ͽ��� ����!");
		return -1;
	}
	while(1)//ret�� EOF���� ���� ������ ������ �б�
	{
		ret=fscanf(src, "%d,%d,%d\n", &A,&B,&C);//������ ������ 1,2,3 ���� �ĸ��� ���е�
		if(ret==EOF)
			break;
		a[n]=A;
		b[n]=B;
		c[n]=C;
		n++;


	}
	

	printf("�о���� �����ʹ� %d�� �Դϴ�.\n", n);//���� ������ �� ǥ��
	for(i=0;i<n;i++){
	printf("%d,%d,%d\n", a[i],b[i],c[i]);//���� ������ ȭ�鿡 ���
	}
	printf("�о���� �����ʹ� %d�� �Դϴ�.\n", n);//���� ������ �� ǥ��
	for(i=0;i<n;i++){
		abar=abar+(double)a[i];
		bbar=bbar+(double)b[i];
		cbar=cbar+(double)c[i];
	}
	total=abar+bbar+cbar;
	total=total/(3*(double)n);
	abar=abar/(double)n;
	bbar=bbar/(double)n;
	cbar=cbar/(double)n;
	printf("ù��° ó���� ���\n%f\n", abar);
	printf("�ι�° ó���� ���\n%f\n", bbar);
	printf("����° ó���� ���\n%f\n", cbar);
	printf("��ü�� ���\n%f\n", total);
	for(i=0;i<n;i++){
		ssta=ssta+(a[i]-total)*(a[i]-total);
		sstb=sstb+(b[i]-total)*(b[i]-total);
		sstc=sstc+(c[i]-total)*(c[i]-total);
	}
	sst=ssta+sstb+sstc;
	printf("���������� %f\n", sst);
	tss=(abar-total)*(abar-total)+(bbar-total)*(bbar-total)+(cbar-total)*(cbar-total);
	tss=tss*n;
	printf("ó���������� %f\n", tss);
	for(i=0;i<n;i++){
		ssea=ssea+(a[i]-abar)*(a[i]-abar);
		sseb=sseb+(b[i]-bbar)*(b[i]-bbar);
		ssec=ssec+(c[i]-cbar)*(c[i]-cbar);
	}
	sse=ssea+sseb+ssec;
	printf("������������ %f\n", sse);
	df=3*(n-1);
	f=(tss/2)/(sse/df);
	printf("F��� %f\n", f);
	fprintf(des,"ù��° ó���� ���\n%f\n", abar);
	fprintf(des,"�ι�° ó���� ���\n%f\n", bbar);
	fprintf(des,"����° ó���� ���\n%f\n", cbar);
	fprintf(des,"��ü�� ���\n%f\n", total);
	fprintf(des,"���������� %f\n", sst);
	fprintf(des,"ó���������� %f\n", tss);
	fprintf(des,"������������ %f\n", sse);
	fprintf(des,"F��� %f\n", f);
	fclose(src);
	fclose(des);
	return 0;
}

