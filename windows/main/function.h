#include "login-manager\login-manager.c"
#include "file-manager\file-manager.c"

//from file main.c
void cls(void);
void print_log(char info[2000]);
void file_verification(void);

//from file login-manager.c
void login_manager(char login[2000], char password[2000]);

//from file file-manager.c
void add_account(char name[2000], char password[2000]);
