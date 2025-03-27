#include <stdio.h>

struct student {       // 학생 구조체 선언
    int id;            // 학번
    char name[20];     // 이름
    double grade;      // 학점
};

int main(void) {
    // 구조체 변수 선언과 초기화
    struct student s1 = { 315, "홍길동", 2.4 },
                     s2 = { 316, "이순신", 3.7 },
                     s3 = { 317, "세종대왕", 4.4 };

    struct student max; // 최고 학점 학생을 저장할 변수

    max = s1; // s1을 최고 학점 학생으로 초기화
    if (s2.grade > max.grade) max = s2; // s2가 더 크면 max를 s2로 변경
    if (s3.grade > max.grade) max = s3; // s3가 더 크면 max를 s3로 변경

    printf("학번 : %d\n", max.id);     // 최고 학점 학생의 학번 출력
    printf("이름 : %s\n", max.name);   // 최고 학점 학생의 이름 출력
    printf("학점 : %.1lf\n", max.grade); // 최고 학점 학생의 학점 출력

    return 0;
}
