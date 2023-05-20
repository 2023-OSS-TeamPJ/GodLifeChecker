#include <stdio.h>
#include <stdlib.h>
#include "evaluate.h"


void conformDaily(standard *s, daily *d[], int count){
    int  day;
    int evaluate[7];

    //�����Ͱ� ������
    if (count == 0) {
        printf("\n���� �����ϴ� �����Ͱ� �����ϴ�\n");
        return;
    }

    printf("\n�� ��° �Ϸ縦 ���Ͻðڽ��ϱ�? (���: 0) ");
    scanf("%d",&day);

    if (day == 0) return; 
    //������ ��� ���ڸ� �Է��� ��� -> ������
    else if (day > count || day < 1){
        printf("\n�ش� ���ڰ� �������� �ʽ��ϴ�.\n");
        return;
    }

    evaluate[0]=(d[day-1]->exerciseTime*100/s->exerciseTime);
    evaluate[1]=(d[day-1]->majorStudy*100/s->majorStudy);
    evaluate[2]=(d[day-1]->otherStudy*100/s->otherStudy);
    evaluate[3]=(d[day-1]->sleepTime*100/s->sleepTime);
    evaluate[4]=(d[day-1]->readingTime*100/s->readingTime);
    evaluate[5]=(d[day-1]->mealCount*100/s->mealCount);
    evaluate[6]=(d[day-1]->friendshipTime*100/s->friendshipTime);

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
        printf("******************************************************\n");
        printf("* �����̱���!! �׷� ������ ���� �������°� ����? *\n");
        printf("******************************************************\n");
        return;
    }
    if(result>=4){
        printf("\n��� %d%% \n", evaluate[0]);
        printf("�ֿ������ %d%% \n", evaluate[1]);
        printf("��������� %d%% \n", evaluate[2]);
        printf("����ð��� %d%% \n", evaluate[3]);
        printf("�����ð��� %d%% \n", evaluate[4]);
        printf("�Ļ�Ƚ���� %d%% \n", evaluate[5]);
        printf("�米�ð��� %d%% �Դϴ� �̸� �� �����غ� ���.....\n", evaluate[6]);
        printf("*************\n");
        printf("* �����̽ñ��� *\n");
        printf("*************\n");
            return;
    }
    if(result>=3){
        printf("\n��� %d%% \n", evaluate[0]);
        printf("�ֿ������ %d%% \n", evaluate[1]);
        printf("��������� %d%% \n", evaluate[2]);
        printf("����ð��� %d%% \n", evaluate[3]);
        printf("�����ð��� %d%% \n", evaluate[4]);
        printf("�Ļ�Ƚ���� %d%% \n", evaluate[5]);
        printf("�米�ð��� %d%% �Դϴ� �̸� �� �����غ� ���.....\n", evaluate[6]);
        printf("****************\n");
        printf("* �����̽ñ���. *\n");
        printf("****************\n");
            return;
    }
    if(3>result && result > 0){
        printf("\n��� %d%% \n", evaluate[0]);
        printf("�ֿ������ %d%% \n", evaluate[1]);
        printf("��������� %d%% \n", evaluate[2]);
        printf("����ð��� %d%% \n", evaluate[3]);
        printf("�����ð��� %d%% \n", evaluate[4]);
        printf("�Ļ�Ƚ���� %d%% \n", evaluate[5]);
        printf("�米�ð��� %d%% �Դϴ� �̸� �� �����غ� ���.....\n", evaluate[6]);
        printf("*********************************************************\n");
        printf("* �ƽ��Ե� �̻��Դϴ�. ������ ���� ���� ���°� ����? *\n");
        printf("*********************************************************\n");
        return;
    }
    else{
        printf("\n��� %d%% \n", evaluate[0]);
        printf("�ֿ������ %d%% \n", evaluate[1]);
        printf("��������� %d%% \n", evaluate[2]);
        printf("����ð��� %d%% \n", evaluate[3]);
        printf("�����ð��� %d%% \n", evaluate[4]);
        printf("�Ļ�Ƚ���� %d%% \n", evaluate[5]);
        printf("�米�ð��� %d%% �Դϴ� �̸� �� �����غ� ���.....\n", evaluate[6]);
        printf("***************************************************************************\n");
        printf("* �ƽ��Ե� �̻��Դϴ�. ������ ���� ���� ���°� ����? (�ұ����� �� �Դϴ�)*\n");
        printf("***************************************************************************\n");
        return;
    }
}

void calculatorWeek(daily *d[], int count){
    int week;
    if(count<7){
        printf("\n������ġ�� �����Ͱ� ����� ������ �ʾҽ��ϴ�\n"); 
        return;
            
    }
    
    printf("\n�������� ������ �˰�����Ű���? ");
    scanf("%d",&week);

    int start = (week-1)*7 ;
    if(start+6>count){
        printf("\n�ش� ������ �����Ͱ� �����մϴ�\n");
        return;
    }
    double result;
    for(int i = 0 ; i < 7 ; i++){
        result += d[start+i]->godchecker;
    }

    result = result/7;
    if(result>=4.5){
        printf("\n************************************************************\n");
        printf("* %d ������ �����̱���!! �׷� ������ ���� �������°� ����? *\n", week);
        printf("************************************************************\n");
        return;
    }
    if(result>=4){
        printf("\n***********************\n");
        printf("* %d ������ �����̳׿�! *\n", week);
        printf("***********************\n");
        return;
    }
    if(result>=3){
        printf("\n***************************\n");
        printf("* %d ������ ������ ��̳׿�. *\n", week);
        printf("***************************\n");
        return;
    }
    else{
        printf("* %d ������ �ƽ��Ե� �̻��Դϴ�. ������ ���� ���� ���°� ����?\n", week);
        return;
    }
}