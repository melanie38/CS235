//
//  Fighter.cpp
//  lab1_RPG
//
//  Created by Mélanie on 08/05/2015.
//  Copyright (c) 2015 Mélanie. All rights reserved.
//

#include "Fighter.h"

// Constructor -------------------------------------------------------------------------------------
Fighter::Fighter(string name, char type, int maxHitPoints, int strength, int speed, int magic)
{
    this->name = name;
    this->type = type;
    this->maxHitPoints = maxHitPoints;
    this->strength = strength;
    this->speed = speed;
    this->magic = magic;
    currentHP = maxHitPoints;
}
Fighter::~Fighter(){};
// Setter ------------------------------------------------------------------------------------------
/*
 * 	Reduces the fighter's current hit points by an amount equal to the given
 *	damage minus one fourth of the fighter's speed.  This method must reduce
 *	the fighter's current hit points by at least one.  It is acceptable for
 *	this method to give the fighter negative current hit points.
 */
void Fighter::takeDamage(int damage)
{
    if ((damage - (speed/4)) > 1)
    {
        currentHP = damage - (speed/4);
    }
    else
    {
        currentHP -= 1;
    }
    
}
/*
 * Restores a fighter's current hit points to its maximum hit points.
 */
void Fighter::reset()
{
    currentHP = maxHitPoints;
}
/*
 *  Increases the fighter's current hit points by an amount equal to one sixth of
 *	the fighter's strength.  This method must increase the fighter's current hit
 *	points by at least one.  Do not allow the current hit points to exceed the
 *	maximum hit points.
 */
void Fighter::regenerate()
{
    int toIncrease = strength / 6;
    
    if ((toIncrease + currentHP) < maxHitPoints)
    {
        if ( toIncrease < 1)
        {
            currentHP += 1;
        }
        else
        {
            currentHP += toIncrease;
        }
    }
    else
    {
        currentHP = maxHitPoints;
    }
}
// Getter ------------------------------------------------------------------------------------------
string Fighter::getName()
{
    return name;
}
int Fighter::getMaximumHP()
{
    return maxHitPoints;
}
int Fighter::getCurrentHP()
{
    return currentHP;
}
int Fighter::getStrength()
{
    return strength;
}
int Fighter::getSpeed()
{
    return speed;
}
int Fighter::getMagic()
{
    return magic;
}

