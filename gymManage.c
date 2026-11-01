#include "gymManage.h"

/*
Algorithm: Automatic Member ID Generation
To automatically generate a unique Member ID in the format GYM001, GYM002, GYM003, etc.
-Pass the address of the MemberRecord structure and a character array to store the generated ID.
-. Access the current memberCount from the MemberRecord structure.
-. Increment memberCount by 1 and store the result in a variable called nextID.
-. Use sprintf() to generate the Member ID in the format GYM001.
-. Store the generated ID in the character array.
-. Return to the registration function.
-. Display the generated Member ID.
*/

int validate_member_id(struct MemberRecord *memberRecord, char *id)
{
    /* return -1 when id already exists
    return 0 when unique id is found.
    */
    int i = 0;
    for(int i = 0; i < memberRecord->memberCount; i++)
    {
        if(strcmp(memberRecord->members[i].memberID, id) == 0)
        {
            return -1; 
        }
    }

    return 0;
}

void generate_member_id(struct MemberRecord *memberRecord, char *id)
{
    int nextID = memberRecord->memberCount + 1;
    sprintf(id, "GYM%03d", nextID);

    while(validate_member_id(memberRecord, id) != 0)
    {
        nextID++;
        sprintf(id, "GYM%03d", nextID);
    }

    /*sprintf- stands for String Print Formatted.
     stores formatted output inside a character array.
     */
}

int validate_phone_number(char * temp_phone)
{
    /*
    return -1: invalid
    return 0: valid
    */
    int len = strlen(temp_phone);

    if(len <= 6 || len >= 15)
    {
        printf("Invalid phone number. Try again.\n");
        return -1;
    }

    if(temp_phone[0] < '6' || temp_phone[0] > '9')
    {
        printf("Invalid phone number. Try again.\n");
        return -1;
    }

    for(int i = 0; i < len; i++)
    {
        if(!isdigit(temp_phone[i]))
        {
            return -1;
        }
    }

    return 0;
}

void generate_joining_date(char *date)
{
    time_t current_time;
    struct tm *local_time;

    time(&current_time);

    local_time = localtime(&current_time);

    sprintf(date, "%02d-%02d-%04d",
                 local_time->tm_mday,
                 local_time->tm_mon + 1,
                 local_time->tm_year + 1900);
}

void new_member_registration(struct MemberRecord *memberRecord)
{
    char temp_phone[15];
    int i = memberRecord->memberCount;

    /* Generate Member ID by calling the function */
    generate_member_id(memberRecord, memberRecord->members[i].memberID);

    /* Display Member ID */
    printf("Generated Member ID: %s\n", memberRecord->members[i].memberID);
    printf("💪--------------------------💪\n");
    /* Display joining date, by calling
     generate_joining_date function */
    generate_joining_date(memberRecord->members[i].joiningDate);
    printf("Registration Date: %s\n", memberRecord->members[i].joiningDate);
    printf("💪--------------------------💪\n");
    /*Reading member's name*/
    printf("Enter your name:\n");
    scanf(" %49[^\n]", memberRecord->members[i].name);
    printf("💪--------------------------💪\n");
    /*Reading member's age*/
    printf("Enter your age:\n");
    scanf(" %d", &memberRecord->members[i].age);
    printf("💪--------------------------💪\n");
    /*Reading member's gender*/
    printf("What is your gender?:\na)Male\nb)Female\nc)Custom\n");
    scanf(" %9s", memberRecord->members[i].gender);
    printf("💪--------------------------💪\n");
    /*Reading member's phone number
    and validating it*/
    do
    {
        printf("Enter your contact number:\n");
        scanf(" %14[^\n]", temp_phone);
    } while (validate_phone_number(temp_phone) != 0);
    strcpy(memberRecord->members[i].phone, temp_phone);

    memberRecord->memberCount++;

}

void list_members(struct MemberRecord *memberRecord)
{
    printf("\n👥---------------------------💪\n");
    printf("All registered members:\n");

    for(int i = 0; i < memberRecord->memberCount; i++)
    {
        printf("💪---------------------------💪\n");
        printf("Member ID: %s\n", memberRecord->members[i].memberID);
        printf("Joining date: %s\n", memberRecord->members[i].joiningDate);
        printf("Name: %s\n", memberRecord->members[i].name);
        printf("Age: %d\n", memberRecord->members[i].age);
        printf("Gender: %s\n", memberRecord->members[i].gender);
        printf("Contact number: %s\n", memberRecord->members[i].phone);
        printf("💪---------------------------💪");
    }

}

void search_members(struct MemberRecord *memberRecord)
{

}

void view_membership_plans(struct MemberRecord *memberRecord)
{

}

void assign_membership(struct MemberRecord *memberRecord)
{

}

void payment_record(struct MemberRecord *memberRecord)
{

}

void renew_membership(struct MemberRecord *memberRecord)
{

}

void generate_reports(struct MemberRecord *memberRecord)
{
}

/*
Create three seperate .csv files to store the data permanently
create three seperate functions to perform write operation
-it will make data handling easy.
*/
/*void save_members_rec(struct MemberRecord *memberRecord)
{
    FILE *fptr = fopen("memberRec.csv", "w"); 

    if(fptr == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    for(int i = 0; i < memberRecord->memberCount; i++)
    {
        fprintf(fptr, "%s,%s,%s,%d,%s,%s\n", memberRecord->members[i].memberID,
                                                  memberRecord->members[i].name,
                                                  memberRecord->members[i].phone,
                                                  memberRecord->members[i].age,
                                                  memberRecord->members[i].gender,
                                                  memberRecord->members[i].joiningDate);
    }

    fclose(fptr);

}

void save_memberships_rec(struct MemberRecord *memberRecord)
{
    FILE *fptr = fopen("membershipRec.csv", "w");

    if(fptr == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    for(int i = 0; i < memberRecord->membershipCount; i++)
    {
        fprintf(fptr, "%s, %s, %g, %d, %s, %s, %d\n", memberRecord->memberships[i].memberID,
                                                      memberRecord->memberships[i].planName,
                                                      memberRecord->memberships[i].amount,
                                                      memberRecord->memberships[i].duration,
                                                      memberRecord->memberships[i].startDate,
                                                      memberRecord->memberships[i].endDate,
                                                      memberRecord->memberships[i].status);

    }

    fclose(fptr);
}

void save_payments_rec(struct MemberRecord *memberRecord)
{
    FILE *fptr = fopen("paymentRec.csv", "w");

    if(fptr == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    for(int i = 0; i < memberRecord->paymentCount; i++)
    {
        fprintf(fptr, "%s, %s, %f, %s, %s, %d\n", memberRecord->payments[i].paymentID,
                                                  memberRecord->payments[i].memberID,
                                                  memberRecord->payments[i].amount,
                                                  memberRecord->payments[i].paymentDate,
                                                  memberRecord->payments[i].paymentMode,
                                                  memberRecord->payments[i].paymentStatus);                                        
           
    }

    fclose(fptr);
}

void load_members_from_file(struct MemberRecord *memberRecord)
{
    FILE* fptr = fopen("memberRec.csv", "r");

    if(fptr == NULL)
    {
        printf("File do not exist\n");
        return;
    }

    int i = memberRecord->memberCount;

     while(fscanf(fptr, "%[^,],%[^,],%[^,],%d,%[^,],%[^\n]",
                 memberRecord->members[i].memberID,
                 memberRecord->members[i].name,
                 memberRecord->members[i].phone,
                 &memberRecord->members[i].age,
                 memberRecord->members[i].gender,
                 memberRecord->members[i].joiningDate) == 6)
    {
        memberRecord->memberCount++;
        i++;
    }

    fclose(fptr);

}

void load_memberships_from_file(struct MemberRecord *memberRecord)
{
     FILE* fptr = fopen("membershipRec.csv", "r");

     if(fptr == NULL)
     {
        printf("File do not exist\n");
        return;
     }

    int i = memberRecord->membershipCount;

     while(fscanf(fptr, "%14[^,],%29[^,],%lf,%d,%10[^,],%10[^,],%d",
                 memberRecord->memberships[i].memberID,
                 memberRecord->memberships[i].planName,
                 memberRecord->memberships[i].amount,
                 memberRecord->memberships[i].duration,
                 memberRecord->memberships[i].startDate,
                 memberRecord->memberships[i].endDate,
                 memberRecord->memberships[i].status) == 7)
    {
        memberRecord->memberCount++;
        i++;
    }

    fclose(fptr);

}

void load_payments_from_file(struct MemberRecord *memberRecord)
{
    FILE* fptr = fopen("paymentRec.csv", "r");

    if(fptr == NULL)
    {
        printf("File do not exist\n");
        return;
    }

    int i = memberRecord->paymentCount;

    while(fscanf(fptr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                 memberRecord->payments[i].paymentID,
                 memberRecord->payments[i].memberID,
                 memberRecord->payments[i].amount,
                 memberRecord->payments[i].paymentDate,
                 memberRecord->payments[i].paymentMode,
                 memberRecord->payments[i].paymentStatus) == 6)
    {
        memberRecord->paymentCount++;
        i++;
    }

    fclose(fptr);

}
    */