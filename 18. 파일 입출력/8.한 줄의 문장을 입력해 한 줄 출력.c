#include <stdio.h>
#include <string.h> // strlen 함수 사용을 위해 포함 (개행 문자 제거 시)

int main(void) {
    FILE *ifp, *ofp;      // 입력, 출력 파일 포인터 선언
    char str[80];         // 입력한 문자열을 저장할 배열
    char *res;            // fgets 함수의 반환값을 저장할 변수

    ifp = fopen("a.txt", "r"); // 입력 파일을 읽기 전용으로 개방
    if (ifp == NULL) {
        printf("입력 파일을 열지 못했습니다.\n");
        return 1;
    }

    ofp = fopen("b.txt", "w"); // 출력 파일을 쓰기 전용으로 개방
    if (ofp == NULL) {
        printf("출력 파일을 열지 못했습니다.\n");
        fclose(ifp); // 열었던 입력 파일은 닫아줌
        return 1;
    }

    while (1) { // 문자열을 입력하고 출력하는 과정 반복
        res = fgets(str, sizeof(str), ifp); // 입력 파일에서 한 줄 읽음
        if (res == NULL) {                 // 반환값이 널 포인터면 종료 (파일 끝 또는 오류)
            // feof(ifp) 등으로 실제 파일 끝인지 확인 가능
            break;
        }
        // fgets는 개행 문자도 읽으므로, 필요하다면 제거
        // str[strlen(str) - 1] = '\0'; // 간단하지만 마지막 줄에 개행 없으면 문제
        str[strcspn(str, "\n")] = '\0';  // 더 안전한 방법

        fputs(str, ofp);      // 출력 파일로 문자열 출력 (개행 문자 없음)
        fputs(" ", ofp);      // 문자열 뒤에 공백 추가 (예제 결과와 맞추기 위해)
                               // 예제에서는 공백 추가 후 개행하지 않음
                               // 한 줄씩 쓰려면 fputs("\n", ofp); 추가
    }

    fclose(ifp); // 입력 파일 닫기
    fclose(ofp); // 출력 파일 닫기

    return 0;
}
