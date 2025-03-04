#include <stdio.h>

void print_ary(int *pa, int size);           // 예제 10-5.c, 10-6.c
void input_ary(double *pa, int size);        // 예제 10-7.c
double find_max(double *pa, int size);     // 예제 10-7.c

int main(void) {
    // 예제 10-5.c (배열을 처리하는 함수)
    // -------------------------------------------------------
    int ary5[5] = {10, 20, 30, 40, 50};
    print_ary(ary5, 5); // 배열명(ary5)과 배열 크기(5)를 인수로 전달
    printf("\n");


    // 예제 10-6.c (크기가 다른 배열을 출력하는 함수)
    // -------------------------------------------------------
    int ary6_1[5] = {10, 20, 30, 40, 50};
    int ary6_2[7] = {10, 20, 30, 40, 50, 60, 70};

    print_ary(ary6_1, 5);      // ary6_1과 그 크기 5를 전달
    printf("\n");
    print_ary(ary6_2, 7);      // ary6_2와 그 크기 7을 전달
    printf("\n");

    // 예제 10-7.c (배열에 값을 입력하는 함수)
    // -------------------------------------------------------
    double ary7[5];
    double max;
    int size = sizeof(ary7) / sizeof(ary7[0]); // 배열 요소의 개수 계산

    input_ary(ary7, size);              // 배열과 크기를 input_ary 함수에 전달
    max = find_max(ary7, size);         // 최댓값을 찾아 max에 저장
    printf("배열의 최댓값: %.1lf\n", max); // 소수점 아래 한 자리까지 출력


    return 0;
}

// 예제 10-5.c, 10-6.c: 배열 출력 함수
void print_ary(int *pa, int size) { // pa: 배열의 시작 주소, size: 배열 요소 개수
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", pa[i]); // pa[i]는 *(pa + i)와 동일.  배열 요소 출력
    }
}

// 예제 10-7.c: 배열에 값 입력 함수
void input_ary(double *pa, int size) {  // double형 포인터 pa, 배열 크기 size
    int i;
    printf("%d개의 실수값 입력 : ", size);
    for (i = 0; i < size; i++) {
        scanf("%lf", pa + i); // &pa[i]와 동일. pa + i는 i번째 요소의 주소.
    }
}

// 예제 10-7.c: 배열에서 최댓값 찾는 함수
double find_max(double *pa, int size) { // double형 포인터 pa, 배열 크기 size
    double max;
    int i;

    max = pa[0]; // 첫 번째 배열 요소를 최댓값으로 초기 설정

    for (i = 1; i < size; i++) { // 두 번째 요소부터 비교 시작
        if (pa[i] > max) {     // 새로운 배열 요소의 값이 max보다 크면
            max = pa[i];     // max를 새로운 요소의 값으로 업데이트
        }
    }

    return max; // 최댓값 반환
}
