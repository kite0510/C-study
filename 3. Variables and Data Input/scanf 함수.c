#include <stdio.h>
#include <string.h>

int main(void)
{
	int age; //정수형
	double height; //실수형

	printf("나이와 키를 입력하세요 : "); //입력 안내
	scanf("%d%lf", &age, &height); // 나이와 키 함께 입력
	printf("나이는 %d살, 키는 %.1lfcm입니다\n", age, height); //입력값 출력
	
	char grade; // 학점 입력 변수
	char name[20]; //이름 입력할 배열

	printf("학점 입력 : "); //입력 안내
	scanf(" %c", &grade); //grade 변수에 학점 문자 입력 앞에 공백을 넣어 이전 입력에서 남아 있던 개행 문자 제거
	printf("이름 입력 : "); 
	scanf("%s", name); //name 배열에 이름 문자열 입력, &을 사용하지 않는다.
	printf("%s의 학점은 %c 입니다.\n", name, grade); 
	
	return 0;
}
