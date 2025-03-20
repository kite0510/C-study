#include <stdio.h>

// 함수 선언 (함수 포인터를 사용하는 예제들을 위해)
int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);
void func(int (*fp)(int, int));

int main(void) {
    // 예제 15-7.c (함수 포인터를 사용한 함수 호출)
    // -------------------------------------------------------
    int (*fp)(int, int); // 함수 포인터 선언: int형 매개변수 2개, int형 반환값
    int res;

    fp = sum;          // 함수명을 함수 포인터에 저장 (sum 함수의 주소를 fp에 저장)
    res = fp(10, 20);  // 함수 포인터를 사용하여 함수 호출 (sum(10, 20)과 동일)
    //res = (*fp)(10,20); // *를 써도 동일한 결과.
    printf("result : %d\n", res); // 반환값 출력

    // 예제 15-8.c (함수 포인터로 원하는 함수를 호출하는 프로그램)
    // -------------------------------------------------------

    int sel;

    // 메뉴 출력
    printf("01 두 정수의 합\n");
    printf("02 두 정수의 곱\n");
    printf("03 두 정수 중에서 큰 값 계산\n");
    printf("원하는 연산을 선택하세요 : ");

    scanf("%d", &sel); // 메뉴 번호 입력

    switch (sel) {
        case 1:
            func(sum); // sum 함수의 주소를 func 함수에 전달
            break;
        case 2:
            func(mul); // mul 함수의 주소를 func 함수에 전달
            break;
        case 3:
            func(max); // max 함수의 주소를 func 함수에 전달
            break;
    }

    // 예제 15-9.c (void 포인터의 사용)
    //---------------------------------------------
    int a = 10;
    double b = 3.5;
    void *vp; //void 포인터

    vp = &a; //int 형 변수의 주소 저장
    printf("a : %d\n", *(int *)vp); //int *로 형 변환 후 간접 참조 연산 수행

    vp = &b; //double 형 변수의 주소 저장
    printf("b : %.1lf\n", *(double *)vp); //double *로 형 변환 후 간접 참조 연산 수행

    return 0;
}

// 함수 정의 (예제 15-7.c, 15-8.c)
//------------------------------------------
int sum(int a, int b) { // 덧셈 함수
    return (a + b);
}

int mul(int a, int b){ //곱셈 함수
    return (a*b);
}

int max(int a, int b){ //최댓값 반환 함수
    if(a>b) return a;
    else return b;
}

void func(int (*fp)(int, int)) { // 함수 포인터를 매개변수로 받는 함수
    int a, b;
    int res;

    printf("두 정수의 값을 입력하세요 : ");
    scanf("%d%d", &a, &b);            // 두 정수 입력
    res = fp(a, b);                 // 함수 포인터가 가리키는 함수를 호출, 결과 저장
    printf("결괏값은 : %d\n", res);    // 결과 출력
}
