//3개의 처리를 계산하는 분산분석 프로그램
#include <stdio.h>

int main(void)
{
	FILE*src=fopen("src.txt","rt");//읽어들일 데이터 파일
	FILE*des=fopen("f.txt","wt");//계산결과 및 f비 저장 파일
	int ret;//while문 에러체크
	int A,B,C;//데이터 입력용 임시 변수
	int a[65536],b[65536],c[65536];//각 처리별 데이터 저장소
	int i=0;//while, for 반복문용 변수
	int n=0;//데이터 열 수
	int df=0;//자유도
	double abar=0;//처리1 평균
	double bbar=0;//처리2 평균
	double cbar=0;//처리3 평균
	double total=0;//총평균
	double sst=0;//총제곱합
	double ssta=0;
	double sstb=0;
	double sstc=0;
	double tss=0;//처리제곱합
	double sse=0;//잔차제곱합
	double ssea=0;
	double sseb=0;
	double ssec=0;
	double f=0;//f비 결과치
	if(src==NULL){
		puts("파일오픈 실패!");
		return -1;
	}
	while(1)//ret가 EOF값을 가질 때까지 데이터 읽기
	{
		ret=fscanf(src, "%d,%d,%d\n", &A,&B,&C);//데이터 파일은 1,2,3 으로 컴마로 구분됨
		if(ret==EOF)
			break;
		a[n]=A;
		b[n]=B;
		c[n]=C;
		n++;


	}
	

	printf("읽어들인 데이터는 %d열 입니다.\n", n);//읽은 데이터 수 표시
	for(i=0;i<n;i++){
	printf("%d,%d,%d\n", a[i],b[i],c[i]);//읽은 데이터 화면에 출력
	}
	printf("읽어들인 데이터는 %d열 입니다.\n", n);//읽은 데이터 수 표시
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
	printf("첫번째 처리의 평균\n%f\n", abar);
	printf("두번째 처리의 평균\n%f\n", bbar);
	printf("세번째 처리의 평균\n%f\n", cbar);
	printf("전체의 평균\n%f\n", total);
	for(i=0;i<n;i++){
		ssta=ssta+(a[i]-total)*(a[i]-total);
		sstb=sstb+(b[i]-total)*(b[i]-total);
		sstc=sstc+(c[i]-total)*(c[i]-total);
	}
	sst=ssta+sstb+sstc;
	printf("총제곱합은 %f\n", sst);
	tss=(abar-total)*(abar-total)+(bbar-total)*(bbar-total)+(cbar-total)*(cbar-total);
	tss=tss*n;
	printf("처리제곱합은 %f\n", tss);
	for(i=0;i<n;i++){
		ssea=ssea+(a[i]-abar)*(a[i]-abar);
		sseb=sseb+(b[i]-bbar)*(b[i]-bbar);
		ssec=ssec+(c[i]-cbar)*(c[i]-cbar);
	}
	sse=ssea+sseb+ssec;
	printf("잔차제곱합은 %f\n", sse);
	df=3*(n-1);
	f=(tss/2)/(sse/df);
	printf("F비는 %f\n", f);
	fprintf(des,"첫번째 처리의 평균\n%f\n", abar);
	fprintf(des,"두번째 처리의 평균\n%f\n", bbar);
	fprintf(des,"세번째 처리의 평균\n%f\n", cbar);
	fprintf(des,"전체의 평균\n%f\n", total);
	fprintf(des,"총제곱합은 %f\n", sst);
	fprintf(des,"처리제곱합은 %f\n", tss);
	fprintf(des,"잔차제곱합은 %f\n", sse);
	fprintf(des,"F비는 %f\n", f);
	fclose(src);
	fclose(des);
	return 0;
}

