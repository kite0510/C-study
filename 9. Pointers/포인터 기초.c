#include <stdio.h>  // 표준 입출력 (printf)

 /*
  * 예제 9-1.C: 변수의 메모리 주소 확인
  *  변수의 주소를 출력하는 방법을 보여줍니다.
  */
void example_9_1() {
    printf("\n--- 예제 9-1 ---\n");

    int a;         // int형 변수 선언
    double b;      // double형 변수 선언
    char c;        // char형 변수 선언

    printf("int형 변수 a의 주소 : %p\n", (void*)&a);   // &a는 변수 a의 주소를 나타냅니다. %p는 주소를 출력하기 위한 형식 지정자.
    printf("double형 변수 b의 주소 : %p\n", (void*)&b);  // &b는 변수 b의 주소를 나타냅니다.
    printf("char형 변수 c의 주소 : %p\n", (void*)&c);  // &c는 변수 c의 주소를 나타냅니다.
                                                        // (void*) 캐스팅은 포인터 타입을 void*로 변환하여 %p 형식 지정자와 호환되도록 합니다.
}

/*
 * 예제 9-2.C: 포인터 선언과 사용
 *  포인터를 선언하고 사용하는 기본적인 방법을 보여줍니다.
 */
void example_9_2() {
    printf("\n--- 예제 9-2 ---\n");

    int a;      // 일반 정수형 변수 선언
    int* pa;     // 정수형 포인터 변수 선언 (int형 변수의 주소를 저장할 수 있음)

    pa = &a;     // 포인터 pa에 변수 a의 주소를 대입
    *pa = 10;    // 포인터 pa가 가리키는 곳(변수 a)에 10을 대입

    printf("포인터로 a 값 출력 : %d\n", *pa);  // *pa는 pa가 가리키는 곳의 값(a의 값)을 나타냄
    printf("변수명으로 a 값 출력 : %d\n", a);   // a의 값을 직접 출력
}

/*
 * 예제 9-3.C: 포인터를 사용한 두 정수의 합과 평균 계산
 */
void example_9_3() {
    printf("\n--- 예제 9-3 ---\n");

    int a = 10, b = 15, total;
    double avg;
    int* pa, * pb, * pt;
    double* pg;

    pa = &a;        // pa에 a의 주소 대입
    pb = &b;        // pb에 b의 주소 대입
    pt = &total;    // pt에 total의 주소 대입
    pg = &avg;      // pg에 avg의 주소 대입

    *pt = *pa + *pb;       // pa가 가리키는 값(a)과 pb가 가리키는 값(b)을 더하여 pt가 가리키는 곳(total)에 저장
    *pg = *pt / 2.0;      // total 값을 2.0으로 나누어 pg가 가리키는 곳(avg)에 저장

    printf("두 정수의 값: %d, %d\n", *pa, *pb);    // a와 b의 값을 출력
    printf("두 정수의 합: %d\n", *pt);            // total 값을 출력
    printf("두 정수의 평균: %.1lf\n", *pg);        // avg 값을 출력
}

/*
 * 예제 9-4.C: 포인터에 const 사용
 *  const를 사용하여 포인터가 가리키는 값을 변경하지 못하게 하는 방법을 보여줍니다.
 */
void example_9_4() {
    printf("\n--- 예제 9-4 ---\n");

    int a = 10, b = 20;
    const int* pa = &a;  // pa는 const int* 형.  pa를 통해 a의 값을 변경할 수 없음.

    printf("변수 a 값: %d\n", *pa); // pa를 통해 a의 값을 읽을 수는 있음.
    pa = &b;                   // pa가 다른 변수(b)를 가리키도록 변경하는 것은 가능.
    printf("변수 b 값: %d\n", *pa);
    pa = &a;
    // *pa = 20;  // 컴파일 에러: pa는 const int* 형이므로, pa가 가리키는 값을 변경할 수 없음.
    a = 20;         // a는 const 변수가 아니므로 a를 직접 변경하는 것은 가능.
    printf("변수 a 값: %d\n", *pa);
}

/*
 *  swap 함수: 두 변수의 값을 교환하는 함수 (포인터 사용)
 */
void swap(int* pa, int* pb) {  // 두 정수형 포인터를 매개변수로 받음
    int temp;               // 임시 변수 선언

    temp = *pa;             // temp에 pa가 가리키는 값(a의 값)을 저장
    *pa = *pb;             // pa가 가리키는 곳(a)에 pb가 가리키는 값(b의 값)을 저장
    *pb = temp;             // pb가 가리키는 곳(b)에 temp 값을 저장
}

/*
 * 예제 9-7.C: 포인터를 사용한 두 변수의 값 교환
 */
void example_9_7() {
    printf("\n--- 예제 9-7 ---\n");

    int a = 10, b = 20;

    swap(&a, &b);  // a와 b의 주소를 swap 함수에 전달 (call by reference)
    printf("a:%d, b:%d\n", a, b); // a와 b의 값이 바뀌었는지 확인
}

/*
 * 예제 9-5.C: 주소와 포인터의 크기
 *  다양한 자료형의 주소와 포인터의 크기를 출력합니다.
 */
void example_9_5() {
    printf("\n--- 예제 9-5 ---\n");
    char ch;
    int in;
    double db;

    char* pc = &ch;
    int* pi = ∈
    double* pd = &db;
    // 주소의 크기 출력 (일반적으로 시스템에 따라 4바이트 또는 8바이트)
    printf("char형 변수의 주소 크기 : %zu\n", sizeof(&ch));
    printf("int형 변수의 주소 크기 : %zu\n", sizeof(&in));
    printf("double형 변수의 주소 크기 : %zu\n", sizeof(&db));
    // 포인터의 크기 출력 (주소의 크기와 동일, 일반적으로 4바이트 또는 8바이트)
    printf("char * 포인터의 크기 : %zu\n", sizeof(pc));
    printf("int * 포인터의 크기 : %zu\n", sizeof(pi));
    printf("double * 포인터의 크기 : %zu\n", sizeof(pd));
     // 포인터가 가리키는 변수의 크기 출력
    printf("char * 포인터가 가리키는 변수의 크기 : %zu\n", sizeof(*pc)); // 1
    printf("int * 포인터가 가리키는 변수의 크기 : %zu\n", sizeof(*pi));  // 4
    printf("double * 포인터가 가리키는 변수의 크기: %zu\n", sizeof(*pd)); //8

}
/*
 * 예제 9-6.C: 허용되지 않는 포인터의 대입
 */
void example_9_6() {
    printf("\n--- 예제 9-6 ---\n");
    int a = 10;
    int *p = &a;
    double *pd;

    //pd = p; // 컴파일 경고 또는 오류 발생: 다른 자료형의 포인터끼리 직접 대입은 허용되지 않습니다.

    printf("%lf\n", (double)*p);   // 올바르지 않은 사용: int형 변수 a의 값을 double형으로 해석하여 출력.
                                  // 예상치 못한 결과가 출력될 수 있음.
}

int main() {
    example_9_1();
    example_9_2();
    example_9_3();
    example_9_4();
    example_9_7();
    example_9_5();
    example_9_6();

    return 0;
}
