/*--------------------------------------------------------------------------------------------------------------------------------------
														ADDRESS BOOK PROJECT Using FILE I/O
---------------------------------------------------------------------------------------------------------------------------------------*/

/*
    Name - Aditya Shete
    Date - 29/08/2024
    Description - AddessBook Project Using File I/O
                  The project involves basic file I/O, string handling, and user interaction using the console. 
                  It serves as a good exercise in handling dynamic data, file operations, and user input validation in C.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <ctype.h>
#include"header.h"
#include"add_detail.c"
#include"print_detail.c"
#include"search_detail.c"
#include"edit_detail.c"
#include"delete_detail.c"

int main(int argc,char * argv[])
{
    Addressbook *user = malloc(sizeof(Addressbook)); // Allocate memory for user
    if (!user) 
    {
        printf("Memory allocation failed.\n");
        return failure;
    }
    if(Validation_Checking(argc,argv,user)==failure)
    {
        free(user);
        return failure;
    }  
    printf("-----------------------------------"BLUE"WELCOME"RESET"-------------------------------------\n\n");
    int choice=1;                            // inlitizing int varaible for option
    while(choice!=6)                                 // while loop for infinte time calling
    {
        printf(RED"\nAddress Book Menu:\n"RESET);
        printf(YELLOW"1. Add details\n2. Print all details\n3. Search details\n"RESET);
        printf(YELLOW"4. Edit details\n5. Delete details\n6. Exit\n"RESET);
        printf(BLUE"Enter your choice: "RESET);
        scanf("%d",&choice);                   // read the input for the user
        switch(choice)
        {
            case 1 : Adding_detial(user);     // function calling depend on choice
                    break;
            case 2 : print_detial(user);
                    break;
            case 3 : Search_detial(user);
                   break;
            case 4 : Edit_detial(user);
                     break;
            case 5 : Delete_detial(user);
                     break;    
            case 6 : printf(YELLOW"Exiting...\n"RESET);
                     printf(GREEN"Thank You!!!!\nHave a good day!!! \n"RESET);
                     break;
            default : printf(RED"Invalid Choice !!\n"RED);
                     break;
        }
    }
    free(user);
	remove("temp.csv");
    return success;
}

Status Validation_Checking(int argc, char *argv[], struct Addressbook *user)
{
    if (argc < 2)
    {
        fprintf(stderr, RED "Usage:" RESET " < File is Missing > <.csv File is Required>\n");
        return failure;
    }
    else if (argc >= 3)
    {
        fprintf(stderr, RED "ERROR :" RESET " <Too Many Files>\nUsage: < File is Missing > <.csv File is Required>\n");
        return failure;
    }
    else if (strstr(argv[1], ".csv"))
    {
        FILE *file_name = fopen(argv[1], "r");
        if (file_name == NULL)
        {
            printf(RED "ERROR :" RESET " <File is not Present>\n");
            printf(YELLOW "You have to continue with this name" RESET " " RED "%s" RESET " " YELLOW ". It will create a new Address book\n" RESET, argv[1]);
            char ch = ask_to_continue();
            if (ch == 'Y' || ch == 'y')
            {
                file_name = fopen(argv[1], "w");
                if (!file_name)
                {
                    perror("File creation failed");
                    return failure;
                }
                int count = 0;
                fprintf(file_name, "#%d#", count);
                fclose(file_name);

                user->file_name = strdup(argv[1]); // Allocate memory for user->file_name
                return success;
            }
            return failure;
        }
        else
        {
            user->file_name = strdup(argv[1]); // Allocate memory for user->file_name
            fclose(file_name);
        }
    }
    else
    {
        printf(YELLOW "You have to continue with this name" RESET " " RED "%s" RESET " " YELLOW ". It will create a new Address book\n" RESET, argv[1]);
        char ch = ask_to_continue();
        if (ch == 'Y' || ch == 'y')
        {
            strcat(argv[1],".csv");
            FILE *file_name = fopen(argv[1], "w");
            if (!file_name)
            {
                perror("File creation failed");
                return failure;
            }
            int count = 0;
            fprintf(file_name, "#%d#", count);
            fclose(file_name);

            user->file_name = strdup(argv[1]); // Allocate memory for user->file_name
            return success;
        }
        return failure;
    }
    return success;
}

char ask_to_continue() 
{
    char ch;
    do {
        printf(YELLOW"Do you want to continue? (Y/N): "RESET);
        scanf(" %c", &ch);
    } while (((ch != 'Y') && (ch != 'y')) && ((ch != 'N') && (ch != 'n')));
    return ch;
}

