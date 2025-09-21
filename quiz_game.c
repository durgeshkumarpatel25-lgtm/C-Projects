// 10 MCQ Quiz Game
#include<stdio.h>
int main()
{
char a,b,c,d,e,f,g,h,i,j,k;
int score=0;
char roll[10],course[10],name[30],mobile[13],clg[30],address[50];
printf("Enter your roll number: \n");
scanf("%s",roll);
printf("Enter your course: \n");
scanf("%s",course);
printf("Enter your name: \n");
scanf("%s",name);
printf("Enter your mobile number: \n");
scanf("%s",mobile);
printf("Enter your college name: \n");
scanf("%s",clg);
printf("Enter your address \n");
scanf("%s",address);

printf("10 MCQ Questions choose optin a to d\n");
printf("Q1 Which of these is an input device: \n");
printf("a  Mouse   b CPU   c  Moniter     d   Printer\n");
scanf(" %c",&a);
if(a=='a')
{
printf("Right answer\n");
score++;
}
else
{
printf("Wrong answer a is correct answer\n");
}
printf("Q2 What is an output device: \n");
printf("a Moniter  b  CPU     c  Keyboard   d  UPS\n");
scanf(" %c",&b);
if(b=='a')
{
printf("\n Right answer\n");
score++;
}
else
{
printf("Wrong answer a is right answer\n");
}
printf("Q3 which of this a hardware device:\n");
printf("a moniter   b  facebook    c   insta   d  twiter\n");
scanf(" %c",&c);
if(c=='a')
{
printf("Right answer\n");
score++;
}
else
{
printf("Wrong The right answer is moniter\n");
}
printf("Q4 Brain of computer is: \n");
printf("a  Mouse   b CPU   c  Moniter     d   Printer\n");
scanf(" %c",&d);
if(d=='b')
{
printf("Right answer\n");
score++;
}
else
{
printf("Wrong answer b is correct answer\n");
}
printf("Q5 sortest network is \n");
printf("a LAN  b  MAN     c  WAN   d  PAN\n");
scanf(" %c",&e);
if(e=='d')
{
printf("\n Right answer\n");
score++;
}
else
{
printf("Wrong answer d is right answer\n");
}
printf("Q6 Temporary memory is:\n");
printf("a RAM   b  ROM   c   HDD  d  NON \n");
scanf(" %c",&f);
if(f=='a')
{
printf("Right answer\n");
score++;
}
else
{
printf("Wrong The right answer is a\n");
}
printf("Q7 How many types of ram \n");
printf("a  1   b 2   c  3     d   4\n");
scanf(" %c",&g);
if(g=='b')
{
printf("Right answer\n");
score++;
}
else
{
printf("Wrong answer b is correct answer\n");
}
printf("Q8 How many types of ROM \n");
printf("a 1  b  2     c  3   d  4\n");
scanf(" %c",&h);
if(h=='c')
{
printf("\n Right answer\n");
score++;
}
else
{
printf("Wrong answer c is right answer\n");
}
printf("Q9 which of fastest memory in a computer:\n");
printf("a Cache memory   b  HDD    c   SSD   d  pen drive\n");
scanf(" %c",&i);
if(i=='a')
{
printf("Right answer\n");
score++;
}
else
{
printf("Wrong The right answer is a\n");
}
printf("Q10 what is projector\n");
printf("a output device   b  input device   c  memory   d  non\n");
scanf(" %c",&j);
if(j=='a')
{
printf("Right answer\n");
score++;
}
else
{
printf("\n\n Wrong answer a is  right answer\n");
}
printf("\n Name: %s",name);
printf("\n Roll No: %s",roll);
printf("\n Course: %s",course);
printf("\n Address: %s",address);
printf("\n Mobile no: %s",mobile);
printf("\n College: %s",clg);
printf("\n \n Your total score is %d out of 10",score);
printf("\n Right answer is: %d",score);
printf("\n Wrong answer is: %d",10-score);
return 0;
}