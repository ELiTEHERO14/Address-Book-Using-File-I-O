#ifndef DEL_DETIAL
#define DEL_DETIAL


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <ctype.h>
#include"header.h"

Status Delete_detial(Addressbook * user)
{
    user->name = malloc(100 * sizeof(char));   // Adjust size as needed
    user->mobile = malloc(15 * sizeof(char));
    user->email = malloc(50 * sizeof(char));
    user->address = malloc(100 * sizeof(char));
    system("clear");
    loading();
    char * str= malloc(15*sizeof(char));
    printf(BLUE"Enter the Mobile No want to Delete Contact : "RESET);
    scanf(" %[^\n]",str);
    while (!(is_valid_mobile(str)))
    {
        printf(RED"Invalid Mobile No...!!\nYou have Entered Alphabet or Special character or Extra Digits\n"RESET""BLUE"Pelase,Re-Enter the Mobile No. : "RESET);
        scanf(" %[^\n]",str);
    }
    FILE * fptr=fopen(user->file_name,"r");
    FILE * temp = fopen("temp.csv","w"); 
    fscanf(fptr,"#%d#\n",&count);
    int flag=0;
    int flag1=0;
    for(int i=0; i<count; i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^,],%[^\n]\n",user->name,user->mobile,user->email,user->address);
        if(strcmp(user->mobile,str)==0)
        {
            print(user,i);
            while(1)
            {
                printf(YELLOW"You Want to delete this Contact (Y/n): "RESET);                             // asking quetion you want to delete a data or not
                char ch;
                scanf(" %c",&ch);
                if(ch=='Y'||ch=='y')
                {
                    system("clear");
                    loading();
                    printf(GREEN"Succefully Deleted!!\n\n"RESET);
                    fprintf(temp,"#%d#\n",count-1);
                    flag=1;
                    break;
                }
                else if(ch=='N'||ch=='n')
                {
                    flag1=1;                                                                 // indication  
                    printf(YELLOW"Data is Not Delete !!\n\n"RESET);
                    break;
                }
                else
                    printf(RED"Appropriate Command !!\nPlease Enter again\n\n"RESET);
            }
        }
        else
            fprintf(temp,"%s,%s,%s,%s\n",user->name,user->mobile,user->email,user->address);
    }
    fclose(fptr);
    fclose(temp);
    free(str);
    if(flag)
        copy(user->file_name);
    else if(flag1!=1) 
        printf(RED"No Data is Found!!\n\n"RESET);

    free(user->name);
    free(user->mobile);
    free(user->email);
    free(user->address);    
    return success;
}

#endif