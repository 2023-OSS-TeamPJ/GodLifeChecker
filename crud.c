#include <stdio.h>
#include <stdlib.h>
#include "crud.h"


void standardChecker(standard *s){
    getchar();
    printf("\n*모든 시간은 분 단위로 적어주십시오*\n");
    printf("\n당신이 원하는 운동 시간은? ");
    scanf("%d",&s->exerciseTime);
    printf("당신이 원하는 전공공부 시간은? ");
    scanf("%d",&s->majorStudy);
    printf("당신이 원하는 전공 외 공부 시간은? ");
    scanf("%d",&s->otherStudy);
    printf("당신이 원하는 수면 시간은? ");
    scanf("%d",&s->sleepTime);
    printf("당신이 원하는 식사 횟수는? ");
    scanf("%d",&s->mealCount);
    printf("당신이 원하는 독서시간은? ");
    scanf("%d",&s->readingTime);
    printf("당신이 원하는 사교시간은? ");
    scanf("%d",&s->friendshipTime);
    printf("\n갓생 기준이 입력되었습니다!\n");
}
int menu(){
    int select;
    printf("\n===========메뉴============\n");
    printf("1. 나의 갓생 기준 설정/수정\n");
    printf("2. 오늘 얼마나 하셨나요?\n");
    printf("3. 전체 갓생데이터를 삭제!\n");
    printf("4. 원하는 날짜의 갓생데이터를 수정해 보자!\n");
    printf("5. 원하는 날짜의 갓생을 확인해보자!\n");
    printf("6. 일일날짜의 갓생을 평가해보자!\n");
    printf("7. 주간 갓생을 평가해보자!\n");    
    printf("8. 저장!\n");
    printf("0. 나가기\n");    
    printf("원하는 메뉴는? => ");
    scanf("%d",&select);
    return select;
}

void saveData(standard *s, daily *d[], int count){
    int i = 0 ;
    FILE *fp;
    fp = fopen("standardText.txt", "wt");
    fprintf(fp,"%d %d %d %d %d %d %d \n",s->exerciseTime, s->majorStudy, s->otherStudy,s->sleepTime, s->mealCount,s->readingTime,s->friendshipTime );
    fclose(fp);

    fp = fopen("DailyData.txt", "wt");
    for(; i < count ; i ++){
        if(d[i]== NULL)continue;
        fprintf(fp," %d %d %d %d %d %d %d %d\n", d[i]->exerciseTime,d[i]->majorStudy, d[i]->otherStudy,d[i]->sleepTime, d[i]->mealCount,d[i]->readingTime,d[i]->friendshipTime, d[i]->godchecker);
    }
    fclose(fp);
    printf("\n저장되었습니다!\n");

}

int loadData(standard *s, daily *d[], int *standardExist){
    int i = 0 ;
    FILE *fp;
    fp = fopen("standardText.txt", "rt");
    if(fp==NULL){
        printf("불러올 데이터가 없습니다\n");
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
        *standardExist = 1; //기준 존재여부
    }
    fclose(fp);
    fp = fopen("DailyData.txt", "rt");
    i = 0 ;
    for(; i < 100; i++){
        d[i] = (daily*)malloc(sizeof(daily));
        fscanf(fp,"%d",&d[i]->exerciseTime);
        if(feof(fp))break;
        fscanf(fp,"%d",&d[i]->majorStudy);
        fscanf(fp,"%d",&d[i]->otherStudy);
        fscanf(fp,"%d",&d[i]->sleepTime);
        fscanf(fp,"%d",&d[i]->mealCount);
        fscanf(fp,"%d",&d[i]->readingTime);
        fscanf(fp,"%d",&d[i]->friendshipTime);
        fscanf(fp,"%d",&d[i]->godchecker);
    }
    fclose(fp);
    printf("데이터를 로딩완료 하였습니다!\n");
    return i;

}
int calculatorDaily(standard *s, daily *d){
    int evaluate[7];
    int error=0;

    double sum=0.0;

    evaluate[0]=(d->exerciseTime*100/s->exerciseTime);
    printf("\n운동 목표량은 %d%% 달성 하였습니다\n", evaluate[0]);
    evaluate[1]=(d->majorStudy*100/s->majorStudy);
    printf("전공공부 목표량은 %d%% 달성 하였습니다\n", evaluate[1]);
    evaluate[2]=(d->otherStudy*100/s->otherStudy);
    printf("전공 외 공부 목표량은 %d%% 달성 하였습니다\n", evaluate[2]);
    evaluate[3]=(d->sleepTime*100/s->sleepTime);
    printf("수면시간 목표량은 %d%% 달성 하였습니다\n", evaluate[3]);
    evaluate[4]=(d->readingTime*100/s->readingTime);
    printf("독서시간 목표량은 %d%% 달성 하였습니다\n", evaluate[4]);
    evaluate[5]=(d->mealCount*100/s->mealCount);
    printf("식사횟수 목표량은 %d%% 달성 하였습니다\n", evaluate[5]);
    evaluate[6]=(d->friendshipTime*100/s->friendshipTime);
    printf("사교시간 목표량은 %d%% 달성 하였습니다\n", evaluate[6]);
    for(int i = 0 ; i < 7 ; i ++){
        if(evaluate[i]<50) {
            error=1;
            break;
        }
        sum+=evaluate[i];
    }
    
    double average = sum/7;
    if(error==0){
        if(average>=120){
            return 5;
        }
        else if((average<120)&&(average>=100)){
            return 4;
        }
        else if((average<100)&&(average>=80)){
            return 3;
        }
        else{
            return 2;
        }
    }else{
        return 0;
    }
}

void addDailyData(standard *s, daily *d[], int count) {
    printf("\n사용자님이 %d 일째에 할당한 시간을 각 항목별로 입력받겠습니다\n", count+1);
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
    d[count]->godchecker = calculatorDaily(s, d[count]);
    printf("\n입력이 완료되었습니다!\n");
}

int deleteDailyData(daily *d[], int count) {
    int choice;

    //데이터가 없으면
    if (count == 0) {
        printf("\n현재 존재하는 데이터가 없습니다\n");
        return 0;
    }

    printf("정말로 삭제하시겠습니까?(삭제: 1)");
    scanf("%d", &choice);
    if (choice != 1) return 0;
    //데이터 전체삭제
    for (int i=count; i>=0; i--) {
        free(d[i]);
    }
    printf("\n데이터가 모두 삭제 되었습니다!\n");
    return 1;
}

void updateDailyData(daily *d[], int count) {
    int updateNum; //수정일자

    //데이터가 없으면
    if (count == 0) {
        printf("\n현재 존재하는 데이터가 없습니다\n");
        return;
    }

    printf("\n몇 번째 하루를 수정하고 싶으신가요? (취소: 0) ");
    scanf("%d", &updateNum);
    //취소할 경우 -> 나가기
    if (updateNum== 0) return; 
    //범위에 벗어난 일자를 입력할 경우 -> 나가기
    else if (updateNum > count || updateNum < 1){
        printf("\n해당 일자가 존재하지 않습니다\n");
        return;
    }
    else {
        //수정하기
        printf("\n사용자님이 %d 일째에 할당한 시간을 각 항목별로 수정하겠습니다\n", updateNum);
        printf("*모든 시간은 분 단위로 적어주십시오*\n");
        printf("-----------------------------------\n\n");
        printf("오늘 하루 운동에 투자한 시간을 입력해주세요: ");
        scanf("%d",&d[updateNum-1]->exerciseTime);
        printf("오늘 하루 운동에 전공공부에 투자한 시간을 입력해주세요: ");
        scanf("%d",&d[updateNum-1]->majorStudy);
        printf("오늘 하루 전공 외 공부에 투자한 얼마나 투자하셨나요? ");
        scanf("%d",&d[updateNum-1]->otherStudy);
        printf("오늘 하루 얼마나 주무셨나요? ");
        scanf("%d",&d[updateNum-1]->sleepTime);
        printf("오늘 하루 몇 끼를 드셨나요? ");
        scanf("%d",&d[updateNum-1]->mealCount);
        printf("오늘 하루 책을 얼마나 읽으셨나요? ");
        scanf("%d",&d[updateNum-1]->readingTime);
        printf("오늘 하루 사람들과 얼마나 시간을 보내셨나요? ");
        scanf("%d",&d[updateNum-1]->friendshipTime);

        printf("\n수정이 완료 되었습니다!\n");
    }
}

void showDailyData(daily *d[], int count) {
    int searchNum; //출력하고 싶은 일자

    //데이터가 없으면
    if (count == 0) {
        printf("\n현재 존재하는 데이터가 없습니다\n");
        return;
    }

    printf("\n몇 번째 하루를 보고 싶으신가요? (전체보기: 0) ");
    scanf("%d", &searchNum);
    //취소할 경우 -> 나가기
    if (searchNum== 0) {
        for(int i=0; i<count; i++) {
            printf("\n%d 일차 할당시간(분)\n", i+1);
            printf("------------------------------------------------------------\n");
            printf(" 운동   전공공부  기타공부      수면   식사횟수  독서   사교\n");
            printf("  %d       %d        %d         %d        %d      %d     %d\n", d[i]->exerciseTime, d[i]->majorStudy, d[i]->otherStudy, 
            d[i]->sleepTime, d[i]->mealCount, d[i]->readingTime, d[i]->friendshipTime);
            printf("------------------------------------------------------------\n");
        }
    }
    //범위에 벗어난 일자를 입력할 경우 -> 나가기
    else if (searchNum > count || searchNum < 1){
        printf("\n해당 일자가 존재하지 않습니다\n");
    }
    else {
            searchNum = searchNum-1;
            printf("\n%d 일차 할당시간(분)\n", searchNum+1);
            printf("------------------------------------------------------------\n");
            printf(" 운동   전공공부  기타공부      수면   식사횟수  독서   사교\n");
            printf("  %d       %d        %d         %d        %d      %d     %d\n", d[searchNum]->exerciseTime, d[searchNum]->majorStudy, d[searchNum]->otherStudy, 
            d[searchNum]->sleepTime, d[searchNum]->mealCount, d[searchNum]->readingTime, d[searchNum]->friendshipTime);
            printf("------------------------------------------------------------\n\n");
    }
}
//평가 데이터 업데이트 함수
void refreshEvalutation(standard *s, daily *d[], int count) {
        int evaluate[7];
        int error;
        double average = 0.0;
        double sum = 0.0;
        //전체 데이터 계산
        for (int i=0; i<count; i++){
            error = 0; //error 초기화
            evaluate[0]=(d[i]->exerciseTime*100/s->exerciseTime);
            evaluate[1]=(d[i]->majorStudy*100/s->majorStudy);
            evaluate[2]=(d[i]->otherStudy*100/s->otherStudy);
            evaluate[3]=(d[i]->sleepTime*100/s->sleepTime);
            evaluate[4]=(d[i]->readingTime*100/s->readingTime);
            evaluate[5]=(d[i]->mealCount*100/s->mealCount);
            evaluate[6]=(d[i]->friendshipTime*100/s->friendshipTime);

            for(int i = 0 ; i < 7 ; i ++){
                if(evaluate[i]<50) {
                    error=1;
                    break;
                }
                sum+=evaluate[i];
            }

            
            average = sum/7;
            //godchecker 업데이트
            if(error==0){
                if(average>=120){
                    d[i]->godchecker = 5;
                }
                else if((average<120)&&(average>=100)){
                    d[i]->godchecker = 4;
                }
                else if((average<100)&&(average>=80)){
                    d[i]->godchecker = 3;
                }
                else {
                    d[i]->godchecker = 2;
                }
            }
            else{
                d[i]->godchecker = 0;
            }
        } 
        
}
