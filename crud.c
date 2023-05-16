#include <stdio.h>
#include <stdlib.h>
#include "crud.h"


void standardChecker(standard *s){
    printf("����� ���ϴ� � �ð���?");
    scanf("%d",&s->exerciseTime);
    printf("����� ���ϴ� �������� �ð���?");
    scanf("%d",&s->majorStudy);
    printf("����� ���ϴ� ���� �� ���� �ð���?");
    scanf("%d",&s->otherStudy);
    printf("����� ���ϴ� ���� �ð���?");
    scanf("%d",&s->sleepTime);
    printf("����� ���ϴ� �Ļ� Ƚ����?");
    scanf("%d",&s->mealCount);
    printf("����� ���ϴ� �����ð���?");
    scanf("%d",&s->readingTime);
    printf("����� ���ϴ� �米�ð���?");
    scanf("%d",&s->friendshipTime);
}
int menu(){
    int select;
    printf("1. ���� ���� ���� ����/����\n");
    printf("2. ���� �󸶳� �ϼ̳���?\n");
    printf("3. ��ü ���������͸� ����!\n");
    printf("4. ���ϴ� ��¥�� ���������͸� ������ ����!\n");
    printf("5. ���ϴ� ��¥�� ������ Ȯ���غ���!\n");
    printf("6. ���ϳ�¥�� ������ ���غ���!\n");
    printf("7. �ְ� ������ ���غ���!\n");    
    printf("8. ����!\n");  
    printf("9. ������!\n");
    printf("0. ������ �������ִ��� Ȯ��!\n");    
    printf("���ϴ� �޴���? =>");
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
        fprintf(fp,"%d %d %d %d %d %d %d %d \n", d[i]->day, d[i]->exerciseTime,d[i]->majorStudy, d[i]->otherStudy,d[i]->sleepTime, d[i]->mealCount,d[i]->readingTime,d[i]->friendshipTime);
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
double calculatorDaily(standard *s, daily *d){
    double evaluate[7];
    int error=0;
    double sum;
    evaluate[0]=d->exerciseTime/s->exerciseTime*100;
    printf("��� ��� %.2f �Ͽ����ϴ�.", evaluate[0]);
    evaluate[1]=d->majorStudy/s->majorStudy*100;
    printf("�ֿ������ ��� %.2f �Ͽ����ϴ�.", evaluate[1]);
    evaluate[2]=d->otherStudy/s->otherStudy*100;
    printf("��������� ��� %.2f �Ͽ����ϴ�.", evaluate[2]);
    evaluate[3]=d->sleepTime/s->sleepTime*100;
    printf("����ð��� ��� %.2f �Ͽ����ϴ�.", evaluate[3]);
    evaluate[4]=d->readingTime/s->readingTime*100;
    printf("�����ð��� ��� %.2f �Ͽ����ϴ�.", evaluate[4]);
    evaluate[5]=d->mealCount/s->mealCount*100;
    printf("�Ļ�Ƚ���� ��� %.2f �Ͽ����ϴ�.", evaluate[5]);
    evaluate[6]=d->friendshipTime/s->friendshipTime*100;
    printf("�米�ð��� ��� %.2f �Ͽ����ϴ�.", evaluate[6]);
    for(int i = 0 ; i < 7 ; i ++){
        if(evaluate[i]<50) error=1;
        break;
        sum+=evaluate[i];
    }
    double average = sum/7;
    if(error==0){
        if(average>=120){
            return 5;
        }
        if(average>=100){
            return 4;
        }
        if(average>=80){
            return 3;
        }
        if(80>average){
            return 2;
        }
    }else{
        return 0;
    }
}


void addDailyData(standard *s, daily *d[], int count) {
    printf("����ڴ��� %d ��°�� �Ҵ��� �ð��� �� �׸񺰷� �Է¹ްڽ��ϴ�\n", count+1);
    printf("*��� �ð��� �� ������ �����ֽʽÿ�*\n");
    printf("-----------------------------------\n\n");
    printf("���� �Ϸ� ��� ������ �ð��� �Է����ּ���: ");
    scanf("%d",&d[count]->exerciseTime);
    printf("���� �Ϸ� ��� �������ο� ������ �ð��� �Է����ּ���: ");
    scanf("%d",&d[count]->majorStudy);
    printf("���� �Ϸ� ���� �� ���ο� ������ �󸶳� �����ϼ̳���? ");
    scanf("%d",&d[count]->otherStudy);
    printf("���� �Ϸ� �󸶳� �ֹ��̳���? ");
    scanf("%d",&d[count]->sleepTime);
    printf("���� �Ϸ� �� ���� ��̳���? ");
    scanf("%d",&d[count]->mealCount);
    printf("���� �Ϸ� å�� �󸶳� �����̳���? ");
    scanf("%d",&d[count]->readingTime);
    printf("���� �Ϸ� ������ �󸶳� �ð��� �����̳���? ");
    scanf("%d",&d[count]->friendshipTime);
    d[count]->godchecker = calculatorDaily(s, d[count]);

}

int deleteDailyData(daily *d[], int count) {
    int choice;
    printf("������ �����Ͻðڽ��ϱ�?(����: 1)");
    scanf("%d", &choice);
    if (choice != 1) return 0;
    //������ ��ü����
    for (int i=count; i>=0; i--) {
        free(d[i]);
    }
    printf("\n�����Ͱ� ��� ���� �Ǿ����ϴ�!\n");
    return 1;
}

void updateDailyData(daily *d[], int count) {
    int updateNum; //��������
    printf("�� ��° �Ϸ縦 �����ϰ� �����Ű���? (���: 0) ");
    scanf("%d", &updateNum);
    //����� ��� -> ������
    if (updateNum== 0) return; 
    //������ ��� ���ڸ� �Է��� ��� -> ������
    else if (updateNum > count || updateNum < 1){
        printf("\n�ش� ���ڰ� �������� �ʽ��ϴ�.\n");
        return;
    }
    else {
        //�����ϱ�
        printf("����ڴ��� %d ��°�� �Ҵ��� �ð��� �� �׸񺰷� �����ϰڽ��ϴ�\n", updateNum);
        printf("*��� �ð��� �� ������ �����ֽʽÿ�*\n");
        printf("-----------------------------------\n\n");
        printf("���� �Ϸ� ��� ������ �ð��� �Է����ּ���: ");
        scanf("%d",&d[updateNum-1]->exerciseTime);
        printf("���� �Ϸ� ��� �������ο� ������ �ð��� �Է����ּ���: ");
        scanf("%d",&d[updateNum-1]->majorStudy);
        printf("���� �Ϸ� ���� �� ���ο� ������ �󸶳� �����ϼ̳���? ");
        scanf("%d",&d[updateNum-1]->otherStudy);
        printf("���� �Ϸ� �󸶳� �ֹ��̳���? ");
        scanf("%d",&d[updateNum-1]->sleepTime);
        printf("���� �Ϸ� �� ���� ��̳���? ");
        scanf("%d",&d[updateNum-1]->mealCount);
        printf("���� �Ϸ� å�� �󸶳� �����̳���? ");
        scanf("%d",&d[updateNum-1]->readingTime);
        printf("���� �Ϸ� ������ �󸶳� �ð��� �����̳���? ");
        scanf("%d",&d[updateNum-1]->friendshipTime);

        printf("\n������ �Ϸ� �Ǿ����ϴ�!\n");
    }
}

void showDailyData(daily *d[], int count) {
    int searchNum; //����ϰ� ���� ����
    printf("�� ��° �Ϸ縦 ���� �����Ű���? (��ü����: 0) ");
    scanf("%d", &searchNum);
    //����� ��� -> ������
    if (searchNum== 0) {
        for(int i=0; i<count; i++) {
            printf("%d ���� ��������: %d\n", i+1, d[i]->godchecker);
            printf("-----------------------------------------\n");
            printf("�   ��������  ��Ÿ����  ����  �Ļ�Ƚ��  ����  �米\n");
            printf("  %d       %d        %d         %d        %d      %d     %d\n", d[i]->exerciseTime, d[i]->majorStudy, d[i]->otherStudy, 
            d[i]->sleepTime, d[i]->mealCount, d[i]->readingTime, d[i]->friendshipTime);
            printf("-----------------------------------------\n\n");
        }
    }
    //������ ��� ���ڸ� �Է��� ��� -> ������
    else if (searchNum > count || searchNum < 1){
        printf("\n�ش� ���ڰ� �������� �ʽ��ϴ�.\n");
    }
    else {
            searchNum = searchNum-1;
            printf("%d ���� ��������: %d\n", searchNum+1, d[searchNum]->godchecker);
            printf("-----------------------------------------\n");
            printf("�   ��������  ��Ÿ����  ����  �Ļ�Ƚ��  ����  �米\n");
            printf("  %d       %d        %d         %d        %d      %d     %d\n", d[searchNum]->exerciseTime, d[searchNum]->majorStudy, d[searchNum]->otherStudy, 
            d[searchNum]->sleepTime, d[searchNum]->mealCount, d[searchNum]->readingTime, d[searchNum]->friendshipTime);
            printf("-----------------------------------------\n\n");
    }

}
