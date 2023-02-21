#include <stdio.h>

//number of rows all together
#define ROWS 10
//number of columns
#define COLS 5
//number of rows after splitting
#define ROWS_prog 5
int n = 5;

int main() {
    //an array of all the data
    int allnumbers[ROWS][COLS];
    //an array of departments 
    int depart[ROWS_prog][COLS];
    //an array of the programmers 
    int programmers[ROWS_prog][COLS];
    //to print the number of the department
    int printnum = 1;
    //an array of first choices
    int firstrow[ROWS_prog][ROWS_prog];
    //the number that is duplicate
    int duplicatenum;
    int duplicatelist[5];
    int removeprog[5] = {1, 2, 3, 4, 5};
    
    //lines 25-36 - reading the file and appending the numbers into a new array
    FILE *fp;
    int i, j;
    fp = fopen("matching-data.txt","r");
    if (fp == NULL){
       printf("Error! opening file"); 
       return 1;
    }
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            fscanf(fp, "%d", &allnumbers[i][j]);  
        }    
    }
    //assignes the programmers to a new array
    for (int i = 5; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            programmers[i][j] = allnumbers[i][j];
        }
    }

    //assigns the departments to a new array
    printf("\n");
    for (int i = 0; i < ROWS-5; i++){
        for (int j = 0; j < COLS; j++){
            depart[i][j] = allnumbers[i][j];
        }
    }
    
    //declares the first row of departments
    for (int i = 0; i < ROWS_prog; i++){
        firstrow[0][i] = allnumbers[0][i];
    }


    //
    int index = 0;
    //iterating to find the first row
    //if you find duplicates append it to a new list and its index 
    for (int i = 0; i < ROWS_prog+1; i++) {
        for (int j = i + 1; j < ROWS_prog+1; j++) {
            //if you find duplicates append it to a new list and its index 
            if (firstrow[0][i] == firstrow[0][j]) {
                //printf("%d", firstrow[0][i]);
                duplicatenum = firstrow[0][i];
                duplicatelist[index] = index;
                //this is going through the programmers array and printing the first choice of the programmers 
                for (int i = 5; i < ROWS; i++){
                    for (int j = 0; j < COLS; j++){
                        programmers[i][duplicatenum-1] = allnumbers[i][duplicatenum-1];
                        //printf("%d\n", programmers[i][duplicatenum-1]);
                        //printf("%d\n", duplicatelist[index]);
                        if ((programmers[i][duplicatenum-1]-1) == duplicatelist[index]){
                            //printf("%d\n", programmers[i][duplicatenum-1]-1);
                            printf("%s %d %s %d\n","Department #", printnum, "will get Programmer #", programmers[i][duplicatenum-1]);
                            for (int i = index; i < n-1; i++){
                                removeprog[i] = removeprog[i+1];
                            }
                            n--;
                            printnum++;
                        }
                        break;
                    }
                }
            } else {
                
                for (int i = 5; i < ROWS; i++){
                    for (int j = 0; j < COLS; j++){
                        index++;
                        programmers[i][duplicatenum-1] = allnumbers[i][duplicatenum-1];
                        if ((programmers[i][duplicatenum-1]-1) == duplicatelist[index]){
                            if (printnum != 6){
                                if (printnum == 4){
                                    if (programmers[i][duplicatenum-1]-3 == -2){
                                        break;
                                    }
                                    printf("%s %d %s %d\n","Department #", printnum, "will get Programmer #", programmers[i][duplicatenum-1]-3);
                                    printf("%s %d %s %d\n","Department #", printnum+1, "will get Programmer #", programmers[i][duplicatenum-1]-1);
                                    break;
                                }
                                printf("%s %d %s %d\n","Department #", printnum, "will get Programmer #", programmers[i][duplicatenum-1]+1);
                                for (int i = index; i < n-1; i++){
                                    removeprog[i] = removeprog[i+1];
                                }
                                n--;
                                printnum++;
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
    }
}
