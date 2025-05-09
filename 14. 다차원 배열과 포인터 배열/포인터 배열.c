// example_combined_chapter14_part2.c

#include <stdio.h>

int main(void) {
    // 예제 14-6.c (포인터 배열로 여러 개의 문자열 출력)
    // -------------------------------------------------------

    char *pary[5];  // char형 포인터 5개를 저장할 수 있는 포인터 배열 선언
    int i;

    pary[0] = "dog";       // 배열 요소에 문자열 대입
    pary[1] = "elephant";
    pary[2] = "horse";
    pary[3] = "tiger";
    pary[4] = "lion";
    // 문자열 리터럴("dog", "elephant" 등)은 메모리의 읽기 전용 영역에 저장되고,
    // pary[0], pary[1] 등에는 각 문자열 리터럴의 첫 번째 문자의 주소가 저장됨.

    for (i = 0; i < 5; i++) {
        printf("%s\n", pary[i]); // 배열 요소를 사용해 모든 문자열 출력
    }

    // 예제 14-7.c (여러 개의 1차원 배열을 2차원 배열처럼 사용)
    // -------------------------------------------------------

    int ary1[4] = {1, 2, 3, 4};     // 1차원 배열 선언과 초기화
    int ary2[4] = {11, 12, 13, 14};
    int ary3[4] = {21, 22, 23, 24};

    int *pary2[3] = {ary1, ary2, ary3}; // 포인터 배열에 각 배열명 초기화
    int j, k;

    for (j = 0; j < 3; j++) {       // 3행 반복
        for (k = 0; k < 4; k++) {   // 4열 반복
            printf("%5d", pary2[j][k]); // 2차원 배열처럼 출력
        }
        printf("\n");               // 한 행을 출력한 후 줄 바꿈
    }

    return 0;
}
