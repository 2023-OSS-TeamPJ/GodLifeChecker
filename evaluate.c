#include <stdio.h>
#include "evaluate.h"
#include "crud.h"


void calculatorDaily(standard *s, daily *d){
    double evaluate[7];
    int error=0;
    double sum;
    evaluate[0]=d->exerciseTime/s->exerciseTime*100;
    evaluate[1]=d->majorStudy/s->majorStudy*100;
    evaluate[2]=d->otherStudy/s->otherStudy*100;
    evaluate[3]=d->sleepTime/s->sleepTime*100;
    evaluate[4]=d->readingTime/s->readingTime*100;
    evaluate[5]=d->mealCount/s->mealCount*100;
    evaluate[6]=d->friendshipTime/s->friendshipTime*100;
    for(int i = 0 ; i < 7 ; i ++){
        if(evaluate[i]<50) error=1;
        sum+=evaluate[i];
    }
    double average = sum/7;

    if(error==0){
        if(average>=120){
            printf("초 갓생이군요!!!");
            d->godChecker=5;
            return;
        }
        if(average>=100){
            printf("갓생이네요!");
            d->godChecker=4;
            return;
        }
        if(average>=80){
            printf("범생이시군요.");
            d->godChecker=3;
            return;
        }
        if(80>average){
            printf("미생입니다.");
            d->godChecker=0;
            return;
        }
    }else{
        printf("미생입니다 (불균형한 삶 입니다.)");
        d->godChecker=0;
        return;
    }
}

void calculatorWeek(daily *d[]){
    double everage;
    int limit;
    if(sizeof(d)/sizeof(daily*)<7)limit = sizeof(d)/sizeof(daily*);
    else limit = 7;

    for(int i = 0 ; i < limit ; i ++){
        everage = everage+d[i]->godchecker;
    }
    everage = everage/limit;
    if(everage>=120){
        printf("이번주는 초 갓생처럼 사셨군요!!!");
        return;
    }
    if(everage>=100){
        printf("이번주는 갓생이네요!");
        return;
    }
    if(everage>=80){
        printf("이번주는 범생을 사셨네요.");
        return;
    }
    if(80>everage){
        printf("이번주는 미생입니다.");
        return;
    }
}

