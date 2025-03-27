#include <stdio.h>

struct vision {      // 로봇의 시력을 저장할 구조체
    double left;     // 왼쪽 눈
    double right;    // 오른쪽 눈
};

struct vision exchange(struct vision robot); // 함수 선언

int main(void) {
    struct vision robot; // 구조체 변수 선언

    printf("시력 입력 : ");
    scanf("%lf%lf", &(robot.left), &(robot.right)); // 시력 입력
    robot = exchange(robot);                        // 교환 함수 호출 (구조체를 값으로 전달하고 받음)
    printf("바뀐 시력 : %.1lf  %.1lf\n", robot.left, robot.right); // 바뀐 시력 출력

    return 0;
}

struct vision exchange(struct vision robot) { // 구조체를 매개변수로 받고 반환
    double temp; // 교환을 위한 임시 변수

    temp = robot.left;  // 좌우 시력 교환
    robot.left = robot.right;
    robot.right = temp;

    return robot; // 교환된 구조체 반환
}
