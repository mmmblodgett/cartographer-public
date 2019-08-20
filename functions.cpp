/*
Introduction to C++
Final Project: Cartographer
Misc Functions
Michael Blodgett
8/5/19

Various function definitions used throughout
*/
#include "cartographer.h"

// Check that an input corresponds to a direction
bool validIn(char in)
{
    switch (in)
    {
        case 'n':
        case 'e':
        case 's':
        case 'w':
            return true;
        default:
            cout << in << " is not a valid command\n";
            return false;
    }
}

// Get a direction input from the user
char userInput()
{
    char selection;
    bool valid;
    do {
            cin >> selection;
            valid = validIn(selection);
        } while (!valid);
    return selection;
}

// Find an address based on a current address and a direction
void nextAddress(int &east, int &north, char selection)
{
    switch(selection)
    {
        case 'n':
            ++north;
            break;
        case 'e':
            ++east;
            break;
        case 's':
            --north;
            break;
        case 'w':
            --east;
            break;
    }
}

// Get a pointer to a tile based on address
// Return nullptr if nothing exists at that address
Tile* getByAddress(int east, int north, vector<Tile> &tiles)
{
    for (int i = 0; i < tiles.size(); ++i)
    {
        if (east == tiles[i].m_east && north == tiles[i].m_north)
            return &tiles[i];
    }
    return nullptr;
}

// Initialize the starting tiles
vector<Tile> initTiles()
{
    vector<Tile> tiles;
    //Starting Tile
    tiles.push_back(Tile());
    //Free tile
    tiles.push_back(Tile(0,-1,TileType("garden", "Your tranquil garden")));
    //Mastermind tile
    tiles.push_back(Tile(1,-1,TileType("mastermind")));
    //Shop tile
    tiles.push_back(Tile(1,0,TileType("shop")));

    return tiles;
}

// Prompt the user to confirm before continuing
void pressToContinue()
{
    char response;
    cout << "Enter 'y' to accept ";
    do {
        cin >> response;
    } while (response != 'y');
    cout << endl;
}

// Display a shop
void shop(int inv[])
{
    char response;
    cout << "Shopkeeper:\n"
         << "Hello, and welcome! What would you like to buy?\n";
    do {
        cout << "AVAILABLE GOLD " << inv[gold] << endl
             << "Raft           " << RAFT_PRICE << " Gold (r)\n"
             << "Hiking Boots   " << BOOTS_PRICE << " Gold (b)\n"
             << "Climbing Ropes " << ROPES_PRICE << " Gold (c)\n"
             << "Lantern        " << LANTERN_PRICE << " Gold (l)\n"
             << "Leave Shop (x)\n";
        cin >> response;
        if (response == 'r')
            buy(inv,raft,RAFT_PRICE,"raft");
        else if (response == 'b')
            buy(inv,boots,BOOTS_PRICE,"pair of hiking boots");
        else if (response == 'c')
            buy(inv,ropes,ROPES_PRICE,"set of climbing ropes");
        else if (response == 'l')
            buy(inv,ropes,ROPES_PRICE,"lantern");
    } while (response != 'x');
}

// Buy an item or tell the user if they don't have enough gold
void buy(int inv[], Inventory item, int price, string itemName)
{
    if (inv[gold] - price < 0)
        cout << "You don't have enough gold\n";
    else
    {
        inv[gold] -= price;
        inv[item] += 1;
        cout << "One " << itemName << " purchased for "
             << price << " gold\n";
    }
}

// Handle obstacles
bool impasse(Tile *current, int inv[], bool haveTools)
{
    if (!haveTools)
    {
        cout << "You'll have to turn back the way you came.\n";
        pressToContinue();
        return true;
    }
    current->display();
    return false;
}

// Show inventory
// Not currently used
void showInv(int inv[])
{
     cout << "gold:     " << inv[gold] << endl
         << "rafts:    " << inv[raft] << endl
         << "boots:    " << inv[boots] << endl
         << "ropes:    " << inv[ropes] << endl
         << "lanterns: " << inv[lantern] << endl;
}