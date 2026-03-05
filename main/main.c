#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>
#include "file-manager\file-manager.c"


void verification(void){

    FILE *ptr = fopen("bank", "r");
    FILE *log = fopen("log.txt", "r");

    if (log == NULL)
    {

        log = fopen("log.txt", "w");
        fprintf(log, " \nfile \"log.txt\" not found, created succesfully");

    }
    
    fprintf(log, "\nlooking for bank file");

    if (ptr == NULL)
    {

        fprintf(log, "\nERROR: File \"bank\" not found, creating one");

        printf("(CLIENT): ERRORE: file not found\ncreating one");

        ptr = fopen("bank", "w");
        fprintf(ptr, "\n\nend");
        fprintf(log, "\nfile \"bank\" created\nexiting");
        fclose(ptr);
        fclose(log);

        printf("\nfile created !");

        exit(-1);
    }

    fclose(ptr);
    fclose(log);

}

int main(void){
    system("cls");

    verification();

    FILE *log = fopen("log.txt", "a");
    char choice[200];

    fprintf(log, "\nsuccess of verification function");

    start:

    printf(">");
    scanf("%s", &choice);

    if (strcmp(choice, "help") == 0)
    {
        system("cls");
        fprintf(log, "\ncommand \"help\" typed");
        printf("add account (add)\n\n");
        goto start;
    }
    
    if (strcmp(choice, "add") == 0)
    {
        
        char name[64];
        char password[2000];

        char choice[3];

        fprintf(log, "\nget name of user information");

        start_add:

        printf("\nname: ");
        scanf("%s", &name[0]);

        if (strcmp(name, "mother") == 0 || strcmp(name, "fuck") == 0, strcmp(name, "damn") == 0)
        {
            printf("\033[1;31mThis is not a name !\033[0m\n");
        }
        

        fprintf(log, "\nget password of user information");

        password:

        printf("\n\npassword: ");
        scanf("%s", &password[0]);

        if (strcmp(password, "123456") == 0 || strcmp(password, "1234") == 0 || strcmp(password, "000000") == 0 || strcmp(password, "0000") == 0 || strcmp(password, "password") == 0 || strcmp(password, name) == 0 || strcmp(password, "azerty") == 0 || strcmp(password, "querty") == 0)
        {

            printf("\033[1;31mMake a stronger password !\033[0m\n");

            goto password;

        }   
        
        system("cls");

        printf("\nAre you sure to make the new user (yes/no): ");
        scanf("%s", &choice);

        if (strcmp(choice, "yes") == 0)
        {

            srand(time(NULL));

            function_add(name, password);

            system("cls");

            printf("printing information, you will have 30 second, are you ready, say yes to print it and no for don't print.\n>");
            scanf("%s", &choice);

            if (strcmp(choice, "yes") == 0)
            {
                int time = 30;
                system("cls");

                time: 

                    printf("time: %d\n\nname: %s password: %s\ndon't loose this information !", time, name, password);
                    Sleep(1000);
                    time = time - 1;
                    system("cls");

                    if (time == 0)
                    {
                        system("cls");
                        exit(0);
                    } else{
                        goto time;
                    }
            
            } else{

                printf("\n\nwe will not printing information...");

                return 0;

            }
            


        }  else if (strcmp(choice, "no") == 0)
        {
            
            printf("\n\nexit (yes/no): ");
            scanf("%s", &choice);

            if (strcmp(choice, "no") == 0)
            {
                
                goto start_add;

            } else{

                exit(0);

            }

        }
        
    }

}