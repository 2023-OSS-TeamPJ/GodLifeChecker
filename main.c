#include <stdio.h>
#include <stdlib.h>
//#include "crud.h"
#include "evaluate.h"



int main(void) {
    int menuNum; //사용자가 선택한 메뉴번호
    int count = 0; //입력 되어있는 데이터의 개수
    int result; //함수별 결과값
    int standardExist = 0; //기준 데이터 존재 여부
    //갓생기준 저장공간 메모리 할당 & 일일데이터 저장공간 선언
    standard *myStandard = (standard*)malloc(sizeof(standard));
    daily *myDaily[28];

    //파일로드
    count = loadData(myStandard, myDaily);
    //저장된 데이터가 존재할 경우, 기준 데이터 존재도 확인
    if (count > 0) standardExist = 1;


    while(1) {

        menuNum = menu();
        printf("%f", sizeof(*myDaily));
        if (menuNum == 1) {
            //갓생 기준 설정/수정하기
            standardChecker(myStandard);
            standardExist = 1;
        }
        else if (menuNum == 2 && standardExist != 0) {
            //일일 데이터 입력
            myDaily[count] = (daily*)malloc(sizeof(daily)); //일일데이터 저장공간 메모리 할당
            addDailyData(myStandard, myDaily, count);
            count ++;
        }
    
        else if (menuNum == 3 && standardExist != 0) {
            //전체 일일 데이터 삭제
            result = deleteDailyData(myDaily, count);
            if (result ==  1) count = 0; //삭제되었다면 count를 0으로 변환
        }
        else if (menuNum == 4 && standardExist != 0) {
            //일일 데이터 수정
            updateDailyData(myDaily, count);
        }
        else if (menuNum == 5 && standardExist != 0) {
            //일일 데이터 출력
            showDailyData(myDaily, count);
        }
        else if (menuNum == 6 && standardExist != 0) {
            //일별 갓생 평가
            conformDaily(myStandard, myDaily);
        }
        else if (menuNum == 7 && standardExist != 0) {
            //주별 갓생 평가
            calculatorWeek(myDaily, count);
        }
        else if (menuNum == 8) {
            //데이터 저장
            saveData(myStandard, myDaily, count);
        }
        else if (menuNum == 0) {
            //나가기
            break;
        }
        else if (standardExist == 0) { 
            //기준 데이터가 없을 경우
            printf("기준을 먼저 입력해주세요\n");
        }
        else {
            //잘못된 입력을 받았을 경우
            printf("\n잘못된 메뉴번호입니다\n");
        }
    }
}
