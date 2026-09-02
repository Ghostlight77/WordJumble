#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	cout << "Let's Play Word Jumble!/n"
		<< "Enter 'hint' for a hint\n"
		<< "Enter 'exit' to give up!\n\n";

	vector<string> words = {"guitar", "violin", "tapestry"};

	srand(time(nullptr));

	char playAgain = 'y';

	while (tolower(playAgain) == 'y')
	{
		int index = rand() % words.size();
		string word = words[index];

		string jumbledWord = word;
		int length = word.size();

		for (int i = 0; i < length; i++)
		{
			int j = rand() % length;
			swap(jumbledWord[i], jumbledWord[j]);
		}

		cout << "The jumble is...";
		for (char c : jumbledWord)
		{
			cout << static_cast<char>(toupper(c));
		}
		cout << "\n\n";

		int hintCount = 0;
		string guess;

		while (true)
		{
			cout << "Your guess: ";
			cin >> guess;
			cin.ignore(1000, '\n');

			if (guess == word)
			{
				cout << "Congrats! You guessed it using " << hintCount <<
					" hint(s)!\n\n";
				break;
			}
			else if (guess == "hint")
			{
				hintCount++;
				cout << "Hint: ";
				for (int i = 0; i < word.length(); i++)
				{
					if (i < hintCount)
					{
						cout << static_cast<char>(toupper(word[i])) << ' ';
					}
					else
					{
						cout << "_ ";
					}
				}
				cout << "\n\n";
			}
			else if (guess == "exit")
			{
				cout << "You gave up! the word was: " << word << "\n\n";
				break;
			}
			else
			{
				cout << "Nope! try again";
			}
		}
		cout << "Do you want to play again? (y/n): ";
		cin >> playAgain;
		cin.ignore(1000, '\n');
	}
	cout << "Thanks for playing!!!!!\n";
	return 0;
}
