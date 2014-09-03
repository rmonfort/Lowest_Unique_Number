#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::vector;
using std::stoi;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs,line))
	{
		istringstream iss(line);
		string temp;
		vector<int> numbers;

		// Load numbers in line into an vector of ints
		while (getline(iss, temp, ' '))
		{
			int num = stoi(temp);
			numbers.push_back(num);
		}

		// Find the lowest unique number amongst the players
		int player_number = 0;
		int player_pick = 0;
		for (size_t i = 0; i < numbers.size(); i++)
		{
			int count = std::count(numbers.begin(), numbers.end(), numbers[i]);
			if (count == 1)
			{
				if (player_pick == 0 || player_pick > numbers[i])
				{
					player_number = i;
					++player_number;
					player_pick = numbers[i];
				}
				
			}
		}
		// Print winner
		cout << player_number << endl;
	}

	return 0;
}