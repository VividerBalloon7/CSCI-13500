#include <iostream>
#include <random>
#include <cctype>


int main(){

    // start game (declare variables)
    int player_score = 0;
    int bot_score = 0;
    std::string player_move = "";
    int bot_move = 0;
    std::string bot_pick = ""; 

    // game loop
    for (int rounds = 0; rounds < 3; rounds++){

        // check for early winner 
        if (player_score >= 2 || bot_score >= 2){
            break;
        }

        // ask for user input 
        std::cout << "Choose rock, paper or scissor: ";
        std::cin >> player_move;

        // Capitalize player input
        player_move[0] = toupper(player_move[0]);

        for (int i = 1; i < player_move.length(); i++){
            player_move[i] = tolower(player_move[i]);
        }



        // generate bot input 
        bot_move = rand() % 3;

        if (bot_move == 0){
            bot_pick = "Rock";
            std::cout << "Bot picked: " << bot_pick << std::endl;
        }
        else if (bot_move == 1){
            bot_pick = "Paper";
            std::cout << "Bot picked: " << bot_pick << std::endl;
        }
        else{
            bot_pick = "Scissor";
            std::cout << "Bot picked: " << bot_pick << std::endl;
        }

        // figure out the score 
        if (player_move == bot_pick){
            player_score += 0;
            bot_score += 0;
            std::cout << "Player and Bot tied!" << std::endl;
        }
        else if (player_move == "Rock" && bot_pick == "Scissor"){
            player_score++;
            std::cout << "Player Wins!" << std::endl;

        }
        else if (player_move == "Paper" && bot_pick == "Rock"){
            player_score++;
            std::cout << "Player Wins!" << std::endl;

        }
        else if (player_move == "Scissor" && bot_pick == "Paper"){
            player_score++;
            std::cout << "Player Wins!" << std::endl;

        }
        else{
            bot_score++;
            std::cout << "Bot Wins!" << std::endl;
        }
        //Keeps track of player and bot scores
        std::cout << "Score: Player " << player_score << " - Bot " << bot_score << std::endl;
    }

    // Declare winner or tie
    if (player_score > bot_score){
        std::cout << "Player wins!" << std::endl;
    }
    else if (bot_score > player_score){
        std::cout << "Bot wins!" << std::endl;
    }
    else{
        std::cout << "Tie!" << std::endl;
    }

}