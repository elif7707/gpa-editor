//
//  main.c
//  pointersCode
//
//  Created by Elif Zeynep Çetinkaya on 1.11.2023.
//

#include <stdio.h>
void enterNumber(int *num);
void reset(float *a);

int main(void) {
    
    float grade1 = 0, grade2 = 0, grade3 = 0;
    int selection;
    float *p1, *p2, *p3;
    float gpa;
    
    // to find their address I created pointers
    p1 = &grade1;
    p2 = &grade2;
    p3 = &grade3;
    
    do {
        // to convert gpa into x/4 format I multiplied by 4.
        gpa = (grade1 + grade2 + grade3) / (3 * 100);
        gpa *= 4;
        
        // to display the address of grades I used pointers
        printf("---------------GRADES----------------\n");
        printf(" 1- CMPE114: %.2f (%p)\n",grade1, p1);
        printf(" 2- PHYS102: %.2f (%p)\n",grade2, p2);
        printf(" 3- HIST201: %.2f (%p)\n",grade3, p3);
        printf("-------------------------------------\n");
        printf("Your GPA is %.2f/4\n",gpa);
        printf("-------------------------------------\n");
        printf("1- Edit class grade\n2- Clear grade\n3-Quit\n");
        
       
        enterNumber(&selection);
        
        if (selection == 1) {
            int classNum;
            int gradeForClass;
            do {
                printf("Enter class number to edit (1-3): ");
                scanf(" %d", &classNum);
            } while (classNum < 1 || classNum > 3);
            printf("Enter grade for class %d: ", classNum);
            scanf(" %d", &gradeForClass);
            switch (classNum) {
                case 1:
                    *p1 = gradeForClass;
                    break;
                case 2:
                    *p2 = gradeForClass;
                    break;
                case 3:
                    *p3 = gradeForClass;
                    break;
                default:
                    break;
            }
            printf("Updated the grade for class %d!\n", classNum);
        } else if (selection == 2) {
            int classNum;
            do {
                printf("Enter class number to clear (1-3): ");
                scanf(" %d", &classNum);
            } while (classNum < 1 || classNum > 3);
            switch (classNum) {
                case 1:
                    reset(p1);
                    break;
                case 2:
                    reset(p2);
                    break;
                case 3:
                    reset(p3);
                    break;
                default:
                    break;
            }
            printf("Cleared the grade for class %d!\n", classNum);
        }
    } while (selection != 3);
    
    printf("Goodbye :)");
    
    return 0;
    
}

void enterNumber(int *num){
    do {
        printf("Enter selection (1-3):");
        scanf(" %d", num);
        
        if(*num < 1 || *num > 3){
            printf("Not a valid number!\n");
            
        }
    } while (*num < 1 || *num > 3);
}

void reset(float *a) {
    *a = 0;
}
