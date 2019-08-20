/*
Introduction to C++
Final Project: Cartographer
Tile functions
Michael Blodgett
8/5/19

The tileFunction function handles all of the special properties
of different tiles
*/
#include "cartographer.h"

bool tileFunction(Tile *current, int inv[])
{
    // If it's an obstacle tile, check if the user can pass
    if (current->getName() == "lake")
    {
        cout << "There is a great lake\n";
        if (impasse(current, inv, inv[raft] > 0))
            return false;
    }
    else if (current->getName() == "mountain")
    {
        cout << "There is a steep mountain\n";
        if (impasse(current, inv, inv[boots] > 0))
            return false;
    }
    else if (current->getName() == "cliffs")
    {
        cout << "There are vertical cliffs\n";
        if (impasse(current, inv, inv[ropes] > 0))
            return false;
    }
    else if (current->getName() == "forest")
    {
        cout << "There are treacherous woods\n";
        if (impasse(current, inv, inv[boots] > 0))
            return false;
    }
    else if (current->getName() == "caverns")
    {
        cout << "There are dark and treacherous caverns\n";
        if (impasse(current, inv, inv[boots] > 0 && inv[lantern] > 0))
            return false;
    }
    // If it's a treasure tile give user the gold and update the tile
    else if (current->getName() == "gold")
    {
        cout << "You found a piece of gold!\n"
             << "You now have " << ++inv[gold]
             << " pieces of gold\n";
        current->setName("field");
    }
    else if (current->getName() == "treasure")
    {
        int bounty = rand() % 10 + 2;
        cout << "You found a treasure chest!\n"
             << "It had " << bounty << " pieces of gold in it, "
             << "so you now have " << (inv[gold] += bounty)
             << " pieces of gold\n";
        current->setName("empty chest");
    }
    // If it's a shop call the shop function
    else if (current->getName() == "shop")
    {
        char response;
        do {
            cout << "There is a small shop."
                 << "Would you like to enter?\n(y or n) ";
            cin >> response;
        } while (response != 'y' && response != 'n');
        if (response == 'y')
            shop(inv);
    }
    // If it's a mastermind tile call the mastermind function
    else if (current->getName() == "mastermind")
    {
        char response;
        bool hardMode;
        do {
            cout << "You find an old woman with a board and some pegs.\n"
                << "She challenges you to a game- if you can guess a pattern in "
                << "seven guesses she will give you some gold.\nAccept her "
                << "challenge?\n(y or n) ";
            cin >> response;
        } while (response != 'y' && response != 'n');
        if (response == 'y')
            if (mastermind(hardMode))
            {
                if (hardMode) 
                    cout << "You won 2 gold coins. You now have "
                         << (inv[gold] += 2) << " gold coins.\n";
                else
                    cout << "You won 1 gold coin. You now have "
                         << ++inv[gold] << " gold coins.\n";
            }
    }
    // If it's anything else show the display text
    else
        current->display();    
    // Prompt the user to choose a direction and
    // return true (tile passable)
    cout << "Choose a direction:\n(n e s w) ";
    return true;
}