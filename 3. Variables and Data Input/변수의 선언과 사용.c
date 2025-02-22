#include <stdio.h>

int main(void)
{
	int a; // int형 변수 a 선언
	int b, c; // 2개 동시 선언
	double da; // double형 변수 da 선언
	char ch; // char형 변수 ch 선언

	a = 10; //int형 변수 a에 정수 10 대입
	b = a; //변수 b에 a의 값 대입
	c = a + 20; //c에 a 값과 20을 더한 값 대입
	da = 3.5; //da에 실수 대입
	ch = 'A'; //ch에 문자 A 대입


	printf("변수 a의 값 : %d\n", a);
	printf("변수 b의 값 : %d\n", b);
	printf("변수 c의 값 : %d\n", c);
	printf("변수 da의 값 : %.1lf\n", da);
	printf("변수 ch의 값 : %c\n", ch);

	return 0;
}
