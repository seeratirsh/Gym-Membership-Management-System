#ifndef GYMMANAGE_H
#define GYMMANAGE_H

#include <stdio.h>
#include <string.h>  //String manipulation
#include <ctype.h>   //Character validation.
#include <stdlib.h> // General utilities and conversions.
#include <time.h>  // Current date and time.


struct member{
    char memberID[15];
    char name[50];
    char phone[15];
    int age;
    char gender[10];
    char joiningDate[11];
};

/*A separate membership record allows you to 
maintain membership history.

status values represent:
- 1 = Active
- 0 = Expired
- 2 = Cancelled
*/
struct membership{
    char memberID[15];
    char planName[30];
    char startDate[11];
    char endDate[11];
    float amount;
    int duration;
    int status;
};

/*
This will help maintain:
- Payment history.
- Cash/UPI/card payments.
- Successful or pending.
- Total revenue reports.

paymentStatus:
1 = Paid successfully
0 = Not paid
*/
struct payment{
    char paymentID[15];
    char memberID[15];
    float amount;
    char paymentDate[11];
    char paymentMode[20];
    int paymentStatus;
};

struct MemberRecord{
    struct member members[100];
    int memberCount;

    struct membership memberships[200];
    int membershipCount;

    struct payment payments[500];
    int paymentCount;
};


int validate_member_id(struct MemberRecord *memberRecord, char *id);
void generate_member_id(struct MemberRecord *memberRecord, char *id);
int validate_phone_number(char * temp_phone);
void generate_joining_date(char *date);
void new_member_registration(struct MemberRecord *memberRecord);
void list_members(struct MemberRecord *memberRecord);
void search_members(struct MemberRecord *memberRecord);
void view_membership_plans(struct MemberRecord *memberRecord);
void assign_membership(struct MemberRecord *memberRecord);
void payment_record(struct MemberRecord *memberRecord);
void renew_membership(struct MemberRecord *memberRecord);
void generate_reports(struct MemberRecord *memberRecord);
void save_member_details(struct MemberRecord *memberRecord);
void load_members_from_file(struct MemberRecord *memberRecord);





#endif