#include <stdio.h>

int main(void)
{
const int MAX_LEN = 6;

int sum = 0;

int num [6] = {8,1,3, 6, 2, 10};


 for(int i = 0 ; i < MAX_LEN; i++)

 {

 if ((num[i] % 2) == 0)

 {

 sum = sum + num[i];

 }


 }

 printf("%d\n", sum);

 return 0;
}