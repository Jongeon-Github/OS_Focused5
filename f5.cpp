/*
* Filename: f5.cpp
* Project: Focused Assignment 5
* By: Jongeon Lee
* Date: Feb 24, 2023
* Description: Revise Focused 4 to use functions.
*/

#include <stdio.h>

int getNum(void);
int modifyArrayValues(int inArray[], int length);
int minArrayValue(int inArray[], int length);

int main()
{
    const int kLength = 10;
    int getArray[kLength] = { 0 };
    int minIndex = 0;
    modifyArrayValues(getArray, kLength);
    minIndex = minArrayValue(getArray, kLength);
    
    printf("The lowest value is %d at index %d", getArray[minIndex], minIndex);
    
    return 0;
}

/*
* Function: getNum(void)
* Description: This function takes in user input and outputs it as a variable.
* Parameters: int void
* Returns: int number: the entered number is printed.
           -1 if the user did not enter a number recognizable by the system.
*/

#pragma warning(disable: 4996) // required by Visual Studio
int getNum(void)
{
    /* the array is 121 bytes in size; we'll see in a later lecture how we can
    improve this code */
    char record[121] = { 0 }; /* record stores the string */
    int number = 0;
    /* NOTE to student: brace this function consistent with your others */
    /* use fgets() to get a string from the keyboard */
    fgets(record, 121, stdin);
    /* extract the number from the string; sscanf() returns a number
    * corresponding with the number of items it found in the string */
    if (sscanf(record, "%d", &number) != 1)
    {
        /* if the user did not enter a number recognizable by
        * the system, set number to -1 */
        number = -1;
    }
    return number;
}

/*
* Function: modifyArrayValues(int inArray[10])
* Description: This replaces getting the user values in main.
* Parameters: int inArray[10] - integer array of 10 numbers elements.
* Returns: Nothing
*/
int modifyArrayValues(int inArray[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Please input the value at index %d in the array: ", i);
        inArray[i] = getNum();
    }
    return 0;
}

/*
* Function: minArrayValue(int inArray[10)
* Description: This is for finding the minimum value and its index.
* Parameters: int inArray[10] - integer array of 10 numbers elements.
* Returns: The index which is the minimum value.
*/
int minArrayValue(int inArray[], int length)
{
    int typemaxValue = 2147483647;
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        if ( typemaxValue >= inArray[i])
        {
            typemaxValue = inArray[i];
            index = i;
        }
    }
    return index;
}