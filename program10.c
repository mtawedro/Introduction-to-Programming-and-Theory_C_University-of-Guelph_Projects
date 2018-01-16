/*****************************************************************
Name: Martina Tawedrous
Program: program10.c
Email: mtawedro@mail.uoguelph.ca
Student Num: 0977473
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>

//prints array until reaches a double duplicate of a letter
void printArray(int length, char toPrint[])
{

int count = 0;

//prints array
for(int i = 0; i<length; i++)
{

     printf("%c", toPrint[i]);

        //checks for the occurance of the same letter and stores it into var
        if(toPrint[i] == toPrint[i+1])
        {
          count= i+2;

        }

}
//prints new array until reaches the last ocuurace of where a chaarcter was found
for (int x = 0; x<count; x++)
{

  printf("%c", toPrint[x]);

}


}


//asks users to input a char to be stored in each elemnt of teh array
void inputValues(int arrayLen, char arrayToFill[])
{

char elem = ' ';

 //stores each char user input into array
 for(int i = 0; i < arrayLen; i++)
  {

    printf("enter in a char");

    scanf("%c ", &elem);

   arrayToFill[i] = elem;


  }


//calls function 2 to print array
 printArray(arrayLen, arrayToFill);


}



int main (void)
{

char arrayToFill[200]= " ";

int len= 0;

printf("How many elements would you lke in the array\n");

scanf("%d", &len);

inputValues(len, arrayToFill);


return 0;

}