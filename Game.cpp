#include "Game.hpp"
#include "Player.hpp"


namespace coup {



    Game::Game() {
        for (string role : roleList){
            pair<string, vector<coup::Player* >> pair = {role, vector<Player* >()};
            roles.insert(pair);
        }
    }



    string Game::turn(){
        string s = this -> playerList.at(this -> curPlayer).name;
        return s;
    }


    string Game::winner(){
        for (Player &player : this->playerList){
            if (player.dead() == false){
                return player.name;
            }
        }
        throw invalid_argument("the game is not over yet");
    }


    vector<string> Game::players(){
        vector<string> PlayerNames;
        for (Player &player : this->playerList){
            if (player.dead() == true){
                PlayerNames.push_back(player.name);
            }
        }
        return PlayerNames;
    }


    void Game::add_player(Player &p){
        int size = this->playerList.size();
        p.playerNumber = size;
        this->playerList.push_back(p);
        this->roles.at(p.roleName).push_back(&p);
    }

}