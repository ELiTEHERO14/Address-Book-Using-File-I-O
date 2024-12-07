#ifndef EDIT_DETIAL
#define EDIT_DETIAL

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <ctype.h>
#include"header.h"

Status Edit_detial(Addressbook * user)
{
    user->name = malloc(100 * sizeof(char));   // Adjust size as needed
    user->mobile = malloc(15 * sizeof(char));
    user->email = malloc(50 * sizeof(char));
    user->address = malloc(100 * sizeof(char));
    system("clear");
    loading();
    int choice;
    printf(YELLOW"What do you want to Change\n"RESET""BLUE"1.Name\n2.Moblie Number\n3.Email Address\n4.Address\nEnter the choice :"RESET);
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 :
        {
            char * str=malloc(30*sizeof(char));
            printf(BLUE"Enter the Name you want to change : "RESET);
            scanf(" %[^\n]",str);
            FILE * fptr = fopen(user->file_name,"r");
            FILE * temp = fopen("temp.csv","w"); 
            fscanf(fptr,"#%d#\n",&count);
            fprintf(temp,"#%d#\n",count);
            int flag=0;
            for(int i=0;i<count;i++)
            {
                fscanf(fptr,"%[^,],%[^,],%[^,],%[^\n]\n",user->name,user->mobile,user->email,user->address);
                if((strcmp(user->name,str))==0)
                {
                    print(user,i);
                    printf(BLUE"Enter the Changed Name : "RESET);
                    scanf(" %[^\n]",user->name);
                    fprintf(temp,"%s,%s,%s,%s\n",user->name,user->mobile,user->email,user->address);
                    system("clear");
                    loading();
                    printf(GREEN"Succefully Changed!!\n\n"RESET);
                    print(user,i);
                    flag=1;                                                              // for indication data found or not
                }
                else
                    fprintf(temp,"%s,%s,%s,%s\n",user->name,user->mobile,user->email,user->address);
            }
            fclose(fptr);
            fclose(temp);
            free(str);
            if(flag)
                copy(user->file_name);
            else 
                printf(RED"No Data Found !!\n\n"RESET);
            break;
        }

        case 2 :
        {
            char * str=malloc(15*sizeof(char));
            printf(BLUE"Enter the Mobile Number you want to change : "RESET);
            scanf(" %[^\n]",str);
            while (!(is_valid_mobile(str)))
            {
                printf(RED"Invalid Mobile No...!!\nYou have Entered Alphabet or Special character or Extra Digits\n"RESET""BLUE"Pelase,Re-Enter the Mobile No. : "RESET);
                scanf(" %[^\n]",str);
            }        
            FILE * fptr = fopen(user->file_name,"r");
            FILE * temp = fopen("temp.csv","w"); 
            fscanf(fptr,"#%d#\n",&count);
            fprintf(temp,"#%d#\n",count);
            int flag=0;
            for(int i=0;i<count;i++)
            {
                fscanf(fptr,"%[^,],%[^,],%[^,],%[^\n]\n",user->name,user->mobile,user->email,user->address);
                if((strcmp(user->mobile,str))==0)
                {
                    print(user,i);
                    printf(BLUE"Enter the Changed Moblie_Number : "RESET);
                    scanf(" %[^\n]",user->mobile);
                    while (!(is_valid_mobile(user->mobile)))
                    {
                        printf(RED"Invalid Mobile No...!!\nYou have Entered Alphabet or Special character or Extra Digits\n"RESET""BLUE"Pelase,Re-Enter the Mobile No. : "RESET);
                        scanf(" %[^\n]",user->mobile);
                    }
                    fprintf(temp,"%s,%s,%s,%s\n",user->name,user->mobile,user->email,user->address);
                    system("clear");
                    loading();
                    printf(GREEN"Succefully Changed!!\n\n"RESET);
                    print(user,i);
                    flag=1;
                }
                else
                    fprintf(temp,"%s,%s,%s,%s\n",user->name,user->mobile,user->email,user->address);
            }
            fclose(fptr);
            fclose(temp);
            free(str);
            if(flag)
                copy(user->file_name);
            else 
                printf(RED"No Data Found !!\n\n"RESET);
            break;
        }

        case 3 :
        {
            char * str= malloc(30 * sizeof(char));
            printf(BLUE"Enter the Email ID you want to change : "RESET);
            scanf(" %[^\n]",str);
            while(!(is_valid_email(str)))
            {
                printf(RED"Invalid Email Address...!!\n"RESET""BLUE"Pelase,Re-Enter the Email Address : "RESET);
                scanf(" %[^\n]",str);
            }
            FILE * fptr = fopen(user->file_name,"r");
            FILE * temp = fopen("temp.csv","w"); 
            fscanf(fptr,"#%d#\n",&count);
            fprintf(temp,"#%d#\n",count);
            int flag=0;
            for(int i=0;i<count;i++)
            {
                fscanf(fptr,"%[^,],%[^,],%[^,],%[^\n]\n",user->name,user->mobile,user->email,user->address);
                if((strcmp(user->email,str))==0)
                {
                    print(user,i);
                    printf(BLUE"Enter the Changed Email ID : "RESET);
                    scanf(" %[^\n]",user->email);
                    while(!(is_valid_email(user->email)))
                    {
                        printf(RED"Invalid Email Address...!!\n"RESET""BLUE"Pelase,Re-Enter the Email Address : "RESET);
                        scanf(" %[^\n]",user->email);
                    }
                    fprintf(temp,"%s,%s,%s,%s\n",user->name,user->mobile,user->email,user->address);
                    system("clear");
                    loading();
                    printf(GREEN"Succefully Changed!!\n\n"RESET);
                    print(user,i);
                    flag=1;
                }
                else
                    fprintf(temp,"%s,%s,%s,%s\n",user->name,user->mobile,user->email,user->address);
            }
            fclose(fptr);
            fclose(temp);
            free(str);
            if(flag)
                copy(user->file_name);
            else 
                printf(RED"No Data Found !!\n\n"RESET);
            break;
        }
        case 4 :
        {
            char * str= malloc(30*sizeof(char));
            printf(BLUE"Enter the Address you want to change : "RESET);
            scanf(" %[^\n]",str);
            FILE * fptr = fopen(user->file_name,"r");
            FILE * temp = fopen("temp.csv","w"); 
            fscanf(fptr,"#%d#\n",&count);
            fprintf(temp,"#%d#\n",count);
            int flag=0;
            for(int i=0;i<count;i++)
            {
                fscanf(fptr,"%[^,],%[^,],%[^,],%[^\n]\n",user->name,user->mobile,user->email,user->address);
                if((strcmp(user->address,str))==0)
                {
                    print(user,i);
                    printf(BLUE"Enter the Changed Address : "RESET);
                    scanf(" %[^\n]",user->address);
                    fprintf(temp,"%s,%s,%s,%s\n",user->name,user->mobile,user->email,user->address);
                    system("clear");
                    loading();
                    printf(GREEN"Succefully Changed!!\n\n"RESET);
                    print(user,i);
                    flag=1;
                }
                else
                    fprintf(temp,"%s,%s,%s,%s\n",user->name,user->mobile,user->email,user->address);
            }
            fclose(fptr);
            fclose(temp);
            free(str);
            if(flag)
                copy(user->file_name);
            else 
                printf(RED"No Data Found !!\n\n"RESET);
            break;
        }

        default : printf(RED"Invalid Choice!!\n\n"RESET);
    }
    free(user->name);
    free(user->mobile);
    free(user->email);
    free(user->address);
    return success;
}
#endif