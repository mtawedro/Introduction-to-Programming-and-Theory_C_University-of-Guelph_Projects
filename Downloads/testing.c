/***********************************************
 * Program: testing.c
 * Name: Martina Tawedrous
 * Student Number: 0977473
 * Email: mtawedro@mail.uoguelph.ca
 * *********************************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//3rd function: this function replaces the contents of original  with the specfied substring the user replaces  
void insertString(char original[], int start, int length, char toInsert[])
{
   
    char frontArray[500]= " ";
    char endArray[500]= " ";
    char firstHalf[500];
    char final[500];
    int z= 0;
    

    if(start == -1) 
    {
        printf("Sorry, coudn't find substring--> ");
    }

    //stores the first elements from the beginning of the string to the first occurance of substring into a temp frontArray
    for(int i = 0; i<start; i++)    
    {
         frontArray[i] = original[i];
    }

    //stores the elements from the end of the substring to the end of the original string into a temp endArray
    for(int count = (start + length) +1; count<strlen(original); count++)
    {
         endArray[z] = original[count];
           z++;
    }

    // copys the front part of the original string and adds the word the user wants to replace(toInsert) into a string array called firstHalf
    strcpy(firstHalf, (strcat(frontArray, toInsert)));
       
    //copys the half of the string (up to the toInsert) and adds the end part of the original string and stores it into a string array called final
    strcpy(final, (strcat(firstHalf,endArray)));
        
    
       //truncates
       if(strlen(original) > 81)
       {
          endArray[80]='\0';
       }
	 
	 
    if(start != -1)  
    {
        printf("New Line is:  %s--> ",final);
    }

}


//2nd function: This function searches for the first ocuurance of the substring located in the string 
int findSubString(char original[], char toFind[])
{
    int k =0;
    int start =0;

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



//1st function: This function calls function 2 and function 1 if substring is found in origional string 
int replaceInString(char original[], char substring[], char replace[])
{

    int start = 0;
    char toFind[80] = " ";
       
    strcpy(toFind, substring);
        
    start= findSubString(original, toFind);

    if(start == -1)  
    {
       return 0;
    }
       
    else
    {
       start=1;
       return start;
    }



}



int main(void)
{

    int ROWS=5;
    int COLS= 500;
    char buffer[ROWS][COLS];
    char tempBuffer[500] = " ";
    int start = 0;
    int fail = 0;

    strcpy(buffer[0],"1 I can dream, dreams that nobody has dreamt before" );
    strcpy(buffer[1],"2 advent adventures all over the world" );
    strcpy(buffer[2],"3 I want to write out my imagination" );
    strcpy(buffer[3],"4 tomorrow and yesterday and today" );
    strcpy(buffer[4],"5 A yellow fire clinging deep in a dry well" );

    printf("%s\n%s\n%s\n%s\n%s\n",buffer[0], buffer[1], buffer[2],buffer[3],buffer[4]);


    //second function
    start = findSubString(buffer[3], "tomorrow"); //call function ak uer
    printf("Should return index 2: %d\n", start);

    start = findSubString(buffer[2], "want to write"); //call function ak uer
    printf("Should return index 4: %d\n", start);

    start = findSubString(buffer[0], "martina"); //call function ak uer
    printf("Should return -1: %d\n", start);
    
    start = findSubString(buffer[1], "adventures"); //call function ak uer
    printf("Should return index 9: %d\n", start);

    start = findSubString(buffer[4], "Ayell"); //call function ak uer
    printf("Should return -1: %d\n", start);



    //first function
    fail = replaceInString(buffer[3], "tomorrow", "candy"); //call function ak uer
    printf("Should return 1: %d\n", fail);

    fail = replaceInString(buffer[2], "want to write", "hate"); //call function ak uer
    printf("Should return 1: %d\n", fail);

    fail = replaceInString(buffer[0], "martina", "john"); //call function ak uer
    printf("Should return 0: %d\n", fail);

    fail = replaceInString(buffer[1], "adventures", "advent"); //call function ak uer
    printf("Should return 1: %d\n", fail);

    fail = replaceInString(buffer[4], "Ayell", "hello"); //call function ak uer
    printf("Should return 0: %d\n", fail);
    
    //copys the modfied line into the buffer(original buffer) at that same line--> modifies original buffer  
    strcpy(tempBuffer, buffer[3]);
    
    //stores the length of the line user chose into orLen
    int orLen=strlen(tempBuffer);
    
      //initializes every index after the length of the line (user chose) to null terminators
      for(int x = orLen; x < 500; x++ )
      {
        tempBuffer[x] = '\0';
      }

    //third function
    insertString(buffer[3], 2, strlen("tomorrow"), "candy");
    printf("Should be: 4 candy and yesterday and today\n");

    strcpy(tempBuffer, buffer[2]);

    orLen=strlen(tempBuffer);

      for(int x = orLen; x < 80; x++ )
      {
        tempBuffer[x] = '\0';
      }


    insertString(buffer[2],4, strlen("want to write"), "hate"); //call function ak uer
    printf("Should be: 3 I hate out my imagination\n");

    strcpy(tempBuffer, buffer[0]);

    orLen=strlen(tempBuffer);

     for(int x = orLen; x < 80; x++ )
     { 
       tempBuffer[x] = '\0';
     }


    insertString(buffer[0],-1, strlen("martina"), "john"); //call function ak uer
    printf("Should print: Sorry, coudn't find substring\n");

    strcpy(tempBuffer, buffer[1]);

    orLen=strlen(tempBuffer);

     for(int x = orLen; x < 80; x++ )
     {
        tempBuffer[x] = '\0';
     }


    insertString(buffer[1],9, strlen("adventures"), "advent"); //call function ak uer
    printf("Should be 2 advent advent all over the world\n" );

    strcpy(tempBuffer, buffer[2]);

    orLen=strlen(tempBuffer);

     for(int x = orLen; x < 80; x++ )
     {
       tempBuffer[x] = '\0';
     }


    insertString(buffer[3],2, strlen("tomorrow"), "oooooooooooooooooooooooooooooo");
    printf("Should be: 4 ooooooooooooooooooooooooooooooand yesterday and today\n");


    return 0;



}
