//
//  Cleric.cpp
//  lab1_RPG
//
//  Created by Mélanie on 08/05/2015.
//  Copyright (c) 2015 Mélanie. All rights reserved.
//

#include "Cleric.h"

// Constructor -------------------------------------------------------------------------------------
Cleric::Cleric(string name, char type, int maxHitPoints, int strength, int speed, int magic)
:Fighter(name, type, maxHitPoints, strength, speed, magic)
{
    damage = magic;
    maxMana = 5 * magic;
    
}
Cleric::~Cleric(){};
// Setters -----------------------------------------------------------------------------------------
void Cleric::takeDamage(int damage)
{
    Fighter::takeDamage(damage);
}

/*
 * Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
 */
 void Cleric::reset()
{
    Fighter::reset();
    currentMana = maxMana;
}

/*	Also increases a Cleric's current mana by an amount equal to one fifth of the
 *	Cleric's magic.  This method must increase the Cleric's current mana by at
 *	least one.  Do not allow the current mana to exceed the maximum mana.
 */
void Cleric::regenerate()
{
    Fighter::regenerate();
    
    if ((currentMana + (magic / 6)) < maxMana)
    {
        if ((magic / 6) < 1)
        {
            currentMana += magic / 6;
        }
        else
        {
            currentMana +=1;
        }
    }
    else
    {
        currentMana = maxMana;
    }
}
// Getters -----------------------------------------------------------------------------------------
int Cleric::getDamage()
{
    return damage;
}
/*
 *	Cleric: Healing Light
 *	Increases the Cleric's current hit points by an amount equal to one third of its magic.
 *	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
 *	Will be used even if the Cleric's current HP is equal to their maximum HP.
 *	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
 *	Cleric Note:
 *	This ability, when successful, must increase the Cleric's current hit points
 *	by at least one.  Do not allow the current hit points to exceed the maximum
 *	hit points.
 */
bool Cleric::useAbility()
{
    if (currentMana >= CLERIC_ABILITY_COST)
    {
        if (currentHP < maxHitPoints)
        {
            if ((magic/3) > 1)
            {
                currentHP += magic / 3;
            }
            else
            {
                currentHP += 1;
            }
        }
        currentMana -= CLERIC_ABILITY_COST;
        return true;
    }
    return false;
}
