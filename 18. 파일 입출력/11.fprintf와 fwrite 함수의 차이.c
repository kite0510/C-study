#include <stdio.h>

int main(void) {
    FILE *afp, *bfp; // 텍스트 파일용, 바이너리 파일용 포인터
    int num = 10;
    int res;

    afp = fopen("a.txt", "wt"); // 텍스트 파일로 개방 (쓰기)
    if (afp == NULL) { printf("a.txt 열기 실패\n"); return 1; }
    fprintf(afp, "%d", num);   // num의 값을 "10" 문자열로 변환하여 파일에 씀

    bfp = fopen("b.txt", "wb"); // 바이너리 파일로 개방 (쓰기)
    if (bfp == NULL) { printf("b.txt 열기 실패(wb)\n"); fclose(afp); return 1; }
    fwrite(&num, sizeof(num), 1, bfp); // num 변수의 메모리 내용을 그대로 파일에 씀

    fclose(afp);
    fclose(bfp);

    // 바이너리 파일 내용 확인 (fread 사용)
    bfp = fopen("b.txt", "rb"); // 바이너리 파일로 개방 (읽기)
    if (bfp == NULL) { printf("b.txt 열기 실패(rb)\n"); return 1; }
    fread(&res, sizeof(res), 1, bfp); // 파일에서 데이터를 읽어 res 변수에 저장
    printf("%d", res);                // 읽어온 값 출력 (10이 출력됨)

    fclose(bfp);

    return 0;
}
