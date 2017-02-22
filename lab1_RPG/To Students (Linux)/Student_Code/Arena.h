//
//  Arena.h
//  lab1_RPG
//
//  Created by Mélanie on 08/05/2015.
//  Copyright (c) 2015 Mélanie. All rights reserved.
//
#pragma once

#include "ArenaInterface.h"
#include "FighterInterface.h"
#include "Fighter.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Arena : public ArenaInterface
{
private:
    vector<FighterInterface*> roster;
    
public:
    Arena();
    bool         addFighter(string info);
    virtual bool removeFighter(string name);
    virtual FighterInterface* getFighter(string name);
    virtual int  getSize();
    int          findFighter(string name);
    void		 printRoster();
    
~Arena();
};
