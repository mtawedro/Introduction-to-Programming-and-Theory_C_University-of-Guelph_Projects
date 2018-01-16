
#include <stdio.h>
#include <stdlib.h>

//typedef int bool;





typedef struct Weather{

char	location;	//will	be	S	or	G

int	daynum;

double	temp;


double	precip;


} Weather;




void parseLine(char toParse[], struct Weather * toLoad)
{
 char * theToken;
 theToken = strtok(toParse, ",");
 toLoad->location = theToken[0];
 theToken = strtok(NULL, ",");
 toLoad->daynum = atoi(theToken);
 theToken = strtok(NULL, ",");
 if(theToken != NULL)
 {
 toLoad->temp = atof(theToken);
 }
 else
 {
 toLoad->temp = -400;
 }
 theToken = strtok(NULL, ",");
 if(theToken != NULL)
 {
 toLoad->precip = atof(theToken);
 }
 else
 {
 toLoad->precip = -1.0;
 }


}


int main(void)
{


		
			
	char toParse[]= "Guelph,2,9.5,0.8\n";
	Weather w;
	
	
	parseLine(toParse, &w); 
	
	
	
	//Weather Guelph [10];
		
    //Weather Sask[10];
	
	printf("%lf\n", w.temp);
	printf("%c\n", w.location);
	printf("%d\n", w.daynum);
	printf("%lf\n", w.precip);
	
	
   FILE* inFile = NULL; // File pointer
   int fileNum = 0;     // Data value from file
   
   // Open file
   printf("Opening file myfile.txt.\n");
   
   inFile = fopen("myfile.txt", "r");
   
   

   
   if (inFile == NULL) {
      printf("Could not open file myfile.txt.\n");
      return -1; // -1 indicates error
   }
   
   // Print read numbers to output
   printf("Reading and printing numbers.\n");
   
   fscanf(inFile, "%d", &fileNum);
   while (!feof(inFile)) {
      printf("num: %d\n", fileNum);
      fscanf(inFile, "%d", &fileNum);
   }
   printf("num: %d\n", fileNum);
   
   printf("Closing file myfile.txt.\n");
   
   // Done with file, so close it
   fclose(inFile);
	
		//Weather w;
		
		//parseLine(toParse[], &w)
	
	
	return 0;
	
}






