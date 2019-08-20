/*
Introduction to C++
Week3
Game Project: Mastermind Header
Michael Blodgett
7/13/19
*/
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
enum Peg {blue, red, purple, orange, brown, green};
const int BOARD_SIZE = 4;
const int NUM_PEGS = 6;

bool mastermind(bool &hardMode);
void getAnswer(Peg answer[BOARD_SIZE], bool repeats=false);
void printBoard(Peg board[BOARD_SIZE]);
bool isDuplicate(Peg draw, Peg board[BOARD_SIZE], int pos);
bool stringToBoard(string input[BOARD_SIZE], Peg output[BOARD_SIZE]);
void getGuess(Peg guess[BOARD_SIZE]);
bool checkPegs(Peg guess[BOARD_SIZE], Peg answer[BOARD_SIZE],
                int &blackPegs, int &whitePegs);