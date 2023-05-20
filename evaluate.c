#include <stdio.h>
#include <stdlib.h>
#include "evaluate.h"


void conformDaily(standard *s, daily *d[], int count){
    int  day;
    int evaluate[7];

    //데이터가 없으면
    if (count == 0) {
        printf("\n현재 존재하는 데이터가 없습니다\n");
        return;
    }

    printf("\n몇 번째 하루를 평가하시겠습니까? (취소: 0) ");
    scanf("%d",&day);

    if (day == 0) return; 
    //범위에 벗어난 일자를 입력할 경우 -> 나가기
    else if (day > count || day < 1){
        printf("\n해당 일자가 존재하지 않습니다.\n");
        return;
    }

    evaluate[0]=(d[day-1]->exerciseTime*100/s->exerciseTime);
    evaluate[1]=(d[day-1]->majorStudy*100/s->majorStudy);
    evaluate[2]=(d[day-1]->otherStudy*100/s->otherStudy);
    evaluate[3]=(d[day-1]->sleepTime*100/s->sleepTime);
    evaluate[4]=(d[day-1]->readingTime*100/s->readingTime);
    evaluate[5]=(d[day-1]->mealCount*100/s->mealCount);
    evaluate[6]=(d[day-1]->friendshipTime*100/s->friendshipTime);

    int result;
    result = d[day-1]->godchecker;
    //항목별 퍼센테이지도 나오면 좋을듯: 그리고 마지막에 “종합해본 결과~ 갓생/범생/미생 입니다“
    if(result>=5){
        printf("\n운동은 %d%% \n", evaluate[0]);
        printf("주요과목은 %d%% \n", evaluate[1]);
        printf("서브과목은 %d%% \n", evaluate[2]);
        printf("수면시간은 %d%% \n", evaluate[3]);
        printf("독서시간은 %d%% \n", evaluate[4]);
        printf("식사횟수은 %d%% \n", evaluate[5]);
        printf("사교시간은 %d%% 입니다 이를 총 종합해본 결과.....\n", evaluate[6]);
        printf("******************************************************\n");
        printf("* 갓생이군요!! 그럼 기준을 조금 높여보는건 어떨까요? *\n");
        printf("******************************************************\n");
        return;
    }
    if(result>=4){
        printf("\n운동은 %d%% \n", evaluate[0]);
        printf("주요과목은 %d%% \n", evaluate[1]);
        printf("서브과목은 %d%% \n", evaluate[2]);
        printf("수면시간은 %d%% \n", evaluate[3]);
        printf("독서시간은 %d%% \n", evaluate[4]);
        printf("식사횟수은 %d%% \n", evaluate[5]);
        printf("사교시간은 %d%% 입니다 이를 총 종합해본 결과.....\n", evaluate[6]);
        printf("*************\n");
        printf("* 갓생이시군요 *\n");
        printf("*************\n");
            return;
    }
    if(result>=3){
        printf("\n운동은 %d%% \n", evaluate[0]);
        printf("주요과목은 %d%% \n", evaluate[1]);
        printf("서브과목은 %d%% \n", evaluate[2]);
        printf("수면시간은 %d%% \n", evaluate[3]);
        printf("독서시간은 %d%% \n", evaluate[4]);
        printf("식사횟수은 %d%% \n", evaluate[5]);
        printf("사교시간은 %d%% 입니다 이를 총 종합해본 결과.....\n", evaluate[6]);
        printf("****************\n");
        printf("* 범생이시군요. *\n");
        printf("****************\n");
            return;
    }
    if(3>result && result > 0){
        printf("\n운동은 %d%% \n", evaluate[0]);
        printf("주요과목은 %d%% \n", evaluate[1]);
        printf("서브과목은 %d%% \n", evaluate[2]);
        printf("수면시간은 %d%% \n", evaluate[3]);
        printf("독서시간은 %d%% \n", evaluate[4]);
        printf("식사횟수은 %d%% \n", evaluate[5]);
        printf("사교시간은 %d%% 입니다 이를 총 종합해본 결과.....\n", evaluate[6]);
        printf("*********************************************************\n");
        printf("* 아쉽게도 미생입니다. 기준을 조금 낮춰 보는건 어떨까요? *\n");
        printf("*********************************************************\n");
        return;
    }
    else{
        printf("\n운동은 %d%% \n", evaluate[0]);
        printf("주요과목은 %d%% \n", evaluate[1]);
        printf("서브과목은 %d%% \n", evaluate[2]);
        printf("수면시간은 %d%% \n", evaluate[3]);
        printf("독서시간은 %d%% \n", evaluate[4]);
        printf("식사횟수은 %d%% \n", evaluate[5]);
        printf("사교시간은 %d%% 입니다 이를 총 종합해본 결과.....\n", evaluate[6]);
        printf("*********************************************************\n");
        printf("* 아쉽게도 미생입니다. 기준을 조금 낮춰 보는건 어떨까요? (불균형한 삶 입니다)\n");
        printf("*********************************************************\n");
        return;
    }
}

void calculatorWeek(daily *d[], int count){
    int week;
    if(count<7){
        printf("\n일주일치의 데이터가 충분히 모이지 않았습니다\n"); 
        return;
            
    }
    
    printf("\n몇주차의 갓생을 알고싶으신가요? ");
    scanf("%d",&week);

    int start = (week-1)*7 ;
    if(start+6>count){
        printf("\n해당 주차의 데이터가 부족합니다\n");
        return;
    }
    double result;
    for(int i = 0 ; i < 7 ; i++){
        result += d[start+i]->godchecker;
    }

    result = result/7;
    if(result>=4.5){
        printf("\n************************************************************\n");
        printf("* %d 주차는 갓생이군요!! 그럼 기준을 조금 높여보는건 어떨까요? *\n", week);
        printf("************************************************************\n");
        return;
    }
    if(result>=4){
        printf("\n***********************\n");
        printf("* %d 주차는 갓생이네요! *\n", week);
        printf("***********************\n");
        return;
    }
    if(result>=3){
        printf("\n***************************\n");
        printf("* %d 주차는 범생을 사셨네요. *\n", week);
        printf("***************************\n");
        return;
    }
    else{
        printf("* %d 주차는 아쉽게도 미생입니다. 기준을 조금 낮춰 보는건 어떨까요?\n", week);
        return;
    }
}

