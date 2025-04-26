#include <stdio.h>

int main(void) {
    FILE *fp;
    int age;         // 나이 저장 변수
    char name[20];   // 이름 저장 배열

    fp = fopen("a.txt", "r"); // 파일 개방 (a.txt에 "20 홍길동" 같은 내용이 있다고 가정)
    if (fp == NULL) { printf("파일 열기 실패\n"); return 1; }

    fscanf(fp, "%d", &age); // 나이 입력 (버퍼에 '\n'이 남음)
    fgets(name, sizeof(name), fp); // 이름 입력 시도 (버퍼의 '\n'만 읽고 종료될 수 있음)

    printf("나이 : %d, 이름 : %s", age, name); // 입력 결과 출력

    fclose(fp); // 파일 닫음

    return 0;
}
// 이 코드는 의도대로 동작하지 않을 수 있습니다.
// 해결책: fscanf 후 fgetc(fp); 또는 while(fgetc(fp)!='\n'); 등으로 개행 문자 제거
