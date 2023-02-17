/*
* Filename: f4.cpp
* Project: Focused Assignment 4
* By: Jongeon Lee
* Date: Feb 11, 2023
* Description: Write a program that gets integers from the user
               and determines which is the lowest.
*/

#include <stdio.h>

int getNum(void);

int main()
{
    /*
    * These are local variables
    * int i means counter.
    * int myArray means an array of 10 initialized to 0.
    * int minValue means a variable holding the minimum value of user inputs.
    *   - initial value 2,147,483,647 is maxmum value of int.
    * int minIndex means a variable holding the array index's minimum value.
    */
    int i = 0;
    int myArray[10] = { 0 };
    int minValue = 2147483647;
    int minIndex = 0;

    while (i < 10)
    {
        printf("Please input the value at index %d in the array: ", i);
        myArray[i] = getNum();

        /*
        * This if statement is to find the minimum value in the array.
        */
        if (myArray[i] < minValue)
        {
            minValue = myArray[i];
            minIndex = i;
        }
        i++;
    }
    printf("The lowest value is %d at index %d", minValue, minIndex);

    return 0;
}

/*
* Function: getNum()
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