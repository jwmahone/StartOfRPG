//
// Created by Jack Mahoney on 9/14/23.
//weapon class is used for character struct, sidekick class, and opponent class
//weapons can attack and have damage, price, and name attributes
//

#ifndef M1OEP_JWMAHONE_WEAPON_H
#define M1OEP_JWMAHONE_WEAPON_H
#include<string>
#include "Armor.h"
using namespace std;

class Weapon {
private:
    string name;
    float price;
    int damage;

public:
    //constructors
    //empty constructor
    Weapon(){
    }
    //constructor that takes both arguments
    Weapon(string name, float price, int damage){
        this->name = name;
        this->price = price;
        this->damage = damage;
    }

    //getters
    string getName(){
        return name;
    }
    float getPrice(){
        return price;
    }
    int getDamage(){
        return damage;
    }

    //setters
    void setName(string name){
        this->name = name;
    }
    void setPrice(float price){
        this->price = price;
    }
    void setDamage(int damage){
        this->damage = damage;
    }

    //overload < comparison operator
    friend bool operator < (Weapon& lhs, Weapon& rhs) {
        return lhs.getPrice() < rhs.getPrice();
    }

    //overload > comparison operator
    friend bool operator > (Weapon& lhs, Weapon& rhs) {
        return lhs.getPrice() > rhs.getPrice();
    }

    //overload <= comparison operator
    friend bool operator <= (Weapon& lhs, Weapon& rhs) {
        return lhs.getPrice() <= rhs.getPrice();
    }

    //overload >= comparison operator
    friend bool operator >= (Weapon& lhs, Weapon& rhs) {
        return lhs.getPrice() >= rhs.getPrice();
    }

    //overload == comparison operator
    friend bool operator == (Weapon& lhs, Weapon& rhs) {
        return lhs.getPrice() == rhs.getPrice();
    }

    //overload != comparison operator
    friend bool operator != (Weapon& lhs, Weapon& rhs) {
        return lhs.getPrice() != rhs.getPrice();
    }

    //attack subtracts weapon damage from health of what the weapon is attacking
    Armor attack(Armor armor, Weapon weapon){
        int health = armor.getHealth();
        health -= weapon.getDamage();
        armor.setHealth(health);
        return armor;
    }

};
#endif //M1OEP_JWMAHONE_WEAPON_H
