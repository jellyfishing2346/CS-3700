/*
	Name: Valid Division
	Copyright: 2022
	Author: Faizan Khan
	Date: 25/10/22 18:16
	Description: Write a program to enter a
	numerator and a denominator then to check
	if the values of those two numbers are
	valid to divide. 
*/

#include <iostream>
using namespace std;

// Check if the user enters 0 for the denominator
int checkDenominator(int denominator)
{
	// If the user enters 0 print the run-time error message
	if (denominator == 0)
	{
		throw runtime_error("SORRY - You are not allowed to divide by 0");
	}
	// Otherwise return the denominator
	else
	{
		return denominator;
	}
}

// Divide the numerator by the denominator
int integerDivision(int &numerator, int &denominator)
{

	int result;

	// Prompt the user to enter a numerator
	cout << "Numerator? ";
	cin  >>  numerator;
	cout << "Denominator? ";
	cin  >> denominator;


	// Store the value of numerator/denominator
	result = (numerator/checkDenominator(denominator));

	return result;
}

// Main function
int main()
{
	int num;
	int den;
	int quotient;
	
	// Check for the runtime error with den, if its valid, print the result
	try
	{
		quotient = integerDivision(num, den);
		cout << "Result: " << (num) << "/" << (den) << "= " << quotient << endl;
	} 
	// Otherwise, print the error message in main
	catch (runtime_error mathError)
	{	
		cout << mathError.what() << endl;
	}
	system("PAUSE");
	return 0;
}