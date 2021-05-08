//****************************************************************************
// Student Name: Venul Boyagoda
// Student Number:20909488
//
// SYDE 121 Assignment: 2
// Filename: a2_q1
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Primes, Palindromes, Odd sum of digits
// Purpose: Determine which integers are prime, palindromes and have an odd sum of digits
// for all integers less than a user enetered integer greater than 1
// Due Date: Friday, October 9, 2020
//**************************************************************

/*
 Tested the values: 10, 50, 919, 99999, 205678, 10000000
 
 Using a list of prime number, and a list of palindromes up to 1000000, and an online calculator
 to see if the sum of digits were odd, I determined that all the above test values produced
 correct results.
 
 The range of values the user could input would be from 2 to 2147483647 which is the greatest
 value int can hold.
 
 However, realistically in order for the program to run for a reasonable amount of time before
 outputting the result, the range of values would be fron 2 to about 10000000 which takes about
 30 seconds.
 */

#include <iostream>
#include <cmath>
using namespace std;

void set_integer(int& int_val);
// Purpose: Allows user to set integer value
//      INPUTS: int_val - integer value reference that will contain user entered integer value
//      OUTPUTS: nothing; value is passed by reference

void compute_stats(int index);
// Purpose: Processes user enetered value to determine primes, palindromes and odd sums of digits
//      INPUTS: index - integer value that will contain a nu,ber from 2 to the user enetered integer
//      OUTPUTS: nothing

void output_stats(int index, int int_val);
// Purpose: Outputs proper stat for each integer between 2 and user enetered integer
//      INPUTS: index - integer value that will contain a nu,ber from 2 to the user enetered integer
//      OUTPUTS: nothing

void execute_a2_q1();
// PURPOSE: Runs the steps of the program


void set_integer(int& int_val)
{
    // step1. allows user to enter integer value until user enters an integer greater than one
    while (int_val <= 1)
    {
        cout << "Please enter an integer that is greater than 1" << endl;
        cin >> int_val;
    }
}

void compute_stats(int index)
{
    //[setup] declare and initialize variables
    bool is_prime = true;
    bool is_palin_prime = false;
    bool is_odd_digit_sum_prime = false;
    
    // step1.1 loop through all numbers between 2 and index to determine if index is a prime value
    for (int iterator = 2; iterator <= sqrt(index); iterator++)
    {
        if (index % iterator == 0)
        {
            is_prime = false;
            break;
        }
    }
    // step1.2 check if index is a palindrome
    if ((index < 10000 && is_prime && index % 10000 / 1000 == index % 10 && index % 1000 / 100 == index % 100 / 10) || (index < 1000 && is_prime && index % 1000 / 100 == index % 10) || (index < 100 && is_prime && index % 100 / 10 == index % 10) || (index < 10))
        is_palin_prime = true;
    // step 1.3 check if sum of digits in index is odd
    if (index < 100000 && ((index % 100000 / 10000) + (index % 10000 / 1000) + (index % 1000 / 100) + (index % 100 / 10) + (index % 10)) % 2 != 0)
        is_odd_digit_sum_prime = true;
    
    // step2. output whether index is palindromic prime with odd sum of integers, palindromic prime, prime with odd sum of integers, or prime
    if (is_prime && is_palin_prime && is_odd_digit_sum_prime)
        cout << "Palindromic prime with odd sum of digits: " << index << endl;
    else if (is_prime && is_palin_prime)
        cout << "Palindromic prime: " << index << endl;
    else if (is_prime && is_odd_digit_sum_prime)
        cout << "Prime with odd sum of integers: " << index << endl;
    else if (is_prime)
        cout << "Prime: " << index << endl;
}


void output_stats(int index, int int_val)
{
    // step1. loop through all integers between 2 and user enetered integer and output stats accordingly for each number (only if prime)
    for (index = 2; index <= int_val; index++)
    {
        compute_stats(index);
    }
}


void execute_a2_q1()
{
    //[SETUP] declare and initialize variables
    int int_val = 0;
    int index = 0;
    
    //[Input] step1. allow user to set the integer
    set_integer(int_val);
    
    //[PROCESSING] step2. compute required output values from user set integer
    //and [Output] step3. output results to console
    output_stats(index, int_val);
}

int main()
{
    execute_a2_q1();
}
