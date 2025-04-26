#include <stdio.h>

int main(void) {
    int ch; // 입력한 문자를 저장할 변수

    while (1) {
        ch = fgetc(stdin); // 키보드에서 문자 입력 (표준 입력 스트림 stdin 명시)
        if (ch == EOF) {  // <Ctrl> + <Z> 또는 <Ctrl> + <D>로 입력 종료
            break;
        }
        fputc(ch, stdout); // 화면에 문자 출력 (표준 출력 스트림 stdout 명시)
    }

    return 0;
}
