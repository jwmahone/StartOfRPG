//Jack Mahoney
//main.ccp for module 1 open-ended project in CS2300

#include "Weapon.h"
#include "Armor.h"
#include "Sidekick.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Opponent.h"

using namespace std;

//create a character structure
struct Character{
    string name;
    Weapon weapon1;
    Weapon weapon2;
    Armor armor;
    Sidekick sidekick;
};

//declare functions
string get_name_from_user();
int get_choice_from_user();
Weapon get_weapon(int);
Armor get_armor(int);
Sidekick get_sidekick(int, string, Weapon, Armor);


int main() {
    //initialize a character
    Character character1;

    //initialize opponent object with sword and metal armor
    Weapon opponentWeapon("default", 35, 50);
    Armor opponentArmor("default", 50, 300);
    Opponent opponent(opponentArmor, opponentWeapon);

    //initialize character price
    float totalPrice;
    //initialize choice variable used to pick items
    int choice;

    //welcome message
    cout << "Welcome" << endl;
    cout << "Who are you? ";

    //get character name
    character1.name = get_name_from_user();

    //user chooses a sidekick
    cout << "Choose a sidekick, it's free!" << endl;
    cout << " 1. Goblin \n 2. Bat \n 3. Another person" << endl;
    choice = get_choice_from_user();
    //while loop makes sure user input is one of the available choices
    while(choice < 1 || choice > 3){
        cout << "Please pick a number on the list. " << endl;
        choice = get_choice_from_user();
    }
    //get sidekick name
    cout << "What's your sidekick's name? ";
    string sidekickName = get_name_from_user();

    //user selects first weapon
    cout << "Choose a weapon: " << endl;
    cout << " 1. Sword($35) \n 2. Knives($15) \n 3. Axes($25) \n 4. Bow and arrows($35)" << endl;
    choice = get_choice_from_user();

    //while loop makes sure user input is one of the available choices
    while(choice < 1 || choice > 4){
        cout << "Please pick a number on the list. " << endl;
        choice = get_choice_from_user();
    }
    //set weapon choice once while loop is exited
    character1.weapon1 = get_weapon(choice);
    //add price of weapon to total price
    totalPrice += character1.weapon1.getPrice();

    //user selects second weapon
    cout << "Choose another weapon: " << endl;
    cout << " 1. Sword($35) \n 2. Knives($15) \n 3. Axes($25) \n 4. Bow and arrows($35)" << endl;
    choice = get_choice_from_user();
    while(choice < 1 || choice > 4){
        cout << "Please pick a number on the list. " << endl;
        choice = get_choice_from_user();
    }
    character1.weapon2 = get_weapon(choice);
    //add
    totalPrice += character1.weapon2.getPrice();

    //user selects armor
    cout << "Choose your set of armor: " << endl;
    cout << " 1. Leather($30) \n 2. Metal($50) \n 3. Rare Metal($70) \n 4. Crystal($90)"<< endl;
    choice = get_choice_from_user();
    while(choice < 1 || choice > 4){
        cout << "Please pick a number on the list. " << endl;
        choice = get_choice_from_user();
    }
    //set users armor to their choice
    character1.armor = get_armor(choice);
    totalPrice += character1.armor.getPrice();

    //user selects weapon for sidekick
    cout << "Now choose a weapon for your sidekick: " << endl;
    cout << " 1. Sword($35) \n 2. Knives($15) \n 3. Axes($25) \n 4. Bow and arrows($35)" << endl;
    choice = get_choice_from_user();
    while(choice < 1 || choice > 4){
        cout << "Please pick a number on the list. " << endl;
        choice = get_choice_from_user();
    }
    //set the users sidekick's weapon
    character1.sidekick.setWeapon(get_weapon(choice));
    totalPrice += character1.sidekick.getWeapon().getPrice();

    //user selects armor
    cout << "Choose your set of armor for your sidekick: " << endl;
    cout << " 1. Leather($30) \n 2. Metal($50) \n 3. Rare Metal($70) \n 4. Crystal($90)"<< endl;
    choice = get_choice_from_user();
    while(choice < 1 || choice > 4){
        cout << "Please pick a number on the list. " << endl;
        choice = get_choice_from_user();
    }
    //set the user's sidekick's armor
    character1.sidekick.setArmor(get_armor(choice));
    totalPrice += character1.sidekick.getArmor().getPrice();

    //create the sidekick using get_sidekick function
    character1.sidekick = get_sidekick(choice, sidekickName, character1.sidekick.getWeapon(), character1.sidekick.getArmor());

    //indicate character creation process is complete
    cout << "Character creation complete. Cost: " << totalPrice << endl;

    //start fight sequence
    cout << "Get ready to fight" << endl;
    while((character1.armor.getHealth() > 0) && (opponent.getArmor().getHealth() > 0)){
        cout << "It's your attack, would you like to attack with weapon 1 or 2(enter the number of the weapon)?" << endl;
        choice = get_choice_from_user();
        while(choice < 1 || choice > 2){
            cout << "Please pick a number on the list. " << endl;
            choice = get_choice_from_user();
        }
        //you attack and your sidekick attack the opponent
        //choose 1, use weapon 1
        if ((choice == 1) && (character1.sidekick.getArmor().getHealth() > 0)){
            //use attack function to damage opponent's armor
            opponent.setArmor(character1.weapon1.attack(opponent.getArmor(), character1.weapon1));
            opponent.setArmor(character1.sidekick.getWeapon().attack(opponent.getArmor(), character1.sidekick.getWeapon()));
            cout << "You and your sidekick attacked the opponent. " << endl;
            cout << "Damage done: " << (character1.weapon1.getDamage() + character1.sidekick.getWeapon().getDamage()) << endl;
            cout << "Opponent's armor health: " << opponent.getArmor().getHealth() << endl;
        }

        if ((choice == 1) && (character1.sidekick.getArmor().getHealth() <= 0)){
            //use attack function to damage opponent's armor
            opponent.setArmor(character1.weapon1.attack(opponent.getArmor(), character1.weapon1));
            cout << "You attacked the opponent. " << endl;
            cout << "Damage done: " << (character1.weapon1.getDamage()) << endl;
            cout << "Opponent's armor health: " << opponent.getArmor().getHealth() << endl;
        }

        //same for weapon 2
        if ((choice == 2) && (character1.sidekick.getArmor().getHealth() > 0)){
            opponent.setArmor(character1.weapon2.attack(opponent.getArmor(), character1.weapon2));
            opponent.setArmor(character1.sidekick.getWeapon().attack(opponent.getArmor(), character1.sidekick.getWeapon()));
            cout << "You and your sidekick attacked the opponent. " << endl;
            cout << "Damage done: " << (character1.weapon2.getDamage() + character1.sidekick.getWeapon().getDamage()) << endl;
            cout << "Opponent's armor health: " << opponent.getArmor().getHealth() << endl;
        }

        if ((choice == 2) && (character1.sidekick.getArmor().getHealth() <= 0)){
            //use attack function to damage opponent's armor
            opponent.setArmor(character1.weapon2.attack(opponent.getArmor(), character1.weapon2));
            cout << "You attacked the opponent. " << endl;
            cout << "Damage done: " << (character1.weapon2.getDamage()) << endl;
            cout << "Opponent's armor health: " << opponent.getArmor().getHealth() << endl;
        }

        //opponent attacks you
        character1.armor = opponent.getWeapon().attack(character1.armor, opponent.getWeapon());
        cout << "Your opponent attacked you and did " << opponent.getWeapon().getDamage() << " damage." << endl;
        cout << "Your armor health: " << character1.armor.getHealth() << endl;
        //opponent attacks your sidekick
        if(character1.sidekick.getArmor().getHealth() > 0){
            character1.sidekick.setArmor(opponent.getWeapon().attack(character1.sidekick.getArmor(), opponent.getWeapon()));
            cout << "The opponent attacked your sidekick and did " << opponent.getWeapon().getDamage() << " damage." << endl;
            cout << "Sidekick's armor health: " << character1.sidekick.getArmor().getHealth() << endl;
        }
        if(character1.sidekick.getArmor().getHealth() <= 0){
            cout << "Your sidekick is dead :(" << endl;
        }
    }
    //print statement if you and your opponent both die
    if ((character1.armor.getHealth() <= 0) && (opponent.getArmor().getHealth() <= 0)){
        cout << "You both died!" << endl;
    }
    if ((character1.armor.getHealth() > 0) && (opponent.getArmor().getHealth() <= 0)){
        cout << "You win!" << endl;
    }
    if ((character1.armor.getHealth() <= 0) && (opponent.getArmor().getHealth() > 0)){
        cout << "You lose!" << endl;
    }

    return 0;
}

int get_choice_from_user() {
    string input;
    string leftover;
    int num;
    cout << "Enter the number of your chosen item: ";
    getline(cin, input);
    if(input.empty()){
        cout << "No input. ";
        return get_choice_from_user();
    }
    stringstream ss;
    ss << input;
    if(ss >> num && ss.eof()) {
        cout << num << endl;
        return num;
    }
    else{
        cout << "Invalid input. ";
        return get_choice_from_user();
    }

}

string get_name_from_user() {
    string input;
    getline(cin, input);
    if(input.empty()){
        cout << "No input.";
        return get_name_from_user();
    }
    return input;
}

//get_weapon defines each kind of weapon and returns a weapon object
Weapon get_weapon(int choice){
    if(choice == 1){
        string name = "sword";
        int damage = 50;
        float price = 35;
        //weapon object
        Weapon weapon(name, price, damage);
        return weapon;
    }
    if(choice == 2) {
        string name = "knives";
        int damage = 25;
        float price = 15;
        //weapon object
        Weapon weapon(name, price, damage);
        return weapon;
    }
    if(choice == 3) {
        string name = "axes";
        int damage = 40;
        float price = 25;
        //weapon object
        Weapon weapon(name, price, damage);
        return weapon;
    }
    if(choice == 4) {
        string name = "bow";
        int damage = 20;
        float price = 35;
        //weapon object
        Weapon weapon(name, price, damage);
        return weapon;
    }
}

//get_armor defines each kind of armor and returns an armor object
Armor get_armor(int choice){
    if(choice == 1){
        string name = "leather";
        int health = 100;
        float price = 30;
        Armor armor(name, price, health);
        return armor;
    }
    if(choice == 2) {
        string name = "metal";
        int health = 150;
        float price = 50;
        Armor armor(name, price, health);
        return armor;
    }
    if(choice == 3) {
        string name = "rare metal";
        int health = 175;
        float price = 70;
        Armor armor(name, price, health);
        return armor;
    }
    if(choice == 4) {
        string name = "crystal";
        int health = 200;
        float price = 90;
        Armor armor(name, price, health);
        return armor;
    }
}

Sidekick get_sidekick(int choice, string name, Weapon weapon, Armor armor){
    if(choice == 1){
        string type = "goblin";
        int damage = 50;
        Sidekick sidekick(name, type, damage, weapon, armor);
        return sidekick;
    }
    if(choice == 2) {
        string type = "bat";
        int damage = 40;
        Sidekick sidekick(name, type, damage, weapon, armor);
        return sidekick;
    }
    if(choice == 3) {
        string type = "person";
        int damage = 30;
        Sidekick sidekick(name, type, damage, weapon, armor);
        return sidekick;
    }
}



