/*
	Name: Election
	Copyright: 2022
	Author: Faizan Khan 
	Date: 21/11/22 14:54
	Description: Designing an evote system
	that has a file of listed voters. Check
	if the voter is in the system, if so
	ask them to vote, then check if they vote
	already. Organize the voter's data and
	determine the winner.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// This class contains the following info for the e-voting system
class ElectionInfo
{
private:
	
    vector<int>id;
	vector<bool>voted;
	vector<string>candidate;
	vector<int>counts;
	int voterId;
	int votes;
	int electionResults;
	int voteTally;
	string voterCandidate;
	fstream audit; 
public:
	ElectionInfo();
	void voterList();
	void voterTally();
	void voterAudit();
	void voterResults();
};

ElectionInfo::ElectionInfo()
{
	audit.open("AuditTrailing.txt", ios::app);
}

// Voter list
void ElectionInfo::voterList()
{

	int i, v;

	// Prompt the user to enter some voter Id
	cout << "Welcome to the Kingsborough CS Evote System" << endl;
	cout << "---------------------------------------------" << endl;	
	
	int voterOption;
	
	// Open the VotedId.txt
	fstream fileInfo;
	fileInfo.open("VotedId.txt", ios::in);


	// Access the voted section with the user's id number
	while(fileInfo >> i)
	{
		// Push back the id number and see if they voted
		id.push_back(i);
	
		fileInfo >> v;
		// If the voted section is empty , push back false
		if (v == 0)
		{
			voted.push_back(false);
		}

		// Otherwise push back true 
		else
		{
			voted.push_back(true);
		}	
	}
	
	// Close the file
	fileInfo.close();
	

	bool end = false;
	
	while (end== false)
	{
		cout << "Voter ID?";
		cin  >> voterId;

		// Flag
		int idIndex = -1;	

		// Go through the id list
		for (int k = 0; k < id.size(); k++)
		{

			// If the id is in the list, print the fraud message
			if (voterId == id[k])
			{
				if (voted[k] == 1)
				{	
					cout << "YOU VOTED ALREADY! No fraud allowed here!" << endl;
					cout << "Have a nice day!" << endl;  
					cout << "_______________________________________________\n";
					idIndex = 0; 
					return;
				}
				idIndex = k;
				break;		
			}

		 
		}	
				
          idIndex = 0; 
		  for (int j = 0; j < id.size(); j++)
		  {
				if (voterId == id[j])
				{
					idIndex = 1;
				}
		  }
          // If the id is not in the list, then they can't vote in this district
		  if (idIndex == 0)
		  { 
			 cout << voterId << " is not a valid ID in this district!" << endl;
			 cout << "Go to your own voting district where ever that is!\n";
			 cout << "Have a nice day!" << endl;
			 cout << "_____________________________________________________\n";
		  }	
	
	// Check the flag if is true
	if (idIndex == 1)
	{
		// Vote Menu
		cout << "WELCOME!" << endl;
		cout << "EVOTE" << endl;
		cout << "--------" << endl;
		voterTally();
		cout << "1) Kathy Hocul\n"
			 << "2) Lee Zeldin\n"
			 << "3) Mickey Mouse\n";
		cin  >> voterOption;

		
		// If the user enters one of the approved choices, accept their vote
		if (voterOption == 1 || voterOption == 2 || voterOption == 3)
		{
			cout << "Thank you for your vote!!" << endl;
		}
		
		// Otherwise reject their option, with an error message
		else
		{
			cout << "This is not a valid voter option!" << endl; 
		}


		idIndex = 1; 

		for (int l = 0; l < voted.size(); l++)
		{
			if (voted[l] != 1)
			{
				idIndex = 0; 
				
	
			}
		}

        if (idIndex == 0)
		{
			char choice;	
			cout << "Do you wish to continue?(Y/N) ";
			cin  >> choice;
					
			
			if (choice == 'N')
			{
				cout << "Have a nice day!" << endl;
				return; 
			}
		}
		
	}
	voterTally();
    voterAudit();
	}
}


// Tally the number of votes
void ElectionInfo::voterTally()
{

	string str;
	int voterOption;
	int num;
	ifstream VotingTally("Tally.txt", ios::app);

	while (VotingTally >> str)
	{
		candidate.push_back(str);
		VotingTally >> num;
		counts.push_back(num);
	} 
		
	
	for (int i = 0; i <= candidate.size(); i++)
	{
		cout << candidate[i] << endl;
	}

	cin  >> voterOption;

	// If the user enters one of the approved choices, accept their vote
	if (voterOption == 1 || voterOption == 2 || voterOption == 3)
	{
		cout << "Thank you for your vote!!" << endl;
		counts[voterOption-1]++;
	}

	// Otherwise reject their option, with an error message
	else
	{
		cout << "This is not a valid voter option!" << endl;
	}
	VotingTally.close();
	
	ofstream voting("Tally.txt");
	voting.open("Tally.txt", ios::in);
	for (int i = 0; i < counts.size(); i++)
	{
		voting << candidate[i] << " " << counts[i];
	}
	voting.close();
}


// Audit the voter records
void ElectionInfo::voterAudit()
{
	audit.open("AuditTrail.txt");

}

// Retrieve the voter's results
void ElectionInfo::voterResults()
{
	cout << "The winner is: " << voterCandidate;
}

// Main function
int main()
{
	int adminCode;
	ElectionInfo voter;
	int choice;
	
	// If the admin code is not correct keep asking them for the right one
	while(adminCode != 12345)
	{
		cout << "Enter admin code? ";
		cin  >> adminCode;

		// If the voter enters the correct admin code, then show the admin menu
		if (adminCode == 12345)
		{
			cout << "Admin menu" << endl;
			cout << "------------" << endl;
			cout << "1) Show current Voter Tally" << endl;
			cout << "2) Show list of all voter records (ID's and"
                 << " whether they voted or not)" << endl;
			cout << "3) Show audit trail that records everything entered"
                 << " in the system" << endl;
			cout << "4) End election and report results" << endl;
			cin  >> choice;
			
			// If the choice is 1, call the tally function
			if (choice == 1)
			{
				voter.voterTally();
			}
			
			// If the choice is 2, call the list function
			else if (choice == 2)
			{
				voter.voterList();
			}

			// If the choice is 3, call the audit function
			else if (choice == 3)
			{
				voter.voterAudit();
			}

			// If the choice is 4, call the results function
			else if (choice == 4)
			{
				voter.voterResults();
			}

			// Otherwise, enter a valid choice for the admin menu
			else
			{
				cout << "Please Enter a valid choice" << endl;
			}
		}

		// Otherwise, the admin code is incorrect
		else
		{
			cout << "This code is not valid" << endl;
		}
	}
    
	
	system("PAUSE");
	return 0;
}