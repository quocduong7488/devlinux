#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>

#define DATA "students.dat"

typedef struct {
    int id;
    char name[64];
    int age;
    float gpa;
} Student;

// int input_int(const char *message, int *value)
// {
//     char buffer[64];
//     char extra;

//     printf("%s", message);

//     if (fgets(buffer, sizeof(buffer), stdin) == NULL)
//     {
//         return 0;
//     }

//     if (sscanf(buffer, "%d %c", value, &extra) != 1)
//     {
//         printf("Invalid input! Please enter an integer.\n");
//         return 0;
//     }

//     return 1;
// }

// int input_float(const char *message, float *value)
// {
//     char buffer[64];
//     char extra;

//     printf("%s", message);

//     if (fgets(buffer, sizeof(buffer), stdin) == NULL)
//     {
//         return 0;
//     }

//     if (sscanf(buffer, "%f %c", value, &extra) != 1)
//     {
//         printf("Invalid input! Please enter a number.\n");
//         return 0;
//     }

//     return 1;
// }

// int input_name(char name[64])
// {
//     int i;

//     printf("Enter name: ");

//     if (fgets(name, 64, stdin) == NULL)
//     {
//         return 0;
//     }

//     name[strcspn(name, "\n")] = '\0';

//     if (strlen(name) == 0)
//     {
//         printf("Name cannot be empty.\n");
//         return 0;
//     }

//     /* Check name contains only letters and spaces */
//     for (i = 0; name[i] != '\0'; i++)
//     {
//         if ((name[i] >= '0' && name[i] <= '9'))
//         {
//             printf("Name cannot contain numbers.\n");
//             return 0;
//         }
//     }

//     return 1;
// }

// int check_id(int id){
//     Student student;
//     int fd = open(DATA, O_RDONLY);
//     if(fd == -1){
//         return 0;
//     }
//     while(read(fd, &student, sizeof(Student)) == sizeof(Student)){
//         if(student.id == id){
//             close(fd);
//             return 1;
//         }
//     }
//     close(fd);
//     return 0;
// }


/* ------------Actions----------------- */
void add_student (int fd) {
    Student student;



    if(fd == -1){
        printf("Can't open %s\n", DATA);
        return;
    }
    //        

    if(write(fd, &student, sizeof(Student)) != sizeof(Student)){
        printf("Can't write student\n");
        close(fd);
        return;
    }

    close(fd);

    printf("Student added succesfully\n");
}

// void print_student(Student student){
//     printf("\n-------------------------\n");
//     printf("ID   : %d\n", student.id);
//     printf("Name : %s\n", student.name);
//     printf("Age  : %d\n", student.age);
//     printf("GPA  : %f\n", student.gpa);
//     printf("-------------------------\n");
// }

// void show_student(int fd){
//     Student student;

//     if(fd == -1){
//         printf("Can't open %s\n", DATA);
//         return;
//     }

//     int count = 0;
    
//     while(read(fd, &student, sizeof(Student)) == sizeof(Student)){
//         print_student(student);
//         count++;
//     }
// }

// void find_student(int fd){
//     Student student;
//     int id;

//     printf("Enter student ID: ");
//     scanf("%d", &id);

//     if(fd == -1){
//         printf("Cannot open %s\n", DATA);
//         return;
//     }

//     while(read(fd, &student, sizeof(Student)) == sizeof(Student)){
//         if(student.id == id){
//             printf("\nStudent found:\n");
//             print_student(student);

//             break;
//         }else{
//             printf("Student not found.\n");
//         }
//     }

//     close(fd);
// }

int main(void){
    int choice;
    // int fd = open(DATA, O_RDWR | O_CREAT, 0644);
    // if(fd == -1){
    //     printf("Can't open %s\n", DATA);
    //     return 1;
    // }

    while(1){
        printf("\n==== MENU =====\n");
        printf("1. Add student\n");
        printf("2. List all students\n");
        printf("3. Find student by ID\n");
        printf("4. Exit\n");
        printf("Choose: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            {
                add_student(fd);
                printf("Add student function called.\n");
                break;
            }

            case 2:
                //show_student(fd);
                break;

            case 3:
                //find_student(fd);
                printf("Find student function called.\n");
                break;
            
            case 4:
                printf("Exit program.\n");
                exit(0);
            
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}