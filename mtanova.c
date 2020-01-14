//분산분석 프로그램//
#include "stdio.h"
#include "string.h"
 // 문자의 아스키 코드값으로 비교합니다.
 
#define MAX 9000
     int sample[MAX][MAX]; //샘플을 저장하는 2차원 배열
	 int i=0; //차원배열 다루기 위함
	 int j=0; //차원배열 다루기 위함
	 int t=0; //처리의 숫자
	 int ret;//와일 탈출 조건용 변수
	 int n=0;
	 double av[MAX];//평균을 저장하기 위함 배열
	 double SSt[MAX];//SSt 계산용 배열
	 double SSE[MAX];//SSt 계산용 배열
	 double F;
	 char input[MAX]; // 문자열 저장 배열 선언
	 FILE * fp;
	 FILE * out;
 void main(void)
 {
	fp=fopen("data.csv", "rt");//데이터 파일 오픈, 데이터는 컴마로 구분되며 각 처리는 세로로 배열
	out=fopen("result.txt", "wt");
	if(fp==NULL){
	puts("File open failed");//파일이 없으면 종료
	return -1;
	}
fgets(input, sizeof(input), fp); //처리의 수를 알기위해 첫째열 읽기, 문자열 입력함수 gets 사용하여 변수에 저장
while(input[i] != NULL) // 글자 수 만큼
{
switch(input[i]) // 글자의 값 비교
{
case ',' : t++; // 컴마면 1증가, 컴마 수 +1 이 처리의 수, 컴마 수는 처리의 자유도
break; 
 default : break;//컴마 없으면 노카운트
}
i++; // i증가
}
i=0;
printf ("head => %s\n", input);//확인용 첫번째 열 출력
printf ("처리의 수 => %d개\n",t+1);//처리의 갯수 확인
fseek(fp, 0, SEEK_SET);//첫열을 읽었으므로 다시 시작점으로 돌아감
while(1){
for(i=0;i<t;++i)
{
	fscanf(fp,"%d,",&sample[j][i]);//컴마를 구분점으로 데이터 입력받음
	}
ret=fscanf(fp, "%d\n",&sample[j][t]);//각 열의 마지막은 컴마가 없고 \n으로 끝남
if(ret==EOF)//파일의 끝 이 나오면 빠져나가는 조건
	break;
j++;//끝이 나오지 않은 경우 다음열을 읽음
}
n=j;//총 열수를 n에 저장
//읽은 데이터를 출력하여 확인//
for(j=0;j<n;j++){
	for(i=0;i<t+1;i++){
		printf("%d ",sample[j][i]);}
	printf("\n");
}
//각각의 처리의 함 계산//
for(i=0;i<t+1;i++){
for(j=0;j<n;j++){
	sample[n+1][i]+=sample[j][i];
}
}
printf("각 처리의 합\n");//처리의 합 확인//
for(i=0;i<t+1;i++)
printf("%d ",sample[n+1][i]);
//처리의 합을 모두 더함//
for(i=0;i<t+1;i++)
	sample[n+1][t+2]+=sample[n+1][i];
printf("\n각 표본의 총합\n%d\n", sample[n+1][t+2]);//총합 확인//
//각 처리의 평균 계산//나눗셈을 위해 더블 변수로 전환하여 av배열에 넣어준 후 나눗셈//
for(i=0;i<t+1;i++){
	av[i]=sample[n+1][i];
	av[i]=av[i]/n;
}
printf("각 처리의 평균\n");
for(i=0;i<t+1;i++)
printf("%f ",av[i]);
printf("총평균\n");
av[t+2]=sample[n+1][t+2];//총평균 계산을 위해 평균계산용 변수의 끝자리에 총합을 넣어줌
av[t+2]=av[t+2]/n/(t+1);//총합을 총 표본수로 나눠줌
printf("%f\n",av[t+2]);
for(i=0;i<t+1;i++){
	SSt[i]=(av[i]-av[t+2])*(av[i]-av[t+2]);//처리제곱 계산
}
for(i=0;i<t+1;i++){
	SSt[t+2]+=SSt[i];//처리제곱 합
}
for(j=0;j<n;j++){
	for(i=0;i<t+1;i++){
		SSE[j]+=(sample[j][i]-av[i])*(sample[j][i]-av[i]);//잔차제곱 계산
	}
	SSE[n+1]+=SSE[j];//잔차제곱합
}
printf("SSt %f 자유도 %d \n",SSt[t+2]*n,t);
printf("SSE %f 자유도 %d \n",SSE[n+1],(t+1)*(n-1));
printf("SST %f 자유도 %d \n",SSE[n+1]+SSt[t+2]*n,(t+1)*(n-1)+t);
F=SSt[t+2]*n/t/SSE[n+1]*(t+1)*(n-1);//f비 계산
printf("F비 %f\n", F);//목적 달성~~ 싱난다~~~~
fprintf(out,"SSt %f 자유도 %d \n",SSt[t+2]*n,t);
fprintf(out,"SSE %f 자유도 %d \n",SSE[n+1],(t+1)*(n-1));
fprintf(out,"SST %f 자유도 %d \n",SSE[n+1]+SSt[t+2]*n,(t+1)*(n-1)+t);
fprintf(out,"F비 %f\n", F);
fclose(fp);
fclose(out);
return 0;//끝~~~~~
 }
 
