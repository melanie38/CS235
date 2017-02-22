//
//  Archer.cpp
//  lab1_RPG
//
//  Created by Mélanie on 08/05/2015.
//  Copyright (c) 2015 Mélanie. All rights reserved.
//

#include "Archer.h"

// Constructor -------------------------------------------------------------------------------------
Archer::Archer(string name, char type, int maxHitPoints, int strength, int speed, int magic)
:Fighter(name, type, maxHitPoints, strength, speed, magic)
{
    damage = speed;
}
Archer::~Archer(){};
// Setters -----------------------------------------------------------------------------------------
void Archer::takeDamage(int damage)
{
    Fighter::takeDamage(damage);
}
/*
 * Also resets an Archer's current speed to its original value.
 */
void Archer::reset()
{
    Fighter::reset();
    currentSpeed = speed;
}
void Archer::regenerate()
{
    Fighter::regenerate();
}
// Getters -----------------------------------------------------------------------------------------
int Archer::getDamage()
{
    return speed;
}
/*
 *	Archer: Quickstep
 *	Increases the Archer's speed by one point each time the ability is used.
 *	This bonus lasts until the reset() method is used.
 *	This ability always works; there is no maximum bonus speed.
 */
bool Archer::useAbility()
{
    currentSpeed += 1;
    
    return true;
}
