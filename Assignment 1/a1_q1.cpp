//****************************************************************************
// Student Name: Venul Boyagoda
// Student Number:20909488
//
// SYDE 121 Assignment: 1
// Filename: a1_q1
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Balance Scale Weights
// Purpose: Calculate number of each type of weight required to weigh an
//          object of a user inputted weight.
// Due Date: Friday, September 25, 2020
//**************************************************************

/*
 Testing:
 I used a calcultaor and divided the test value by the heaviest weight type(125),
 then rounded down to the nearest whole number. I then multiplied that whole
 number by the weight(125) of the weight type and subtracted that prodeuct from the weight
 to find the weight left. This process was repeasted with the weight type going to the next
 largest one each time until the weight left was 0.
 
 By using the above method, I verified my program works with the following values:
 0, 2, 16, 43, 75, 78, 130, 500, 4089, 95000
 
 An input of 2048 outputs the correct value which is:
 "The number of 125 lb weights required is 16
 The number of 75 lb weights required is 0
 The number of 42 lb weights required is 1
 The number of 15 lb weights required is 0
 The number of 1 lb weights required is 6"
 
 The range of values for which my program will work correctly is from
 0 to 2147483647 which is the greatest value int can hold.
 */

#include <iostream>
using namespace std;

void number_of_weight_type_calculation()
{
    //declare and initialize variables
    int weight_entered = 0;
    int weight_left = 0;
    int weights_of_125 = 0;
    int weights_of_75 = 0;
    int weights_of_42 = 0;
    int weights_of_15 = 0;
    int weights_of_1 = 0;
    
    //get input from user
    cout << "Please enter a weight value.\n";
    cin >> weight_entered;
    cout << "You entered " << weight_entered << " for the weight value.\n";
    
    //perform calculation of how many of each weight type required
    weights_of_125 = weight_entered/125;
    if (weight_entered%125 > 0)
    {
        weight_left = weight_entered - (weights_of_125*125);
        weights_of_75 = weight_left/75;
        if (weight_left%75 > 0)
        {
            weight_left -= (weights_of_75*75);
            weights_of_42 = weight_left/42;
            if (weight_left%42 > 0)
            {
                weight_left -= (weights_of_42*42);
                weights_of_15 = weight_left/15;
                if (weight_left%15 > 0)
                {
                    weight_left -= (weights_of_15*15);
                    weights_of_1 = weight_left;
                }
            }
        }
    }
    
    //output result to console
    cout << "The number of 125 lb weights required is " << weights_of_125
    << "\n";
    cout << "The number of 75 lb weights required is " << weights_of_75
    << "\n";
    cout << "The number of 42 lb weights required is " << weights_of_42
    << "\n";
    cout << "The number of 15 lb weights required is " << weights_of_15
    << "\n";
    cout << "The number of 1 lb weights required is " << weights_of_1
    << "\n";
}


int main()
{
    number_of_weight_type_calculation();
}
