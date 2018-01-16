#include <stdio.h>
#include <string.h>



//function that  searches for the ending of the  word/noun the user inputs and adds the appropriate ending to change the noun to plural 
void Plural( char noun [], int length)

{

//if the  last element in string ends with 's', 'ch' or 'sh, add an 'es' to the ending of the  noun
if(noun[(length - 1)] == 's' || (noun[(length - 2)] == 'c' && noun[(length - 1 )] == 'h') || (noun[(length - 2 )] == 's' && noun[(length - 1 )] == 'h') )

{

 strcat(noun, "es");

 printf("Plural: %s\n", noun);


}

//if the last element in string ends with a 'y' replace the 'y' with 'i' and add 'es' to ending of the noun
else if(noun[(length - 1)] == 'y')

{

 noun[(length - 1)] = 'i';

 strcat(noun, "es");


 printf("Plural: %s\n", noun);

}

else

{

 strcat(noun, "s");


 printf("Plural: %s\n", noun);


}

}

int main(void) {

//declare and initialize variables
char noun[25] ;

int length ;

//prompts user to enter noun
printf("enter a noun\n");
scanf("%s", noun);

//stores length of noun in var length
length =  strlen(noun);

//error trap in case user inputted more than 25 characters
while((length) > 25 )

{

 printf("Oops!, you've entered more than 25 characters, Please try again:\n");
 scanf("%s", noun);

length =  strlen(noun);

}

//prints noun
printf("Noun: %s\n", noun);

//calls function Plural with passing in parameters noun and length of noun
Plural(noun, length);


 return 0;

}

/*

Input:
Noun is entered by user
***********************
Hobby
Horse
Couch
Cat
Wish
Log

Output:
Noun that’s entered by user is changed to a plural of the noun
************************
Hobbies
Horses
Couches
Cats
Wishes
Logs

Main Algorithm (numbered steps):
1.User enters a noun no more than 25 characters
2.Call and pass string noun to a method/function called plural
3.In method Plural, dependent on ending characters in word, add “s” or “es” and/or replace a certain letter  with ‘i  ‘
4.Call and pass string noun to a method called PrintPlural to print the plural of string noun

Step Refinements:
1.Declare and initialize string (char array) noun
2.Declare and initialize int length (representing length of string noun)
3.Ask user to enter a noun no more than 25 characters
4.Add a strlen function to return the length of the string and store it in variable int length
5.Add an IF statement, IF the length of string noun is greater than 25
6.Message will appear stating that user eexceeded the limit of 25 characters and prompts user to try to try again
7.Print the noun the user inputted
8.Call and pass string noun and int length to Plural method/function
9.In Plural method, add an IF statement where IF the length of string noun e.g. [4], (using the strlen function) ends with characters: ‘s’,  ‘ch’ or ‘sh’
10.Use the strcat function to add “es” to the end of the string noun
11.Print the plural of the noun user inputted
12.Add an ELSE IF statement where IF the length of string noun e.g. [4], (using the strlen function) ends with character, ‘y’
13.Replace the last element of the array using the strlen function with ‘i ‘
14.Use strcat to add an “es” to the end of string noun
15.Print the plural of the noun user inputted
16.Add an ELSE statement, use strcat to add an “s” to the end of string noun
17.Print the plural of the noun user inputted

 */




















