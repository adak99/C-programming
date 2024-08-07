#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    char name[50];
    char address[100];
    int age;
    float avg;
};

void display(struct student stud)
{
    printf("\nRoll: %d\n", stud.roll);
    printf("Name: %s\n", stud.name);
    printf("Address: %s\n", stud.address);
    printf("Age: %d\n", stud.age);
    printf("Average Marks: %.2f\n", stud.avg);
}

int main()
{
    struct student students[12];
    int i;

    for (i = 0; i < 12; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &students[i].roll);
        getchar();

        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Address: ");
        fgets(students[i].address, sizeof(students[i].address), stdin);
        students[i].address[strcspn(students[i].address, "\n")] = '\0';

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("Average Marks: ");
        scanf("%f", &students[i].avg);
    }

    printf("\nDisplaying details of all students:\n");
    for (i = 0; i < 12; i++)
    {
        display(students[i]);
    }

    return 0;
}
