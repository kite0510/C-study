#include <stdio.h>

// 함수 선언 (11-6.c를 위함)
void my_gets(char *str, int size);

int main(void) {
    // 예제 11-4.c (버퍼를 사용하는 문자 입력)
    // -------------------------------------------------------
    char ch;
    int i;

    for (i = 0; i < 3; i++) {
        scanf("%c", &ch); // 문자 입력
        printf("%c", ch);  // 입력된 문자 출력
    }
    printf("\n");
    // 설명: scanf("%c", &ch)는 입력 버퍼에서 문자 하나를 읽어옵니다.
    //       만약 입력 버퍼에 여러 문자가 남아있다면, 다음 scanf 호출 시
    //       이전 입력의 나머지 문자들이 읽힐 수 있습니다.

    // 예제 11-5.c (입력 문자의 아스키 코드 값을 출력하는 프로그램)
    // -------------------------------------------------------
    int res;
    char ch2;

    while (1) { // 무한 루프
        res = scanf("%c", &ch2); // 문자 입력 (<Ctrl> + <Z> 누르면 -1 반환)
        if (res == -1) break;    // 입력이 없거나 EOF(-1)이면 반복 종료
        printf("%d ", ch2);     // 입력된 문자의 아스키 코드 값 출력
    }
    printf("\n");

    // 예제 11-6.c (getchar 함수를 사용한 문자열 입력)
    // -------------------------------------------------------
    char str[7];             // 문자열을 저장할 배열 (널 문자 포함 크기)
    my_gets(str, sizeof(str)); // 한 줄의 문자열을 입력받는 함수 호출
    printf("입력된 문자열 : %s\n", str); // 입력된 문자열 출력

    // 예제 11-7.c (버퍼의 내용을 지워야 하는 경우)
    // -------------------------------------------------------
    int num, grade;

    printf("학번 입력 : ");
    scanf("%d", &num);  // 학번 입력 (정수)
    getchar();          // 버퍼에 남아있는 개행 문자 제거

    printf("학점 입력 : ");
    grade = getchar();  // 학점 입력 (문자)
    printf("학번 : %d, 학점 : %c\n", num, grade); //입력값 출력
    return 0;
}

// 예제 11-6.c: getchar()를 사용하여 문자열 입력받는 함수
void my_gets(char *str, int size) {
    int ch;
    int i = 0;

    // getchar()로 한 문자씩 읽어서 str 배열에 저장
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < size - 1) { // 배열 범위 초과 방지 (널 문자 공간 확보)
            str[i++] = ch;
        }
    }
    str[i] = '\0'; // 문자열의 끝에 널 문자 추가
}
