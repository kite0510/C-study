#include <stdio.h>

int main(void) {
    int ch; // 입력한 문자를 저장할 변수

    while (1) {
        ch = getchar(); // 키보드에서 문자 입력 (내부적으로 stdin 사용)
        if (ch == EOF) { // <Ctrl> + <Z> (Windows) 또는 <Ctrl> + <D> (Unix/Linux)로 입력 종료
            break;
        }
        putchar(ch); // 화면에 문자 출력 (내부적으로 stdout 사용)
    }

    return 0;
}
