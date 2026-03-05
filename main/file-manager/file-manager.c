#include <stdio.h>
#include <stdlib.h>

void function_add(char name[64], char password[2000]){

    FILE *ptr = fopen("bank", "r");
    FILE *tempo = fopen("tempo.txt", "w");

    char output[2000];

    while (!feof(ptr))
    {
        
        fscanf(ptr, "%s", &output);

        if (strcmp(output, "}") == 0)
        {
            
            fscanf(ptr, "%s", &output);
            fprintf(tempo, "\n\n");

        }

        if (strcmp(output, "end") == 0)
        {

            fprintf(tempo, "%s %s id 800\n\nend", name, password);
            
            fclose(ptr);
            fclose(tempo);
            
            break;

        }
        
        if (strcmp(output, "{") == 0)
        {
            
            fscanf(ptr, "%s", &output);

        }
        
        fprintf(tempo, "%s ", output);

    }

    ptr = fopen("bank", "w");
    tempo = fopen("tempo.txt", "r");

    while (!feof(tempo))
    {
        fscanf(tempo, "%s", &output);

        if (strcmp(output, "}") == 0)
        {
            fscanf(tempo, "%s", &output);
        }
        

        if (strcmp(output, "end") == 0)
        {

            fprintf(ptr, "\n\nend");
            break;

        }

        fprintf(ptr, "%s {\n", output);

        fscanf(tempo, "%s", &output);
        fprintf(ptr, "%s\n", output);

        fscanf(tempo, "%s", &output);
        fprintf(ptr, "%s\n", output);

        fscanf(tempo, "%s", &output);
        fprintf(ptr, "%s\n}\n\n", output);

    }
    
    fclose(ptr);
    fclose(tempo);

    remove("tempo.txt");
    
}