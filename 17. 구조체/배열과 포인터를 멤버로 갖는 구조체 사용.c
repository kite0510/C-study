#include <stdio.h>
#include <stdlib.h> // malloc, free 함수 사용을 위해 포함
#include <string.h> // strcpy 함수 사용을 위해 포함

struct profile {       // 신상명세 구조체 선언
    char name[20];     // 이름을 저장할 배열 멤버
    int age;           // 나이
    double height;     // 키
    char *intro;       // 자기소개를 위한 포인터
};

int main(void) {
    struct profile yuni; // profile 구조체 변수 선언

    strcpy(yuni.name, "서하윤"); // name 멤버에 이름 복사
    yuni.age = 17;              // age 멤버에 나이 저장
    yuni.height = 164.5;        // height 멤버에 키 저장

    yuni.intro = (char *)malloc(80); // 자기소개를 저장할 공간 동적 할당
    printf("자기소개 : ");
    gets(yuni.intro); // gets_s를 사용하는 것이 더 안전합니다 (C11 표준 이상)
                      // gets는 버퍼 오버플로우 취약점이 있습니다.
                      // 할당한 공간에 자기소개 입력

    printf("이름 : %s\n", yuni.name);    // 각 멤버의 데이터 출력
    printf("나이 : %d\n", yuni.age);
    printf("키 : %.1lf\n", yuni.height);
    printf("자기소개 : %s\n", yuni.intro);
    free(yuni.intro); // 동적 할당 영역 반환

    return 0;
}
