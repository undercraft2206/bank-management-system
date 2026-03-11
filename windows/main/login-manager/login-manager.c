#ifdef _WIN32

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>


void login_manager(char login[2000], char password[2000]) {

    FILE *setting = fopen("settings", "rb");
    FILE *accounts = fopen("accounts", "rb");

    char output[2000];
    char output_[2000];

    fscanf(setting, "%s", output);
    fscanf(setting, "%s", output);
    fscanf(setting, "%s", output_);

    if(strcmp(output, login) == 0 && strcmp(output_, password) == 0){
        printf("successfully loged in !");
        Sleep(1000);
        system("cls");
    } else{

        fscanf(accounts, "%s", output);

        while(strcmp(output, "end") != 0){

            if(strcmp(output, login) == 0){
                fscanf(accounts, "%s", output);
                fscanf(accounts, "%s", output);

                if(strcmp(output, password) == 0){
                    printf("good password !");
                    Sleep(3000);
                    system("cls");
                    return;
                } else if(strcmp(output, password) != 0){
                    Sleep(2000);
                    printf("wrong password !");
                    Sleep(2000);
                    exit(1);
                }

            }

            fscanf(accounts, "%s", output);
        }

        Sleep(3000);
        system("cls");
        printf("the username or password is wrong...");
        Sleep(4000);
        exit(1);
    }
}


#endif
