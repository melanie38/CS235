//
//  Robot.cpp
//  lab1_RPG
//
//  Created by Mélanie on 08/05/2015.
//  Copyright (c) 2015 Mélanie. All rights reserved.
//

#include "Robot.h"

// Constructor -------------------------------------------------------------------------------------
Robot::Robot(string name, char type, int maxHitPoints, int strength, int speed, int magic)
:Fighter(name, type, maxHitPoints, strength, speed, magic)
{
    damage = strength;
    maxEnergy = 2 * magic;
    bonusDamage = (strength  * pow(((double)currentEnergy/(double)maxEnergy), 4));
}
Robot::~Robot(){};
// Setters -----------------------------------------------------------------------------------------
void Robot::takeDamage(int damage)
{
    Fighter::takeDamage(damage);
}

/*
 *  Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
 *	Also resets a Robot's bonus damage to 0.
 */
void Robot::reset()
{
    Fighter::reset();
    currentEnergy = maxEnergy;
    bonusDamage = 0;
}
void Robot::regenerate()
{
    Fighter::regenerate();
}
// Getters -----------------------------------------------------------------------------------------
int Robot::getDamage()
{
    return damage;
}
/*
*	Robot: Shockwave Punch
*	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
*	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
*	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
*		Examples:
*		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
*		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
*		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
*		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
*	Robot Note:
*	The bonus damage formula should be computed using double arithmetic, and only
*	the final result should be cast into an integer.
 */
bool Robot::useAbility()
{
    if (currentEnergy >= ROBOT_ABILITY_COST)
    {
        damage += bonusDamage;
        currentEnergy -= ROBOT_ABILITY_COST;
        return true;
    }
    return false;
}
