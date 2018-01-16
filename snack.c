/*******************************************
Email: mtawedro@mail.uoguelph.ca
Time: 2:20 pm - 3:50pm
Date: October 13 2016
********************************************/


#include <stdio.h>

#include <stdlib.h>

#include <time.h>

int main(void)

{

srand(time(0));

int ranNum1 =  0;

int ranNum3= 0;

int x = 0;

int preValue = 0;



while(x < 2)

{

ranNum3= (rand () % 5) +1;

ranNum1= (rand () % 10) +1;


if(ranNum3 == preValue)

{


ranNum3= (rand () % 5) + 1;


}


switch (ranNum3)


{

case 1 :

printf("%d Cookies\n", ranNum1);

break;


case 2:

printf("%d Cheetos\n", ranNum1);

break;

case 3:

 printf("%d Peanut Butter Cups\n ", ranNum1);

break;

case 4:

 printf("%d Skittles\n", ranNum1);

break;

case 5:

printf("%d  Ketchup Chips\n", ranNum1);

break;



}

preValue = ranNum3;

x++;


}


return 0;

}
