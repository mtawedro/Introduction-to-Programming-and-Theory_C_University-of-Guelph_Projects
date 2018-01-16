#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findSubString(char original[], char toFind[])
{
int k =0;
int start =0;
int length= strlen(toFind);
//change everything to length down
for(int i =0; i<strlen(original); i++)
{
if(original[i] == toFind[0])
{
for(int j=1; j<strlen(toFind); j++)
{
if(toFind[j] == original[i + j])
{
k++;
if(k == strlen(toFind) -1)
{
start = i;
return start;
}
}
}
}
}
return -1;
}

int main(void)
{
char original[] = "i can dream yesturday and today";
char toFind[] = "i can dream"; // test
int index = 0;
index = findSubString(original, toFind);
printf(" Index %d", index);

return 0;
}
