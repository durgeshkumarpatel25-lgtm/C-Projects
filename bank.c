#include<stdio.h>
#include<string.h>

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

const char* ACCOUNT_FILE="Account.dat";

typedef struct 
{
    char name[50];
    int acc_no;
    float balance;
}Account;




int main()
{
    while(1)
    {
        int choice;
        printf("\n\n*** Bank Management System ***");
        printf("\n1. Create Account ");
        printf("\n2. Deposit Money ");
        printf("\n3. Withdraw Money ");
        printf("\n4. Check Balance ");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
        create_account();
            break;
        case 2:
        deposit_money();
            break;  
        case 3:
        withdraw_money();
            break;
        case 4: 
        check_balance();
            break;
        case 5:
        printf("\n Closing the bank, thank for visit!");
        return 0;
            break;

        default:
        printf("Invalid Choice!");
            break;
        }
        
    }
}

void create_account()
{
Account acc;

FILE *file = fopen(ACCOUNT_FILE, "ab+");
if(file==NULL)
{
    printf("\nUnable to open file");
    return;
}

char c;
do{
    c=getchar();
}
while(c!='\n' && c!=EOF);

printf("\n Enter your name: ");
fgets(acc.name, sizeof(acc.name), stdin);
strcspn(acc.name,"\n");
int ind=strcspn(acc.name,"\n");
acc.name[ind]='\0';
printf("Enter your account number: ");
scanf("%d",&acc.acc_no);
acc.balance=0;

fwrite(&acc, sizeof(acc), 1, file);
fclose(file);
printf("\nAccount created successfully!");

}

void deposit_money()
{
FILE *file = fopen(ACCOUNT_FILE,"rb+");
    if(file==NULL)
{
    printf("\nUnable to open file");
    return;
}
int acc_no;
float money;
Account acc_r;
printf("\n Enter your account no. ");
scanf("%d",&acc_no);
printf("\n Enter the amount to deposit: ");
scanf("%f",&money);

while (fread(&acc_r, sizeof(acc_r), 1, file))
{
    if(acc_r.acc_no==acc_no)
    {
        acc_r.balance += money;
        fseek(file, -sizeof(acc_r), SEEK_CUR);
        fwrite(&acc_r, sizeof(acc_r), 1, file);
        fclose(file);
        printf("Successfully deposited Rs. %.2f New Balance is Rs. %.2f", money, acc_r.balance);
        return;

    }
}

fclose(file);
printf("\n Money could not be deposited as the Account no. %d this was not found in records.",acc_no);

}


void withdraw_money()
{
FILE *file=fopen(ACCOUNT_FILE, "rb+");
if(file==NULL)
{
    printf("\nUnable to open file");
    return;
}
int acc_no;
float money;
Account acc_r;
printf("\n Enter your account number: ");
scanf("%d",&acc_no);
printf("\n Enter the amount you wish to withdraw: ");
scanf("%f",&money);

while (fread(&acc_r, sizeof(acc_r), 1, file))
{
    if(acc_r.acc_no==acc_no)
    {
        if(acc_r.balance>=money)
        {
            acc_r.balance-=money;
            fseek(file, -sizeof(acc_r), SEEK_CUR);
            fwrite(&acc_r, sizeof(acc_r), 1, file);
           printf("\n Successfully withdrawn Rs. %.2f Remaining balance is Rs. %.2f", money,acc_r.balance);

        }
        else
        {
            printf("\n Insufficient balance! ");
        }
        fclose(file);
        return;
    }
}
printf("\n Money could not be withdrawn as the Account no. %d this was not found in records.",acc_no);
}

void check_balance()
{
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if(file==NULL)
{
    printf("\nUnable to open file");
    return;
}
int acc_no;
Account acc_read;
printf("Enter your account number: ");
scanf("%d",&acc_no);

while(fread(&acc_read, sizeof(acc_read), 1, file))
{
    if(acc_read.acc_no==acc_no)
    {
        printf("\nYour account balance is Rs. %.2f",acc_read.balance);

    fclose(file);
    return;
    }
}
fclose(file);
printf("\n Account No: %d was not found.\n",acc_no);
}