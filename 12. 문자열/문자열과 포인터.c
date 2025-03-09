#include <stdio.h>
#include <string.h> // strlen, gets, fgets 등의 함수를 사용하기 위해 필요

int main(void) {
    // 예제 12-1.c (문자열 상수 주소 출력)
    // -------------------------------------------------------
    printf("apple이 저장된 시작 주소 값: %p\n", "apple");        // 문자열 상수의 주소 출력
    printf("두 번째 문자의 주소 값: %p\n", "apple" + 1);     // 두 번째 문자의 주소 출력
    printf("첫 번째 문자: %c\n", *"apple");            // 첫 번째 문자 출력 (간접 참조)
    printf("두 번째 문자: %c\n", *("apple" + 1));       // 두 번째 문자 출력
    printf("배열로 표현한 세 번째 문자: %c\n", "apple"[2]); // 세 번째 문자 출력 (배열 표기법)
    printf("\n");

    // 예제 12-2.c (포인터로 문자열 사용)
    // -------------------------------------------------------
    char *dessert = "apple"; // 포인터 dessert에 문자열 "apple"의 주소 저장

    printf("오늘 후식은 %s입니다.\n", dessert); // 문자열 출력

    dessert = "banana"; // dessert에 새로운 문자열 "banana"의 주소 저장
    printf("내일 후식은 %s입니다.\n", dessert); // 바뀐 문자열 출력
    printf("\n");

    // 예제 12-3.c (scanf 함수를 사용한 문자열 입력)
    // -------------------------------------------------------
    char str[80];

    printf("문자열 입력 : ");
    scanf("%s", str);                   // 공백 없는 문자열 입력
    printf("첫 번째 단어: %s\n", str);     // 입력된 문자열 중 첫 번째 단어 출력

    scanf("%s", str);                   // 버퍼에 남아 있는 다음 단어 입력
    printf("버퍼에 남아 있는 두 번째 단어: %s\n", str); // 버퍼에 남아 있던 두 번째 단어 출력
    printf("\n");
    
    // fflush(stdin); // 표준 입력 버퍼를 비움 (Windows에서는 동작, Linux/macOS에서는 미정의 동작)

    // 예제 12-4.c (gets 함수로 한 줄의 문자열 입력)
    // -------------------------------------------------------
    char str2[80];

    printf("공백이 포함된 문자열 입력 : ");
    gets(str2);                        // gets 함수는 사용하지 않는 것이 좋습니다 (버퍼 오버플로우 위험).
    printf("입력된 문자열은 %s입니다.\n", str2);
    printf("\n");

    // 예제 12-5.c (fgets 함수로 문자열 입력)
    // -------------------------------------------------------
    char str3[80];

    printf("공백이 포함된 문자열 입력 : ");
    fgets(str3, sizeof(str3), stdin);   // fgets 함수는 stdin(표준 입력)으로부터 입력을 받음
    printf("입력된 문자열은 %s입니다\n", str3); // fgets는 개행 문자도 함께 저장
    printf("\n");
    
    // 예제 12-6.c (개행 문자로 인해 gets 함수가 입력을 못하는 경우)
      // -------------------------------------------------------
      int age;
      char name[20];

      printf("나이 입력 : ");
      scanf("%d", &age); // 숫자 입력 후 엔터 키('\n')가 버퍼에 남음

      // fflush(stdin); // 표준 입력 버퍼를 비움 (Windows에서는 동작, Linux/macOS에서는 미정의 동작)
      // getchar();     // 버퍼에 남아있는 개행 문자('\n')를 제거 (가장 간단한 방법)
      fgetc(stdin);  // 표준 입력 버퍼에서 문자 하나를 읽어옴 (개행 문자 제거)

      printf("이름 입력 : ");
      gets(name);      // gets는 버퍼에 남아있는 개행 문자만 읽고 입력을 끝냄 (문제 발생)
      // fgets(name, sizeof(name), stdin); // fgets를 사용하면 버퍼 문제 해결 가능

      printf("나이 : %d, 이름 : %s\n", age, name);
      printf("\n");

    // 예제 12-7.c (문자열을 출력하는 puts와 fputs 함수)
    // -------------------------------------------------------
    char str4[80] = "apple juice";  // 배열에 문자열 초기화
    char *ps = "banana";          // 포인터에 문자열 연결

    puts(str4);     // apple juice 출력하고 줄 바꿈
    fputs(ps, stdout);  // banana만 출력
    puts("milk");   // milk 출력하고 줄 바꿈

    return 0;
}
