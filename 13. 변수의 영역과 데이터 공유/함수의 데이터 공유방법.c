#include <stdio.h>

// 함수 선언 (13-6.c)
void add_ten_by_value(int a); // 값에 의한 호출 (call by value)

// 함수 선언 (13-7.c)
void add_ten_by_reference(int *pa); // 주소에 의한 호출 (call by reference)

//함수 선언 (13-8.c)
int *sum(int a, int b);

int main(void) {
    // 예제 13-6.c (10을 더하기 위해 값을 인수로 주는 경우)
    // -------------------------------------------------------
    int a = 10;
    add_ten_by_value(a);      // a의 값을 복사하여 전달
    printf("a : %d\n", a);    // 10 (main 함수의 a는 변경되지 않음)

    // 예제 13-7.c (포인터를 써서 변수의 값에 10을 더하는 경우)
    // -------------------------------------------------------
    int b = 10;
    add_ten_by_reference(&b); // b의 주소를 전달
    printf("b : %d\n", b);    // 20 (main 함수의 b가 변경됨)

    // 예제 13-8.c
    //--------------------------------------------------------
    int *resp; //반환값을 저장할 포인터
    resp = sum(10, 20); //반환된 주소는 resp에 저장
    printf("두 정수의 합 : %d\n", *resp); //resp가 가리키는 변수의 값 출력

    return 0;
}

// 예제 13-6.c 함수 정의 (값에 의한 호출)
void add_ten_by_value(int a) { // main 함수의 a와는 다른 별개의 변수
    a = a + 10;                // 매개변수 a의 값을 변경 (main 함수의 a에는 영향 없음)
}

// 예제 13-7.c 함수 정의 (주소에 의한 호출)
void add_ten_by_reference(int *pa) { // pa는 main 함수의 b의 주소를 받음
    *pa = *pa + 10;                 // pa가 가리키는 곳(main 함수의 b)의 값을 변경
}

// 예제 13-8.c 함수 정의
int *sum(int a, int b){ //int형 변수의 주소를 반환하는 함수
  static int res;       //정적 지역 변수
  res = a + b;          //두 정수의 합을 res(result)에 저장
  return &res;          //정적 지역 변수의 주소 반환
}
