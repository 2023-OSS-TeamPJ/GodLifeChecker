#include <stdio.h>
#include "evaluate.h"
#include "crud.h"


void calculatorDaily(standard *s, daily *d){
    double evaluate[7];
    double sum;
    evaluate[0]=d->exerciseTime/s->exerciseTime*100;
    evaluate[1]=d->majorStudy/s->majorStudy*100;
    evaluate[2]=d->otherStudy/s->otherStudy*100;
    evaluate[3]=d->sleepTime/s->sleepTime*100;
    evaluate[4]=d->readingTime/s->readingTime*100;
    evaluate[5]=d->mealCount/s->mealCount*100;
    evaluate[6]=d->friendshipTime/s->friendshipTime*100;
    for(int i = 0 ; i < 7 ; i ++){
        sum+=evaluate[i];
    }
    sum = sum/7;
    d->godchecker=sum;
    if(sum>=120){
        printf("초 갓생이군요!!!");
        return;
    }
    if(sum>=100){
        printf("갓생이네요!");
        return;
    }
    if(sum>=80){
        printf("범생이시군요.");
        return;
    }
    if(80>sum){
        printf("미생입니다.");
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

