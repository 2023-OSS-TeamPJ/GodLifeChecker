#include <stdio.h>
#include "crud.h"
#include "evaluate.h"



int main(void) {
    int menuNum; //사용자가 선택한 메뉴번호
    int count; //입력 되어있는 데이터의 개수

    standard *myStandard = (standard*)malloc(sizeof(standard));
    daily *myDaily[28] = (daily*)malloc(sizeof(daily)*28);

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
            calculatorDaily(myStandard, myDaily);
        }
        else if (menuNum = 7) {
            //주별 갓생 평가
            calculatorWeek(myStandard);
        }
        else if (menuNum = 8) {
            //데이터 저장
            saveData(myStandard, myDaily, count);
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