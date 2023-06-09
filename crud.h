
typedef struct{
    int exerciseTime;
    int majorStudy;
    int otherStudy;
    int sleepTime;
    int mealCount;
    int readingTime;
    int friendshipTime;
}standard;

typedef struct{
    int exerciseTime;
    int majorStudy;
    int otherStudy;
    int sleepTime;
    int mealCount;
    int readingTime;
    int friendshipTime;
    int godchecker;
}daily;



void standardChecker(standard *s);
void saveData(standard *s,daily *d[]  ,int count);
int loadData(standard *s, daily *d[], int *standardExist);
int calculatorDaily(standard *s, daily *d);
void addDailyData(standard *s,daily *d[], int count);
int deleteDailyData(daily *d[], int count);
void updateDailyData(daily *d[], int count);
void showDailyData(daily *d[], int count);
void refreshEvalutation(standard *s, daily *d[], int count);
int menu();
