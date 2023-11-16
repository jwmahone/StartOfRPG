//
// Created by Jack Mahoney on 9/14/23.
//armor class is used in character struct, sidekick class, and opponent class
//armor is used to absorb damage and has name, price, and health attributes
//

#ifndef M1OEP_JWMAHONE_ARMOR_H
#define M1OEP_JWMAHONE_ARMOR_H
#include<string>
using namespace std;

class Armor {
private:
    string name;
    float price;
    int health;

public:
    //constructors
    //empty constructor
    Armor(){
    };
    //constructor that takes both arguments
    Armor(string name, float price, int health){
        this->name = name;
        this->price = price;
        this->health = health;
    };
    //getters
    string getName(){
        return name;
    }
    float getPrice(){
        return price;
    }
    int getHealth(){
        return health;
    }

    //setters
    void setName(string name){
        this->name = name;
    }
    void setPrice(float price){
        this->price = price;
    }
    void setHealth(int health){
        this->health = health;
    }

    //overload < comparison operator
    friend bool operator < (Armor& lhs, Armor& rhs) {
        return lhs.getPrice() < rhs.getPrice();
    }

    //overload > comparison operator
    friend bool operator > (Armor& lhs, Armor& rhs) {
        return lhs.getPrice() > rhs.getPrice();
    }

    //overload <= comparison operator
    friend bool operator <= (Armor& lhs, Armor& rhs) {
        return lhs.getPrice() <= rhs.getPrice();
    }

    //overload >= comparison operator
    friend bool operator >= (Armor& lhs, Armor& rhs) {
        return lhs.getPrice() >= rhs.getPrice();
    }

    //overload == comparison operator
    friend bool operator == (Armor& lhs, Armor& rhs) {
        return lhs.getPrice() == rhs.getPrice();
    }

    //overload != comparison operator
    friend bool operator != (Armor& lhs, Armor& rhs) {
        return lhs.getPrice() != rhs.getPrice();
    }

};
#endif //M1OEP_JWMAHONE_ARMOR_H
