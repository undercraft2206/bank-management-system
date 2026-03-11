#ifdef _WIN32

#include <stdio.h>
#include <stdlib.h>

void file_print_log(char info[2000]){
    FILE *log = fopen("log.txt", "a");
    if (log == NULL) {
        return;
    }
    fprintf(log, "%s\n", info);
    fclose(log);
}


void cpy_file(char function[10], char name[2000], char password[2000]){
    FILE *accounts = fopen("accounts", "rb");
    FILE *tempo = fopen("tempo.txt", "wb");

    char output[2000];

    if(strcmp(function, "add") == 0){
        file_print_log("start add function modification file");

        fscanf(accounts, "%s", output);

        while(strcmp(output, "end") != 0){
            fprintf(tempo, "%s ", output);
            fscanf(accounts, "%s", output);
        }

        fprintf(tempo, "%s { %s ID 800 }\n\nend", name, password);

        fclose(accounts);
        fclose(tempo);

        FILE *accounts = fopen("accounts", "wb");
        FILE *tempo = fopen("tempo.txt", "rb");

        int i = 0;

        fscanf(tempo, "%s", output);

        while(strcmp(output, "end") != 0){
            start_cpy_acc:

            if(strcmp(output, "}") == 0){
                goto start_cpy_acc;
            }

            if(strcmp(output, "end") == 0){
                break;
            }

            fprintf(accounts, "%s ", output);

            fscanf(tempo, "%s", output);
            fprintf(accounts, "%s\n\n", output);

            fscanf(tempo, "%s", output);
            fprintf(accounts, "%s\n", output);

            fscanf(tempo, "%s", output);
            fprintf(accounts, "%s\n", output);

            fscanf(tempo, "%s", output);
            fprintf(accounts, "%s\n\n", output);

            fscanf(tempo, "%s", output);
            fprintf(accounts, "%s\n\n", output);

            fscanf(tempo, "%s", output);
        }

        fprintf(accounts, "end");

        fclose(accounts);
        fclose(tempo);

        remove("tempo.txt");

        file_print_log("added accounts !");
    }

}


void add_account(char name[2000], char password[2000]){
    file_print_log("start add function");

    FILE *accounts = fopen("accounts", "rb");
    FILE *tempo = fopen("tempo.txt", "wb");

    char output[2000];

    start_log_a_pass:

    fscanf(accounts, "%s", output);

    while(strcmp(output, "end") != 0){
        if(strcmp(output, name) == 0){

            system("cls");
            printf("You can not use this name\n\nlogin: ");
            scanf("%s", &name);

            printf("password: ");
            scanf("%s", &password);

            fclose(accounts);
            accounts = fopen("accounts", "rb");

            goto start_log_a_pass;
        }

        fscanf(accounts, "%s", output);
    }

    cpy_file("add", name, password);

}

#endif
