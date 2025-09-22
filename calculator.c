#include<stdio.h>
#include<math.h>

double division(double, double);
int modulus(int, int);
void print_Menu();
int main()
{
    int choice;
    double first, second, result;
    while(1){
        print_Menu();
   
    scanf("%d",&choice);
    if(choice==7){
        break;
    }
if(choice < 1 || choice > 7)
{
    fprintf(stderr, "Invalid Menu choice.");
    continue;
}

    printf("\n Plesr Enter the first number:  ");
    scanf("%lf",&first);

    printf(" Now enter the second number:  ");
    scanf("%lf",&second);

    switch (choice)
    {
        case 1: //Add
        result=first+second;
            break;
        case 2:  //Subtract
        result=first-second;
            break;
        case 3:  //Multiply
        result=first*second;
            break;
        case 4:  //divide
        result=division(first,second);
       break;
        case 5:  //Moduls
        result=modulus(first,second);

            break;
        case 6:  //Power
        result=pow(first,second);
            break;
    }
if(!isnan(result))
    {
printf("\n Result operation is: %.2f ",result);
    }    
};


    return 0;
}

double division(double a,double b)
{
if(b==0)
{
    fprintf(stderr, "Incalid Argument for Division \n");
return NAN;
}
else{
    return a/b;
}
}

int modulus (int a,int b)
{
    if(b==0)
    {
        fprintf(stderr, "Invalid Argument for modulus ");
        return 0;
    }
    else{
        return a % b;
    }
}

void print_Menu()
{
    printf("\n\n---------------------------------------------------");
    printf("\n Welcome to Simple Calculator ");
    printf("\n \n Choose one of the following options: ");
    printf("\n1. Add");
    printf("\n2. Subtract"); 
    printf("\n3. Multiply");
    printf("\n4. Divide");
    printf("\n5. Moduls");
    printf("\n6. Power");
    printf("\n7. Exit");

    printf("\n \n Now enter your choice: ");
};