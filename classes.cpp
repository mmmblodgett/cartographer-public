/*
Introduction to C++
Final Project: Cartographer
Class methods
Michael Blodgett
8/5/19

Contains all the constructors and method functions for the Tile
and TileType functions used throughout Cartographer.
*/
#include "cartographer.h"

// Show a tiletype's text
void TileType::display() const
{
    cout << m_text << endl;
}

// Get a tiletype's name
string TileType::getName() const
{
    return m_name;
}

// Initialize a home tile
Tile::Tile()
{
    m_type = TileType("home", "You are home by your little cottage");
    m_east = 0;
    m_north = 0;
}

// Initialize a tile manually
Tile::Tile(int east, int north, TileType type)
{
    m_east = east;
    m_north = north;
    m_type = type;
}

// Show a tile's display text
void Tile::display() const
{
    m_type.display();
}

// Return a string of the tile's address
string Tile::getAddress() const
{
    return to_string(m_east) + ", " + to_string(m_north);
}

// Return a tile's name
string Tile::getName() const
{
    return m_type.getName();
}

// Set a tile's name
void Tile::setName(string name)
{
    m_type.m_name = name;
}