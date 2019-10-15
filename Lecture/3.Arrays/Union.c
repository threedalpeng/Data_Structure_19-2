typedef struct 
{
    enum tagField{female, male} sex;
    union
    {
        int children;
        int beard;
    } u;
} sex_type;

typedef struct 
{
    char name[10];
    int age;
    float salary;
    sex_type sex_info;
} human_being;

human_being person1, person2;