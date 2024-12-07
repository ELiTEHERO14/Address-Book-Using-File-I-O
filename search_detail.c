#ifndef SEARCH_DETIAL
#define SEARCH_DETIAL

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <ctype.h>
#include"header.h"

Status Search_detial(Addressbook * user)                                       // function excetion
{
    short flag=1;
    user->name = malloc(100 * sizeof(char));   // Adjust size as needed
    user->mobile = malloc(15 * sizeof(char));
    user->email = malloc(50 * sizeof(char));
    user->address = malloc(100 * sizeof(char));
    system("clear");
    loading();
    char *str=(char *)malloc(15*sizeof(char));                                                               // taking 1 str to stored a data and compare
    printf(BLUE"Enter the Mobile No want to search : "RESET);
    scanf(" %[^\n]",str);
    while (!(is_valid_mobile(str)))
    {
        printf(RED"Invalid Mobile No...!!\nYou have Entered Alphabet or Special character or Extra Digits\n"RESET""BLUE"Pelase,Re-Enter the Mobile No. : "RESET);
        scanf(" %[^\n]",str);
    }
    FILE * fptr=fopen(user->file_name,"r");
    fscanf(fptr,"#%d#\n",&count);
    for(int i=0; i<count; i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^,],%[^\n]\n",user->name,user->mobile,user->email,user->address);
        if(strcmp(user->mobile,str)==0)                                            // compare
        {
            print(user,i);                                                       // printing data on screen
            flag=0;
        }
    }
    if(flag)
        printf(RED"Invalid Search !!\nData not Found!!\n\n"RESET);
    fclose(fptr);
    free(user->name);
    free(user->mobile);
    free(user->email);
    free(user->address);
    free(str);
    return success;
}
#endif