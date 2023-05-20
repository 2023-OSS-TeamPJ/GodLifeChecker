#include <stdio.h>
#include <stdlib.h>
//#include "crud.h"
#include "evaluate.h"



int main(void) {
    int menuNum; //����ڰ� ������ �޴���ȣ
    int count = 0; //�Է� �Ǿ��ִ� �������� ����
    int result; //�Լ��� �����
    int standardExist = 0; //���� ������ ���� ����
    //�������� ������� �޸� �Ҵ� & ���ϵ����� ������� ����
    standard *myStandard = (standard*)malloc(sizeof(standard));
    daily *myDaily[28];

    //���Ϸε�
    count = loadData(myStandard, myDaily, &standardExist);
    //����� �����Ͱ� ������ ���, ���� ������ ���絵 Ȯ��

    while(1) {

        menuNum = menu();
        if (menuNum == 1) {
            //���� ���� ����/�����ϱ�
            standardChecker(myStandard);
            standardExist = 1;
        }
        else if (menuNum == 2 && standardExist != 0) {
            //���� ������ �Է�
            myDaily[count] = (daily*)malloc(sizeof(daily)); //���ϵ����� ������� �޸� �Ҵ�
            addDailyData(myStandard, myDaily, count);
            count ++;
        }
    
        else if (menuNum == 3 && standardExist != 0) {
            //��ü ���� ������ ����
            result = deleteDailyData(myDaily, count);
            if (result ==  1) count = 0; //�����Ǿ��ٸ� count�� 0���� ��ȯ
        }
        else if (menuNum == 4 && standardExist != 0) {
            //���� ������ ����
            updateDailyData(myDaily, count);
        }
        else if (menuNum == 5 && standardExist != 0) {
            refreshEvalutation(myStandard, myDaily, count); //�� ������ ���ΰ�ħ
            //���� ������ ���
            showDailyData(myDaily, count);
        }
        else if (menuNum == 6 && standardExist != 0) {
            refreshEvalutation(myStandard, myDaily, count); //�� ������ ���ΰ�ħ
            //�Ϻ� ���� ��
            conformDaily(myStandard, myDaily, count);
        }
        else if (menuNum == 7 && standardExist != 0) {
            refreshEvalutation(myStandard, myDaily, count); //�� ������ ���ΰ�ħ
            //�ֺ� ���� ��
            calculatorWeek(myDaily, count);
        }
        else if (menuNum == 8) {
            refreshEvalutation(myStandard, myDaily, count); //�� ������ ���ΰ�ħ
            //������ ����
            saveData(myStandard, myDaily, count);
        }
        else if (menuNum == 0) {
            //������
            break;
        }
        else if (standardExist == 0) { 
            //���� �����Ͱ� ���� ���
            printf("\n������ ���� �Է����ּ���\n");
        }
        else {
            //�߸��� �Է��� �޾��� ���
            printf("\n�߸��� �޴���ȣ�Դϴ�\n");
        }
    }
}
