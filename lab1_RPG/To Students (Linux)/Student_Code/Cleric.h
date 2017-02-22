//
//  Cleric.h
//  lab1_RPG
//
//  Created by Mélanie on 08/05/2015.
//  Copyright (c) 2015 Mélanie. All rights reserved.
//

#pragma once

#include "Fighter.h"

class Cleric : public Fighter
{
private:
    int damage;
    int maxMana;
    int currentMana;
    
public:
    Cleric(string name, char type, int maxHitPoints, int strength, int speed, int magic);
    int getDamage();
    void takeDamage(int damage);
    void reset();
    void regenerate();
    bool useAbility();

~Cleric();
};
