#include <stdio.h>

// # 연산자: 인수를 문자열로 만듦
#define PRINT_EXPR(x) printf(#x " = %d\n", x)
// ## 연산자: 두 토큰을 하나로 붙임
#define NAME_CAT(x, y) (x##y)

int main(void) {
    int a1, a2;

    NAME_CAT(a, 1) = 10; // a##1 => a1 = 10; 으로 치환
    NAME_CAT(a, 2) = 20; // a##2 => a2 = 20; 으로 치환

    PRINT_EXPR(a1 + a2); // printf("a1 + a2" " = %d\n", a1 + a2); 로 치환
    PRINT_EXPR(a2 - a1); // printf("a2 - a1" " = %d\n", a2 - a1); 로 치환

    return 0;
}
