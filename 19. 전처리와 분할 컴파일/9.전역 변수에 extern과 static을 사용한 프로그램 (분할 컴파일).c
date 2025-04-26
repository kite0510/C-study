// main.c
#include <stdio.h>

// 다른 파일에 정의된 함수들의 원형 선언
int input_data(void);
double average(void);
void print_data(double);

// main.c에서 사용할 전역 변수 정의 (Internal Linkage)
// 이 count는 input.c나 average.c의 count와 다른 변수
static int count = 0;

int main(void) {
    int total;      // 입력한 양수의 합 (main에서는 사용 안 함)
    double avg;

    total = input_data(); // 양수를 입력하고 합계를 반환받음 (내부적으로 전역 변수 사용)
    avg = average();      // 평균 계산 (내부적으로 전역 변수 사용)
    print_data(avg);    // 결과 출력 함수 호출

    return 0;
}

void print_data(double avg) { // 입력 개수, 전체 합, 평균 출력 함수
    // input.c의 전역 변수 count, total을 사용하기 위해 extern 선언
    extern int count;  // input.c의 count를 사용하겠다고 선언
    extern int total;  // input.c의 total을 사용하겠다고 선언

    printf("입력한 양수의 개수 : %d\n", count);
    printf("전체 합과 평균 : %d, %.1lf\n", total, avg);
}

// input.c
#include <stdio.h>

// input.c와 average.c에서 공유할 전역 변수 정의 (External Linkage)
int count = 0; // 입력한 양수의 개수
int total = 0; // 입력한 양수의 합

int input_data(void) { // 양수 입력 함수
    int pos; // 양수 저장 변수

    while (1) {
        printf("양수 입력 : ");
        scanf("%d", &pos); // 양수 입력
        if (pos < 0) break; // 음수면 반복 종료
        count++;            // 개수 증가 (전역 변수)
        total += pos;       // 합계 누적 (전역 변수)
    }
    return total; // 전역 변수 total 반환
}


// average.c

// 다른 파일(input.c)에 정의된 전역 변수를 사용하기 위해 extern 선언
extern int count; // input.c의 count를 사용
extern int total; // input.c의 total을 사용

double average(void) { // 평균을 구하는 함수
    // 전역 변수 total과 count를 사용하여 평균 계산
    // count가 0인 경우 0으로 나누는 것을 방지하는 로직 추가 필요
    if (count == 0) {
        return 0.0;
    }
    return total / (double)count; // 입력값의 평균 반환 (실수 나누기)
}
