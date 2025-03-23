#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *pi;
    int size = 5;     // 한 번에 할당할 저장 공간의 크기, int형 변수 5개
    int count = 0;    // 현재 입력된 양수 개수
    int num;
    int i;

    pi = (int *)calloc(size, sizeof(int)); // 일단 5개의 저장 공간 할당. calloc은 0으로 초기화
    if(pi == NULL){
      printf("메모리가 부족합니다!\n");
      exit(1);
    }

    while (1) {  // 무한 루프
        printf("양수를 입력하세요 => ");
        scanf("%d", &num);

        if (num <= 0) break; // 데이터 입력 종료 (0 또는 음수 입력 시)

        if (count == size) {   // 저장 공간을 모두 사용하면
            size += 5;         // 크기를 늘려서 재할당
            pi = (int *)realloc(pi, size * sizeof(int));
            if(pi == NULL){
                printf("메모리가 부족합니다!\n");
                exit(1);
            }
        }
        pi[count++] = num; // 입력받은 양수를 배열에 저장, count 증가
    }

    for (i = 0; i < count; i++) { //저장된 데이터 출력
        printf("%5d", pi[i]);
    }
    printf("\n");

    free(pi);   // 동적 할당 저장 공간 반환
    pi = NULL;
    return 0;
}
