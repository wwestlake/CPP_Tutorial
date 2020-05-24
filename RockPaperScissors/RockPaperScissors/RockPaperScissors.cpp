// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


// X 1. Display a prompt to the user 
// X 2. Read a line of input from the user
// 3. Process the user input (into Rock, Paper, Scissors, or Quit, or Help) 
//    3.1 If quit exit game
//    3.2 If help display help text and goto to step 1
// X 4. Computer randomly select a Rock, Paper or Scissors
// X 5. Compare and determine winner or a draw (select same it is a draw)
// 6. Accumlate a score for the computer and the user
// 7. Display the results of the round
// 8. Go back to 1 or quit

enum class Tokens { ROCK = 0, PAPER, SCISSORS, QUIT, HELP };
enum class PlayResult { Computer, Player, Draw };

typedef struct Score 
{
    int User = 0;
    int Computer = 0;
} Score_t;


void Prompt(std::string prompt)
{
    std::cout << prompt;
    std::cout.flush();
}

std::string ReadUserInput()
{
    std::string result;
    std::getline(std::cin, result);
    return result;
}

const std::string WS = " \n\r\t\f\v";

std::string left_trim(const std::string& input)
{
    size_t start = input.find_first_not_of(WS);
    return (start == std::string::npos) ? "" : input.substr(start);
}

std::string right_trim(const std::string& input)
{
    size_t end = input.find_last_not_of(WS);
    return (end == std::string::npos) ? "" : input.substr(0, end + 1);
}

std::string trim(const std::string& input)
{
    return right_trim(left_trim(input));
}

Tokens Tokenize(const std::string& input)
{
    char ch = input[0];
    if (ch == 'R' || ch == 'r') return Tokens::ROCK;
    if (ch == 'P' || ch == 'p') return Tokens::PAPER;
    if (ch == 'S' || ch == 's') return Tokens::SCISSORS;
    if (ch == 'Q' || ch == 'q') return Tokens::QUIT;
    if (ch == 'H' || ch == 'h') return Tokens::HELP;
}

// RandomToken only selects ROCK, PAPER, or SCISSORS
Tokens RandomToken()
{
    return static_cast<Tokens>(std::rand() % 3);
}

PlayResult CompareSelection(Tokens player, Tokens computer)
{

    switch (player)
    {
    case Tokens::ROCK: 
        switch (computer)
        {
            case Tokens::ROCK: return PlayResult::Draw;
            case Tokens::PAPER: return PlayResult::Computer;
            case Tokens::SCISSORS: return PlayResult::Player;
        }
    case Tokens::PAPER:
        switch (computer)
        {
            case Tokens::ROCK: return PlayResult::Player;
            case Tokens::PAPER: return PlayResult::Draw;
            case Tokens::SCISSORS: return PlayResult::Computer;
        }
    case Tokens::SCISSORS:
        switch (computer)
        {
            case Tokens::ROCK: return PlayResult::Computer;
            case Tokens::PAPER: return PlayResult::Player;
            case Tokens::SCISSORS: return PlayResult::Draw;
        }
    }

}

std::string ToString(PlayResult playResult)
{
    switch (playResult)
    {
        case PlayResult::Computer: return "Computer";
        case PlayResult::Player: return "Player";
        case PlayResult::Draw: return "Draw";
    }
}

void Help() 
{
    std::cout << "Really? You need help with this game!" << std::endl;
}

void ScoreResult(PlayResult play, Score_t& score)
{
    switch (play)
    {
    case PlayResult::Computer: score.Computer++; break;
    case PlayResult::Player: score.User++; break;
    case PlayResult::Draw: break;
    }
}


int main()
{
    Score_t score;

    std::srand(std::time(nullptr));

    while (true)
    {

        Prompt("R)ock, P)aper, S)cissors, Q)uit, H)elp >");
        Tokens token = Tokenize(trim(ReadUserInput()));

        switch (token)
        {
        case Tokens::QUIT: return 0;
        case Tokens::HELP: Help(); continue;
        }

        Tokens comp = RandomToken();
        PlayResult result = CompareSelection(token, comp);

        ScoreResult(result, score);

        std::cout << "The winner is: " << ToString(result) << std::endl;
        std::cout << "  The score is: Player   - " << score.User << std::endl;
        std::cout << "                Computer - " << score.Computer << std::endl;

    }
}

