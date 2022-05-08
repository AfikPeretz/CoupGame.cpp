#include "Player.hpp"
#include <iostream>


namespace coup {


    void Player::coup(Player &p){
        if (this->coin < couPrice){
            throw invalid_argument("You do not have enough coins to perform this operation!");
        }
        if (p.dead() == true){
            throw invalid_argument("The player is dead already");
        }
        this->coin = coin - couPrice;
        p.dead();
        this->game.endTurn();
    }


    void Player::income(){
        if (this -> game.turn() != this -> name){
            throw invalid_argument("Wait to your turn!");
        }
        this -> coin = coin + incomeBonus;
        this -> game.endTurn();
    }


    bool Player::dead(){
        return this -> isAlive = false;
    }

    int Player::coins(){
        return this -> coin;
    }

    void Player::foreign_aid(){
        if (this -> game.turn() != this -> name){
            throw invalid_argument("Wait to your turn!");
        }
        if (this -> coin >= maxCapacity){
            throw invalid_argument("you have reached the capacity limit!");
        }
        this -> game.addB(this, "Duke");
        this -> canGetHurt = true;
        this -> coin = coin + foreignAidBonus;
        this -> game.endTurn();
    }

    void Player::revive(){
        this -> isAlive = true;
    }

    string Player::role(){
        return this -> roleName;
    }

}