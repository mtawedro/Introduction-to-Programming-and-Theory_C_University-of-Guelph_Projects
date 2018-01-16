#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void insertString(char original[], int start, int length, char toInsert[])
{


int frontRemain = 0;
int endRemain = 0;
char frontArray[80]= " ";
char endArray[80]= " ";
char firstHalf[80];
char final[80];
int store = 0;
int count = 0 + strlen("tomorow");
int z= 0;

for(int i = 0; i<0; i++)
{

frontArray[i] = original[i];


}

printf("\nTEST FRONTARRAY %s",frontArray);


for(count+1; count<strlen(original); count++)
{

endArray[z] = original[count];
z++;
printf("\nTEST ENDARRAY char %c", endArray[count]);


}


if(strlen(toInsert) >=5)

{

endArray[4]='\0';

}






printf("\nTEST ENDARRAY %s", endArray);


strcpy(firstHalf, (strcat(frontArray, toInsert)));

printf("\nTEST", firstHalf);

strcpy(final, (strcat(firstHalf,endArray)));


printf("\nReplace string %s:", final);


//print the rest of the lines



}




int main(void) {


char original[80]= " ";
strcpy(original, "tomorow yesterday and today");
int orLen=strlen("tomorow yesterday and today");

for(int x = orLen; x < 80; x++ )
{
original[x] = '\0';
}


original[80] = "tomorow yesterday and today";
char toFind[] = "tomorow"; // test
char replace[] = "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo";
int length= strlen("tomorow");


//if(strlen(replace) >= 81)

//{

//replace[81] = '\0';
//}



printf("\nTEST OROGINA %s", original);


insertString(original, 3, length, replace);
return 0;
}
