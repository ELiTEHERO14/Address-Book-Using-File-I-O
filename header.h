#ifndef HEADER_H
#define HEADER_H


#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"
#define YELLOW "\033[1;33m"


int count;                                    // created global variable



typedef enum Status
{
    failure,
    success
}Status;


typedef struct Addressbook 
{
    char *name;
    char *mobile;
    char *email;
    char *address;
    char *file_name; // File name from CLA
} Addressbook;





Status Adding_detial(Addressbook * user);       // function prototype
Status print_detial(Addressbook * user );
Status Search_detial(Addressbook * user );
Status Edit_detial(Addressbook * user);
Status Delete_detial(Addressbook * user);
Status print(Addressbook * user,int );
Status copy(const char * file_name);
Status Validation_Checking(int argc,char * argv[],Addressbook * user );
char ask_to_continue();
Status is_valid_mobile(const char *mobile);
Status is_valid_email(const char *email);
void loading(void);


Status is_valid_mobile(const char *mobile) 
{
    if (strlen(mobile) != 10) 
        return failure;
    for (int i = 0; mobile[i]; i++) 
    {
        if (!isdigit(mobile[i])) 
            return failure;
    }
    return success;
}

Status is_valid_email(const char *email)
{
    // Check for '@'
    char *at_sign = strchr(email, '@');
    if (!at_sign || at_sign == email || at_sign[1] == '\0')
    {
        return failure;                           // No '@' or it's at the start or end
    }

    // Ensure there's at least one character after '@'
    if (at_sign[1] == '.')
    {
        return failure; // '.' immediately follows '@'
    }

    // Check that the domain contains a '.'
    char *dot = strchr(at_sign + 1, '.');
    if (!dot || dot[1] == '\0')
    {
        return failure; // No '.' in the domain or it's at the end
    }

    // Ensure at least one character exists between '@' and '.'
    if (dot - at_sign <= 1)
    {
        return failure; // No characters between '@' and '.'
    }

    // Optional: Ensure the email ends with ".com"
    if (strcmp(dot, ".com") != 0)
    {
        return failure; // Not a '.com' domain
    }

    return success;
}

void loading(void)
{
    int j=0;
    for(int k=0; k<3;k++)
    {   
        for(int i=0;i<4;i++)
        {
            printf(GREEN"\rloading"RESET);
            for(j=0;j<i;j++)
                printf(GREEN"."RESET);
            for(int z=j;z<=3;z++)
                printf(" ");
            fflush(stdout);
            usleep(500000);
        }
	}
    printf("\n");
    return;
}

#endif