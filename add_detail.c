#ifndef ADD_DETIAL
#define ADD_DETIAL

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <ctype.h>
#include"header.h"


Status copy(const char * file_name)                                                            // function execution copying the data
{
    FILE * fptr = fopen(file_name,"w");                                 // file opening
    FILE * temp = fopen("temp.csv","r");
    char ch;
    while((ch=fgetc(temp))!= EOF)                                    // copying the all charater by charater from one file to another till EOF 
        fputc(ch,fptr);
    fclose(fptr);                                                  // closing file
    fclose(temp);
    return success;
}


Status Adding_detial(Addressbook * user)                // function exeution
{
    user->name = malloc(100 * sizeof(char));   // Adjust size as needed
    user->mobile = malloc(15 * sizeof(char));
    user->email = malloc(50 * sizeof(char));
    user->address = malloc(100 * sizeof(char));
    system("clear");
    loading();
    FILE * fptr = fopen(user->file_name,"r");           // file opening in reading mode
    FILE * temp = fopen("temp.csv","w");               // file opening in writing mode

    fscanf(fptr,"#%d#",&count);                // counting the number form the file
    fprintf(temp,"#%d#",count+1);              // printing the count value in the temp file
    for(int i=0; i<count; i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^,],%[^\n]",user->name,user->mobile,user->email,user->address);                  // reading the data form the file to structure members
        fprintf(temp,"%s,%s,%s,%s",user->name,user->mobile,user->email,user->address);                              // printing the temp file
    }

    printf(BLUE"Enter the Name : "RESET);
    scanf(" %[^\n]",user->name);                                                               // read the input form the user
    printf(BLUE"Enter the Mobile No. : "RESET);
    scanf(" %[^\n]",user->mobile);
    while (!(is_valid_mobile(user->mobile)))
    {
        printf(RED"Invalid Mobile No...!!\nYou have Entered Alphabet or Special character or Extra Digits\n"RESET""BLUE"Pelase,Re-Enter the Mobile No. : "RESET);
        scanf(" %[^\n]",user->mobile);
    }
    printf(BLUE"Enter the Email Address : "RESET);
	scanf(" %[^\n]",user->email);
    while(!(is_valid_email(user->email)))
    {
        printf(RED"Invalid Email Address...!!\n"RESET""BLUE"Pelase,Re-Enter the Email Address : "RESET);
        scanf(" %[^\n]",user->email);
    }
    printf(BLUE"Enter the address : "RESET);
    scanf(" %[^\n]",user->address);
    fprintf(temp,"\n%s,%s,%s,%s\n",user->name,user->mobile,user->email,user->address);
    fclose(fptr);                                                                       // closing the file
    fclose(temp);
    copy(user->file_name);                                                                            // function calling to copy the data
    system("clear");
    loading();
    printf(GREEN"Data Succefully Added !!\n\n"RESET);
    free(user->name);
    free(user->mobile);
    free(user->email);
    free(user->address);
    return success;
}
#endif