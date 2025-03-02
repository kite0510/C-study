#include <stdio.h>   // 표준 입출력 (printf, puts, gets)
#include <string.h>  // 문자열 관련 함수 (strcpy)

/*
 * 예제 8-7.C:  널 문자가 없는 문자열
 *  문자 배열을 초기화하지만 널 종료 문자를 명시적으로 포함하지 않는 경우를 보여줍니다.
 */
void example_8_7() {
    printf("\n--- 예제 8-7 ---\n");

    char str[5]; // 5개의 문자를 저장할 수 있는 배열을 선언.  (널 문자 포함 X 가정)

    str[0] = '0';
    str[1] = 'K';
    // str[2], str[3], str[4]는 초기화되지 않음.

    printf("%s\n", str); // 문자열을 출력.  널 종료되지 않았기 때문에 예상치 못한 결과가 발생할 수 있음.
                         // 쓰레기 값이나 다른 메모리 영역의 내용이 출력될 수 있다.
}

/*
 * 예제 8-4.C: char형 배열
 *  문자열을 char 배열로 처리하는 방법을 보여줍니다.
 */

void example_8_4() {
    printf("\n--- 예제 8-4 ---\n");

    char str[80] = "applejam"; // 문자열 리터럴로 초기화된 char 배열. 널 문자('\0')가 자동으로 추가됨.

    printf("최초 문자열 : %s\n", str); // 초기 문자열 출력
    printf("문자열 입력 : ");
    scanf("%s", str);          // 사용자로부터 새로운 문자열 입력 (공백 포함 X).
                                // 입력 버퍼 오버플로우에 주의 (배열 크기보다 큰 입력은 위험).
    getchar(); // scanf 이후 버퍼에 남아있는 개행 문자('\n')를 제거합니다.

    printf("입력 후 문자열 : %s\n", str); // 입력받은 문자열 출력
}

/*
 * 예제 8-5.C: strcpy 함수
 *  strcpy 함수를 사용하여 문자열을 복사하는 방법을 보여줍니다.
 */

void example_8_5() {
    printf("\n--- 예제 8-5 ---\n");

    char str1[80] = "cat";  // str1을 "cat"으로 초기화
    char str2[80];       // str2 선언 (초기화되지 않음)

    strcpy(str1, "tiger");     // str1에 "tiger"를 복사.  str1의 내용은 "tiger"로 변경됨.
    strcpy(str2, str1);       // str1의 내용("tiger")을 str2에 복사.

    printf("%s, %s\n", str1, str2); // str1과 str2 출력 ("tiger", "tiger")
}

/*
 * 예제 8-6.C: gets와 puts를 이용한 문자열 입출력
 * gets 함수로 문자열을 입력받고, puts 함수로 출력하는 방법을 보여줍니다.
 */

void example_8_6() {
    printf("\n--- 예제 8-6 ---\n");

    char str[80];

    printf("문자열 입력 : "); // 입력 안내 메시지 출력
    gets(str);          // 사용자로부터 문자열을 입력받습니다. (공백 포함 가능)
                        // gets는 버퍼 오버플로우에 취약하므로 사용에 주의해야 합니다!  (fgets 권장)
    puts("입력된 문자열 : ");  // "입력된 문자열 : " 출력
    puts(str);             // 입력받은 문자열을 출력하고 자동으로 줄 바꿈.
}
#define _CRT_SECURE_NO_WARNINGS //gets함수 사용시 Visual Studio에서 보안 경고를 무시하기 위한 정의

int main() {
    example_8_7();
    example_8_4();
    example_8_5();
    example_8_6();


    return 0;
}
