struct {
    char name[10];
    int age;
    float salary;
} person;

typedef struct human_being
{
    char name[10];
    int age;
    float salary;
};

typedef struct {
    char name[10];
    int age;
    float salary;
} human_being2;

int main()
{
    strcpy(person.name, "james");
    person.age = 10;
    person.salary = 35000;
    
    struct human_being human1;

    human_being2 human2;
}

