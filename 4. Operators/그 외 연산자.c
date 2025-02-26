#include <stdio.h>

int main(void) {
    // 비트 연산
    int x = 60, y = 20;    // 60 = 0011 1100, 20 = 0001 0100 (2진수)
    int res;

    res = x & y;    // AND: 0001 0100 = 20
    printf("x & y : %d\n", res);
    res = x | y;    // OR: 0011 1100 = 60
    printf("x | y : %d\n", res);
    res = x ^ y;    // XOR: 0010 1000 = 40
    printf("x ^ y : %d\n", res);
    res = ~x;       // NOT: 1100 0011 = -61 (2의 보수)
    printf("~x : %d\n", res);
    res = x << 2;   // 왼쪽 시프트: 1111 0000 = 240
    printf("x << 2 : %d\n", res);
    res = x >> 2;   // 오른쪽 시프트: 0000 1111 = 15
    printf("x >> 2 : %d\n", res);

    // 조건 연산 (삼항 연산자)
    int a = 10, b = 20;
    res = (a > b) ? a : b;    // a > b가 거짓이므로 b(20)를 반환
    printf("(a > b) ? a : b : %d\n", res);

    // sizeof 연산
    double da = 3.4, db = 10.5;
    int ia = 10, ib = 20;
    char c_array[5] = "test";
    int i_array[3] = {1, 2, 3};
    printf("size of char : %d\n", sizeof(char));
    printf("size of int : %d\n", sizeof(int));
    printf("size of double : %d\n", sizeof(double));
    printf("size of char array : %d\n", sizeof(c_array));    // 5 (문자열 + NULL 종료문자)
    printf("size of int array : %d\n", sizeof(i_array));     // 12 (3 * sizeof(int))
    printf("size of da : %d\n", sizeof(da));                 // double 크기
    printf("size of ia : %d\n", sizeof(ia));                 // int 크기

    // 형 변환 연산
    res = (int)(da / db);    // 실수를 정수로 캐스팅 후 나눗셈
    printf("da / db (int casting) : %d\n", res);

    // 복합 대입 연산
    x += y;    // x = x + y (60 + 20 = 80)
    printf("x += y : %d\n", x);
    x -= y;    // x = x - y (80 - 20 = 60)
    printf("x -= y : %d\n", x);
    x *= y;    // x = x * y (60 * 20 = 1200)
    printf("x *= y : %d\n", x);
    x /= y;    // x = x / y (1200 / 20 = 60)
    printf("x /= y : %d\n", x);
    x %= y;    // x = x % y (60 % 20 = 0)
    printf("x %= y : %d\n", x);
    x &= y;    // x = x & y (0 & 20 = 0)
    printf("x &= y : %d\n", x);
    x |= y;    // x = x | y (0 | 20 = 20)
    printf("x |= y : %d\n", x);
    x ^= y;    // x = x ^ y (20 ^ 20 = 0)
    printf("x ^= y : %d\n", x);
    x <<= 2;   // x = x << 2 (0 << 2 = 0)
    printf("x <<= 2 : %d\n", x);
    x >>= 2;   // x = x >> 2 (0 >> 2 = 0)
    printf("x >>= 2 : %d\n", x);

    // 콤마 연산
    int i = 0, j = 0;
    res = (i++, j += 2);    // i는 1로 증가, j는 2 증가, 최종 res는 j 값(2)
    printf("i, j after (i++, j += 2) : i = %d, j = %d, res = %d\n", i, j, res);

    // 연산자 우선순위와 방향
    int p = 10, q = 5, r = 2, s = 3;
    res = p + q * r - s & x | y ^ ~q << 2 >> 1;    // 복잡한 연산자 우선순위: (10 + (5 * 2) - 3) & 0 | 20 ^ ~5 << 2 >> 1
    printf("p + q * r - s & x | y ^ ~q << 2 >> 1 : %d\n", res);
    res = ((p + q) * r - s) & (x | y) ^ (~q << 2) >> 1;    // 괄호로 우선순위 명시: ((10 + 5) * 2 - 3) & (0 | 20) ^ (~5 << 2) >> 1
    printf("((p + q) * r - s) & (x | y) ^ (~q << 2) >> 1 : %d\n", res);

    return 0;
}
