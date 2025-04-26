#include <stdio.h>

void func(void); // 함수 선언

int main(void) {
    printf("컴파일 날짜와 시간 : %s, %s\n", __DATE__, __TIME__); // 컴파일 날짜, 시간 출력
    printf("파일명 : %s\n", __FILE__);             // 파일명 출력
    printf("함수명 : %s\n", __func__);             // 함수명 출력 (C99 이상)
    // printf("함수명 : %s\n", __FUNCTION__);     // 일부 컴파일러 지원 (비표준)
    printf("행번호 : %d\n", __LINE__);             // 행 번호 출력

#line 100 "macro.c" // 행 번호를 100부터 시작, 파일명을 macro.c로 변경 (전처리기에 의해)
    func();          // 여기부터 행 번호는 100으로 시작

    return 0;
}

void func(void) { // 함수 정의
    printf("\n");
    printf("파일명 : %s\n", __FILE__);     // 변경된 파일명 출력 (macro.c)
    printf("함수명 : %s\n", __func__);     // 함수명 출력 (func)
    printf("행번호 : %d\n", __LINE__);     // 변경된 행 번호 출력 (110)
}
