#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Game.hpp"
#define incomeBonus 1
#define foreignAidBonus 2
using namespace std;



namespace coup {
    class Player {
        protected:
            Game game;
            int coin;
            string roleName;
            bool isPlaying;
            bool isAlive;
            int playerNumber = 0;
            string name;


        public: 
            Player(Game &game, string name, string roleName) : game(game), name(name), roleName(roleName), coin(0), isPlaying(true), isAlive(true), playerNumber(playerNumber +1){}
            void income();
            void foreign_aid();
            void coup(Player &player);
            int coins();
            void role();
            bool dead();
            void revive();
            ~Player();
        
        friend class Game;
    };
}
