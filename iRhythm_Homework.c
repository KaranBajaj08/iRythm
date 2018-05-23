#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Largest_three_result{
int32_t first;
int32_t second;
int32_t third;
};


//******************************************************
// Function:         find_largest3()
//
// Author:           Karan
// Creation date:    04/25/2018
// Description:      This method finds the largest three
//                   numbers in an array and returns a resultant structure
//                   holding those values.
// Parameters:       int array, int variable
// Return:           Largest_three_result structure
//*******************************************************


struct Largest_three_result find_largest3(int32_t array[], uint8_t size)
{
    /* Check for size greater than 2 */
    //int i, first, second, third;
    uint8_t i;
    struct Largest_three_result result;

    /* There should be atleast two elements */
    if (size < 3 || size >100)
    {
        result.first=0;
        result.second=0;
        result.third=0;
        return result;
    }

    //third = first = second = INT_MIN;
    result.third=result.second=result.first=INT_MIN;
    for (i = 0; i < size ; i ++)
    {
        if(array[i]!='\0')
        {
        /* If current element is smaller than first*/
        if (array[i] > result.first)
        {
            result.third = result.second;
            result.second = result.first;
            result.first = array[i];
        }

        /* If arr[i] is in between first and second then update second  */
        else if (array[i] > result.second)
        {
            result.third = result.second;
            result.second = array[i];
        }

        else if (array[i] > result.third)
            result.third = array[i];
        }
        else{
        result.first=0;
        result.second=0;
        result.third=0;
        return result;

    }
    }



    return result;
    }





// Test to check for size less than 2

bool Unit_test_1(struct Largest_three_result result)
{
    int32_t array[5]={1,2,3,4,5};
    uint8_t size=2;
    result=find_largest3(array, size);
    if(result.first==0 && result.second==0 && result.third==0)
    {

            return true;

    }
    else{

            return false;

    }


}

// test valid values
bool Unit_test_2(struct Largest_three_result result)
{
    int32_t array[5]={1,2,3,4,5};
    uint8_t size=5;
    result=find_largest3(array, size);
    if(result.first==5 && result.second==4 && result.third==3)
    {
            return true;

    }
    else{

            return false;

    }


}

// test upper limit size >100
bool Unit_test_3(struct Largest_three_result result)
{
    int32_t array[5]={1,2,3,4,5};
    uint8_t size=101;
    result=find_largest3(array, size);
    if(result.first==0 && result.second==0 && result.third==0)
    {

            return true;

    }
    else{

            return false;

    }


}

//test if mismatched array size and length are specified

bool Unit_test_4(struct Largest_three_result result)
{
    int32_t array[5]={1,2,3,4,5};
    uint8_t size=99;
    result=find_largest3(array, size);
    if(result.first==0 && result.second==0 && result.third==0)
    {

            return true;

    }
    else{

            return false;

    }


}

// Test Decimal values

bool Unit_test_5(struct Largest_three_result result)
{
    int32_t array[5]={1,1.2,3.2,4.2,5};
    uint8_t size=5;
    result=find_largest3(array, size);
    if(result.first==5 && result.second==4 && result.third==3)
    {

            return true;

    }
    else{

            return false;

    }


}




int main()
{


    // Unit test code below

    struct Largest_three_result result;
    bool result_1=Unit_test_1(result); // validate size <2
    bool result_2=Unit_test_2(result); // validate valid values
    bool result_3=Unit_test_3(result); // validate size >100
    bool result_4=Unit_test_4(result); // validate size >100
    bool result_5=Unit_test_5(result); // validate decimal values

    //if((result_1 == true) && result_2==true && result_3==true && result_4==true && result_5=true )
    if((result_1==true) && (result_2==true) && (result_3==true) && (result_4==true) && (result_5==true) )
    {
        printf("Test Suite Passed!");
    }
    else
    {
        printf("Test Suite Failed");
    }




}
