/* c structured programming week3 peer-graded
   Program will generate 100 random integers then store in a linked list
   Output should be in row of 5
   John Phillip Mazo 10/6/2020
*/

#include <stdio.h>
#include <stdlib.h>  //for rand() function

//var definitions
#define MAX_NUM 100
#define MAX_COL 20
typedef struct list{int data; struct list* next;} list;

//functions, ADTs
list *addInList(int value);
int bubbleSort();
list *swapInList();
void printList();

int main()
{
        list *finalList = NULL; //make sure this list is empty
        list *tempList;
        list *sortedList;
        int i, randNum;
        for(i=0;i<MAX_NUM;i++) //now we generate a 100-element list of random integers
        {
                randNum = rand()%MAX_NUM; //generate a random integer (but I've limited it to <=100, to have a neat printout
                tempList=addInList(randNum); //add that integer to the list
                tempList->next=finalList; //link it
                finalList = tempList; //store the data
        }
        printf("\nThe list before sorting:\n");
        printList(finalList);

        bubbleSort(&finalList,MAX_NUM); //now sort the list
        sortedList=finalList;
        printf("\nThe list after sorting:\n");
        printList(sortedList);
}
/*sample output
  The list before sorting:
  39 94 86 26 12 39 68 76 60 32 99 54 51  3 84 88 78 76  8 87 
  50 43 64 34 67 14 45 82 95 24 57 13 29 46  5 36 27 84 25  5
*/

list *addInList(int value)
{
	list *theList = malloc(sizeof(list));
	theList->data = value;
	theList->next = NULL;
	return theList;
}

void printList(list *inList)
{
	int i=MAX_NUM;
	list *tempList = inList;
	while (tempList != NULL)
	{
		i--;
		printf("%2d ", tempList->data); //print 2 digits to align the texts
		tempList=tempList->next;
		if (i%MAX_COL==0){ printf("\n");} //just insert a new line after 20th data
	}
}

list *swapInList(list *a, list *b)
{
	list *temp=b->next;
        b->next=a;
        a->next=temp;
	return b;
}

int bubbleSort(list **head, int count) //reference geeksforgeeks
{ 
	list **h; 
    	int i, j, isSwapped; 
    	for (i = 0; i <= count-1; i++) 
    	{ 
        	h = head; 
        	isSwapped = 0; 
        	for (j = 0; j < count-i-1; j++)  
        	{ 
            		list *ptr1 = *h; 
            		list *ptr2 = ptr1->next; 
            		if (ptr1->data > ptr2->data) 
            		{	 
                		/* update the link after swapping */
               			*h = swapInList(ptr1, ptr2); 
                		isSwapped = 1; 
            		} 
            		h = &(*h)->next; 
        	} 
        	/* break if the loop ended without any swap */
        	if (isSwapped == 0) 
            		break; 
    	} 
} 
