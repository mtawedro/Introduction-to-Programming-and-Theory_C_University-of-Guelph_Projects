/***********************************************
 * Program: editor.c
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
   
    //stores the first elements from the beginning of the string to the first occurance of substring into a temp frontArray
    for(int i = 0; i<start; i++)
    {
	    frontArray[i] = original[i];

    }

    //stores the elements from the end of the substring to the end of the original string into a temp endArray
    for( int count = (start + length); count<strlen(original); count++)
    {
            endArray[z] = original[count];
             z++;
    }

    // copys the front part of the original string and adds the word the user wants to replace(toInsert) into a string array called firstHalf
    strcpy(firstHalf, (strcat(frontArray, toInsert)));
    
    //copys the half of the string (up to the toInsert) and adds the end part of the original string and stores it into a string array called final
    strcpy(final, (strcat(firstHalf,endArray)));
    
    //truncates
    if(strlen(final) > 80)
    {
        final[79] = '\0';   
        strncpy(original,final,80);           
    } 
    
   
   else
   {
    //copys the final string that has been modified into the temp array(dummy) which has been modified in whole program     
    strcpy(original,final); 
   
   }    
}


// **Judi's Algorithm** 2nd function: This function searches for the first ocuurance of the substring located in the string 
int findSubString(char original[], char toFind[])
{
    int k =0;
    int start =0;
    //int length= strlen(toFind);

    
    for(int i =0; i<strlen(original); i++)
     {
       //searches for the first index of the substring
       if(original[i] == toFind[0])
        { 
           for(int j=1; j<strlen(toFind); j++)
            {
                 //once found the index of the first occurance in origional string, checks for each character after to check for a correct match of substring
                 if(toFind[j] == original[i + j])
                    {
                         k++;
                         
                         //once reached the end of the substring and vertifies a match, will return the first occurance of the substring(index)  
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
    int length = 0;
    char toFind[80] = " ";
                  
    //stores substring into another string called toFind 
    strcpy(toFind, substring);
    
    length = strlen(toFind);
    
    //calls function 2
    start= findSubString(original, toFind);
              
    if(start == -1)
    {
       return 0;
    }
               
    
    else
    {
       //calls function 3               
       insertString(original, start, length, replace);
                        
       start=1;
       
       return start;
    }

 }



//This function prompts the user for input such as the substring they want to remove, word or line they want to replace
void askUser(char buffer[5][80],int num, char tempBuffer[],char substring[], char replace[])

{
    int fail = 0;
    char user = ' ';
    printf("press \'r\' to remove the whole line or press \'s\' to insert or delete a substring in line\n");
    scanf("%c", &user);
    getchar();

    //error trap
    while(!(user == 'r' || user =='R' || user == 's' || user == 'S'))
    {
	
	      printf("Srry inccorect choices, please press \'r\' to remove the whole line or press \'s\' to insert or delete a substring in line\n");
          scanf("%c", &user);
          getchar();
	      
    }


    if(user == 'r' || user == 'R')
    {
          //replaces each index in line user chose with a space
          for(int i = 0; i <strlen(tempBuffer); i++)
          {
                    
              tempBuffer[i] = ' ';

          }
        
          //copys the modfied line into the buffer(original buffer) at that same line--> modifies original buffer             
          strcpy(buffer[num-1], tempBuffer);
    
          printf("Enter in a sentence you will like to replace with:\n");
             
          fgets(replace, 500 ,stdin);

          //gets rid of the hard return by checking the last char of word user entered and replaces it with a null terminator
          if(replace[strlen(replace)-1] == '\n')
          { 
             replace[strlen( replace)-1] = '\0';                 
          }
      
          //truncates
          if(strlen(replace) > 80)
          {
            replace[79] = '\0';                
          } 
       
         strcpy(buffer[num-1],replace);
         
      
   }


    else if(user == 's' || user == 'S')
    {

        printf("Enter in the substring you want to remove:\n");
             
        fgets(substring, 500 ,stdin);

        if(substring[strlen(substring)-1] == '\n')
        {
           substring[strlen( substring)-1] = '\0';
        }

                           
        printf("Enter in the word you will like to replace:\n");
              
        fgets(replace, 500 ,stdin);

        if(replace[strlen(replace)-1] == '\n')
        { 
            replace[strlen( replace)-1] = '\0';           
        }

        //calls function 1        
        fail = replaceInString(tempBuffer, substring, replace);
                                   
        //copys the modfied line into the buffer(original buffer) at that same line--> modifies original buffer         
        strcpy(buffer[num-1],tempBuffer);
         
        
         while(fail == 0)
         {
          
              printf("\nSrry coudn't find substring, please enter in another substring you want to remove:\n");
                     
              fgets(substring, 500 ,stdin);

              if(substring[strlen(substring)-1] == '\n')
              {
                    substring[strlen( substring)-1] = '\0';
              }
        
              printf("Enter in the word you will like to replace:\n");
                 
              fgets(replace, 500 ,stdin);

              if(replace[strlen(replace)-1] == '\n')
              {
                   replace[strlen( replace)-1] = '\0';
              }
              
              //calls 1st function
              fail = replaceInString(tempBuffer, substring, replace);
               
              //copys the modfied line into the buffer(original buffer) at that same line--> modifies original buffer         
              strcpy(buffer[num-1],tempBuffer);
         }          


         printf("\nSucess\n");
        
        
   }




}


int main(void)
{

    int ROWS=5;
    int COLS= 80;
    char buffer[ROWS][COLS];
    char tempBuffer[500] = " ";
    int num = 0;
    char substring[500]="";
    char replace[500]= " ";

    strcpy(buffer[0],"1 I can dream, dreams that nobody has dreamt before" );
    strcpy(buffer[1],"2 advent adventures all over the world" );
    strcpy(buffer[2],"3 I want to write out my imagination" );
    strcpy(buffer[3],"4 tomorrow and yesterday and today" );
    strcpy(buffer[4],"5 A yellow fire clinging deep in a dry well" );


    printf("%s\n%s\n%s\n%s\n%s\n",buffer[0], buffer[1], buffer[2],buffer[3],buffer[4]);

    printf("\nplease choose a line to edit: 1,2,3,4 or 5\n");

    scanf("%d", &num);
    
    while(!(num == 1 || num==2 || num==3||num==4 || num==5))
    {
		
		
	printf("Sorry invalid line, please enter in a line from 1-5\n");
    scanf("%d", &num);
		
	}
    
    do
    {

        getchar();

        //takes the line user chose and puts that line into a 1D temp string array
        strcpy(tempBuffer, buffer[(num-1)]);
        
        //stores the length of the line user chose into orLen
        int orLen=strlen(tempBuffer);
        
        //initializes every index after the length of the line (user chose) to null terminators
        for(int x = orLen; x < 500; x++ )  
        {
            tempBuffer[x] = '\0';
        }

        //calls function askUser
        askUser(buffer,num,tempBuffer, substring, replace); 
              
        printf("\n%s\n%s\n%s\n%s\n%s\n",buffer[0], buffer[1], buffer[2],buffer[3],buffer[4]);

        printf("\nplease choose a line to edit: 1,2,3,4 or 5, press 10 to exit\n");

        scanf("%d", &num);


   } 

   while(num!=10);
   
   strcpy(buffer[num-1],tempBuffer);
   
   printf("Final Edit: \n%s\n%s\n%s\n%s\n%s\n",buffer[0], buffer[1], buffer[2],buffer[3],buffer[4]);

   return 0;


}

