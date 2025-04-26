#include <stdio.h>

int main(void) {
    FILE *ifp, *ofp;      // 입력, 출력 파일 포인터 선언
    char name[20];        // 이름
    int kor, eng, math;   // 세 과목 점수
    int total;            // 총점
    double avg;           // 평균
    int res;              // fscanf 함수의 반환값 저장

    ifp = fopen("a.txt", "r"); // 입력 파일을 읽기 전용으로 개방
    if (ifp == NULL) {
        printf("입력 파일을 열지 못했습니다.\n");
        return 1;
    }

    ofp = fopen("b.txt", "w"); // 출력 파일을 쓰기 전용으로 개방
    if (ofp == NULL) {
        printf("출력 파일을 열지 못했습니다.\n");
        fclose(ifp);
        return 1;
    }

    while (1) {
        // 입력 파일에서 형식에 맞춰 데이터 읽기
        res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);
        if (res == EOF) { // 파일의 데이터를 모두 읽으면 EOF 반환
            break;
        }
        total = kor + eng + math; // 총점 계산
        avg = total / 3.0;        // 평균 계산
        // 출력 파일에 형식에 맞춰 데이터 쓰기
        fprintf(ofp, "%-10s %5d %7.1lf\n", name, total, avg);
                // %-10s: 왼쪽 정렬 10칸 문자열, %5d: 5칸 정수, %7.1lf: 전체 7칸 소수점 이하 1자리 실수
    }

    fclose(ifp); // 입력 파일 닫기
    fclose(ofp); // 출력 파일 닫기

    return 0;
}
