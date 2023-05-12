#include <stdio.h>
#include "evaluate.h"
#include "crud.h"


void conformDaily(standard *s, daily *d){
    
    int result;
    result = d->godchecker;
    
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
    double everage;
    int limit;
    if(sizeof(d)/sizeof(daily*)<7){
        printf("7이하의 데이터 충분한 데이터가 모이지 않았습니다."); 
        return;
    }
    /*7>몇주차 = 2
    int start = (j-1)*7 
    int w[7];
    for(int i = 0 ; i < 7 ; i++){
        w[i] = d[start+i];
    }*/

    everage = everage/limit;
    if(everage>=4.5){
        printf("이번주는 초 갓생처럼 사셨군요!!!");
        return;
    }
    if(everage>=4){
        printf("이번주는 갓생이네요!");
        return;
    }
    if(everage>=3){
        printf("이번주는 범생을 사셨네요.");
        return;
    }
    else{
        printf("이번주는 미생입니다.");
        return;
    }
}

