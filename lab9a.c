/*************************
Name: Martina Tawedrous
Program: lab9a.c
Email: mtawedro@mail.uoguelph.ca
TA: Dylan
Student Num: 0977473
***************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define ROWS 3
#define COLS 70


/****************
This function uses fgets to get up to 3 lines of text from the user.  It prompts the user for the next line
and if the user does not want to enter another line the user simply hits enter.  
The user may enter 0, 1, 2 or 3 lines of text.

When this function exits,  the lines of text are copied into the stringArray parameter.  
The hard return should not be stored with each line of text.
The function returns the number of lines of text the user entered.

****************/

int getLinesFromUser(char  stringArray[ROWS][COLS])

{
 int i;
 i=0;
 int count;
 count = 0;
 int len;
 len = 0;

 for(i =0; i<ROWS; i++)

 {
    printf("Please enter a line ot hit enter to exit\n");

    fgets(stringArray[i], COLS, stdin);

     if(strcmp(stringArray[i], "\n"))
     
     {
      count++;
     }

 }


 for(i =0; i<ROWS; i++)
 
  {
    len = strlen(stringArray[i]);

    if(len != 0)
    {
     stringArray[i][len-1] = '\0';
    }

 }

 return count;

 }


/********************
This function prints each line of text in the string array, in order.
 Each line is printed on a separate line.
If there is no text in one of the strings,  nothing is printed.
The function will print 0, 1, 2 or 3 lines of text, depending
on how many lines are in the array.
********************/
void printStrings(char stringArray[ROWS][COLS])
{

  int i;
  i = 0;

  for(i =0; i<ROWS; i++)
   {

    if(strcmp(stringArray[i], "\0") != 0)
    {
     
     printf("%s\n", stringArray[i]);

    }
 }



}



/*********
main
*********/

int main(int argc, char * argv[])
{
   char myStrings[ROWS][COLS];
   int numStrings;
   
//intalizing array only up to 3 with null in each line of string
  myStrings[0][0] = '\0';
  myStrings[1][0] = '\0';
  myStrings[2][0] = '\0';
  
   numStrings = getLinesFromUser(myStrings);
   printf("Num of lines:%d\n", numStrings);
   printStrings(myStrings);
  
    return 0;
}