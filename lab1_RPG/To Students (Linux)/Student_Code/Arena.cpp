//
//  Arena.cpp
//  lab1_RPG
//
//  Created by Mélanie on 08/05/2015.
//  Copyright (c) 2015 Mélanie. All rights reserved.
//

#include "Arena.h"

int Arena::findFighter(string name)
{
    for (int i = 0; i < roster.size(); i++)
    {
        if (name == roster[i]->getName())
        {
            return i;
        }
    }
    return 0;
}
// Constructor -------------------------------------------------------------------------------------
Arena::Arena()
{

}
Arena::~Arena(){};
// Setters -----------------------------------------------------------------------------------------
bool Arena::addFighter(string info)
{
    string  name;
    char    type;
    int     maxHitPoints;
    int     strength;
    int     speed;
    int     magic;
    
    stringstream ss;
    
    ss << info;
    
    if (ss >> name >> type >> maxHitPoints >> strength >> speed >> magic)
    {
    
        // roster.findFighter(roster, name);
    
        if (!findFighter(name))
        {
            if (type == 'C')
            {
                FighterInterface* newFighter = new Cleric(name, type, maxHitPoints, strength, speed, magic);
                roster.push_back(newFighter);
            }
            else if (type == 'A')
            {
                FighterInterface* newFighter = new Archer(name, type, maxHitPoints, strength, speed, magic);
                roster.push_back(newFighter);
            }
            else if (type == 'R')
            {
                FighterInterface* newFighter = new Robot(name, type, maxHitPoints, strength, speed, magic);
                roster.push_back(newFighter);
            }
            return true;
        }
        else
        {
            cout << "This fighter is already in the roster." << endl;
            return false;
        }
    }
    else
    {
        cout << "The informations provided are not in the right format." << endl;
        return false;
    }
}
bool Arena::removeFighter(string name)
{
	int i = findFighter(name);

    if (i != 0)
    {
        roster.erase(roster.begin() + i);
        cout << name << " has been successfully removed from the roster." << endl;
        return true;
    }
    else
    {
        cout << name << " is not in the roster." << endl;
        return false;
    }
}

// Getters -----------------------------------------------------------------------------------------

FighterInterface* Arena::getFighter(string name)
{
    for (int i = 0; i < roster.size(); i++)
    {
        if (name == roster[i]->getName())
        {
            return roster[i];
        }
    }
    return NULL;
}

int Arena::getSize()
{
    return roster.size();
}
