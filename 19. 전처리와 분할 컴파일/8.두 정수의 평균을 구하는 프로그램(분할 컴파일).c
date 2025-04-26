// main.c
#include <stdio.h>

// 다른 파일에 정의된 함수들의 원형 선언
void input_data(int *pa, int *pb);
double average(int a, int b);

int main(void) {
    int a, b;
    double avg;

    input_data(&a, &b);                // 두 정수 입력 함수 호출
    avg = average(a, b);               // 평균 계산 함수 호출
    printf("%d와 %d의 평균 : %.1lf\n", a, b, avg); // 입력값과 평균 출력

    return 0;
}

// sub.c
#include <stdio.h> // printf, scanf 함수 사용

void input_data(int *pa, int *pb) { // 두 정수 입력 함수
    printf("두 정수 입력 : ");
    scanf("%d%d", pa, pb);
}

double average(int a, int b) { // 평균을 구하는 함수
    int tot;
    double avg;

    tot = a + b;
    avg = tot / 2.0; // 실수 나누기를 위해 2.0 사용

    return avg;
}
