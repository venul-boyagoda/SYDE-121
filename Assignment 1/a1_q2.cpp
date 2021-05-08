//****************************************************************************
// Student Name: Venul Boyagoda
// Student Number:20909488
//
// SYDE 121 Assignment: 1
// Filename: a1_q2
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Sum of integers from a to l
// Purpose: Calculate the sum of the integers from the user inputted starting
//          value to end value.
// Due Date: Friday, September 25, 2020
//**************************************************************

/*
Testing:
I used an online calculator which calculates the sum of integers from a certain starting value
to an ending value.

By using the above method, I verified my program works with the following values:
0 to 10, 40 to 50, 500 to 900, 1038 to 5000

An input of 1 and 500 outputs the correct value which is:
125250
An input of 5 and 2020 outputs the correct value which is:
2041200
An input of 42 and 32000 outputs the correct value which is:
512015139

The range of values for which my program will work correctly is where the sum
is between 0 and 2147483647 since the sum is an int and those are the
ranges of values int can hold.
*/

#include <iostream>
using namespace std;

void sum_of_arithmetic_series()
{
    //declare and initialize variables
    int a = 0; //starting value
    int l = 0; //ending value
    double n = 0; //number of terms
    int sum = 0;
    const int D = 1; //difference
    
    //get input from user
    cout << "Please enter the starting value.\n";
    cin >> a;
    cout << "Please enter the ending value.\n";
    cin >> l;
    
    //calculate sum
    n = l - a + 1;
    sum = (n/2)*((2*a) + ((n-1)*D));
    
    //ouput sum to console
    cout << "The sum is " << sum << " based on your starting value of " << a
    << " and your ending value of " << l << "\n";
}


int main()
{
    sum_of_arithmetic_series();
}
