//
// Created by Jack Mahoney on 9/15/23.
//sidekick class is used in battle alongside your character
//sidekick has a weapon and armor and has name, type, damage, weapon, and armor attributes

#ifndef M1OEP_JWMAHONE_SIDEKICK_H
#define M1OEP_JWMAHONE_SIDEKICK_H
#include<string>
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class Sidekick {
private:
    string name;
    string type;
    int damage;
    Weapon weapon; //sidekick has-a weapon
    Armor armor; //sidekick has-a armor

public:
    //constructors
    //empty constructor
    Sidekick() {
    }

    //constructor that takes both arguments
    Sidekick(string name, string type, int damage, Weapon weapon, Armor armor) {
        this->name = name;
        this->type = type;
        this->damage = damage;
        this->weapon = weapon;
        this->armor = armor;
    }

    //getters
    string getName() {
        return name;
    }

    string getType() {
        return type;
    }

    int getDamage() {
        return damage;
    }

    Weapon getWeapon(){
        return weapon;
    }
    Armor getArmor(){
        return armor;
    }

    //setters
    void setName(string name) {
        this->name = name;
    }

    void setType(string type) {
        this->type = type;
    }

    void setDamage(int damage) {
        this->damage = damage;
    }

    void setWeapon(Weapon weapon){
        this->weapon = weapon;
    }
    void setArmor(Armor armor){
        this->armor = armor;
    }

    //the heal function allows for your sidekick to heal you main character
    int heal(int health){
        //sidekick heals you by 40 hp
        health += 40;
        return health;
    }

};
#endif //M1OEP_JWMAHONE_SIDEKICK_H
