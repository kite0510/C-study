#include <stdio.h>

int main(void) {
    FILE *fp;
    int ary[10] = {13, 10, 13, 13, 10, 26, 13, 10, 13, 10}; // 아스키 코드 값 배열
    int i, res;

    // 바이너리 모드로 쓰기
    fp = fopen("a.txt", "wb"); // 바이너리 파일로 개방 (쓰기)
    if (fp == NULL) { printf("파일 열기 실패(wb)\n"); return 1; }

    for (i = 0; i < 10; i++) {
        fputc(ary[i], fp); // 배열 요소의 값에 해당하는 아스키 문자 출력 (실제로는 바이트 값 저장)
    }
    fclose(fp); // 파일 닫음

    // 텍스트 모드로 읽기
    fp = fopen("a.txt", "rt"); // 같은 파일을 텍스트 파일로 개방 (읽기)
    if (fp == NULL) { printf("파일 열기 실패(rt)\n"); return 1; }

    while (1) {
        res = fgetc(fp);      // 파일에서 한 문자 입력
        if (res == EOF) break; // 파일 끝이면 종료
        printf("%4d", res);   // 입력한 문자의 아스키 코드 값 출력
                              // 텍스트 모드로 읽을 때 일부 시스템(Windows)에서 변환이 일어날 수 있음
                              // (예: 13 -> 무시, 10 -> 그대로, 26 -> EOF로 인식될 수 있음)
    }
    printf("\n");
    fclose(fp); // 파일 닫음

    return 0;
}
