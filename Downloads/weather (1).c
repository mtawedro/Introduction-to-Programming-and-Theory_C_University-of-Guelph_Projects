/****************************************
 * Program: weather.c
 * Name: Martina Tawedrous
 * Date: Nov 29 2016
 * Email: mtawedro@mail.uoguelph.ca
 * Student Num: 0977473
 * REFERENCE: **Parse Function** used from the 1500 source provided 
 * **************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
//This function opens the file required and if file coud not be opened then user is prompt to enter file input again and returns a file pointer
FILE *OpenFile(char File[])
{
	// File pointer
    FILE *inFile = NULL; 
      
    // Open file
    printf("Opening file myfile.txt.\n");
         
    inFile = fopen(File, "r");
   
     // Error Trap, if file could not be found or user enters in wrong file name
     while(inFile == NULL) 
     {
         printf("Could not open file myfile.txt. Please enter in another file\n");
             
         fgets(File, 200, stdin);
      
         //gets rid of hard return 
         if(File[strlen(File)-1] == '\n')
         {
              File[strlen(File)-1] = '\0';
         }
         
         printf("Opening file myfile.txt.\n");
             
         inFile = fopen(File, "r");
    
     }	
	
    
    return inFile;	

}


     //struct definition of type Weather with defining its sub data structs 
     typedef struct Weather 
     {

        char location;	

        int	daynum;

        double	temp;

        double	precip;


     } Weather;



//calculates average temp for guelph (in guelph struct array) 
double CalcTempGuelph(int guelphCounter, Weather guelph [])
{
    double averTempGuelph = 0.0; 
   
    //within the guelph stuct array, the temp is added in each element 
    for(int k = 0; k<=guelphCounter; k++)
    {
	   
	    averTempGuelph = (averTempGuelph + guelph[k].temp);
	       
    }
    
    return averTempGuelph;

}
    
    

//calculates total perciption for guelph (in guelph struct array) 
double CalcPercipGuelph(int guelphCounter,  Weather guelph []) 
{
    double totalPrecipGuelph  = 0.0;
	   
	//within the guelph stuct array, the perciption is added in each element 
	for(int k = 0; k<=guelphCounter; k++)
    { 
	    totalPrecipGuelph = ( totalPrecipGuelph  + guelph[k].precip);
	    
    }
	   
	return totalPrecipGuelph;
	   
}
   
    

//calculates average temp for saskatoon (in sask struct array) 
double CalcTempSask(int saskCounter, Weather sask[])
{
    double averTempSask = 0.0; 
             
    for(int c = 0; c<= saskCounter; c++)
    {
	    
	    //within the sask stuct array, the temp is added in each element
	    averTempSask = (averTempSask + sask[c].temp);    
    }
   
    return averTempSask;
   
}
   


//calculates total perciption for saskatoon (in sask struct array) 
double CalcPercipSask(int saskCounter, Weather sask[])
{
	double  totalPrecipSask = 0.0;
	         
	//within the sask stuct array, the perciption is added in each element 
	for(int c = 0; c<= saskCounter; c++)
    {
	    totalPrecipSask = (totalPrecipSask + sask[c].precip);
	    
    }
	   
	return totalPrecipSask;
	   	   
}
   
   

//PRINTS EACH STRUCT IN THE GUELPH ARRAY AND THE SASKATOON ARRAY
void toPrint(int guelphCounter, int saskCounter, Weather guelph[], Weather sask[], double averTempGuelph,double totalPrecipGuelph, double averTempSask, double totalPrecipSask)
{

    printf("\n******");
    
    printf("\nGuelph\n");
    
    printf("******\n");

    printf("AVG TEMP: %.2lf\n", averTempGuelph);
    
    printf("TOTAL PRECIP: %.2lf\n\n",  totalPrecipGuelph);
  
    
    guelphCounter--;
    
    //prints data for guelph 
    for(int x = 0; x<= guelphCounter; x++)
    {
	   printf("DAY: %d (TEMP: %.2lf)[%.2lf MM]\n", guelph[x].daynum, guelph[x].temp, guelph[x].precip);   
	   
    } 
   
    printf("\n*********");
   
    printf("\nSaskatoon\n");
    
    printf("*********\n");

    printf("AVG TEMP: %.2lf\n", averTempSask);
   
    printf("TOTAL PRECIP: %.2lf\n\n",  totalPrecipSask);
   
    
    saskCounter--;
    
    //prints data for saskatoon 
    for(int c = 0; c<= saskCounter; c++)
    {
	   printf("DAY: %d (TEMP: %.2lf)[%.2lf MM]\n", sask[c].daynum, sask[c].temp, sask[c].precip);   
	     
    } 
   

}



//**REFERENCE: Parse Function (Judi's Function)** used by the 1500 source provided: 
//seperates each piece of data (after delimiter-> comma) into each data struct(location, temp,etc)
void parseLine(char toParse[], struct Weather * toLoad)
{
 
    char * theToken;
    
    //each delimiter is defined as a comma to let the computer know when to seperate each token 
    theToken = strtok(toParse, ",");
    
    //loads the first token(after first dilimter encountred) with location (Guelph or Saskatoon) to char 'G' or 'S'  
    toLoad->location = theToken[0];
 
    //loads token (2)(after 2nd  dilimter encountred) 
    theToken = strtok(NULL, ",");
    
    //converts the string daynum to a int(daynum)
    toLoad->daynum = atoi(theToken);
 
    //loads token (3) (after 3rd dilimter found) 
    theToken = strtok(NULL, ",");
 
    //converts string(temp) to double temp
    if(theToken != NULL)
    {
        toLoad->temp = atof(theToken);
    }
 
    //if no temp is found then by defualt intalize -400 to tempeture 
    else
    {
        toLoad->temp = -400;
    }
 
    //loads token (4) (after 4th dilimter found)
    theToken = strtok(NULL, ",");
         
    //converts string(percip) to double percip
    if(theToken != NULL)
    {
        toLoad->precip = atof(theToken);
    }
 
    //if no temp is found then by defualt intalize -1 to percip
    else
    {
        toLoad->precip = -1.0;
    }


}
 


int main(int argc, char*argv[]) 
{
	Weather w;
	Weather guelph[700];
	Weather sask[700];
	int saskCounter= -1;
	int guelphCounter= -1;
	double averTempGuelph = 0.0; 
	double averTempSask = 0.0; 
	double  totalPrecipSask = 0.0;
	double totalPrecipGuelph  = 0.0;
	char Line[200] = {' '};
	
	//calls OpenFile function to acess and open file 
	FILE* inFile = OpenFile(argv[1]);
	
    //Print read numbers to output
    printf("Reading and printing data.\n");
   
     
    //as a line is read in (line by line) from file, each data segement will be sorted and stored to either the guelph or sasaktoon array
    while  (fgets(Line, 300,  inFile) != NULL) 
    {
   
          //if the first character of the line being inputed is an g or G
          if(Line[0] == 'g' || Line [0] == 'G')
          {
		     //call parse function to parse the line thats being read into its corosponding data structures  
		     parseLine(Line, &w);
		    
		     //indexes for guelph array starting at index 0
		     guelphCounter++;    
		     
		     //puts each of the data structures within each element of the guelph array 
		     guelph[guelphCounter].location = w.location;
		     guelph[guelphCounter].temp = w.temp;
		     guelph[guelphCounter].precip = w.precip;
		     guelph[guelphCounter].daynum = w.daynum;
		   
		 
	      }

	      //if the first character of the line being inputed is an s or S
	      else if (Line[0] == 's' || Line [0] == 'S')
	      {
		     //call parse function to parse the line thats being read into its corosponding data structures  
		     parseLine(Line, &w);
		    
		     //indexes for sask array starting at index 0
		     saskCounter++;
		     
		     //puts each of the data structures within each element of the sask array 
		     sask[saskCounter].location = w.location;  
		     sask[saskCounter].temp = w.temp;  
		     sask[saskCounter].precip = w.precip;  
		     sask[saskCounter].daynum = w.daynum;   	 		 	 	 		 
	     
	      }
         

    }
  
   
    //calls function to calculate the total temp(sum) for the guelph array 
    averTempGuelph= CalcTempGuelph(guelphCounter, guelph);
  
    guelphCounter++;
    
    //takes the total tempeture (sum) for guelph array and divides it by the amount of elements in the guelph array 
    averTempGuelph= averTempGuelph / (double)guelphCounter; 
 
    //calls function to calculate the total perception for the guelph array 
    totalPrecipGuelph = CalcPercipGuelph(guelphCounter, guelph);
   
    //calls function to calculate the total temp(sum) for the sask array 
    averTempSask= CalcTempSask(saskCounter, sask);
   
    saskCounter++;   
    
    //takes the total tempeture (sum) for sask array and divides it by the amount of elements in the sask array 
    averTempSask = averTempSask /(double)saskCounter; 
   
    //calls function to calculate the total perception for the sask array
    totalPrecipSask= CalcPercipSask(saskCounter, sask);
    
    //calls the toPrint function to print guelph array and saskatoon array 
    toPrint(guelphCounter, saskCounter, guelph, sask, averTempGuelph,totalPrecipGuelph, averTempSask, totalPrecipSask);
    
    printf("\nClosing file.\n"); 
   
    //Done with file, so close it
    fclose(inFile);
    
    return 0;

}
