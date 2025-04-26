#include <stdio.h>
#include <string.h> // strcmp 함수 사용을 위해 포함

int main(void) {
    FILE *fp;
    char str[20];

    // a+ 모드는 읽기/쓰기가 모두 가능하고, 파일이 없으면 생성하며, 쓰기는 항상 파일 끝에 추가됨
    fp = fopen("a.txt", "a+");
    if (fp == NULL) {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    while (1) {
        printf("과일 이름 : ");
        scanf("%s", str); // 키보드로 과일 이름 입력

        if (strcmp(str, "end") == 0) { // end 입력 시 종료
            break;
        } else if (strcmp(str, "list") == 0) { // list 입력하면 파일의 내용 출력
            fseek(fp, 0, SEEK_SET); // 버퍼의 위치 지시자를 맨 처음으로 이동 (읽기 준비)
            // 또는 rewind(fp);
            printf("*** 과일 목록 ***\n");
            while (1) {
                // 파일에서 한 줄씩 읽음 (개행 문자 포함될 수 있음)
                if (fgets(str, sizeof(str), fp) == NULL) {
                    if (feof(fp)) { // 파일 끝에 도달했으면
                        break;      // 안쪽 while 루프 종료
                    } else {
                        printf("파일 읽기 오류\n");
                        break;
                    }
                }
                printf("%s", str); // 읽은 과일 이름 화면 출력
            }
             // list 출력이 끝난 후, 다시 파일 끝으로 이동할 필요는 없음 (a+ 모드는 쓰기가 항상 끝에 추가됨)
             // 하지만 명시적으로 이동하려면 fseek(fp, 0, SEEK_END);
        } else {
            // 입력한 과일 이름을 파일에 출력 (항상 파일 끝에 추가됨)
            fprintf(fp, "%s\n", str);
        }
    }

    fclose(fp); // 파일 닫음

    return 0;
}
