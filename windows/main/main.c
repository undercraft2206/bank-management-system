#ifdef _WIN32

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "function.h"


void cls(void) {
    system("cls");
}


void print_log(char info[2000]){
    FILE *log = fopen("log.txt", "a");
    if (log == NULL) {
        return;
    }
    fprintf(log, "%s\n", info);
    fclose(log);
}


void file_verification(void) {
    print_log("File verification started");

    cls();

    FILE *accounts = fopen("accounts", "rb");
    FILE *settings = fopen("settings", "rb");

    char login[2000];
    char password[2000];

    int t = 30;

    if(accounts == NULL || settings == NULL) {
        print_log("File verification failed: deleting accounts and settings files for security");

        fclose(accounts);
        fclose(settings);

        remove("accounts");
        remove("settings");

        accounts = fopen("accounts", "wb");
        settings = fopen("settings", "wb");

        fprintf(accounts, "\n\nend");

        print_log("make settings");


        printf("file accounts or settings is missing, so we have created a new one\n");

        printf("Press any key to continue and make settings configuration...\n");
        getchar();

        printf("Enter the name of bank login (admin): ");
        scanf("%s", &login);

        printf("Enter the password of bank login (admin): ");
        scanf("%s", &password);

        cls();

        printf("Settings configuration completed.\n\n Press any key to print results (you will have 30 seconds)...\n");
        getchar();

        time_left:

        printf("Time Left: %d\nLogin: %s\nPassword: %s\n", t, login, password);

        if(t == 0) {
            cls();
            printf("Time's up! Writing settings...\n");
            fprintf(settings, "Login{\n%s %s isadmin=true\n}\n\nend", login, password);
            Sleep(5);
            return;
        } else{
            t--;
            Sleep(1000);
            cls();
            goto time_left;
        }


        fclose(accounts);
        fclose(settings);
    }

}


int main(void) {
    print_log("start main function\nstart file verification");

    file_verification();
    cls();

    char login[2000];
    char password[2000];
    int is_admin = 0;

    printf("Welcome to the bank system!\n\nlogin: ");
    scanf("%s", &login);
    printf("password: ");
    scanf("%s", &password);

    login_manager(login, password);

    FILE *settings = fopen("settings", "rb");
    char output[2000];

    fscanf(settings, "%s", output);
    fscanf(settings, "%s", output);

    if(strcmp(output, login) == 0) {
        is_admin = 1;
    }
    fclose(settings);

    if(is_admin == 1){
        print_log("Admin connected !");
    } else{
        print_log("Standard user connected !");
    }

    char commande[2000];

    start_commande:

    printf("> ");
    scanf("%s", &commande);

    if(is_admin == 1){
        if(strcmp(commande, "help") == 0) {
            printf("Available commands:\nhelp (display this help message)\nexit (exit the program)\nadd (add a new account need admin privileges)\nsend money (send money to another account need admin privileges)\nremove (remove an account need admin privileges)\nlist (list all accounts need admin privileges)\nsearch (search for an account need admin privileges)\n\n");
            goto start_commande;
        }
    } else{
        if(strcmp(commande, "help") == 0) {
            printf("Available commands:\nhelp (display this help message)\nexit (exit the program)\nsend money (send money to another account)\nbalance (check your balance)\n\n");
            goto start_commande;
        }
    }

    if(strcmp(commande, "exit") == 0) {
        print_log("exiting programme !");
        exit(0);
    }

    if(strcmp(commande, "add") != 0 && strcmp(commande, "remove") != 0 && strcmp(commande, "send") != 0 && strcmp(commande, "list") != 0 && strcmp(commande, "search") != 0 && strcmp(commande, "balance") != 0 && strcmp(commande, "help") != 0) {
        printf("\n\nCommande \"%s\" in not a commande available.\nType \"help\" to see available commands.\n\n", commande);
        goto start_commande;
    }


    if(strcmp(commande, "add") == 0 && is_admin == 0) {
        printf("\n\nCommande \"%s\" is unavalable\nType \"help\" to see available commands.\n\n", commande);
        goto start_commande;
    } else if(strcmp(commande, "add") == 0 && is_admin == 1){
        print_log("add function typed");

        char name[2000];
        char password_[2000];

        system("cls");
        printf("function: add_account\n\nname for login: ");
        scanf("%s", name);
        printf("\npassword: ");
        scanf("%s", password_);

        add_account(name, password_);

        cls();

        printf("the account \"%s\" added to data base !", name);
        print_log("finished add function");

        Sleep(2000);
        cls();

        goto start_commande;
    }

    return 0;
}


#endif
