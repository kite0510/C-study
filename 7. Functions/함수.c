#include <stdio.h>

// sum 함수 - 두 정수의 합을 반환
int sum(int x, int y) {
    int temp;    // 두 수의 합을 저장할 임시 변수
    temp = x + y;    // x와 y를 더해 temp에 저장
    return temp;     // temp 값을 반환
}

// get_num 함수 - 양수 사용자 입력을 받아 반환
int get_num(void) {
    int num;    // 사용자 입력을 저장할 변수
    do {
        printf("양수 입력 (0 이상): ");    // 양수 입력 요청
        scanf("%d", &num);                 // 정수 입력받아 num에 저장
        if (num < 0) printf("음수는 입력할 수 없습니다. 다시 입력하세요.\n");
    } while (num < 0);    // 음수 입력 시 재입력 요청
    return num;           // 입력된 양수 반환
}

// print_char 함수 - 문자 출력
void print_char(char ch, int count) {
    int i;    // 반복을 위한 인덱스 변수
    for (i = 0; i < count; i++) {    // count번 반복
        printf("%c", ch);             // ch 문자를 count번 출력
    }
    printf("\n");    // 출력 후 줄 바꿈
}

// print_line 함수 - 줄 출력
void print_line(void) {
    printf("*****\n");    // 별 5개와 줄 바꿈 출력
}

// fruit 함수 - 과일 출력 (재귀 함수)
void fruit(int count) {
    if (count >= 3) return;    // count가 3 이상이면 함수 종료 (무한 루프 방지)
    printf("apple\n");         // "apple" 출력
    fruit(count + 1);          // count를 1 증가시켜 재귀 호출
    if (count == 1) printf("jam\n");    // count가 1일 때 "jam" 출력
}

/*
// get_num 함수 (재귀 호출 버전, 주석 처리 - 무한 루프 위험)
// 주의: 재귀 호출이 무한 루프로 작동할 수 있음. 아래는 예시로만 남김
int get_num(void) {
    int result;    // 함수 호출 결과를 저장할 변수
    result = get_num();    // 재귀 호출 (무한 루프 가능성)
    printf("반환값: %d\n", result);    // 반환값 출력
    return 0;    // 0 반환 (실제 구현에서는 사용자 입력 필요) 
/*무한 재귀 호출:
get_num 함수가 자신을 호출(result = get_num();)하면서 종료 조건이 없기 때문에, 함수가 계속해서 자신을 호출합니다. 이는 스택 오버플로우(stack overflow)로 이어져 프로그램이 크래시됩니다.
예를 들어, main에서 get_num()을 호출하면, get_num이 다시 get_num을 호출하고, 이 과정이 무한히 반복됩니다. 컴퓨터 메모리의 스택 공간이 한계에 도달하면 프로그램이 중단됩니다.
반환값 문제:
return 0은 항상 0을 반환하지만, result = get_num()에서 반환된 값이 사용되지 않고 무시됩니다. 이는 함수의 목적(사용자 입력을 받아 반환)에 부합하지 않습니다.
printf("반환값: %d\n", result)는 result 값을 출력하지만, result가 유효한 사용자 입력이 아닌 무한 재귀 호출의 결과(0)로만 채워지므로 의미가 없습니다.*/
}
*/

// fruit 함수 (재귀 호출, 무한 루프 방지 버전)
void fruit(void) {
    static int call_count = 0;    // 호출 횟수 추적 (정적 변수)
    if (call_count >= 2) return;    // 2번 호출 후 종료 (무한 루프 방지)
    printf("apple\n");             // "apple" 출력
    call_count++;                  // 호출 횟수 증가
    fruit();                       // 재귀 호출
}

int main(void) {
    // sum 함수 테스트 - 두 정수의 합 호출
    int a = 10, b = 20;
    int result = sum(a, b);    // sum 함수 호출, a와 b의 합 반환
    printf("result : %d\n", result);    // 출력: 30 (10 + 20)

    // get_num 함수 테스트 - 사용자 입력 받아 출력
    result = get_num();    // 사용자 입력 받기 (양수만 허용)
    printf("반환값: %d\n", result);    // 입력된 값 출력

    // print_char 함수 테스트 - 'a' 문자 5번 출력
    print_char('a', 5);    // 'a'를 5번 출력: aaaaa (줄 바꿈 포함)

    // print_line 함수 테스트 - 별 5개 출력
    print_line();    // ***** 출력

    // fruit 함수 테스트 (재귀 호출)
    fruit(1);    // count를 1로 시작, "apple" 2번, "jam" 1번 출력
                 // 출력: apple, apple, jam

    /*
    // get_num 함수 테스트 (재귀 호출 문제로 주석 처리)
    // 무한 루프 방지를 위해 실제 사용하지 않음
    result = get_num();
    printf("get_num 반환값: %d\n", result);
    */

    // fruit 함수 테스트 (재귀 호출, 무한 루프 방지)
    fruit();    // "apple" 2번 출력 후 종료
                // 출력: apple, apple

    return 0;
}
