/*
Introduction to C++
Week3
Game Project: Mastermind
Michael Blodgett
7/13/19

Mastermind
Users choose to play with or without repeated colors,
then they have seven guesses to determine the answer.

8/5/19
Adapted to a tile for Cartographer
*/
#include "cartographer.h"

bool mastermind(bool &hardMode)
{
    // Declare constants
    Peg answer[BOARD_SIZE];
    Peg guess[BOARD_SIZE];

    // Declare variables
    int blackPegs;
    int whitePegs;
    int guesses = 0;

    // Ask the user if they want to play with repeated pegs
    char response;
    do {
        cout << "The woman asks if you'd like a more difficult "
             << "challenge for a chance at more gold.\n(y or n) ";
        cin >> response;
    } while (response != 'y' && response != 'n');
    cout << "Guess the four colors she's thinking of "
             << "(red, blue, green, purple, orange, brown)\n"
             << "A white peg represents the right color in the "
             << "wrong plage. A black peg is the right color in "
             << "the right place.\n";
    if (response == 'y')
    {
        hardMode = true;
        cout << "Colors may be repeated\n";
    }
    else
    {
        hardMode = false;
        cout << "Colors may not be repeated\n";
    }
        // Get an answer to guess
    getAnswer(answer, response=='y');

    // Give user 7 guesses
    while (guesses < 7)
    {
        // Get a guess
        ++guesses;
        getGuess(guess);

        // If it's right, break the loop
        if (checkPegs(guess, answer, blackPegs, whitePegs)) break;

        // Otherwise print how close they were
        cout << "Black pegs: " << blackPegs << endl;
        cout << "White pegs: " << whitePegs << endl;
    }

    // If they ran out of guesses tell them the answer
    if (guesses >= 7)
    {
        cout << "The answer was:\n";
        printBoard(answer);
        cout << "\nBetter luck next time.\n";
        return false;
    }

    // Otherwise congratulate them
    else cout << "You got it in " << guesses << " guesses\n";
    return true;
}


bool checkPegs(Peg guess[BOARD_SIZE], Peg answer[BOARD_SIZE],
                int &blackPegs, int &whitePegs)
// Check for number of white and black pegs
{
    // Initialize peg counts to zero
    blackPegs = 0;
    whitePegs = 0;

    // Initialize checks to avoid double counting white pegs
    bool guessCheck[BOARD_SIZE] = {};
    bool answerCheck[BOARD_SIZE] = {};

    // Check for black pegs
    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        if (guess[i] == answer[i]) 
        {
            ++blackPegs;
            guessCheck[i] = true;
            answerCheck[i] = true;
        }
    }

    // Check for white pegs
    for(int i = 0; i < BOARD_SIZE; ++i)
    {        
        if (guessCheck[i]) continue;
        for (int j = 0; j < BOARD_SIZE; ++j)
            if (!answerCheck[j] && guess[i] == answer[j])
            {
                ++whitePegs;
                guessCheck[i] = true;
                answerCheck[j] = true;
                break;
            };
    }

    // Return true if the guess is correct
    return (blackPegs == BOARD_SIZE);
}


void getGuess(Peg guess[BOARD_SIZE])
// Prompt a user for a guess
{
    // Initialize an array for the guess
    string input[BOARD_SIZE];

    // Get a valid guess
    do {
        cout << "Enter your guess: ";
        for(int i = 0; i < BOARD_SIZE; ++i)
            cin >> input[i];
        cin.ignore(100, '\n');
    } while (!stringToBoard(input, guess)); // Keep asking if it's not a valid guess
}


bool stringToBoard(string input[BOARD_SIZE], Peg output[BOARD_SIZE])
// Converts a string array to a peg board, returns false if the string is invalid
{
    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        if(input[i] == "blue") output[i] = blue;
        else if(input[i] == "blue") output[i] = blue;
        else if(input[i] == "red") output[i] = red;
        else if(input[i] == "purple") output[i] = purple;
        else if(input[i] == "orange") output[i] = orange;
        else if(input[i] == "brown") output[i] = brown;
        else if(input[i] == "green") output[i] = green;
        else return false;
    }
    return true;
}


void getAnswer(Peg answer[BOARD_SIZE], bool repeats)
// Randomly generate a board to use as an answer
{
    srand(time(0));
    for(int i = 0; i < BOARD_SIZE; ++i)
        do{
            answer[i] = static_cast<Peg>(rand() % NUM_PEGS);
        } while (!repeats && isDuplicate(answer[i], answer, i)); // Only accept duplicates if repeats is set to true
}


bool isDuplicate(Peg draw, Peg board[BOARD_SIZE], int pos)
// Check if a peg is already in a board
{
    for(int i = 0; i < pos; ++i)
        if (draw == board[i])
            return true;
    return false;
}


void printBoard(Peg board[BOARD_SIZE])
// Print a board
{
    string pegColors[NUM_PEGS] = {"blue", "red", "purple", "orange", "brown", "green"};
    for(int i = 0; i < BOARD_SIZE; ++i)
        cout << pegColors[board[i]] << ' ';
}