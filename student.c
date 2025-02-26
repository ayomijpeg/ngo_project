#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student data
struct Student {
    int id;
    char name[50];
    float grade;
};

// Function to read student records from a text file
void readFromTextFile() {
    FILE *file = fopen("/storage/emulated/0/students.txt", "r");
    if (!file) {
        printf("\nError: Could not open students.txt for reading!\n");
        return;
    }

    struct Student student;
    printf("\nStudent Records from Text File:\n");
    while (fscanf(file, "%d %49[^\n] %f", &student.id, student.name, &student.grade) == 3) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
    }

    fclose(file);
}

// Function to write a new student record to a binary file
void writeToBinaryFile() {
    FILE *file = fopen("/storage/emulated/0/students.dat", "ab"); // Append in binary mode
    if (!file) {
        printf("\nError: Could not open students.dat for writing!\n");
        return;
    }

    struct Student student;
    printf("\nEnter Student ID: ");
    scanf("%d", &student.id);
    getchar();  // Consume newline

    printf("Enter Student Name: ");
    fgets(student.name, sizeof(student.name), stdin);
    strtok(student.name, "\n");  // Remove newline safely

    printf("Enter Student Grade: ");
    scanf("%f", &student.grade);

    fwrite(&student, sizeof(struct Student), 1, file);
    printf("\nStudent record saved to binary file!\n");

    fclose(file);
}

// Function to read and display data from the binary file
void readFromBinaryFile() {
    FILE *file = fopen("/storage/emulated/0/students.dat", "rb");
    if (!file) {
        printf("\nError: No binary file found!\n");
        return;
    }

    struct Student student;
    printf("\nStudent Records from Binary File:\n");
    while (fread(&student, sizeof(struct Student), 1, file)) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
    }

    fclose(file);
}

int main() {
    int choice;
    
    do {
        printf("\nStudent Database Management\n");
        printf("1. Read from Text File\n2. Write to Binary File\n3. Read from Binary File\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                readFromTextFile();
                break;
            case 2:
                writeToBinaryFile();
                break;
            case 3:
                readFromBinaryFile();
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}