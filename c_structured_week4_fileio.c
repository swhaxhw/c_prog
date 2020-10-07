/* c structured programming week4 peer-graded
   Program will read a file of integers, with 1st integer deciding how many elements
   John Phillip Mazo 10/7/2020
*/

#include <stdio.h>
#include <stdlib.h>

//globa vars
int iArraySize=0;
int iArrayFromFile[10];

//functions
int getArraySize(); //function to store integer data from file
int storeArray(); //function to store integer data from file

int main()
{
	double dAverage, dSum;
        int i, iMax, *arrayPtr;
	char inputFile[20] = "file_of_int.txt"; //should be on same path of program
        
	getArraySize(inputFile); //get the array size from the first integer of the file
	
	int iArrayData[iArraySize]; //make an array of size iArraySize 
	storeArray(inputFile, iArrayData); 
	
	for(i=0; i<iArraySize;++i)
        {
                dSum += iArrayData[i]; //get the sum of all elements
		if (iArrayData[i]>iArrayData[i-1]) //simple condition to find the max integer
		{
			iMax=iArrayData[i];
		}
        }
        dAverage=dSum/iArraySize;
        
	//print to an output file
	FILE *fptr;
	fptr=fopen("answer-hw3", "w");	
	fprintf(fptr, "\nThe average of the integers in the file %s is: %lf\n", inputFile, dAverage);
	fprintf(fptr, "The integer with MAX value is: %d\n",iMax);
	fclose(fptr);
	
	//print to screen
	printf("\nThe average of the integers in the file %s is: %lf\n", inputFile, dAverage);
	printf("The integer with MAX value is: %d\n\n",iMax);
        return 0;
}

int getArraySize(char sFileName[]) //function to store integer data from file
{
        FILE *file = fopen(sFileName, "r");
        int i=0, iElem;

        while(fscanf(file, "%d", &iElem) > 0)
        {
                iArraySize = iElem; //we are only interested in the first integer
                break;
        }
        fclose(file);
}

int storeArray(char sFileName[], int iArray[]) //function to store integer data from file
{
        FILE *file = fopen(sFileName, "r");
        int i=0, iElem;

        while(fscanf(file, "%d", &iElem) > 0)
        {
                iArrayFromFile[i]=iElem; //the whole data from the file
                if (i!=0) // we ignore the first element since it's the array size
                {
                        *(iArray+i-1) = iElem; //store the elements 1by1 to the array
                }
                i++; //move to the next element
        }
        fclose(file);
}
