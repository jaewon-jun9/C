#include <stdio.h>
int main() {
  int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  printf("arr 배열의 2 행 3 열의 수를 출력 : %d \n", arr[1][2]);
  printf("arr 배열의 1 행 2 열의 수를 출력 : %d \n", arr[0][1]);
  return 0;
}