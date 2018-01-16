#include <stdio.h>

/********************************************************
Name: Martina Tawedrous
Email: mtawedro@mail.uoguelph.ca
Student Number: 0977473
Program: lab7.c
TA: Dylan
*******************************************************/

void calcGradeSys( double aver)


{


   if(aver<0 || aver >100 )

    {


    printf("Error!");


    }


   else if(aver >= 0 && aver<=49)

    {

    printf("Grade acheived: F");

    }

   else if (aver>= 50 && aver<=52)

    {

    printf("Grade acheived: D-");


    }

   else if(aver>=53 && aver <=56)

    {

    printf("Grade acheived: D");

    }

   else if(aver>=57 && aver<=59)

    {

    printf("Grade acheived: D+");

    }


   else if(aver>=60 && aver<=63)

    {


    printf("Grade acheived: C-");


    }


   else if(aver>=64 && aver<=66)

    {


    printf("Grade acheived: C");

    }

   else if(aver>=67 && aver<= 69)

    {

    printf("Grade acheived: C+");

    }

   else if(aver>= 70 && aver<= 72)

    {

    printf("Grade acheived: B-");


    }

   else if(aver >= 73  && aver <= 76)

   {

    printf("Grade acheived: B");

   }



   else if(aver>=77 && aver <= 79)

    {

    printf("Grade acheived: B+");

    }

   else if(aver>= 80 && aver <=84)

    {


    printf("Grade acheived: A-");


    }



   else if(aver>= 85 && aver <= 89)

    {


    printf("Grade acheived: A");


    }

   else

    {


    printf("Grade acheived: A+");

    }


}



int main(void)

{


    printf("Should be A:--> ");

    calcGradeSys( 85.99);

    printf("\nShould give an error:--> ");

    calcGradeSys( -79.3);

    printf("\nShould give an error: --> ");

    calcGradeSys( 101);

    printf("\nShould give a C-: --> ");

    calcGradeSys( 63);

    printf("\n");

return 0;


}