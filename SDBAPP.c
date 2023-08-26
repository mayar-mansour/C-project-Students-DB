#include "SDB.h"
#include <stdio.h>
#define MAX_STUDENTS 10 
void SDB_action(uint8 choice) {
    switch (choice) {
        case 1: {
            SDB_AddEntry();
            break;
        }
        case 2: {
            printf("Used size in database: %u\n", SDB_GetUsedSize());
            break;
        }
        case 3: {
            uint32 id;
            printf("Enter Student ID: ");
            scanf("%u", &id);
            SDB_ReadEntry(id);
            break;
        }
        case 4: {
            uint8 count;
            uint32 idList[MAX_STUDENTS];
            SDB_GetList(&count, idList);
            printf("List of Student IDs:\n");
            for (uint8 i = 0; i < count; i++) {
                printf("%u\n", idList[i]);
            }
            break;
        }
        case 5: {
            uint32 checkId;
            printf("Enter Student ID to check: ");
            scanf("%u", &checkId);
            if (SDB_IsIdExist(checkId)) {
                printf("Student ID %u exists.\n", checkId);
            } else {
                printf("Student ID %u does not exist.\n", checkId);
            }
            break;
        }
        case 6: {
            uint32 deleteId;
            printf("Enter Student ID to delete: ");
            scanf("%u", &deleteId);
            SDB_DeleteEntry(deleteId);
            break;
        }
        case 7: {
            if (SDB_IsFull()) {
                printf("Database is full.\n");
            } else {
                printf("Database is not full.\n");
            }
            break;
        }
        default: {
            printf("Invalid choice.\n");
            break;
        }
    }
}

void SDB_APP() {
    uint8 choice;

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add Entry\n");
        printf("2. Get Used Size in Database\n");
        printf("3. Read Student Data\n");
        printf("4. Get List of Student IDs\n");
        printf("5. Check if ID Exists\n");
        printf("6. Delete Student Data\n");
        printf("7. Check if Database is Full\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%hhu", &choice);

        if (choice == 0) {
            break;
        }

        SDB_action(choice);
    }
}

int main() {
    SDB_APP();
    return 0;
}
