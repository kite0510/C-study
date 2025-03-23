#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char temp[80];      // 임시 char 배열
    char *str[3];       // 동적 할당 영역을 연결할 포인터 배열
    int i;

    for (i = 0; i < 3; i++) {
        printf("문자열을 입력하세요 : ");
        gets(temp);  //fgets(temp, sizeof(temp), stdin); 사용 권장

        str[i] = (char *)malloc(strlen(temp) + 1); // 문자열 저장 공간 할당, +1은 널 문자
        if(str[i] == NULL){
          printf("메모리가 부족합니다!\n");
          exit(1);
        }
        strcpy(str[i], temp);                     // 동적 할당 영역에 문자열 복사
    }

    for (i = 0; i < 3; i++) {
        printf("%s\n", str[i]); // 입력된 문자열 출력
    }

    for (i = 0; i < 3; i++) { //!!
        free(str[i]);         // 동적 할당 영역 반환, 저장한 역순으로 반환하는 것이 안전.
        str[i] = NULL;
    }

    return 0;
}
