/*
Introduction to C++
Final Project: Cartographer
Michael Blodgett
8/5/19

Main file for Cartographer game, in which a user
can explore a randomly generated world
*/
#include "cartographer.h"

int main ()
{
    // Seed the random number generator
    srand(time(0));

    // Get initial tiles
    vector<Tile> tiles = initTiles();
    // Initialize pointers and declare variables
    Tile *currentTile = &tiles[0];
    Tile *nextTile = nullptr;
    Tile *prevTile = nullptr;
    char selection;
    int nextEast;
    int nextNorth;
    int inv[UNIQUE_ITEMS] = {};

    // This is the main game loop
    while (true)
    {
        // Run the function of current tile
        if(!tileFunction(currentTile, inv))
        {
            // If the tile is impassable return user to prev tile
            currentTile = prevTile;
            continue;
        }
        // Get a direction from the user
        selection = userInput();
        // Set next address to current address
        nextEast = currentTile->m_east;
        nextNorth = currentTile->m_north;
        // Offset the next address based on the user's direction
        nextAddress(nextEast, nextNorth, selection);
        // Point to the tile at that address
        nextTile = getByAddress(nextEast, nextNorth, tiles);
        // If tile doesn't exist yet, generate it
        if (!nextTile)
        {
            tiles.push_back(Tile(nextEast, nextNorth));
            nextTile = &tiles.back();
        }
        // Set prev and current tiles
        prevTile = currentTile;
        currentTile = nextTile;
    }

}