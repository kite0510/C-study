#include <stdio.h>

int main(void)
{
  printf("Be happy\n"); //Be happy 출력 \n:줄을 바꿈
  printf("12345678901234\n"); //화면에 열 번호 출력 \n:줄을 바꿈
  printf("My\tfriend\n"); //My를 출력하고 탭 위치로 이동 후(\t) friend 출력 \n:줄을 바꿈
  printf("Goot\bd\tchance\n"); //Good을 출력하고 한 칸 왼쪽으로 이동(\b)하여 t를 d로 바꾸고 탭 위치로 이동 후(\t) chance 출력 \n:줄을 바꿈
  printf("Cow\rW\a\n"); // 맨 앞으로 이동(\r)해 C를 W로 바꾸고 벨소리(\a) 를 내고 \n:줄을 바꿈

return 0;
}
