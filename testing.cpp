//
// Created by Jack Mahoney on 10/6/23.
// testing.cpp tests non-trivial functions used in main.cpp
//
#include "Weapon.h"
#include "Armor.h"
#include "Sidekick.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Opponent.h"

bool test_sidekick();
bool test_armor();
bool test_weapon();
bool test_opponent();

//create a character structure for testing

struct Character{
    string name;
    Weapon weapon1;
    Weapon weapon2;
    Armor armor;
    Sidekick sidekick;
};

int testing() {
    if(test_sidekick()){
        cout << "Passed all sidekick test cases" << endl;
    }
    if(test_armor()){
        cout << "Passed all armor test cases" << endl;
    }
    if(test_weapon()){
        cout << "Passed all weapon test cases" << endl;
    }
    if(test_opponent()){
        cout << "Passed all opponent test cases" << endl;
    }

    return 0;
}

bool test_sidekick(){
    bool passed = true;
    Sidekick sidekick1;


    return passed;
}
bool test_armor(){
    bool passed = true;

    return passed;
}
bool test_weapon(){
    bool passed = true;

    return passed;
}
bool test_opponent(){
    bool passed = true;

    return passed;
}
