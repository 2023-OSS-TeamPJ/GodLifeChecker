#include <stdio.h>
#include <stdlib.h>
#include "evaluate.h"



void conformDaily(standard *s, daily *d[]){
    int  day;
    printf("���ϴ� ��¥��?");
    scanf("%d",&day);

    int result;
    result = d[day-1]->godchecker;
    
    if(result>=5){
        printf("�� �����̱���!!!");
        return;
    }
    if(result>=4){
            printf("�����̳׿�!");
            return;
    }
    if(result>=3){
            printf("�����̽ñ���.");
            return;
    }
    if(3>result){
            printf("�̻��Դϴ�.");
        return;
    }
    else{
        printf("�̻��Դϴ� (�ұ����� �� �Դϴ�.)");
        return;
    }
}

void calculatorWeek(daily *d[]){
    int week;
    if(sizeof(*d)/sizeof(daily*)<7){
        printf("7������ ������ ����� �����Ͱ� ������ �ʾҽ��ϴ�."); 
        return;
    }
    printf("�������� ������ �˰�����Ű���?");
    scanf("%d",&week);
    int start = (week-1)*7 ;
    double result;
    for(int i = 0 ; i < 7 ; i++){
        result += d[start+i]->godchecker;
        if(d[start+i]==NULL){
            printf("�̹� ������ �����Ͱ� �����մϴ�.");
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

