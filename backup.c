#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//calls other 2 functions and change function to int
void replaceInString(char original[] , char substring[], char replace[])

{

char toFind[strlen(substring)];

//printf("replaceInString: %s\n", original);

for(int i = 0; i< strlen(toFind); i ++)

{
//puts substring into tofind array
toFind[i] = substring[i];



}


printf("\nTEST tofind is %s\n", toFind);

findSubString(original, toFind);


//insertString(original, start, length, replace);

//return 0;

}

//searches for index of of toFind
findSubString(char original[], char toFind[])

{

int length = strlen(toFind);

int start = 0;

int  j = 0;

int  flag = 0;

//printf("Original: %s\n", original);

//finds the substring in original
for(int i = 0; i <  strlen(original); i++)
{

     if(j == length){
         break;
     }

  	if(original[i]== toFind[j])
   	 {
   	     

    	      flag = 1;
              j++;
   	}

   else
      {
            flag = 0;
            j = 0;
       

      }
 


}

//printf("%d\n", j);


/*
if(flag == 1)

  {

   for(int i =0; i<strlen(original); i++)

     {


         if(original[i] == toFind[j])

            {


              start = j;
              break;

           }


    }

  }

else if(flag == 0)

   {

    start = -1;


   }*/


printf("\nshould be position 3: %d", start);


return start;

//start= (j +1)- (strlen(original));// return first occurance in oroginal
//printf("\nshould be position 3 %d:", start);


}


//void insertString




int main(void)

{

int num =0;
//char input= ' ';
char user = ' ';
char substring[80] = "tina"; //change length of array
char original[80] = "martinajohn";
char replace[80] = "ball";

printf("%s\n", original);

/*printf("please  choose a line to edit: 1,2,3,4 or 5, press \'q\' to exit\n");
 do ifgets scanf("%d", &num);

switch(num)

{

case 1:

printf("press r to remove the whole line\n");
scanf("%c", &user);

if(user == 'r' || user == 'R');

  {
    for(int i = 0; i <strlen(original); i++)

       {

        original[i] = " ";

        }
  }*/
//printf("Test: String %s\n", original);

/*
printf("press \'s\' to insert or delete a substring in line\n");
scanf("%c", &user);

     if(user == 's' || user == 'S')

     {
               printf("enter in substring you want to remove\n");
               scanf("%s", substring); //change length of array and change to fgets
               printf("TEST OF SUBSTRING %s", substring);
               printf("Enter in word you will like to replace");
               scanf("%s", replace); // change to fgets
               replaceInString(test, substring, replace);// calls first function 





     }





break;

}*/


num = findSubString(original, substring);


return 0;
}