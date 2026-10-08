#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

uint16_t ScanningValue(uint16_t value){
    bool Checker;
    
    do{
       Checker = scanf("%hu", &value);
       if(Checker != 1){
        printf("Number not taking into consideration, please provide another number :");
       }
    }while(Checker !=1);
    return value;
}

int main(){
    uint16_t size_list;
    FILE *file = fopen("wordlist.txt", "r");

    printf("Welcome to the WordList Program, press Enter to Begin :");
    getchar();
    clearScreen();

    printf("Enter the value of the where you want your Wordlist to begin\n");

    ScanningValue(size_list);

    
    for(int i=0;i<size_list;i++){
        fprintf(file, "%0*d\n", size_list, i);
    }

    printf("File created successfully !");

    return 0;
}