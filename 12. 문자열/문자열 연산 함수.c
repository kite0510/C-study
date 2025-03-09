// string_functions_examples.c

#include <stdio.h>
#include <string.h> // strcpy, strncpy, strcat, strncat, strlen, strcmp, strncmp 함수 사용

int main(void) {
    // 예제 12-8.c (strcpy 함수의 사용법)
    // -------------------------------------------------------
    char str1[80] = "strawberry"; // char 배열에 문자열 초기화
    char str2[80] = "apple";      // char 배열에 문자열 초기화
    char *ps1 = "banana";        // 포인터로 문자열 상수 연결
    char *ps2 = str2;          // 포인터로 배열 연결

    printf("최초 문자열: %s\n", str1);

    strcpy(str1, str2);          // str2("apple")를 str1에 복사
    printf("바뀐 문자열: %s\n", str1); // "apple" 출력

    strcpy(str1, ps1);         // ps1("banana")을 str1에 복사
    printf("바뀐 문자열: %s\n", str1); // "banana" 출력

    strcpy(str1, ps2);         // ps2(str2, "apple")을 str1에 복사
    printf("바뀐 문자열: %s\n", str1); // "apple" 출력

    strcpy(str1, "banana");    // 문자열 상수 "banana"를 str1에 복사
    printf("바뀐 문자열: %s\n", str1); // "banana" 출력
    printf("\n");

    // 예제 12-9.c (strncpy 함수를 사용한 문자열 복사)
    // -------------------------------------------------------
    char str3[20] = "mango tree"; // 배열 초기화

    strncpy(str3, "apple-pie", 5); // "apple-pie"에서 5개의 문자만 str3에 복사
    // str3[5] = '\0';             // strncpy는 널 문자를 자동으로 추가하지 않을 *수* 있으므로,
                                   // 필요한 경우 수동으로 널 문자 추가 (여기서는 이미 "mango tree"로 초기화되었기 때문에 주석처리)
    printf("%s\n", str3); // "apple tree" 출력 (기존 문자열의 일부가 남음)
    printf("\n");

    // 예제 12-10.c (strcat, strncat 함수를 사용한 문자열 붙이기)
    // -------------------------------------------------------
    char str4[80] = "straw"; // 문자열 초기화

    strcat(str4, "berry");   // str4에 "berry"를 이어 붙임 ("strawberry")
    printf("%s\n", str4);

    strncat(str4, "piece", 3); // str4에 "piece"의 처음 3문자("pie")를 이어 붙임 ("strawberrypie")
    printf("%s\n", str4);
    printf("\n");


    // 예제 12-11.c (strlen 함수를 사용한 문자열 길이 비교)
    // -------------------------------------------------------
    char str5[80], str6[80];
    char *resp;

    printf("2개의 과일 이름 입력 : ");
    scanf("%s%s", str5, str6); // 2개의 문자열 입력 (공백으로 구분)

    if (strlen(str5) > strlen(str6)) { // str5의 길이가 str6의 길이보다 크면
        resp = str5;               // resp는 str5를 가리킴
    } else {
        resp = str6;               // 그렇지 않으면 resp는 str6를 가리킴
    }
    printf("이름이 긴 과일은: %s\n", resp); // 더 긴 이름을 가진 문자열 출력
    printf("\n");


    // 예제 12-12.c (strcmp, strncmp 함수를 사용한 문자열 비교)
    // -------------------------------------------------------
    char str7[80] = "pear";
    char str8[80] = "peach";

    printf("사전에 나중에 나오는 과일 이름 : ");
    if (strcmp(str7, str8) > 0) {    // str7이 str8보다 사전 순으로 뒤에 나오면
        printf("%s\n", str7);
    } else {
        printf("%s\n", str8); // peach 출력
    }

    return 0;
}
