#include <iostream>
using namespace std;


int main()
{
 int year;
 int month;
 int totalDay = 0;
 int i = 1990;
 int dayOfWeek; // 0 : 월, 1: 화, .....
 int dayOfMonth; // 해당 달의 총 일수

 cout << "년도 입력 : " ;
 cin >> year;
 cout << "월 입력 : " ;
 cin >> month;

 for( ; i < year ; i++)
 {
  if( i % 4 == 0 && i % 100 != 0 || i % 400 == 0 )
  {
   totalDay += 366;
  }
  else
  {
   totalDay += 365;
  }
 }

 cout << year << "년 1월 1일 까지의 일수 " << totalDay << "요일 : ";

 switch( totalDay % 7 )
 {
 case 0:
  cout << "월요일" << endl;
  break;
 case 1:
  cout << "화요일" << endl;
  break;
 case 2:
  cout << "수요일" << endl;
  break;
 case 3:
  cout << "목요일" << endl;
  break;
 case 4:
  cout << "금요일" << endl;
  break;
 case 5:
  cout << "토요일" << endl;
  break;
 case 6:
  cout << "일요일" << endl;
  break;
 }

 for( i = 1; i < month ; i++ ) // 5
 {
  // 1 + 2 + 3 + 4
  switch(i)
  {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
   totalDay += 31;
   break;
  case 4:
  case 6:
  case 9:
  case 11:
   totalDay += 30;
   break;
  case 2:
   if( (year % 4) == 0 && ( (year % 100) != 0 || (year % 400) == 0 ) )
   {
    totalDay += 29;
   }
   else
   {
    totalDay += 28;
   }
   break;
  }
 }

 cout << year << "년 "<< month<<"월 1일 까지의 일수 " << totalDay << "요일 : ";

 switch( totalDay % 7 )
 {
 case 0:
  cout << "월요일" << endl;
  break;
 case 1:
  cout << "화요일" << endl;
  break;
 case 2:
  cout << "수요일" << endl;
  break;
 case 3:
  cout << "목요일" << endl;
  break;
 case 4:
  cout << "금요일" << endl;
  break;
 case 5:
  cout << "토요일" << endl;
  break;
 case 6:
  cout << "일요일" << endl;
  break;
 } 


 switch(month)
 {
 case 1:
 case 3:
 case 5:
 case 7:
 case 8:
 case 10:
 case 12:
  dayOfMonth = 31;
  break;
 case 4:
 case 6:
 case 9:
 case 11:
  dayOfMonth = 30;
  break;
 case 2:
  if( (year % 4) == 0 && ( (year % 100) != 0 || (year % 400) == 0 ) )
  {
   dayOfMonth = 29;
  }
  else
  {
   dayOfMonth = 28;
  }
  break;
 }

 cout << year << "년 " << month << "월 달력 =====" << endl;
 cout << "월 화 수 목 금 토 일" << endl;
 cout << dayOfMonth << "일 입니다" << endl;

 

 for( i = 0 ; i < totalDay % 7 ; i++)
 {
  cout << "   " ;
 }
 for(i = 1; i <= dayOfMonth ; i ++ )
 {  
  printf("%2d ", i);

  if( totalDay % 7 == 6)
  {
   cout << endl;
  }
  totalDay++;  
 }


 cout << endl << endl;


 return 0;
}

 
