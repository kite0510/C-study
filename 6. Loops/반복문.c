#include <stdio.h>

int main(void) {
    // while문 - a가 10보다 작을 때까지 a를 2씩 증가
    // a를 1로 초기화하고, while 조건(a < 10)을 만족하는 동안 a를 2씩 증가시키며 출력
    int a = 1;
    while (a < 10) {    // a가 10보다 작을 때 반복 (a = 1, 3, 5, 7, 9)
        a = a * 2;      // a를 2배로 증가 (1 → 2 → 4 → 8)
        printf("a : %d\n", a);    // 출력: 2, 4, 8 (a가 10 이상이면 반복 종료)
    }

    // for문 - a가 3보다 작을 때까지 a를 2씩 증가
    // a를 1로 초기화하고, for 루프를 통해 a가 3보다 작을 때까지 2씩 증가하며 출력
    int i;
    for (i = 1; i < 3; i++) {    // i가 1일 때 시작, i < 3 동안 반복 (i = 1, 2)
        a = a * 2;               // a를 이전 값의 2배로 증가 (8 → 16 → 32)
        printf("a : %d\n", a);   // 출력: 16, 32 (i가 3이 되면 반복 종료)
    }
  
    // do-while문 - a가 10보다 작을 때까지 a를 2씩 증가
    // do-while은 조건을 나중에 확인하므로 최소 1번은 실행
    a = 1;
    do {    // a가 1로 시작, 최소 1번 실행
        a = a * 2;    // a를 2배로 증가 (1 → 2 → 4 → 8 → 16)
    } while (a < 10);    // a가 10보다 작을 때 반복 (16 ≥ 10이므로 종료)
    printf("do-while a : %d\n", a);    // 출력: 16 (마지막 증가 값)
  
    // 중첩 for문 - i와 j를 사용해 별 출력
    // 외부 for 루프(i: 0부터 2까지)와 내부 for 루프(j: 0부터 4까지)를 통해 별(*) 출력
    for (i = 0; i < 3; i++) {    // i가 0부터 2까지 반복 (3번)
        for (int j = 0; j < 5; j++) {    // j가 0부터 4까지 반복 (5번)
            printf("*");    // 각 내부 루프마다 별 출력
        }
        printf("\n");    // 내부 루프 끝날 때 줄 바꿈
    }
    printf("\n");    // 전체 출력 후 추가 줄 바꿈

    // for문과 break - sum이 30보다 크면 반복 종료
    // i를 1로 초기화하고, i가 10보다 작을 때까지 sum에 i를 누적, sum이 30 이상이면 break
    int sum = 0;
    for (i = 1; i <= 10; i++) {    // i가 1부터 10까지 반복
        sum += i;    // sum에 i를 누적 (1 + 2 + 3 + ... + n)
        if (sum > 30) {    // sum이 30보다 크면 반복 즉시 종료
            break;         // 현재 i에서 루프 종료
        }
    }
    printf("sum (break at > 30): %d\n", sum);    // 출력: sum이 36 (1+2+...+8=36)에서 break

    // for문과 continue - 3의 배수는 건너뛰고 sum에 i 누적
    // i를 1로 초기화하고, i가 100보다 작을 때까지 반복, 3의 배수는 continue로 건너뛰고 sum에 i 추가
    sum = 0;
    for (i = 1; i <= 100; i++) {    // i가 1부터 100까지 반복
        if (i % 3 == 0) {    // i가 3의 배수이면 (3, 6, 9, ...) 다음 반복으로 이동
            continue;        // 현재 i를 건너뛰고 다음 i로 진행
        }
        sum += i;    // 3의 배수 아닌 i 값만 sum에 누적
    }
    printf("sum (excluding multiples of 3): %d\n", sum);    // 출력: 3의 배수 제외한 1~100 합

    return 0;
}
