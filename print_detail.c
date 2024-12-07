#ifndef PRINT_DETIAL
#define PRINT_DETIAL

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <ctype.h>
#include"header.h"

Status print(Addressbook * user,int i)                                  // function exeution 
{
    printf("-----------------------------"YELLOW"Contact"RESET" %d-----------------------------------------\n",i+1);                         // print the data on screen
    printf(""BLUE"Name -"RESET" %s\n"BLUE"Mobile_Number -"RESET" %s\n"BLUE"Email_ID -"RESET" %s\n"BLUE"Address -"RESET" %s\n",user->name,user->mobile,user->email,user->address);
    return success;
}

Status print_detial(Addressbook * user)                       // function execution
{
    user->name = malloc(100 * sizeof(char));               // Adjust size as needed
    user->mobile = malloc(15 * sizeof(char));
    user->email = malloc(50 * sizeof(char));
    user->address = malloc(100 * sizeof(char));
    system("clear");
    loading();
    FILE * fptr = fopen(user->file_name,"r");                          //file opening
    fscanf(fptr,"#%d#\n",&count);
    if(count==0)
    {
        printf(RED"No Recored is present\n"RESET);
    }
    else
    {
        for(int i=0; i<count; i++)
        {
            fscanf(fptr,"%[^,],%[^,],%[^,],%[^\n]\n",user->name,user->mobile,user->email,user->address);
            print(user,i);                                                                                 //function calling to print the data on screen
        }
    }
    fclose(fptr);
    free(user->name);
    free(user->mobile);
    free(user->email);
    free(user->address);
    return success;
}
#endif