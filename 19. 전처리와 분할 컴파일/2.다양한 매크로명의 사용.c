#include <stdio.h>

#define PI 3.14159          // 상수를 매크로명으로 정의
#define LIMIT 100.0         // 상수를 매크로명으로 정의
#define MSG "passed!"       // 문자열을 매크로명으로 정의
#define ERR_PRN printf("허용 범위를 벗어났습니다!\n") // 문장을 매크로명으로 정의

int main(void) {
    double radius, area; // 반지름과 면적 변수

    printf("반지름을 입력하세요(10 이하) : ");
    scanf("%lf", &radius); // 반지름 입력

    area = PI * radius * radius; // 면적 계산 (매크로 상수 PI 사용)

    if (area > LIMIT) ERR_PRN; // 면적이 100을 넘으면 에러 메시지 출력 (매크로 문장 ERR_PRN 사용)
    else printf("원의 면적 : %.2lf (%s)\n", area, MSG); // 면적과 통과 메시지 출력 (매크로 문자열 MSG 사용)

    return 0;
}
