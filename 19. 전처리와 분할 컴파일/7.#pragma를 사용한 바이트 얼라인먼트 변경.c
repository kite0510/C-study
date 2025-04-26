#include <stdio.h>

// pack(push, 1): 현재 패딩 설정을 저장하고, 패딩을 1바이트로 변경
// 컴파일러 및 환경에 따라 동작이 다를 수 있음
#pragma pack(push, 1)
typedef struct {
    char ch; // 1바이트
    int in;  // 4바이트 -> 1바이트 경계에 맞춰 정렬 (총 5바이트 예상)
} Sample1;
#pragma pack(pop) // 이전에 저장한 패딩 설정으로 복원

typedef struct { // 기본 패딩 설정 적용
    char ch; // 1바이트
    // 패딩 바이트 (3바이트, int 정렬 위해)
    int in;  // 4바이트 -> 4바이트 경계에 맞춰 정렬 (총 8바이트 예상)
} Sample2;

int main(void) {
    printf("Sample1 구조체의 크기 : %d바이트\n", sizeof(Sample1));
    printf("Sample2 구조체의 크기 : %d바이트\n", sizeof(Sample2));

    return 0;
}
