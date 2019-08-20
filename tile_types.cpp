/*
Introduction to C++
Final Project: Cartographer
Tile Types
Michael Blodgett
8/5/19

The getType function contains all tile types which might
be generated, along with their probability.
*/
#include "cartographer.h"

TileType getType()
{
    // Declare tile values
    string name;
    string text = "";
    // Get a random selection
    int selection = rand() % DIE_SIDES;
    if (selection < 100)
        selection /= 10;

    // Select a tile
    switch(selection)
    {
        case 1:
        case 2:
            name = "lake";
            text = "You can sail it with your raft";
            break;
        case 3:
        case 4:
            name = "mountain";
            text = "You can hike it with your boots";
            break;
        case 5:
        case 6:
            name = "cliffs";
            text = "You can climb them with your ropes";
            break;
        case 7:
        case 8:
            name = "forest";
            text = "You can traverse it with your boots";
            break;
        case 9:
        case 0:
            name = "caverns";
            text = "You can navigate them with your boots and lantern";
            break;
        case 103:
        case 104:
            name = "gold";
            text = "You are in a wide open field";
            break;
        case 105:
        case 106:
            name = "hill";
            text = "You are on a gently sloping hill";
            break;
        case 107:
            name = "waterfall";
            text = "There is an incredible waterfall";
            break;
        case 108:
            name = "mike";
            text = "It's the game's creator. He thanks you for playing";
            break;
        case 100:
            name = "treasure";
            text = "There is an empty treasure chest";
            break;
        case 101:
            name = "shop";
            break;
        case 102:
            name = "mastermind";
            break;
        default:
            name = "field";
            text ="You are in a wide open field";
    }
    // Return it
    return TileType(name, text);
}