/*
	Name: Sugar Levels 
	Copyright: 2022
	Author: Faizan Khan
	Date: 25/09/22 13:03
	Description: Using a vector and class to handle 
	the patient information. It can check, add, edit,
	retrieve, display or delete certain information
	for the patient. 
*/

#include <iostream>
#include <vector>
using namespace std;

// Setting up the info for a sugar patient
class SugarLevel
{
    private:
		string patientName;
		string country;
		string gender;
 		string birthDate; 
    	int sugarConsumption;
		int age;
    public:
		string get_patientName();
		int get_sugar();
		void retrievePatient();
 		void showPatient();
		void editPatient();
};

// Accessor returns the patient name
string SugarLevel::get_patientName()
{
	return patientName; 
}


// Retrieve the information for the patient
void SugarLevel::retrievePatient()
{
	cout << "\n What is the patient's name: ";
	cin.ignore();
	getline(cin, patientName);
	cout << "\n What is the patient's country: ";
	getline(cin, country);
	cout << "\n What is the patient's date of birth: ";
	getline(cin, birthDate);
	cout << "\n What is the patient's age: ";
	cin  >> age;
	cin.ignore(10, '\n');
  	if ((age < 1) || (age > 100))
	{
		cout << "\n Invalid input for age.";
      	cin  >> age;
      	cin.ignore(10, '\n');
	}
	cout << "\n What is the patient's gender: ";
	getline(cin, gender);
  	if ((gender != "male") && (gender != "female"))
	{
		cout << " Invalid input for gender.\n";
      	getline(cin, gender);
	}
	cout << "\n How much sugar do they consume: ";
	cin  >> sugarConsumption;
  	if (sugarConsumption < 1)
	{
		cout << "Invalid input for sugar consumption\n";
      	cin  >> sugarConsumption;
    }

	if ((sugarConsumption < 36) && (gender == "male") && (age < 35))
	{
		cout << "This young male is not at risk for diabetes.\n";
	}
	else if ((sugarConsumption > 36) && (gender == "male") && (age < 35))
	{
		cout << "This young male is at risk for diabetes.\n";
	}
	else if ((sugarConsumption < 36) && (gender == "male") && (age >= 35))
	{
		cout << "This middle age or older male is not at risk for diabetes.\n";
	}
	else if ((sugarConsumption > 36) && (gender == "male") && (age >= 35))
	{
		cout << "This middle age or older male is at risk for diabetes.\n";
	}
	else if ((sugarConsumption < 24) && (gender == "female") && (age < 35))
	{
		cout << "This young female is not at risk for diabetes.\n";
	}
	else if ((sugarConsumption > 24) && (gender == "female") && (age < 35))
	{
		cout << "This young female is at risk for diabetes.\n";
	}
	else if ((sugarConsumption < 24) && (gender == "female") && (age >= 35))
	{
	   cout << "This middle age or older female isn't at risk for diabetes.\n";
	}
	else if ((sugarConsumption > 24) && (gender == "female") && (age >= 35))
	{
		cout << "This middle age or older female is at risk for diabetes.\n";
	}
}

// Display the patient information
void SugarLevel::showPatient()
{
	cout << "Patient's name: " << patientName << endl;
	cout << "Patient's country: " << country << endl;
	cout << "Patient's date of birth: " << birthDate << endl;
	cout << "Patient's age: " << age << endl;
	cout << "Patient's gender: " << gender << endl;
	cout << "Patient's sugar consumption: " << sugarConsumption << endl;
}


// Edit the patient information
void SugarLevel::editPatient()
{
	int update;
	cout << "\nChanging patient's information...\n";
	do
	{
		cout << "\n 1. Change patient's sugar consumption\n"
			 << "\n 2. Change patient's gender\n"
			 << "\n 3. Change patient's age\n"
			 << "\n 4. Done"
			 << "\n Which change would you like to make with the patient: ";
		while (!(cin >> update) || update < 1 || update > 4)
		{
			cout << "Invalid input, please choose 1-4 only: ";
			cin.clear();
			cin.ignore(10, '\n');
		}
		if (update == 1)
		{
			cout << "The sugar consumption has been updated: ";
			while (!(cin >> sugarConsumption) || (sugarConsumption < 1))
			{
				cout << "Invalid input, only positive numbers are accepted.\n";
				cin.clear();
				cin.ignore(10, '\n');
			}
		}
		else if (update == 2)
		{
		  cout << "The gender has been updated: ";
		 while (!(cin >> gender) || (gender != "male" && gender != "female"))
		  {
			   cout << "Invalid input, only male or female is accepted.\n";
			   cin.clear();
			   cin.ignore(10, '\n');
		  }
        }
		else if (update == 3)
		{
		  cout << "The patient's age has been update: ";
		  while (!(cin >> age) || age < 1 || age > 100)
		  {
				cout << "Invalid input, enter a proper age number.\n";
				cin.clear();
				cin.ignore(10, '\n');
		  }
		}
		else if (update != 1 && update != 2 && update != 3 && update != 4)
		{
			cout << "Invalid input, try to enter the choice again.\n";
		}
	} 
	while (update != 4);
	cout << "The change is officially completed.\n\n";
}

// Accessor returns the amount of sugar consumed
int SugarLevel::get_sugar()
{
	return sugarConsumption;
}

// Main function
int main()
{
	vector<SugarLevel> sugarPatient;
	int options, i;
	int exit = 0;
	string patientName;
	int sugarConsumption; 

	cout << "Hello, welcome to the American Diabetes Association.\n";
	
	do
	{
		// Prompt the user to enter information
		cout << " \n 1. Check the patient list "
			 << " \n 2. Add a patient "
			 << " \n 3. Delete a patient "
			 << " \n 4. Display patient information "
			 << " \n 5. Update patient information "
			 << " \n 6. Display the healthiest patient "
			 << " \n 7. Exit";
		cin  >> options;
		switch(options)
		{
			case 1:
			{
				if (sugarPatient.size() == 0)
				{
					cout << "Empty Patient List.\n";
				}
				else
				{
					cout << "Full Patient List.\n";
				}
				break;
			}
			case 2:
			{
				SugarLevel ADApatient;
				ADApatient.retrievePatient();
				sugarPatient.push_back(ADApatient);
				cout << "Patient # " << sugarPatient.size() << ": "
					 << ADApatient.get_patientName() << endl;
              	cout << "Patient added to list.\n" << endl;
				break;
			}
			case 3:
			{
				int numPat = 1; 
				cout << "Which patient do you want to delete?:\n";
				do
				{
					if (numPat > sugarPatient.size() || numPat < 1)
					{
						cout << "Invalid input.\n";
					}
						cin >> numPat;
				} 
				while(numPat > sugarPatient.size() || numPat < 1);
				sugarPatient.erase(std::begin(sugarPatient) + numPat - 1);
				cout << "Patient " << numPat << " is deleted.\n\n";
				break;
			}
			case 4:
			{
                if (sugarPatient.size() == 0)
				{
					cout << "Please enter a patient.\n";
				}
				else
				{
					for (int index = 0; index < sugarPatient.size(); index++)
					{
						sugarPatient[index].showPatient();
					}
                }
                break;
			}
			case 5:
			{	
				cout << "Which patient do you wish to update.\n";
                cin.ignore();
                getline(cin, patientName);
				if (sugarPatient.size() == 0)
				{
					cout << "Please enter a patient.\n";
				}
				else
				{
					for (int index = 0; index < sugarPatient.size(); index++)
                    {
                       if (patientName == sugarPatient[index].get_patientName())
                        {
                            sugarPatient[index].editPatient();
                        }
                    }
				}
				break;	
			}
			case 6:
			{
				int minisugar = 100;
    			for (int index = 0; index < sugarPatient.size(); index++)
				{
					if (sugarPatient[index].get_sugar() < minisugar)
					{
						patientName = sugarPatient[index].get_patientName();
                        minisugar = sugarPatient[index].get_sugar();
					}
					if (sugarPatient.size() > 0)
					{
						cout << "Patient name: " << patientName << " is clean!"
					         << endl;
					}
					else
					{
						cout << "Empty Patient List.\n";
					}
				}
			}	 	
			case 7:
			{
				exit = 1;
				break;
			}	
			 default:
              	cout << "Invalid input selected please select options 1-7: ";		
		}
	} while(exit != 1);
	cout << "Thank you for using the American Diabetes Association.\n";
	system("PAUSE");
	return 0; 
}