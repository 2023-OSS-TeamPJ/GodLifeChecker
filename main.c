#include <stdio.h>
#include "crud.h"
#include "evaluate.h"


/*
    printf("1. 나의 갓생 기준 설정/수정");
    printf("2. 오늘 얼마나 하셨나요?");
    printf("3. 원하는 요일의 갓생데이터를 삭제!");
    printf("4. 원하는 날짜의 갓생데이터를 수정해 보자!");
    printf("5. 원하는 날짜의 갓생을 확인해보자!");
    printf("6. 일일날짜의 ");
    */

int main(void) {
    int menuNum; //사용자가 선택한 메뉴번호
    standard *myStandard;

    while(1) {
        menuNum = menu();
        if (menuNum = 1) {
            //갓생 기준 설정/수정하기
            standardChecker(myStandard);
        }

        else if (menuNum = 2) {
            //일일 데이터 입력
        }
    
        else if (menuNum = 3) {
            //일일 데이터 삭제
        }
        else if (menuNum = 4) {
            //일일 데이터 수정
        }
        else if (menuNum = 5) {
            //일일 데이터 출력
        }
        else if (menuNum = 6) {
            //일별 갓생 평가
        }
        else if (menuNum = 7) {
            //주별 갓생 평가
        }
        else if (menuNum = 8) {
            //데이터 저장
        }
        else if (menuNum = 9) {
            //나가기
        }
        else {
            //잘못된 입력 
            printf("잘못된 메뉴번호입니다\n");
        }

    }
}