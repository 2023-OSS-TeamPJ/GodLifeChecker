#include <stdio.h>
#include <stdlib.h>
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
    printf("1. 나의 갓생 기준 설정/수정\n");
    printf("2. 오늘 얼마나 하셨나요?\n");
    printf("3. 원하는 요일의 갓생데이터를 삭제!\n");
    printf("4. 원하는 날짜의 갓생데이터를 수정해 보자!\n");
    printf("5. 원하는 날짜의 갓생을 확인해보자!\n");
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

void addDailyData(standard *s, daily *d[], int count) {
    printf("사용자님이 %d 일째에 할당한 시간을 각 항목별로 입력받겠습니다\n", count+1);
    printf("*모든 시간은 분 단위로 적어주십시오*\n");
    printf("-----------------------------------\n\n");
    printf("오늘 하루 운동에 투자한 시간을 입력해주세요: ");
    scanf("%d",&d[count]->exerciseTime);
    printf("오늘 하루 운동에 전공공부에 투자한 시간을 입력해주세요: ");
    scanf("%d",&d[count]->majorStudy);
    printf("오늘 하루 전공 외 공부에 투자한 얼마나 투자하셨나요? ");
    scanf("%d",&d[count]->otherStudy);
    printf("오늘 하루 얼마나 주무셨나요? ");
    scanf("%d",&d[count]->sleepTime);
    printf("오늘 하루 몇 끼를 드셨나요? ");
    scanf("%d",&d[count]->mealCount);
    printf("오늘 하루 책을 얼마나 읽으셨나요? ");
    scanf("%d",&d[count]->readingTime);
    printf("오늘 하루 사람들과 얼마나 시간을 보내셨나요? ");
    scanf("%d",&d[count]->friendshipTime);
}

int deleteDailyData(daily *d[], int count) {
    int choice;
    printf("정말로 삭제하시겠습니까?(삭제 :1)");
    scanf("%d", &choice);
    if (choice != 1) return 0;
    //데이터 전체삭제
    for (int i=count; i>=0; i--) {
        free(d[i]);
    }
    return 1;
}
