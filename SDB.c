#include "SDB.h"
#include <stdio.h>

#define MAX_STUDENTS 10

static student database[MAX_STUDENTS];
static uint8 num_students = 0;

bool SDB_IsFull() {
    return num_students >= MAX_STUDENTS;
}

uint8 SDB_GetUsedSize() {
    return num_students;
}

bool SDB_AddEntry() {
    if (num_students >= MAX_STUDENTS) {
        return false;
    }

    student newStudent;

    printf("Enter Student ID: ");
    scanf("%u", &newStudent.Student_ID);
    printf("Enter Student_year: ");
    scanf("%u", &newStudent.Student_year);
    printf("Enter Course1_ID: ");
    scanf("%u", &newStudent.Course1_ID);
    printf("Enter Course1_grade: ");
    scanf("%u", &newStudent.Course1_grade);
    printf("Enter Course2_ID: ");
    scanf("%u", &newStudent.Course2_ID);
    printf("Enter Course2_grade: ");
    scanf("%u", &newStudent.Course2_grade);
    printf("Enter Course3_ID: ");
    scanf("%u", &newStudent.Course3_ID);
    printf("Enter Course3_grade: ");
    scanf("%u", &newStudent.Course3_grade);

    database[num_students] = newStudent;
    num_students++;

    printf("Student added successfully!\n");
    return true;
}

void SDB_DeleteEntry(uint32 id) {
    for (uint8 i = 0; i < num_students; i++) {
        if (database[i].Student_ID == id) {
            for (uint8 j = i; j < num_students - 1; j++) {
                database[j] = database[j + 1];
            }
            num_students--;
            printf("Student with ID %u deleted.\n", id);
            return;
        }
    }
    printf("Student with ID %u not found.\n", id);
}

bool SDB_ReadEntry(uint32 id) {
    for (uint8 i = 0; i < num_students; i++) {
        if (database[i].Student_ID == id) {
            printf("Student ID: %u\n", database[i].Student_ID);
            printf("Student Year: %u\n", database[i].Student_year);
            printf("Course1 ID: %u\n", database[i].Course1_ID);
            printf("Course1 GARDE: %u\n", database[i].Course1_grade);
            printf("Course2 ID: %u\n", database[i].Course2_ID);
            printf("Course2 GARDE: %u\n", database[i].Course2_grade);
            printf("Course3 ID: %u\n", database[i].Course3_ID);
            printf("Course3 GARDE: %u\n", database[i].Course3_grade);
            return true;
        }
    }
    printf("Student with ID %u not found.\n", id);
    return false;
}

void SDB_GetList(uint8 *count, uint32 *list) {
    for (uint8 i = 0; i < num_students; i++) {
        list[i] = database[i].Student_ID;
    }
    *count = num_students;
}

bool SDB_IsIdExist(uint32 id) {
    for (uint8 i = 0; i < num_students; i++) {
        if (database[i].Student_ID == id) {
            return true;
        }
    }
    return false;
}
