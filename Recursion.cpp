/*
	Name: Recursion
	Copyright: 2022
	Author: Faizan Khan
	Date: 03/10/22 22:47
	Description: Read a mathematical expression
	to deal with the string length(possibly infinite)
    that it must be terminated with a semicolon.
    Determine that the paranthesis is balanced or not.
*/

#include <iostream>
#include <string>
using namespace std;

// Determine if there are letters in the user's input
bool CheckLetters(string string, int index)
{
  if (index == string.length())
  {
     return true;
  }
  if (isalpha(string.at(index)))
  {
     return false;
  }
  else
  {
    return CheckLetters(string, index + 1);
  }
}

// Determine if there are digits and operators in the user's input
bool CheckDigits(string input, int index, int numbers, int op)
{
  if (index == input.length() - 1)
  {
    // Check if the digits and operators are in correct proportion
    if (numbers <= op)
	{
		return false;
	}
    return true;
  }
  if (isdigit(input.at(index)))
  {
    // Loop until either at the end (aka, input.length()
	return CheckDigits(input, index + 1, numbers + 1, op);
  }
    
  if(input.at(index) == '+' || input.at(index) == '-' || input.at(index) == '*' 
	 || input.at(index) == '/')
  {
    // Return checkDigits, with index+1, and operator+1
    return CheckDigits(input, index + 1, numbers, op + 1);
    
  }
  else
  {
    //generally correct, just pass on the other arguments
    return CheckDigits(input, index + 1, numbers, op);
  }
}

// Check the count of left and right paranthesises plus the semicolon
bool CheckPar(string exp, int index, int leftCount, int rightCount)
{
  if (index == exp.length())
  {
	 return false;
  }
  if (exp.at(index) == ';')
  {
      if(leftCount == rightCount && leftCount > 0 && rightCount > 0)
      {
          return true;
      }
	  else if(leftCount != rightCount && leftCount == 0 && rightCount == 0)
	  {
	      return false;
	  }
   	  else
      {
          return false;
      }
  }
  else
  {
	if (exp.at(index) == '(')
	{
		leftCount++;
	}
	else if (exp.at(index) == ')')
	{
		rightCount++;
	}
	return CheckPar(exp, index + 1, leftCount, rightCount);
  }
}

// Main function
int main()
{
  string str;
  int index = 0;
  int x, num = 0;
  int operators = 0;
  cout << "Enter an expression: ";
  getline(cin, str);
  bool result = CheckPar(str, 0, 0, 0) && CheckLetters(str, index)
                && CheckDigits(str, index, num, operators);
  if(result == 0)
  {
       cout << "Invalid Input" << endl;
  }
  else
  {
       cout << "Valid Input" << endl;
  }
  cout << "The result " << result << endl;
  system("PAUSE");
  return 0;
}
