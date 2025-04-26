// point.h  (Point 구조체 선언, Include Guard 사용)

#ifndef _POINT_H_     // _POINT_H_ 매크로가 정의되지 않았다면
#define _POINT_H_     // _POINT_H_ 매크로를 정의한다

typedef struct {    // Point 구조체 선언
    int x;          // x좌표
    int y;          // y좌표
} Point;

#endif // _POINT_H_ // #ifndef의 끝

// line.h  (Line 구조체 선언, point.h 포함)

#ifndef _LINE_H_      // _LINE_H_ 매크로가 정의되지 않았다면
#define _LINE_H_      // _LINE_H_ 매크로를 정의한다

#include "point.h"    // Point 구조체를 사용하기 위해 point.h 포함

typedef struct {    // Line 구조체 선언
    Point first;    // 첫 번째 점
    Point second;   // 두 번째 점
} Line;

#endif // _LINE_H_ // #ifndef의 끝

// main.c (Point와 Line 구조체 모두 사용)
#include <stdio.h>
#include "point.h"    // Point 구조체 선언 포함
#include "line.h"     // Line 구조체 선언 포함 (내부적으로 point.h도 포함 시도)

int main(void) {
    Line a = {{1, 2}, {5, 6}}; // Line 구조체 변수 선언 및 초기화
    Point b;                   // Point 구조체 변수 선언

    // 선의 가운데 점 좌표 계산
    b.x = (a.first.x + a.second.x) / 2;
    b.y = (a.first.y + a.second.y) / 2;

    printf("선의 가운데 점의 좌표 : (%d, %d)\n", b.x, b.y);

    return 0;
}
// Include Guard 덕분에 point.h 내용이 중복 포함되지 않아 오류 없이 컴파일됨
