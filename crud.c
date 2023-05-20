#include <stdio.h>
#include <stdlib.h>
#include "crud.h"


void standardChecker(standard *s){
    getchar();
    printf("\n*��� �ð��� �� ������ �����ֽʽÿ�*\n");
    printf("\n����� ���ϴ� � �ð���? ");
    scanf("%d",&s->exerciseTime);
    printf("����� ���ϴ� �������� �ð���? ");
    scanf("%d",&s->majorStudy);
    printf("����� ���ϴ� ���� �� ���� �ð���? ");
    scanf("%d",&s->otherStudy);
    printf("����� ���ϴ� ���� �ð���? ");
    scanf("%d",&s->sleepTime);
    printf("����� ���ϴ� �Ļ� Ƚ����? ");
    scanf("%d",&s->mealCount);
    printf("����� ���ϴ� �����ð���? ");
    scanf("%d",&s->readingTime);
    printf("����� ���ϴ� �米�ð���? ");
    scanf("%d",&s->friendshipTime);
    printf("\n���� ������ �ԷµǾ����ϴ�!\n");
}
int menu(){
    int select;
    printf("\n===========�޴�============\n");
    printf("1. ���� ���� ���� ����/����\n");
    printf("2. ���� �󸶳� �ϼ̳���?\n");
    printf("3. ��ü ���������͸� ����!\n");
    printf("4. ���ϴ� ��¥�� ���������͸� ������ ����!\n");
    printf("5. ���ϴ� ��¥�� ������ Ȯ���غ���!\n");
    printf("6. ���ϳ�¥�� ������ ���غ���!\n");
    printf("7. �ְ� ������ ���غ���!\n");    
    printf("8. ����!\n");
    printf("0. ������\n");    
    printf("���ϴ� �޴���? => ");
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
    printf("\n����Ǿ����ϴ�!\n");

}

int loadData(standard *s, daily *d[], int *standardExist){
    int i = 0 ;
    FILE *fp;
    fp = fopen("standardText.txt", "rt");
    if(fp==NULL){
        printf("�ҷ��� �����Ͱ� �����ϴ�\n");
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
        *standardExist = 1; //���� ���翩��
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
    printf("�����͸� �ε��Ϸ� �Ͽ����ϴ�!\n");
    return i;

}
int calculatorDaily(standard *s, daily *d){
    int evaluate[7];
    int error=0;

    double sum=0.0;

    evaluate[0]=(d->exerciseTime*100/s->exerciseTime);
    printf("\n� ��ǥ���� %d%% �޼� �Ͽ����ϴ�\n", evaluate[0]);
    evaluate[1]=(d->majorStudy*100/s->majorStudy);
    printf("�������� ��ǥ���� %d%% �޼� �Ͽ����ϴ�\n", evaluate[1]);
    evaluate[2]=(d->otherStudy*100/s->otherStudy);
    printf("���� �� ���� ��ǥ���� %d%% �޼� �Ͽ����ϴ�\n", evaluate[2]);
    evaluate[3]=(d->sleepTime*100/s->sleepTime);
    printf("����ð� ��ǥ���� %d%% �޼� �Ͽ����ϴ�\n", evaluate[3]);
    evaluate[4]=(d->readingTime*100/s->readingTime);
    printf("�����ð� ��ǥ���� %d%% �޼� �Ͽ����ϴ�\n", evaluate[4]);
    evaluate[5]=(d->mealCount*100/s->mealCount);
    printf("�Ļ�Ƚ�� ��ǥ���� %d%% �޼� �Ͽ����ϴ�\n", evaluate[5]);
    evaluate[6]=(d->friendshipTime*100/s->friendshipTime);
    printf("�米�ð� ��ǥ���� %d%% �޼� �Ͽ����ϴ�\n", evaluate[6]);
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
    printf("\n����ڴ��� %d ��°�� �Ҵ��� �ð��� �� �׸񺰷� �Է¹ްڽ��ϴ�\n", count+1);
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
    printf("\n�Է��� �Ϸ�Ǿ����ϴ�!\n");
}

int deleteDailyData(daily *d[], int count) {
    int choice;

    //�����Ͱ� ������
    if (count == 0) {
        printf("\n���� �����ϴ� �����Ͱ� �����ϴ�\n");
        return 0;
    }

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

    //�����Ͱ� ������
    if (count == 0) {
        printf("\n���� �����ϴ� �����Ͱ� �����ϴ�\n");
        return;
    }

    printf("\n�� ��° �Ϸ縦 �����ϰ� �����Ű���? (���: 0) ");
    scanf("%d", &updateNum);
    //����� ��� -> ������
    if (updateNum== 0) return; 
    //������ ��� ���ڸ� �Է��� ��� -> ������
    else if (updateNum > count || updateNum < 1){
        printf("\n�ش� ���ڰ� �������� �ʽ��ϴ�\n");
        return;
    }
    else {
        //�����ϱ�
        printf("\n����ڴ��� %d ��°�� �Ҵ��� �ð��� �� �׸񺰷� �����ϰڽ��ϴ�\n", updateNum);
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

    //�����Ͱ� ������
    if (count == 0) {
        printf("\n���� �����ϴ� �����Ͱ� �����ϴ�\n");
        return;
    }

    printf("\n�� ��° �Ϸ縦 ���� �����Ű���? (��ü����: 0) ");
    scanf("%d", &searchNum);
    //����� ��� -> ������
    if (searchNum== 0) {
        for(int i=0; i<count; i++) {
            printf("\n%d ���� �Ҵ�ð�(��)\n", i+1);
            printf("------------------------------------------------------------\n");
            printf(" �   ��������  ��Ÿ����      ����   �Ļ�Ƚ��  ����   �米\n");
            printf("  %d       %d        %d         %d        %d      %d     %d\n", d[i]->exerciseTime, d[i]->majorStudy, d[i]->otherStudy, 
            d[i]->sleepTime, d[i]->mealCount, d[i]->readingTime, d[i]->friendshipTime);
            printf("------------------------------------------------------------\n");
        }
    }
    //������ ��� ���ڸ� �Է��� ��� -> ������
    else if (searchNum > count || searchNum < 1){
        printf("\n�ش� ���ڰ� �������� �ʽ��ϴ�\n");
    }
    else {
            searchNum = searchNum-1;
            printf("\n%d ���� �Ҵ�ð�(��)\n", searchNum+1);
            printf("------------------------------------------------------------\n");
            printf(" �   ��������  ��Ÿ����      ����   �Ļ�Ƚ��  ����   �米\n");
            printf("  %d       %d        %d         %d        %d      %d     %d\n", d[searchNum]->exerciseTime, d[searchNum]->majorStudy, d[searchNum]->otherStudy, 
            d[searchNum]->sleepTime, d[searchNum]->mealCount, d[searchNum]->readingTime, d[searchNum]->friendshipTime);
            printf("------------------------------------------------------------\n\n");
    }
}
//�� ������ ������Ʈ �Լ�
void refreshEvalutation(standard *s, daily *d[], int count) {
        int evaluate[7];
        int error;
        double average = 0.0;
        double sum = 0.0;
        //��ü ������ ���
        for (int i=0; i<count; i++){
            error = 0; //error �ʱ�ȭ
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
            //godchecker ������Ʈ
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
