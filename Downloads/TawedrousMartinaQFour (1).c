#include <stdio.h>
#include <stdbool.h>

//prints each number in array num []
void PrintArray(int num [])

{
 
 for (int i = 0; i <= 2; i++)

	{

		printf("\n%d\n", num[i]);

	}

}

//sorts array using bubble sort (asending order) 
void Sort(int num[])

{//start of Sort method.

	bool flag = true;// set flag to true to begin first pass.

	while (flag)

	 {// start of while

		flag = false;// set flag to false awaiting a possible swap

			for (int j = 0; j < 2; j++)

			   {// start of for.

					if (num[j] > num[j + 1]) //Least to Greatest (ascending sort).

						{// start of if.

							// Swapping names.
							int numTemp;// holding variable.
							numTemp = num[j];
							num[j] = num[j + 1]; // swap elements.
							num[j + 1] = numTemp;
							flag = true;// shows a swap occurred.

						}// end of if.

			}// end of for.

	}// end of while.

//calls function PrintArray and passes parameter array num
PrintArray(num);

}// end of Sort method.

int main (void)

	{
		//declare and initialize variables 
		int num [3];

		int user = 0;

		printf("Enter an int Num:");

			for (int i = 0; i <= 2; i++)

				{// start of for.

					scanf("%d", &user);

					num[i]= user;

				}

		Sort(num);

		return 0;

	}


/*

Input:
User inputs 3 int numbers
*********************
12, 8, 2
555, 89999, 1233456
0, 88, -1
5, 6, 5

Output:
Prints the 3 input numbers in ascending order:
**********************
2, 8, 12
555, 89999, 1233456
-1, 0, 88
5, 5, 6

Main Algorithm (numbered steps):
1.Get num1 from user
2.Get num2 from user
3.Get num3 from  user
4.Store each of the 3 numbers entered by user in an array
5.Call  and pass in the array with the 3 inputted integers to a sorting method/function
6.By using the bubble sort, sort the array from least to greatest
7.Call and pass the sorted array to the print method/ function for printing the array


Step Refinements:
1.Declare and initialize an array called num with size [3]
2.In a FOR loop, ask user to enter in first num
3.Store that num in the first element [0] of array num []
4.Ask user to enter second num
5.Store that num in the second element [1] of the array num []
6.Ask user to enter in third num
7.Store that num in the third element [2] of the array num []
8.Call Sort method/function with passing in array num []
9.In sort method, declare and initialize a Boolean type variable (flag) to ‘true’, in order to begin the first pass
10.Add a WHILE loop, setting the condition to ‘flag’ (true)
11.In WHILE loop, set flag to false, awaiting a possible swap
12.Within a FOR loop, add an IF statement, where IF the first element in the array is greater than the [first element +1] (compares each occurance of a max num with respect to the num before as (i) increments in the FOR loop) 
13.Then (swapping occurrence) declare and initialize a holding variable (temp) to hold the first element (i) in the array
14.Swap (i) first element in array with [first element +1] 
15.Then [first element +1] is swapped with the holding variable (temp) which is holding the first element (i) in array num []
16.Set flag to ‘true’, showing a swap occurred
17.Continue FOR loop until incrementing variable (i) reaches the end of the array
18.End WHILE loop
19.Call and pass the sorted array num [] to the method/function PrintArray to print the sorted array
20.In PrintArray method, add a FOR loop to print each element in array num [], until incrementing variable (i) reaches the end of the array.


*/





