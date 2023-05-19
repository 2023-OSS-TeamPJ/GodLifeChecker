#include <stdio.h>
#include <stdlib.h>
#include "evaluate.h"


void conformDaily(standard *s, daily *d[]){
    int  day;
    int evaluate[7];
    printf("���ϴ� ��¥��?");
    scanf("%d",&day);

    evaluate[0]=(d[day-1]->exerciseTime*100/s->exerciseTime);
    evaluate[1]=(d[day-1]->majorStudy*100/s->majorStudy);
    evaluate[2]=(d[day-1]->otherStudy*100/s->otherStudy);
    evaluate[3]=(d[day-1]->sleepTime*100/s->sleepTime);
    evaluate[4]=(d[day-1]->readingTime*100/s->readingTime);
    evaluate[5]=(d[day-1]->mealCount*100/s->mealCount);
    evaluate[6]=(d[day-1]->friendshipTime*100/s->friendshipTime);
    /**
     * 
    */

    int result;
    result = d[day-1]->godchecker;
    //�׸� �ۼ��������� ������ ������: �׸��� �������� �������غ� ���~ ����/����/�̻� �Դϴ١�
    if(result>=5){
        printf("\n��� %d%% \n", evaluate[0]);
        printf("�ֿ������ %d%% \n", evaluate[1]);
        printf("��������� %d%% \n", evaluate[2]);
        printf("����ð��� %d%% \n", evaluate[3]);
        printf("�����ð��� %d%% \n", evaluate[4]);
        printf("�Ļ�Ƚ���� %d%% \n", evaluate[5]);
        printf("�米�ð��� %d%% �Դϴ� �̸� �� �����غ� ���.....\n", evaluate[6]);
        printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
        printf("�� �����̱���!! �׷� ������ ���� �������°� ����? ��\n");
        printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
        return;
    }
    if(result>=4){
        printf("\n��� %d%% ,", evaluate[0]);
        printf("�ֿ������ %d%% ,", evaluate[1]);
        printf("��������� %d%% ,", evaluate[2]);
        printf("����ð��� %d%% ,", evaluate[3]);
        printf("�����ð��� %d%% ,", evaluate[4]);
        printf("�Ļ�Ƚ���� %d%% ,", evaluate[5]);
        printf("�米�ð��� %d%% �Դϴ� �̸� �� �����غ� ���.....", evaluate[6]);
        printf("�ڡڡڡڡڡڡڡ�\n");
        printf("�� �����̱��� ��\n");
        printf("�ڡڡڡڡڡڡڡ�\n");
            return;
    }
    if(result>=3){
        printf("\n��� %d%% ,", evaluate[0]);
        printf("�ֿ������ %d%% ,", evaluate[1]);
        printf("��������� %d%% ,", evaluate[2]);
        printf("����ð��� %d%% ,", evaluate[3]);
        printf("�����ð��� %d%% ,", evaluate[4]);
        printf("�Ļ�Ƚ���� %d%% ,", evaluate[5]);
        printf("�米�ð��� %d%% �Դϴ� �̸� �� �����غ� ���.....", evaluate[6]);
        printf("�ڡڡڡڡڡڡڡڡ�\n");
        printf("�� �����̽ñ���.��\n");
        printf("�ڡڡڡڡڡڡڡڡ�\n");
            return;
    }
    if(3>result){
        printf("\n��� %d%% ,", evaluate[0]);
        printf("�ֿ������ %d%% ,", evaluate[1]);
        printf("��������� %d%% ,", evaluate[2]);
        printf("����ð��� %d%% ,", evaluate[3]);
        printf("�����ð��� %d%% ,", evaluate[4]);
        printf("�Ļ�Ƚ���� %d%% ,", evaluate[5]);
        printf("�米�ð��� %d%% �Դϴ� �̸� �� �����غ� ���.....", evaluate[6]);
        printf("�ڡڡڡڡڡڡڡ�\n");
        printf("�� �̻��Դϴ�.��\n");
        printf("�ڡڡڡڡڡڡڡ�\n");
        return;
    }
    else{
        printf("�̻��Դϴ� (�ұ����� �� �Դϴ�.)");
        return;
    }
}

void calculatorWeek(daily *d[], int count){
    int week;
    //if(sizeof(*d)/sizeof(daily)<7){
      
            if(count<7){
        printf("\n7������ ������ ����� �����Ͱ� ������ �ʾҽ��ϴ�.\n"); 
        return;
            
    }
    printf("\n�������� ������ �˰�����Ű���?");
    scanf("%d",&week);
    int start = (week-1)*7 ;
    if(start+6>count){
        printf("\n�ش� ���� �����Ͱ� �����ϴ�.\n");
        return;
    }
    double result;
    for(int i = 0 ; i < 7 ; i++){
        result += d[start+i]->godchecker;
        if(d[start+i]==NULL){
            printf("�̹� ������ �����Ͱ� �����մϴ�.\n");
            return;
        }
    }

    result = result/7;
    if(result>=4.5){
        printf("�̹��ִ� �� ����ó�� ��̱���!!!");
        return;
    }
    if(result>=4){
        printf("�̹��ִ� �����̳׿�!");
        return;
    }
    if(result>=3){
        printf("�̹��ִ� ������ ��̳׿�.");
        return;
    }
    else{
        printf("�̹��ִ� �̻��Դϴ�.");
        return;
    }
}

