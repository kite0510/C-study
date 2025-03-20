#include <stdio.h>

// 함수 선언 (필요한 경우)
void swap_ptr(char **ppa, char **ppb);
void print_str(char **pps, int cnt);
void print_ary(int (*pa)[4]);


int main(void) {
    // 예제 15-1.c (포인터와 이중 포인터의 관계)
    // -------------------------------------------------------
    int a = 10;
    int *pi;      // 포인터 선언
    int **ppi;    // 이중 포인터 선언

    pi = &a;      // int형 변수의 주소를 저장한 포인터
    ppi = π    // 포인터의 주소를 저장한 이중 포인터

    // 주소값 출력을 위해 unsigned int로 형변환, 가독성을 위해 변수들 따로 선언.
    unsigned int a_val = a;
    unsigned int a_addr = (unsigned int)&a;
    unsigned int pi_val = (unsigned int)pi;
    unsigned int pi_addr = (unsigned int)π
    unsigned int ppi_val = (unsigned int)ppi;
    unsigned int ppi_addr = (unsigned int)&ppi;
    int deref_pi = *pi;         // pi가 가리키는 값
    int deref_deref_ppi = **ppi; // ppi가 가리키는 포인터가 가리키는 값


    printf("      변수        변숫값        &연산        *연산       **연산\n");
    printf("---------------------------------------------------------\n");
    printf("   a  %12u  %12u  %12s  %12s\n", a_val, a_addr, "-", "-"); // a는 이중포인터와 관련X
    printf("  pi  %12u  %12u  %12d  %12s\n", pi_val, pi_addr, deref_pi, "-");
    printf(" ppi  %12u  %12u  %12u  %12d\n", ppi_val, ppi_addr,(unsigned int)*ppi, deref_deref_ppi);
    printf("---------------------------------------------------------\n");



    // 예제 15-2.c (이중 포인터를 사용한 포인터 교환)
    // -------------------------------------------------------
    char *pa = "success";
    char *pb = "failure";

    printf("pa -> %s, pb -> %s\n", pa, pb); // 바꾸기 전
    swap_ptr(&pa, &pb);                    // pa와 pb의 주소를 swap_ptr 함수에 전달
    printf("pa -> %s, pb -> %s\n", pa, pb); // 바꾼 후

    // 예제 15-3.c (포인터 배열의 값을 출력하는 함수)
    //---------------------------------------------------------
    char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrel"}; //초기화
    int count; //배열 요소 수를 저장할 변수

    count = sizeof(ptr_ary) / sizeof(ptr_ary[0]); //배열 요소의 수 계산
    print_str(ptr_ary, count); //배열명과 배열 요소 수를 주고 호출

    // 예제 15-4.c 주소로 쓰이는 배열명과 배열의 주소 비교
    //--------------------------------------------------------
    int ary4[5];

	printf("ary의 값 : %u\t", (unsigned int)ary);		// 주소로서의 배열명의 값
	printf("ary의 주소 : %u\n", (unsigned int)&ary);		// 배열의 주소
	printf("ary + 1 : %u\t", (unsigned int)(ary + 1));	// ary + 1
	printf("&ary + 1 : %u\n", (unsigned int)(&ary + 1));  // &ary + 1

    // 예제 15-5.c 배열 포인터로 2차원 배열의 값 출력
    //--------------------------------------------------------
    int ary5[3][4] = {{1,2,3,4}, {5,6,7,8,}, {9,10,11,12}};
    int (*pa5)[4]; //int형 변수 4개의 배열을 가리키는 포인터
    int x,y;
    pa5 = ary5;
    for(x = 0; x<3; x++){
        for(y = 0; y < 4; y++){
            printf("%5d", pa5[x][y]); // pa5를 2차원 배열처럼 사용
        }
        printf("\n");
    }


    // 예제 15-6.c 2차원 배열의 값을 출력하는 함수
    //-------------------------------------------
    int ary6[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
    print_ary(ary6); //배열명을 인수로 주고 함수 호출

    return 0;
}

// 예제 15-2.c (함수 정의)
void swap_ptr(char **ppa, char **ppb) {
    char *pt;

    pt = *ppa;
    *ppa = *ppb;
    *ppb = pt;
}

//예제 15-3.c (함수 정의)
void print_str(char **pps, int cnt){ //매개변수로 이중 포인터 사용
    int i;
    for(i = 0; i<cnt; i++){ //배열 요소 수만큼 반복
        printf("%s\n", pps[i]); //이중 포인터를 배열명 처럼 사용
    }
}

//예제 15-6.c (함수 정의)
void print_ary(int (*pa)[4]){ //매개변수는 배열 포인터
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j<4; j++){
            printf("%5d", pa[i][j]); //pa를 2차원 배열처럼 사용
        }
        printf("\n");
    }
}
