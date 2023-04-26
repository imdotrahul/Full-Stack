#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int MAX_PUZZLES = 20;
const int MAX_GUESSES = 7;

void welcomeScreen();
void loadPuzzles(string puzzles[], bool used[], int &numPuzzles);
void displayPuzzle(const string &puzzle, const bool guessed[]);
char getGuess();
bool updateGuesses(const string &puzzle, const char guess, bool guessed[], int &remaining);
bool playAgain();
void printStats(int wins, int losses);
void printPuzzles(const string puzzles[], const bool used[], int numPuzzles);

int main()
{
    string puzzles[MAX_PUZZLES];
    bool used[MAX_PUZZLES] = {false};
    int numPuzzles = 0;
    int wins = 0, losses = 0;
    char guess;
    bool guessed[puzzles[numPuzzles].size()] = {false};
    int remaining = 0;
    bool gameOver = false;

    cout << "Welcome to Hangman!" << endl;
    loadPuzzles(puzzles, used, numPuzzles);
    do
    {
        int index;
        do
        {
            index = rand() % numPuzzles;
        } while (used[index]);
        used[index] = true;
        const string &puzzle = puzzles[index];
        remaining = puzzle.size();
        for (int i = 0; i < remaining; i++)
        {
            if (puzzle[i] == ' ')
            {
                guessed[i] = true;
                remaining--;
            }
            else
            {
                guessed[i] = false;
            }
        }
        cout << "Guess the word: ";
        displayPuzzle(puzzle, guessed);
        int guesses = 0;
        while (guesses < MAX_GUESSES && remaining > 0)
        {
            guess = getGuess();
            if (!updateGuesses(puzzle, guess, guessed, remaining))
            {
                guesses++;
            }
            displayPuzzle(puzzle, guessed);
        }
        if (remaining == 0)
        {
            cout << "Congratulations, you won!" << endl;
            wins++;
        }
        else
        {
            cout << "Sorry, you lost. The word was \"" << puzzle << "\"" << endl;
            losses++;
        }
        gameOver = !playAgain();
    } while (!gameOver);
    printStats(wins, losses);
    printPuzzles(puzzles, used, numPuzzles);
    return 0;
}

void welcomeScreen()
{
    cout << "Welcome to Hangman!" << endl;
}

void loadPuzzles(string puzzles[], bool used[], int &numPuzzles)
{
    ifstream inFile("puzzleoptions.txt");
    if (!inFile)
    {
        cerr << "Error opening puzzle file!" << endl;
        exit(1);
    }
    while (numPuzzles < MAX_PUZZLES && getline(inFile, puzzles[numPuzzles]))
    {
        used[numPuzzles] = false;
        numPuzzles++;
    }
    inFile.close();
}

void displayPuzzle(const string &puzzle, const bool guessed[])
{
    cout << endl
         << "Puzzle: ";
    for (int i = 0; i < puzzle.size(); i++)
    {
        if (guessed[i])
        {
            cout << puzzle[i];
        }
        else
        {
            cout << "_";
        }
        cout << " ";
    }
    cout << endl;
}

char getGuess()
{
    char guess;
    cout << "Enter a letter: ";
    cin >> guess;
    return guess;
}

bool updateGuesses(const string &puzzle, const char guess, bool guessed[], int &remaining)
{
    bool correct = false;
    for (int i = 0; i < puzzle.size(); i++)
    {
        if (puzzle[i] == guess && !guessed[i])
        {
            guessed[i] = true;
            remaining--;
            correct = true;
        }
    }
    if (correct)
    {
        cout << "Correct guess!" << endl;
    }
    else
    {
        cout << "Incorrect guess!" << endl;
    }
    return correct;
}

bool playAgain()
{
    char response;
    cout << "Do you want to play again? (y/n) ";
    cin >> response;
    if (response == 'y')
    {
        return true;
    }
    else if (response == 'n')
    {
        return false;
    }
}
void printStats(int wins, int losses)
{
    cout << "-------------------------" << endl;
    cout << " Statistics " << endl;
    cout << "-------------------------" << endl;
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
}

void printPuzzles(const string puzzles[], const bool used[], int numPuzzles)
{
    cout << "-------------------------" << endl;
    cout << " Used and Unused Puzzles " << endl;
    cout << "-------------------------" << endl;
    cout << "Used Puzzles:" << endl;
    bool hasUsed = false;
    for (int i = 0; i < numPuzzles; i++)
    {
        if (used[i])
        {
            cout << puzzles[i] << endl;
            hasUsed = true;
        }
    }
    if (!hasUsed)
    {
        cout << "No used puzzles." << endl;
    }
    cout << "-------------------------" << endl;
    cout << "Unused Puzzles:" << endl;
    bool hasUnused = false;
    for (int i = 0; i < numPuzzles; i++)
    {
        if (!used[i])
        {
            cout << puzzles[i] << endl;
            hasUnused = true;
        }
    }
    if (!hasUnused)
    {
        cout << "No unused puzzles." << endl;
    }
    cout << "-------------------------" << endl;
}