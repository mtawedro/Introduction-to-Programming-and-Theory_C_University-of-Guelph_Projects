#include <stdio.h>
#include <string.h>
//#include <booln.h>

int main (void)

{

char Name[10]="";
char letter= ' ';
int i = 0;

printf("hello enter your  name less than 10 characters\n");


while(i<10)

{

for(int x = 0; x<strlen(Name); x++)
{

printf("enter Char\n");
scanf("%c", &letter);
Name[x] = letter;


}

i++;

}

printf("Hello %s", Name);

return 0;

}