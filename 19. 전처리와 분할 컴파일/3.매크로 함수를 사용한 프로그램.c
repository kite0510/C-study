#include <stdio.h>

#define SUM(a, b) ((a) + (b)) // 두 수의 합 매크로 함수 (괄호 사용 필수!)
#define MUL(a, b) ((a) * (b)) // 두 수의 곱 매크로 함수 (괄호 사용 필수!)

int main(void) {
    int a = 10, b = 20;
    int x = 30, y = 40;
    int res;

    printf("a + b = %d\n", SUM(a, b)); // 매크로 함수 SUM 사용
    printf("x + y = %d\n", SUM(x, y)); // 매크로 함수 SUM 사용
    res = 30 / MUL(2, 5);              // 30 / (2 * 5) => 30 / 10 => 3
                                       // 괄호 없으면 30 / 2 * 5 => 15 * 5 => 75 (오답)
    printf("res : %d\n", res);

    return 0;
}
