#include <iostream>
#include <cctype>

//Welcome Message
void WelcomeMessage() {
    std::cout << "Welcome to my new and improved rock, paper, scissors code!" << std::endl;
    std::cout << "Have fun experimenting!" << std::endl;
}

//Getting the player's choice
std::string getPlayerChoice() {
    std::string playerChoice;
    std::cout << "Choose rock, paper or scissors: ";
    std::cin >> playerChoice;

   for (int i = 0; i < playerChoice.size(); i++) {
       playerChoice[i] = tolower(playerChoice[i]);
   }

    if (playerChoice == "paper" ||
        playerChoice == "rock" ||
        playerChoice == "scissors") {
        return playerChoice;
    }
    else {
        std::cout << "INVALID CHOICE. Try again.\n";
    }

}

//Getting the bot's choice
std::string getBotChoice() {
    int botChoice = rand() % 3;

    if (botChoice == 0) {
        return "rock";
    }

    else if (botChoice == 1) {
       return "paper";
    }

    else {
       return "scissors";
    }

}

//Updating track of the score
void updateScore(std::string playerChoice, std::string botChoice, int& player_score, int& bot_score) {
    if (playerChoice == botChoice) {
        std::cout << "Tie!\n";
    }
    else if ((playerChoice == "rock" && botChoice == "scissors") ||
        (playerChoice == "scissors" && botChoice == "paper") ||
        (playerChoice == "paper" && botChoice == "rock")) {

        std::cout << "You win this round!\n";
        player_score++;
    }
    else {
        std::cout << "Bot wins this round!\n";
        bot_score++;
    }
}

//Displaying results
void displayResults(std::string playerChoice, std::string botChoice, int& player_score, int& bot_score) {
    std::cout << "You chose: " << playerChoice << std::endl;
    std::cout << "Bot chose: " << botChoice << std::endl;

    std::cout << "Player score: " << player_score << std::endl;
    std::cout << "Bot score: " << bot_score << std::endl;
}

int main() {

    WelcomeMessage();

    int player_score = 0;
    int bot_score = 0;
    while (player_score < 3 && bot_score < 3) {
        std::string player_move = getPlayerChoice();
        std::string bot_move = getBotChoice();
        updateScore(player_move, bot_move, player_score, bot_score);
        displayResults(player_move, bot_move, player_score, bot_score);
    }

    std::cout << "Game over!\n";

}






