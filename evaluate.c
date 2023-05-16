#include <stdio.h>
#include <stdlib.h>
#include "evaluate.h"


void conformDaily(standard *s, daily *d[]){
    int  day;
    printf("원하는 날짜는?");
    scanf("%d",&day);

    int result;
    result = d[day-1]->godchecker;
    
    if(result>=5){
        printf("초 갓생이군요!!!");
        return;
    }
    if(result>=4){
            printf("갓생이네요!");
            return;
    }
    if(result>=3){
            printf("범생이시군요.");
            return;
    }
    if(3>result){
            printf("미생입니다.");
        return;
    }
    else{
        printf("미생입니다 (불균형한 삶 입니다.)");
        return;
    }
}

void calculatorWeek(daily *d[]){
    int week;
    if(sizeof(*d)/sizeof(daily*)<7){
        printf("7이하의 데이터 충분한 데이터가 모이지 않았습니다."); 
        return;
    }
    printf("몇주차의 갓생을 알고싶으신가요?");
    scanf("%d",&week);
    int start = (week-1)*7 ;
    double result;
    for(int i = 0 ; i < 7 ; i++){
        result += d[start+i]->godchecker;
        if(d[start+i]==NULL){
            printf("이번 주차의 데이터가 부족합니다.");
            return;
        }
    }

    result = result/7;
    if(result>=4.5){
        printf("이번주는 초 갓생처럼 사셨군요!!!");
        return;
    }
    if(result>=4){
        printf("이번주는 갓생이네요!");
        return;
    }
    if(result>=3){
        printf("이번주는 범생을 사셨네요.");
        return;
    }
    else{
        printf("이번주는 미생입니다.");
        return;
    }
}

