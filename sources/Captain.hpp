
#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.hpp"
#define captainsteal 2
using namespace std;
using namespace coup;



namespace coup {
    class Captain: public Player {
        private:
            

        public:
            Player *bS;
            Captain(Game, string): Player(game, name, "Captain"){
                game.addPlayer(*this);
                bS = nullptr;
            }
            void steal(Player &);
            void block(Player &);
            ~Captain();
        
        friend class Ambassador;
    };
}
