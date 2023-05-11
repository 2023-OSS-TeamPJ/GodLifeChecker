#include <stdio.h>
#include "crud.h"

void standardChecker(standard *s){
    printf("당신이 원하는 운동 시간은?");
    scanf("%d",&s->exerciseTime);
    printf("당신이 원하는 전공공부 시간은?");
    scanf("%d",&s->majorStudy);
    printf("당신이 원하는 전공 외 공부 시간은?");
    scanf("%d",&s->otherStudy);
    printf("당신이 원하는 수면 시간은?");
    scanf("%d",&s->sleepTime);
    printf("당신이 원하는 식사 횟수는?");
    scanf("%d",&s->mealCount);
    printf("당신이 원하는 독서시간은?");
    scanf("%d",&s->readingTime);
    printf("당신이 원하는 사교시간은?");
    scanf("%d",&s->friendshipTime);
}
int menu(){
    int select;
    printf("1. 나의 갓생 기준 설정/수정");
    printf("2. 오늘 얼마나 하셨나요?");
    printf("3. 원하는 요일의 갓생데이터를 삭제!");
    printf("4. 원하는 날짜의 갓생데이터를 수정해 보자!");
    printf("5. 원하는 날짜의 갓생을 확인해보자!");
    printf("6. 일일날짜의 ");

    return select;
}
void saveData(standard *s, daily *d[], int count){
    int i = 0 ;
    FILE *fp;
    fp = fopen("standardText.txt", "wt");
    fprintf(fp,"%s %s %s %s %s %s %s \n",s->exerciseTime, s->majorStudy, s->otherStudy,s->sleepTime, s->mealCount,s->readingTime,s->friendshipTime );
    fclose(fp);

    fp = fopen("DailyData.txt", "wt");
    for(; i < count ; i ++){
        if(s[i]== NULL)continue;
        fprintf(fp,"%s %s %s %s %s %s %s %s \n", d[i]->day, d[i]->exerciseTime,d[i]->majorStudy, d[i]->otherStudy,d[i]->sleepTime, d[i]->mealCount,d[i]->readingTime,d[i]->friendshipTime);
    }
    fclose(fp);
    printf("SAVE!!\n");

}

int loadData(standard *s, daily *d[]){
    int i = 0 ;
    FILE *fp;
    fp = fopen("standardText.txt", "rt");
    if(fp==NULL){
        printf("Data is null \n");
        return 0;
    }
    for(; i < 100; i++){
        fscanf(fp,"%d",&s->exerciseTime);
        if(feof(fp))break;
        fscanf(fp,"%d",&s->majorStudy);
        fscanf(fp,"%d",&s->otherStudy);
        fscanf(fp,"%d",&s->sleepTime);
        fscanf(fp,"%d",&s->mealCount);
        fscanf(fp,"%d",&s->readingTime);
        fscanf(fp,"%d",&s->friendshipTime);
    }
    fp = fopen("DailyData.txt", "rt");
    for(; i < 100; i++){
        d[i] = (daily*)malloc(sizeof(daily));
        fscanf(fp,"%d",&d[i]->day);
        if(feof(fp))break;
        fscanf(fp,"%d",&d[i]->exerciseTime);
        fscanf(fp,"%d",&d[i]->majorStudy);
        fscanf(fp,"%d",&d[i]->otherStudy);
        fscanf(fp,"%d",&d[i]->sleepTime);
        fscanf(fp,"%d",&d[i]->mealCount);
        fscanf(fp,"%d",&d[i]->readingTime);
        fscanf(fp,"%d",&d[i]->friendshipTime);
    }
    fclose(fp);
    printf("Loading Complete\n");
    return i;

}

