#include "gymManage.h"

int main()
{
    int choice;
    struct MemberRecord memberRecord = {0};

    /* Load previously saved Gym members*/
	// load_members_from_file(&memberRecord);
    // load_memberships_from_file(&memberRecord);
    // load_payments_from_file(&memberRecord);
    
    do
    {
        printf("\n💪------------WELCOME TO OUR GYM---------------💪");
        printf("\nGym Membership Main Menu: \n");
        printf("1. Register New Member👤\n");
        printf("2. View All Members📃📋\n");
        printf("3. Search Member🔍\n");
        printf("4. View Membership Plans🤩\n");
        printf("5. Assign Membership\n");
        printf("6. Record Payment\n");
        printf("7. Renew Membership\n");
        printf("8. Generate Reports\n");
        printf("9. Save & Exit\n");
        printf("💪----------------------------------------------💪\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            new_member_registration(&memberRecord);
            break;
            case 2:
            list_members(&memberRecord);
            break;
            case 3:
            search_members(&memberRecord);
            break;
            case 4:
            view_membership_plans(&memberRecord);
            break;
            case 5:
            assign_membership(&memberRecord);
            break;
            case 6:
            payment_record(&memberRecord);
            break;
            case 7:
            renew_membership(&memberRecord);
            break;
            case 8:
            generate_reports(&memberRecord);
            break;
            case 9:
            // save_members_rec(&memberRecord);
            // save_memberships_rec(&memberRecord);
            // save_payments_rec(&memberRecord);
            printf("Saving and Exiting...\n");
            break;
            default:
            printf("Invalid choice. Please try again.\n");
        }   
    } while(choice != 9);

    return 0;
}