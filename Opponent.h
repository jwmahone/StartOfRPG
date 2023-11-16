//
// Created by Jack Mahoney on 10/6/23.
// opponent class represents the enemy that character will be able to fight in main
//this class has armor and weapon attributes
//

#ifndef M1OEP_OPPONENT_H
#define M1OEP_OPPONENT_H
using namespace std;

class Opponent{
private:
    //has-a relationships
    Armor armor;
    Weapon weapon;
public:
    //constructor that takes no parameters
    Opponent(){
    }
    //constructor that takes both parameters
    Opponent(Armor armor, Weapon weapon){
        this->armor = armor;
        this->weapon = weapon;
    }

    //getters
    Armor getArmor(){
        return armor;
    }
    Weapon getWeapon(){
        return weapon;
    }

    //setters
    void setArmor(Armor armor){
        this->armor = armor;
    }
    void setWeapon(Weapon weapon){
        this->weapon = weapon;
    }

};
#endif //M1OEP_OPPONENT_H
