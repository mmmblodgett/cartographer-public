/*
Introduction to C++
Final Project: Cartographer
Header
Michael Blodgett
8/5/19
*/
#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include "mastermind.h"

using namespace std;
// Number of sides for die determining random tiles
const int DIE_SIDES = 115;
// Number of items that can be bought
const int UNIQUE_ITEMS = 5;
// Prices for items
const int RAFT_PRICE = 8;
const int BOOTS_PRICE = 5;
const int ROPES_PRICE = 5;
const int LANTERN_PRICE = 9;
// Inventory items
enum Inventory {gold, raft, boots, ropes, lantern};

// Prototypes that don't rely on custom classes
bool validIn(char in);
char userInput();
void nextAddress(int &east, int &north, char selection);
void pressToContinue();
void shop(int inv[]);
void buy(int inv[], Inventory item, int price, string itemName);

// TileType prototypes
class TileType {
    string m_name;
    string m_text;
public:
    TileType(string name="", string text=""):m_name(name), m_text(text) {}
    void display() const;
    string getName() const;
    friend class Tile;
};

// This prototype needs to be here because
// it returns a TileType and is used in Tile constructor
TileType getType();

// Tile prototypes
class Tile {
    TileType m_type;
public:
    int m_north;
    int m_east;
    Tile();
    Tile(int east, int north, TileType type=getType());
    void display() const;
    string getAddress() const;
    string getName() const;
    void setName(string name);
};

// Prototypes that use custom classes
Tile* getByAddress(int east, int north, vector<Tile> &tiles);
bool tileFunction(Tile *current, int inv[]);
vector<Tile> initTiles();
bool impasse(Tile *current, int inv[], bool haveTools);