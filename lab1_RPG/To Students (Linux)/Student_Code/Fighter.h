//
//  Fighter.h
//  lab1_RPG
//
//  Created by Mélanie on 08/05/2015.
//  Copyright (c) 2015 Mélanie. All rights reserved.
//

#pragma once

#include "FighterInterface.h"

#include <string>
#include <vector>

class Fighter : public FighterInterface
{
protected:
    string  name;
    char    type;
    int     maxHitPoints;
    int     strength;
    int     speed;
    int     magic;
    int     currentHP;
    
public:
    Fighter(string name, char type, int maxHitPoints, int strength, int speed, int magic);
    string getName();
    int getMaximumHP();
    int getCurrentHP();
    int getStrength();
    int getSpeed();
    int getMagic();
    virtual int getDamage()= 0;
    virtual void takeDamage(int damage);
    virtual void reset();
    virtual void regenerate()= 0;
    virtual bool useAbility()= 0;
    
~Fighter();
};
