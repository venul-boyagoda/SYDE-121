//***************************************************************************************************
// Name: Venul Boyagoda
// Student ID: 20909488
//
// Name: Janani Satkunarajah
// Student ID: 20885299
//
// SYDE 121: Assignment 4 - Question 1
// Filename: a4_q1.cpp
//
// We hereby declare that this code, submitted for credit for the course SYDE 121, is a product of our
// own efforts. This coded solution has not been plagarized from other sources and has not been
// knowingly plagarized by others.
//
// Project: Tictactoe Game Simulation
// Purpose: A program that simulates a tictactoe game between two players: X and O
// Due Date: Friday, November 6, 2020
//***************************************************************************************************

/*
Program Testing Scenarios:
 - Player X winning with all combinations (4 consecutive Xs in each row, column, diagonal)
 - Player O winning with all combinations (4 consecutive Os in each row, column, diagonal)
 - Verified that program could determine if the game ended with a tie after the board is filled
 - Verified that the user cannot enter an occupied location or a location that is out of bounds
 - Tried multiple rounds of game to check that final scores were correct and that games alternated the starting player
 
Limitations
 - 4x4 board is not as complex as playing on an nxn board
 */

#include <iostream>
#include <array>
using namespace std;

void draw_board(array<array<string, 4>, 4> board);
// PURPOSE: Output game board
//    INPUTS: board - array of board values
//    OUTPUTS: none; outputs to console

void player_turn(string player, array<array<string, 4>, 4>& board);
// PURPOSE: Allow player to enter location and update board
//    INPUTS: player - string of player symbol
//            board - array of board values
//    OUPUTS: none; passes value by reference

bool detect_winner(array<array<string, 4>, 4> board, string symbol, int& score, int turn_count, int& tie_count);
// PURPOSE: iterates through elements of the board array searching for 4 horizontal, vertical or diagonal consecutive symbols
//    INPUTS: board - array storing the current board configuration
//            symbol - string containing the symbol of the most recent player
//            score - integer variable passed by reference containing the most recent player's current score
//            turn_count - integer variable containing the current turn number in the game (value from 1 to 16)
//            tie_count - integer value of number of ties
//    OUTPUTS: returns true is there is a winning combination and prints the results to console
//             returns false if there is no winner

void run_tictactoe_game(string player1, int& score1, string player2, int& score2, int& tie_count);
// PURPOSE: runs one game of tictactoe
//    INPUTS: player1 - string of symbol for starting player
//            score1 - integer passed by reference of score of starting player
//            player2 - string of symbol for second player
//            score2 - integer passed by reference of score of second player
//            tie_count - integer passed by reference of number of ties
//    OUTPUTS: none; values passed by reference

void run_simulation();
// PURPOSE: runs simulation

void draw_board(array<array<string, 4>, 4> board) {
    // step1. loop through both dimenensions of board array and output board array as a square
    for (int index1 = 0; index1 < board.size(); index1++ ) {
        for (int index2 = 0; index2 < board[0].size(); index2++) {
            cout.flags(ios::left);
            cout.width(5);
            cout << board[index1][index2];
        }
        cout << endl;
    }
    cout << endl;
}

void player_turn(string player, array<array<string, 4>, 4>& board) {
    // step1. declare and initialize variables
    int player_entry = 0;
    int x_position = 0;
    int y_position = 0;
    bool invalid_location = true;
    
    // step2. continue to allow player to enter location until valid location is entered
    while (invalid_location) {
        // step2.1 allow player to enter location
        cout << "Player " << player << ", enter the number of the location you would like to take ";
        cin >> player_entry;
        
        // step2.2 determine location of user enetered integer in array
        if (player_entry % board.size() == 0) {
            y_position = player_entry / board.size() - 1;
        }
        else {
            y_position = player_entry / board.size();
        }
        x_position = (player_entry - 1) % board[0].size();
        
        // step2.3 determine which locations are invalid
        invalid_location = player_entry > 16;
        invalid_location = invalid_location || player_entry < 1;
        invalid_location = invalid_location || board[y_position][x_position] == "X";
        invalid_location = invalid_location || board[y_position][x_position] == "O";
        
        // step 2.4 Update board if location is valid
        if (!invalid_location) {
            board[y_position][x_position] = player;
        }
    }
    cout << endl;
}

bool detect_winner(array<array<string, 4>, 4> board, string symbol, int& score, int turn_count, int& tie_count){
    
    // step1. loop to check rows for 4 matching symbols
    for (int row = 0; row < 4; row++){
        for (int element = 0; element < 4; element++){
            if (board[row][element] != symbol){
                break;
            }
            else if (element == 3){
                cout << symbol << " is the winner! Congratulations!" << endl << endl;
                score++;
                return true;
            }
        }
    }
    
    // step2. loop to check columns for 4 matching symbols
    for (int column = 0; column < 4; column++){
        for (int element = 0; element < 4; element++){
            if (board[element][column] != symbol){
                break;
            }
            else if (element == 3){
                cout << symbol << " is the winner! Congratulations!" << endl << endl;
                score++;
                return true;
            }
        }
    }
    
    // step3. loop to check diagonal for 4 matching symbols
    for (int element = 0; element < 4; element++){
        if (board[element][element] != symbol){
            break;
        }
        else if (element == 3){
            cout << symbol << " is the winner! Congratulations!" << endl << endl;
            score++;
            return true;
        }
    }
    
    // step4. loop to check anti-diagonal for 4 matching symbols
    for (int element = 0; element < 4; element++){
        if (board[element][3 - element] != symbol){
            break;
        }
        else if (element == 3){
            cout << symbol << " is the winner! Congratulations!" << endl << endl;
            score++;
            return true;
        }
    }
    
    // step5. player has not won if there are no horizontal, vertical or diagonal combinations of 4 matching symbols
    if (turn_count == 15){
        cout << "It's a tie! No winner this time." << endl << endl;
        tie_count++;
    }
    return false;
}

void run_tictactoe_game(string player1, int& score1, string player2, int& score2, int& tie_count) {
    array<array<string, 4>, 4> board = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};
    // step1. declare and initialize variables
    int turn_num = 0;
    bool winner_exists = false;
    
    // step2. output initial board
    draw_board(board);
    
    // step3. continue game until there is winner or a tie
    while (turn_num < 16 && !winner_exists) {
        // step3.1 conditional statement to alternate between player turns
        if (turn_num % 2 == 1){
            player_turn(player1, board);
            // step3.2 output board after each turn
            draw_board(board);
            if (turn_num >= 6) {
                winner_exists = detect_winner(board, player1, score1, turn_num, tie_count);
            }
        }
        else {
            player_turn(player2, board);
            // step3.2 output board after each turn
            draw_board(board);
            if (turn_num >= 6) {
                winner_exists = detect_winner(board, player2, score2, turn_num, tie_count);
            }
        }
        // step3.3 increment number of turns after each turn
        turn_num++;
    }
}

void run_simulation() {
    // step1. declare and initialize variables
    int score_x = 0;
    int score_o = 0;
    int tie_count = 0;
    int game_number = 1;
    bool continue_game = true;
    string player_x = "X";
    string player_o = "O";
    
    // step2. continue rounds of game until user decides to exit
    do {
        // step2.1 conditional statement to determine starting player
        if (game_number % 2 == 0) {
            run_tictactoe_game(player_x, score_x, player_o, score_o, tie_count);
        }
        else {
            run_tictactoe_game(player_o, score_o, player_x, score_x, tie_count);
        }
        // step2.2 increment number of games after each game
        game_number++;
        
        // step2.3 determine if user wants to continue playng more rounds
        cout << "Enter 1 if you want to continue game, or enter 0 if you want to exit ";
        cin >> continue_game;
        cout << endl;
        
    } while(continue_game);
    
    // step3. output final results once user has decided to stop playing
    cout << "Score Player X - Player O : " << score_x << " - " << score_o << endl;
    cout << "Number of Ties : " << tie_count << endl << endl;
}

int main() {
    run_simulation();
}
