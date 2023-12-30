#include <stdio.h>
#include <stdlib.h>


typedef struct student {
    int studentID;
    char name[50];
    char surname[50];
    int midterm;
    int lab;
    int project;
    int final;
    struct student *next;
} Student;


Student *createLinkedList(int x) {
    Student *head = NULL;
    for (int i = 0; i < x; i++) {
        Student *newStudent = (Student *)malloc(sizeof(Student));
        printf("Enter studentID, name, surname, midterm, lab, project, and final for student %d: ", i+1);
        scanf("%d %s %s %d %d %d %d", &newStudent->studentID, newStudent->name, newStudent->surname, &newStudent->midterm, &newStudent->lab, &newStudent->project, &newStudent->final);
        newStudent->next = head;
        head = newStudent;
    }
    return head;
}


void modifyScore(Student *head) {
    char field[10];
    int value;
    printf("Enter the field to modify: ");
    scanf("%s", field);
    printf("Enter the new value: ");
    scanf("%d", &value);
    while (head != NULL) {
        if (strcmp(field, "midterm") == 0) {
            if (value >= 0 && value <= 100) {
                head->midterm = value;
            } else {
                printf("Invalid score! Score should be in the range of 0-100\n");
            }
        } else if (strcmp(field, "lab") == 0) {
            if (value >= 0 && value <= 100) {
                head->lab = value;
            } else {
                printf("Invalid score! Score should be in the range of 0-100\n");
            }
        } else if (strcmp(field, "project") == 0) {
            if (value >= 0 && value <= 100) {
                head->project = value;
            } else {
                printf("Invalid score! Score should be in the range of 0-100\n");
            }
        } else if (strcmp(field, "final") == 0) {
            if (value >= 0 && value <= 100) {
                head->final = value;
            } else {
                printf("Invalid score! Score should be in the range of 0-100\n");
            }
        } else {
            printf("Invalid field! Field should be midterm, lab, project, or final\n");
        }
        head = head->next;
    }
}


void findHighestMark(Student *head) {
    int highest = 0;
    Student *current = head;
    while (current != NULL) {
        if (current->midterm + current->lab + current->project + current->final > highest) {
            highest = current->midterm + current->lab + current->project + current->final;
        }
        current = current->next;
    }
    printf("The highest mark among the students is %d\n", highest);
}

int main() {
    int x;
    printf("Enter the number of students: ");
    scanf("%d", &x);
    Student *head = createLinkedList(x);
    modifyScore(head);
    findHighestMark(head);
    return 0;
}