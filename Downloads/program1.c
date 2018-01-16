/****************************
Name: Martina-Tawedrous
Email: mtawedro@mail.uoguelph.ca
Date: October 17 2016
Program: program1.c
****************************/

#include <stdio.h>

#include <time.h>

#include <stdlib.h>

int main(void)

{

srand(time(0));

int num1 = rand() % 111; // declares and intalizes a random number

int user= 0;

printf("Enter an int number between 0 and 111\n");

scanf("%d", &user);// reads in users input

while(user >111 ||  user<0)// omits error trap in case user types num out of
//range

{

printf("Oops! you havn't inputed a number between 0 and 111. Try again");

scanf("%d", &user);

}


for(int x = 0; x!= num1; x++) // loop continues until users num matches random
//num

{

if(user < num1 && user >=0)

{

printf("To low! Try again\n");


}

else if(user > num1 && user <=111)

{

printf("Too High! Try again\n");


}

else if(user == num1)

{

printf("Yay! You guessed the correct number\n");

break; //exits the loop right away

}

scanf("%d", &user); // keeps asking for user input if their  guess is wrong


}


return 0;


}