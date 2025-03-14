#include <stdio.h>

int main(void) {
    // 예제 14-1.c (학생 3명의 4과목 점수 총점과 평균)
    // -------------------------------------------------------
    int score[3][4];  // 3명의 4과목 점수를 저장할 2차원 배열
    int total;      // 총점
    double avg;       // 평균
    int i, j;

    // 입력 부분
    for (i = 0; i < 3; i++) {
        printf("4과목의 점수 입력 : ");
        for (j = 0; j < 4; j++) {
            scanf("%d", &score[i][j]); // i번째 학생의 j번째 과목 점수 입력
        }
    }

    // 총점과 평균 계산 및 출력 부분
    for (i = 0; i < 3; i++) {
        total = 0; // 학생이 바뀔 때마다 total을 0으로 초기화
        for (j = 0; j < 4; j++) {
            total += score[i][j]; // i번째 학생의 모든 과목 점수를 total에 누적
        }
        avg = total / 4.0;        // 평균 계산 (double 형으로)
        printf("총점 : %d, 평균 : %.2lf\n", total, avg); // 총점과 평균 출력
    }


    // 예제 14-2.c (2차원 배열의 다양한 초기화 방법)
    // -------------------------------------------------------
    int num[3][4] = {  // 2차원 배열의 선언과 초기화
        {1, 2, 3, 4},   // num의 0행
        {5, 6, 7, 8},   // num의 1행
        {9, 10, 11, 12} // num의 2행
    };

    int k, l;

    for (k = 0; k < 3; k++) {
        for (l = 0; l < 4; l++) {
            printf("%5d", num[k][l]); // 배열 요소 출력
        }
        printf("\n"); // 한 행을 출력한 후 줄 바꿈
    }


    // 예제 14-3.c (여러 개의 동물 이름을 입출력하는 프로그램)
    // -------------------------------------------------------
    char animal[5][20]; // 5개의 동물 이름을 저장할 2차원 char 배열 (각 이름은 최대 19자)
    int m;
    int count;             // 행의 수를 저장할 변수

    count = sizeof(animal) / sizeof(animal[0]); // 행의 수 계산

    for (m = 0; m < count; m++) {
        scanf("%s", animal[m]); // 문자열 입력, animal[m]은 m번째 행의 시작 주소(배열명)
    }

    for (m = 0; m < count; m++) {
        printf("%s ", animal[m]); // 입력된 문자열 출력
    }
    printf("\n");


    // 예제 14-4.c (2차원 char 배열에 동물 이름을 초기화하는 방법)
    // -------------------------------------------------------
    char animal1[5][10] = { // 문자 상수 하나씩 초기화
        {'d', 'o', 'g', '\0'},
        {'t', 'i', 'g', 'e', 'r', '\0'},
        {'r', 'a', 'b', 'b', 'i', 't', '\0'},
        {'h', 'o', 'r', 's', 'e', '\0'},
        {'c', 'a', 't', '\0'}
    };

    char animal2[][10] = {  // 문자열 상수로 한 행씩 초기화, 행의 수 생략
        "dog", "tiger", "rabbit", "horse", "cat"
    };
    int n,o;
    for (n = 0; n < 5; n++) {
        printf("%s ", animal1[n]); // animal1 출력
    }
    printf("\n");
    for (o = 0; o < 5; o++) {
          printf("%s ", animal2[o]);//animal2 출력
    }
     printf("\n");



    // 예제 14-5.c (2개 반 3명 학생의 4과목 점수를 저장하는 3차원 배열)
    // -------------------------------------------------------
    int score3D[2][3][4] = {  // 2개 반, 3명, 4과목 점수 저장
        {
            {72, 80, 95, 60},
            {66, 85, 90, 88},
            {95, 92, 88, 95}
        },
        {
            {68, 98, 83, 90},
            {75, 72, 84, 90},
            {43, 72, 56, 75}
        }
    };

    int p, q, r;

    for (p = 0; p < 2; p++) {         // 반 수만큼 반복
        printf("%d반 점수...\n", p + 1);
        for (q = 0; q < 3; q++) {     // 학생 수만큼 반복
            for (r = 0; r < 4; r++) { // 과목 수만큼 반복
                printf("%5d", score3D[p][q][r]); // 점수 출력
            }
            printf("\n");         // 한 학생의 점수를 출력하고 줄 바꿈
        }
        printf("\n");             // 한 반의 점수를 출력하고 줄 바꿈
    }

    return 0;
}
