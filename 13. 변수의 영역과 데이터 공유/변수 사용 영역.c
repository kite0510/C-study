#include <stdio.h>

// 함수 선언 (13-1.c)
void assign(void);

// 전역 변수 (13-3.c)
int global_a;

// 함수 선언 (13-3.c)
void assign10(void);
void assign20(void);

// 함수 선언 (13-4.c)
void auto_func(void);
void static_func(void);


int main(void) {
    // 예제 13-1.c (두 함수에서 같은 이름의 변수를 사용한 경우)
    // -------------------------------------------------------
    int a = 0;      // main 함수의 지역 변수 a (auto 생략)
    printf("main 함수 a : %d\n", a); // 0

    assign();       // assign 함수 호출

    printf("main 함수 a : %d\n", a); // 0 (assign 함수에서 변경된 값은 main 함수의 a에 영향 X)

    // 예제 13-2.c (블록 안에 지역 변수를 사용해 두 변수를 교환하는 프로그램)
     // -------------------------------------------------------

    int a1 = 10, b1 = 20;
    printf("교환 전 a와 b의 값 : %d, %d\n", a1, b1); // 10, 20
    { // 블록 시작
        int temp; // 블록 안에서만 유효한 지역 변수 temp
        temp = a1;
        a1 = b1;
        b1 = temp;
    } // 블록 끝: temp 변수는 소멸
    printf("교환 후 a와 b의 값 : %d, %d\n", a1, b1); // 20, 10

    // 예제 13-3.c (전역 변수의 사용)
    // -------------------------------------------------------
    printf("함수 호출 전 a 값 : %d\n", global_a); // 0 (전역 변수는 초기화하지 않으면 0으로 자동 초기화)
    assign10();
    assign20();
    printf("함수 호출 후 a 값 : %d\n", global_a); // 20

    // 예제 13-4.c (auto 지역 변수와 static 지역 변수)
    // -------------------------------------------------------
    int i;
    printf("일반 지역 변수(auto)를 사용한 함수...\n");
    for (i = 0; i < 3; i++) {
        auto_func(); // auto_func 함수를 세 번 호출
    }

    printf("정적 지역 변수(static)를 사용한 함수...\n");
    for (i = 0; i < 3; i++) {
        static_func(); // static_func 함수를 세 번 호출
    }

    // 예제 13-5.c (레지스터 변수를 반복문에 사용한 예)
    //----------------------------------------------------------
    register int j;        // 레지스터 변수 선언
    auto int sum = 0;    // auto 지역 변수 (일반적인 지역 변수)

    for (j = 1; j <= 10000; j++) {
        sum += j;          // j 값을 반복해서 누적
    }
    printf("%d\n", sum); // 50005000

    return 0;
}

// 예제 13-1.c 함수 정의
void assign(void) {
    int a;          // assign 함수의 지역 변수 a (main 함수의 a와는 다른 변수)
    a = 10;         // assign 함수의 지역 변수 a에 10 대입
    printf("assign 함수 a : %d\n", a); // 10
}

// 예제 13-3.c 함수 정의
void assign10(void) {
    global_a = 10;    // 전역 변수 global_a에 10 대입
}

void assign20(void) {
    int global_a;     // 같은 이름의 지역 변수 선언 (전역 변수 가려짐)
    global_a = 20;    // 지역 변수 global_a에 20 대입 (전역 변수 global_a에는 영향 없음)
}

// 예제 13-4.c 함수 정의
void auto_func(void) {
    auto int a = 0; // auto 지역 변수 (auto는 생략 가능). 함수 호출 시마다 새로 생성되고 초기화됨.
    a++;
    printf("%d\n", a); // 항상 1 출력
}

void static_func(void) {
    static int a;    // 정적 지역 변수. 함수 호출 사이에 값을 유지.  처음 한 번만 초기화됨(초기화 생략 시 0).
    a++;
    printf("%d\n", a); // 호출될 때마다 값이 1씩 증가 (1, 2, 3 출력)
}
