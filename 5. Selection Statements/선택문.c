#include <stdio.h>

int main(void) {
    // 기본 if문 - a가 b보다 클 때 b 값을 3으로 설정
    // a와 b를 초기화하고, a > b 조건을 확인해 b 값을 변경
    int a = 10, b = 20;
    if (a > b) {    // a(10) > b(20)가 거짓이므로 내부 블록 실행 안 됨
        b = 3;      // 이 줄은 실행되지 않음
    }
    printf("if (a > b) b: %d\n", b);    // b 값은 변경되지 않아 20 출력

    // if-else문 - a가 10보다 클 때 b를 2로, 그렇지 않으면 b를 -1로 설정
    // a와 b를 초기화하고, a > 10 조건을 확인해 b 값을 조건에 따라 변경
    a = 10, b = 20;
    if (a > 10) {    // a(10) > 10이 거짓이므로 else 블록 실행
        b = 2;       // 이 줄은 실행되지 않음
    } else {
        b = -1;      // b가 -1로 설정됨
    }
    printf("if (a > 10) b: %d\n", b);    // b 값은 -1 출력

    // if-else if-else문 - a가 0, 1, 3보다 클 때 b 값을 각각 설정
    // a와 b를 초기화하고, 여러 조건을 순차적으로 평가해 b 값을 설정
    a = 10, b = 20;
    if (a == 0) {    // a(10) == 0이 거짓이므로 다음 조건으로
        b = 1;       // 이 줄은 실행되지 않음
    } else if (a == 1) {    // a(10) == 1이 거짓이므로 다음 조건으로
        b = 2;            // 이 줄은 실행되지 않음
    } else if (a > 3) {     // a(10) > 3이 참이므로 이 블록 실행
        b = 100;           // b가 100으로 설정됨
    }
    printf("if-else if (a > 3) b: %d\n", b);    // b 값은 100 출력

    // 중첩 if문 추가: a가 10보다 크고, b가 20보다 클 때 c 값을 설정
    // 중첩 if는 외부 조건이 참일 때만 내부 조건을 평가
    int c = 0;
    if (a > 10) {    // a(10) > 10이 거짓이므로 내부 if 실행 안 됨
        if (b > 20) {    // 이 줄은 실행되지 않음
            c = 50;      // 이 줄은 실행되지 않음
        }
    } else {
        c = -50;         // a > 10이 거짓이므로 else 블록 실행, c가 -50으로 설정
    }
    printf("중첩 if (a > 10 && b > 20) c: %d\n", c);    // c 값은 -50 출력

    // switch문 - rank 값에 따라 메시지 출력
    // rank 값을 기반으로 case별로 조건을 평가하고 break로 종료
    int rank = 2;
    switch (rank) {
        case 1: printf("rank 1: 100점\n"); break;    // rank가 1이 아니므로 실행 안 됨
        case 2: printf("rank 2: 200점\n"); break;    // rank가 2이므로 실행, "rank 2: 200점" 출력 후 break
        case 3: printf("rank 3: 300점\n"); break;    // rank가 3이 아니므로 실행 안 됨
        default: printf("rank default: 0점\n"); break;    // rank가 case에 없으면 실행 안 됨
    }

    return 0;
}
