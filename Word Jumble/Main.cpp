#include <iostream>
using namespace std;

#include <cstdlib>
#include <ctime>
#include <string>

class jumbleMenus {
public:
	void exitMenu() {
		system("CLS");
		int exitDecision = NULL;
		cout << "\n\n\tAre you sure you want to exit?";
		cout << "\n\n\t1.) Yes.";
		cout << "\n\t2.) No.\n\n\t";

		while (exitDecision == NULL) {
			cin >> exitDecision;
			switch (exitDecision) {
			case 1:
				exit(0);
			case 2:
				mainMenu();
			default:
				cout << "\n\tPlease input a proper value.\n";
				exitDecision = NULL;
			}
		}
	}

	void creditsMenu() {
		system("CLS");
		int creditsDecision = NULL;
		cout << "\n\n\tThe improvements were made by Jacob, Skyler, Riley, and Keegan.";
		cout << "\n\tOriginal code by Nelson.";
		cout << "\n\n\t1.) Back to main menu.";
		cout << "\n\t2.) Exit.\n\n\t";

		while (creditsDecision == NULL) {
			cin >> creditsDecision;
			switch (creditsDecision) {
			case 1:
				mainMenu();
			case 2:
				exitMenu();
			default:
				cout << "\n\tPlease input a proper value.\n";
				creditsDecision = NULL;
			}
		}
	}

	void game() {
		system("CLS");
		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 5;
		const string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{ "wall", "Do you feel you're banging your head against something?" },
		{ "glasses", "These might help you see the answer." },
		{ "labored", "Going slowly, is it?" },
		{ "persistent", "Keep at it." },
		{ "jumble", "It's what the game is all about." }
		};

		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);
		string theWord = WORDS[choice][WORD];  // word to guess
		string theHint = WORDS[choice][HINT];  // hint for word
		int guessAmount = 0; // amount of guesses

		string jumble = theWord;  // jumbled version of word
		int length = jumble.size();
		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

		cout << "\n\n\tType 'hint' for a hint!";
		cout << "\n\tYou've guessed 0 times!";
		cout << "\n\tYour jumble is; ";
		cout << "\n\t  " << jumble;

		string guess;
		cout << "\n\n\tYour guess: ";
		while (guess != theWord) {
			cin >> guess;
			system("CLS");
			guessAmount = guessAmount + 1;
			cout << "\n\n\tType 'hint' for a hint!";
			cout << "\n\tYou've guessed " << guessAmount << " times!";
			cout << "\n\tYour jumble is: ";
			cout << "\n\t  " << jumble;
			if (guess == "hint") {
				cout << "\n\n\tHint: " << theHint << "\n\n";
			}
			cout << "\n\n\tYour guess: ";
		}

		system("CLS");
		cout << "\n\n\tYou win!";
		cout << "\n\tYou guessed the word in " << guessAmount << " attempts.\n\n";
		system("PAUSE");
		mainMenu();
	}

	void mainMenu() {
		system("CLS");
		int menuDecision = NULL;
		cout << "\n\n\tWelcome to word Jumble!\n";
		cout << "\n\t1.) Start a new game.";
		cout << "\n\t2.) Credits.";
		cout << "\n\t3.) Exit.\n\n\t";

		while (menuDecision == NULL) {
			cin >> menuDecision;
			switch (menuDecision) {
			case 1:
				game();
			case 2:
				creditsMenu();
			case 3:
				exitMenu();
			default:
				cout << "\n\tPlease input a proper value.\n";
				menuDecision = NULL;
			}
		}
	}
};

int main()
{
	jumbleMenus jumbleMenus;

	system("CLS");
	int menuDecision = NULL;
	cout << "\n\n\tWelcome to Word Jumble!\n";
	cout << "\n\t1.) Start a new game.";
	cout << "\n\t2.) Credits.";
	cout << "\n\t3.) Exit.\n\n\t";

	while (menuDecision == NULL) {
		cin >> menuDecision;
		switch (menuDecision) {
		case 1:
			jumbleMenus.game();
		case 2:
			jumbleMenus.creditsMenu();
		case 3:
			jumbleMenus.exitMenu();
		default:
			cout << "\n\tPlease input a proper value.\n";
			menuDecision = NULL;
		}
	}

	return 0;
}