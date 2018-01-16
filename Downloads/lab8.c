/************************************************
Name: Martina Tawedrous
Program: lab8.c
Email: mtawedro@mail.uoguelph.ca
Student Num: 0977473
TA: Dylan

*************************************************/

#include <stdio.h>

//determines if the user is sleep deprivied , based  on the amount of hours inputted
void HoursofSleep(double numSleep)

{
    //checks if user enters in minutes and prints an error message stating taht only hours are valid
    if(((int)numSleep / 60) != 0 )

    {

     printf("Error! only hours not minutes!");

	}

    else if((numSleep >= 0 && numSleep <= 4))

    {

     printf("Sleep deprived!");

    }

    else if(numSleep > 4 && numSleep < 6)

    {

     printf("You need more sleep");

    }

    else if(numSleep >= 6 && numSleep < 8)

    {

     printf("Not quite enough");

    }


    else if(numSleep >= 8)

    {

     printf("Well Done!");

    }

}

int main(void)

{

    printf("Should print \" Not quite enough \": ");

    HoursofSleep(6);

    printf("\nShould print \" Error! only hours not minutes! \" : ");

    HoursofSleep(60);

    printf("\nShould print \" You need more sleep \": ");

    HoursofSleep(5.999999);

    printf("\nShould print \" Sleep deprived! \": ");

    HoursofSleep(0.50);

    printf("\nShould print \" Error! only hours not minutes! \" : ");

    HoursofSleep(235);

    printf("\nShould print \" Well Done!  \" : ");

    HoursofSleep(8.00000001);

    printf("\nShould print \" Not quite enough \": ");

    HoursofSleep(7);

    printf("\n");

return 0;


}
