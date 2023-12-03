#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


#include <Windows.h>
#include <stdlib.h>

using namespace std;





std::string words[] = {
		"game",
		"minimum",
		"mature",
		"mile",
		"pollution",
		"desire",
		"hurt",
		"road",
		"excess",
		"ground",
		"reality",
		"chimpanzee",
		"exemption",
		"safari",
		"reaction",
		"romantic",
		"respectable",
		"recruit",
		"clue",
		"claim",
		"conversation",
		"scan",
		"trade",
		"tire",
		"apathy",
		"crystal",
		"new",
		"cancer",
		"artificial",
		"creep",
		"knot",
		"episode",
		"effective",
		"owl",
		"passion",
		"pepper",
		"sickness",
		"progress",
		"adjust",
		"landowner",
		"provision",
		"moon",
		"complain",
		"belly",
		"affect",
		"vegetarian",
		"barrier",
		"stage",
		"even",
		"therapist"
};


vector<int> LetterCheck(string letter, string word)
{

	vector<int> places;
	int amout = 0;

	for (int i = 0; i < word.length(); i++)
	{
		if (letter.at(0) == word.at(i))
		{
			amout++;
			places.push_back(i);
		}

	}

	return places;

}


bool VectorStringHasVar(vector<string> vector, string var)
{
	bool final = false;
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i] == var)
		{

			final = true;

		}
		else
		{

			final = false;

		}


	}
	return final;


}

std::vector<std::string> HangMan = {
	R"(
  +---+
  |   |
      |
      |
      |
      |
=========)",
	R"(
  +---+
  |   |
  O   |
      |
      |
      |
=========)",
	R"(
  +---+
  |   |
  O   |
  |   |
      |
      |
=========)",
	R"(
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========)",
	R"(
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========)",
	R"(
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========)",
	R"(
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========")"
};


void PrintVector(vector<string> list, string sep = " ")
{
	string final;
	for (int i = 0; i < list.size(); i++)
	{
		final.append(list[i]);
		final.append(sep);
		

	}
	cout <<(final + "\n");
}

//main vars
vector<string> WordHidden;

int misses = 0;
string Guess;
string word;
int LettersGuessedRight;
vector<string> LettersGuessed;

void guess()
{
	std::cout << "Hang Man!\n";
	//cout << word;
	cout << HangMan[misses] << "\n";
	PrintVector(WordHidden);
	cout << ("Letters you Guesses:\n ");
	PrintVector(LettersGuessed, ", ");

	cout <<("Guess a letter or word:");
	std::cin >> Guess;

	if (misses != 6)
	{
	

		if (Guess.length() > 1)
		{
			if (Guess == word)
			{

				cout <<("correct");

			}
			else {

				misses++;
				system("CLS");
				cout <<("You Guessed Wrong\n");
				Sleep(1000);

				guess();

			}

		}
		else
		{


			if (LetterCheck(Guess, word).size() >= 1)
			{
				if (VectorStringHasVar(LettersGuessed, Guess) == true)
				{
					system("CLS");
			
					cout <<("You Guessed that letter\n");
					Sleep(1000);
					guess();
			
				}
				else if(VectorStringHasVar(LettersGuessed, Guess) == false)
				{
					LettersGuessed.push_back(Guess);

					for (int i = 0; i < LetterCheck(Guess, word).size(); i++)
					{

						WordHidden[LetterCheck(Guess, word)[i]] = Guess;
						cout << "Vector size:" << LetterCheck(Guess, word).size() << "\n";

					}
					LettersGuessedRight = LettersGuessedRight + LetterCheck(Guess, word).size();
					system("CLS");
					if (LettersGuessedRight == word.size())
					{
						cout <<("Correct\n");
						cout <<("The word was " + word);
					}
					else
					{
						guess();
					}


				}


			}
			else {

				//wrong 
				system("CLS");
				LettersGuessed.push_back(Guess);
				misses++;
				cout <<("Letter guessed is wrong\n");
				Sleep(1000);
				guess();

			}
		}
	}
	else
	{
		cout << ("You lost\n");
		cout << ("The word was " + word);
	}

}

void game()
{
	//no letter = 18446744073709551615
	srand(time(nullptr));
	int WordNum = rand() % 50 + 1;
	word = words[WordNum];

	//setup hidden word
	for (int i = 0; i < word.size(); i++)
	{

		WordHidden.push_back("-");

	}

	guess();

}

int main()
{

	srand(time(nullptr));
	game();

}
