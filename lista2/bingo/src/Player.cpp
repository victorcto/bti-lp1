#include "Player.hpp"

Player::Player(std::string name, std::vector<int> card){
    this->name = name;
    this->card = card; 
}

std::vector<int> Player::getCard(){
    return this->card;
}

std::string Player::getName(){
    return this->name;
}

void Player::setWin(bool win){
    if(win == true)
        this->win = true;
    else
        this->win = false;
}

bool Player::getWin(){
    return this->win;
}