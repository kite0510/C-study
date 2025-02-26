#include <stdio.h>

int main(void) {
    // 기본적인 산술 연산
    int a = 10, b = 20;
    int sum, sub, mul, inv;

    sum = a + b;    // 덧셈 연산
    sub = a - b;    // 뺄셈 연산
    mul = a * b;    // 곱셈 연산
    inv = -a;       // 음수 연산

    printf("a의 값: %d, b의 값: %d\n", a, b);
    printf("덧셈 : %d\n", sum);
    printf("뺄셈 : %d\n", sub);
    printf("곱셈 : %d\n", mul);
    printf("a의 음수 연산 : %d\n", inv);

    // 실수 나누기
    double apple;
    apple = 5.0 / 2.0;    // 실수 나눗셈
    printf("apple : %.1lf\n", apple);

    // 정수 나누기와 나머지
    int banana, orange;
    banana = 5 / 2;    // 정수 나눗셈
    orange = 5 % 2;    // 나머지 연산
    printf("banana : %d\n", banana);
    printf("orange : %d\n", orange);

    // 비교 연산
    int c = 10;
    int res;

    res = (a > b);    // 10 > 20은 거짓이므로 결과는 0
    printf("a > b : %d\n", res);
    res = (a >= b);   // 10 >= 20은 거짓이므로 결과는 0
    printf("a >= b : %d\n", res);
    res = (a < b);    // 10 < 20은 참이므로 결과는 1
    printf("a < b : %d\n", res);
    res = (a <= b);   // 10 <= 20은 참이므로 결과는 1
    printf("a <= b : %d\n", res);
    res = (a <= c);   // 10 <= 10은 참이므로 결과는 1
    printf("a <= c : %d\n", res);
    res = (a == b);   // 10 == 20은 거짓이므로 결과는 0
    printf("a == b : %d\n", res);
    res = (a != c);   // 10 != 10은 거짓이므로 결과는 0
    printf("a != c : %d\n", res);

    // 논리 연산
    res = (a > 10) && (a < 20);    // 거짓 && 거짓 = 거짓 (0)
    printf("(a > 10) && (a < 20) : %d\n", res);
    res = (a < 10) || (a > 20);    // 거짓 || 거짓 = 거짓 (0)
    printf("(a < 10) || (a > 20) : %d\n", res);
    res = !(a >= 30);              // 거짓이므로 결과는 참 (1)
    printf("!(a >= 30) : %d\n", res);

    // 증감 연산
    a = 10;    // a 초기화
    b = 10;    // b 초기화
    int pre, post;
    pre = (++a) * 3;    // 전위 증감: a가 11로 증가 후 3을 곱함
    post = (b++) * 3;   // 후위 증감: b를 3을 곱한 후 b가 11로 증가
    printf("증가 연산 후 a = %d, b = %d\n", a, b);
    printf("전위증가: (++a) * 3 = %d, 후위증가: (b++) * 3 = %d\n", pre, post);

    // 산술 연산과 출력
    a = 10, b = 20;
    res = a + b;    // 덧셈 연산
    printf("%d + %d = %d (변수 res 사용)\n", a, b, res);    // 결과 변수로 출력
    printf("%d + %d = %d (직접 연산)\n", a, b, a + b);      // 직접 연산 출력

    return 0;
}
