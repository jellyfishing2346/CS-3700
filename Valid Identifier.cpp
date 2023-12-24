// Faizan Khan
// Younes Taib

#include <iostream>
#include <string>
using namespace std;

// Remove the white spaces from the string
string trimTheSpaces(string space)
{
	int end;
	string ReturnString = "";
	int i = 0;
	for (i = 0; i < space.length(); i++)
	{
		if (space.at(i) != ' ')
		{
			break;
		}
	}
	for (end = space.length() - 1; end >= 0; end--)
	{
		if (space.at(end) != ' ')
		{
			break;
		}
	}

	for (; i <= end; i++)
	{
		ReturnString = ReturnString + space.at(i);
	}

	return ReturnString;
}

// This function only allows certain characters to be accepted
bool onlyLetters(const string &alphabetic)
{
	for (size_t input = 0; input < alphabetic.size(); input++)
	{
		if (!isalpha(alphabetic[input]) && !isdigit(alphabetic[input]))
		{
			cout << "Only letters and digits are acceptable.\n";
			return false;
		}
	}
	return true;
}

// The function focuses on the validation of the type and identifier
bool validIdentifier(string t, string id)
{ 
	string temp = id;
	if (id.length() == 0)
	{
		cout << "Invalid statement.\n";
		return false;
	}

	id.pop_back();
	// trim whitespace from identifier
	id = trimTheSpaces(id);

	// The type must be a double, int, or char
	if ((t != "double") && (t != "int") && (t != "char") && (t != "float"))
	{
		cout << "Syntax Error! Invalid program statement!\n";
		return false;
	}

	// The identifer must not start with a number
	else if (isdigit(id[0]))
	{
		cout << "Invalid identifier, identifier can not start with a number.\n";
		return false;
	}

	// The identifer can't be an int, double, or char
	else if ((id == "int") || (id == "double") || (id == "char") ||
		(id == "float"))
	{
		cout << "Invalid identifer, can't be int, double, or char.\n";
		return false;
	}

	// The last character in the identifier must be a semicolon
	else if (temp[temp.length() - 1] != ';')
	{
		cout << "Syntax error! Missing semicolon";
		return false;
	}
	else if (onlyLetters(id))
	{
		temp.pop_back();
		cout << "Variable is " << trimTheSpaces(temp) <<
			" and the type is " << t << endl;
		return false;
	}
	return false;
}

// Main function
int main()
{
	string type;
	string identifier;
	cout << "Enter a data type and an identifier: ";
	cin >> type;
	getline(cin, identifier);
	validIdentifier(type, identifier);
	cout << endl;
	system("PAUSE");
	return 0;
}