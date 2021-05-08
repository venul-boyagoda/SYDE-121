//****************************************************************************
// Student Name: Venul Boyagoda
// Student Number: 20909488
//
// SYDE 121 Assignment: 3
// Filename: a3_q1
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Soccer Simulation
// Purpose: Simulate a real time soccer match.
// Due Date: Friday, October 30, 2020
//**************************************************************
/*
 Testing Program:
 To test the program, first I ran the simulation multiple times and verified that the events generated were random
 and that no particular scenario or event happend in a pattern or repeatedly.
 I also ran the program multiple times until I verified that each event happened at least once (ex blocked shot,
 penalty kicks, cards, etc) throughout my tests and that none of them were always 0 even after doing many tests
 Finally, I used the following simulation output and manually calculated that all the values being outputted at half
 time and the end of the game were accurate:
 Welcome to the soccer match simulation, where Team A and Team B will be playing each other for the Cup

 Team A made a shot off goal! The shot was off a Free Kick, from a foul by Team B. A yellow card was given for the foul!

 Team A made a shot on goal, but it was saved by the goalie or last defender! Close! The shot was off a Penalty Kick, from a foul by Team B. A yellow card was given for the foul!

 Team A's shot was blocked by a player who is not the goalie! The shot was off a Free Kick, from a foul by Team B. A red card was given for the foul!

 Team B has scored a goal! Nice Shot! The shot was off a Free Kick, from a foul by Team A. No card was given for the foul!

 Team A made a shot on goal, but it was saved by the goalie or last defender! Close!

 Team A's shot was blocked by a player who is not the goalie!

 End of first half stats:
                  Team A: Team B:
           Score:       0       1
   Shots On Goal:       2       1
  Shots Off Goal:       1       0
   Blocked Shots:       0       2
           Fouls:       1       3
    Yellow Cards:       0       2
       Red Cards:       0       1
 Team A made a shot on goal, but it was saved by the goalie or last defender! Close! The shot was off a Penalty Kick, from a foul by Team B. No card was given for the foul!

 Team A's shot was blocked by a player who is not the goalie!

 Team A has scored a goal! Nice Shot! The shot was off a Penalty Kick, from a foul by Team B. No card was given for the foul!

 Team A made a shot off goal! The shot was off a Free Kick, from a foul by Team B. A yellow card was given for the foul!

 Team B's shot was blocked by a player who is not the goalie!

 Team A's shot was blocked by a player who is not the goalie!

 Team B has scored a goal! Nice Shot! The shot was off a Penalty Kick, from a foul by Team A. No card was given for the foul!

 End of game stats:
                  Team A: Team B:
           Score:       1       2
   Shots On Goal:       4       2
  Shots Off Goal:       2       0
   Blocked Shots:       1       4
           Fouls:       2       6
    Yellow Cards:       0       3
       Red Cards:       0       1

 TEAM B WINS THE SOCCER MATCH

 Limitations:
 One of the main limitations to my simulation is that there is a random chance of any event happening or any team getting
 a goal, however this should not be the case as soccer teams have different players of different skill levels where some
 may have a greater chance of getting a shot or blocking a shot
 Another limitiation is that my simulation only does 2 halves and then determines if there is a winner of if there is a tie,
 however in a real soccer match, if it was a tie, there would be further overtime which my program does not simulate
 */

#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <thread>
using namespace std;

void shot_at_target(string team_name, const int MAX_POSSIBILITIES_FOR_GOAL, int& team_shooting_score, int& team_shooting_shots_on_goal, int& team_shooting_shots_off_goal, int& opposition_shots_blocked);
// PURPOSE: Performs actions that happen when a team attempts a shot
//     INPUTS: team_name - string of team name thats taking shot,
//             MAX_POSSIBILITIES_FOR_GOAL - const integer value of number possibilities for a shot attempt,
//             team_shooting_score - integer value of score of team shooting score,
//             team_shooting_shots_on_goal - integer value of team shooting number of shots on goal,
//             team_shooting_shots_off_goal - integer value of team shooting nuber of shots off goal,
//             opposition_shots_blocked - integer value of shots blocked by team not shooting
//     OUTPUTS: none, passed by reference or outputted to console

void foul_and_free_kick_or_penalty(string type_of_foul_kick, string opp_team_name, int& opp_team_fouls, int& opp_team_yellow_cards, int& opp_team_red_cards);
// PURPOSE: Performs actions that happen when a team is given a free kick or penalty due to foul from other team
//     INPUTS: type_of_foul_kick - string of type of foul kick given (penalty or free kick),
//             opp_team_name - string of name of team that committed the foul,
//             opp_team_fouls - integer value of number of fouls of team that committed foul,
//             opp_team_yellow_cards - integer value of number of yellow cards of team that committed foul,
//             opp_team_red_cards - integer value of number of red cards of team that committed foul
//     OUTPUTS: none, passed by reference or outputted to console

void execute_half(int num_of_events, int& teama_score, int& teamb_score, int& teama_shots_on_goal, int& teamb_shots_on_goal, int& teama_shots_off_goal, int& teamb_shots_off_goal, int& teama_blocked_shots, int& teamb_blocked_shots, int& teama_fouls, int& teamb_fouls, int& teama_yellow_cards, int& teamb_yellow_cards, int& teama_red_cards, int& teamb_red_cards);
// PURPOSE: Executes one half of the simulation
//     INPUTS: num_of_events - integer value of the number of events in the half,
//             teama_score - integer value of Team A's score,
//             teamb_score - integer value of Team B's score,
//             teama_shots_on_goal - integer value of the number of Team A's shots on goal,
//             teamb_shots_on_goal - integer value of the number of Team B's shots on goal,
//             teama_shots_off_goal - integer value of the number of Team A's shots off goal,
//             teamb_shots_off_goal - integer value of the number of Team B's shots off goal,
//             teama_blocked_shots - integer value of the number of Team A's blocked shots,
//             teamb_blocked_shots - integer value of the number of Team B's blocked shots,
//             teama_fouls - integer value of the number of Team A's fouls,
//             teamb_fouls - integer value of the number of Team B's fouls,
//             teama_yellow_cards - integer value of the number of Team A's yellow cards,
//             teamb_yellow_cards - integer value of the number of Team B's yellow cards,
//             teama_red_cards - integer value of the number of Team A's red cards,
//             teamb_red_cards - integer value of the number of Team B's red cards,
//     OUTPUTS: none, values passed by reference

void output_stats(int teama_score, int teamb_score, int teama_shots_on_goal, int teamb_shots_on_goal, int teama_shots_off_goal, int teamb_shots_off_goal, int teama_blocked_shots, int teamb_blocked_shots, int teama_fouls, int teamb_fouls, int teama_yellow_cards, int teamb_yellow_cards, int teama_red_cards, int teamb_red_cards);
// PURPOSE: Outputs current stats of soccer match
//     INPUTS: teama_score - integer value of Team A's score,
//             teamb_score - integer value of Team B's score,
//             teama_shots_on_goal - integer value of the number of Team A's shots on goal,
//             teamb_shots_on_goal - integer value of the number of Team B's shots on goal,
//             teama_shots_off_goal - integer value of the number of Team A's shots off goal,
//             teamb_shots_off_goal - integer value of the number of Team B's shots off goal,
//             teama_blocked_shots - integer value of the number of Team A's blocked shots,
//             teamb_blocked_shots - integer value of the number of Team B's blocked shots,
//             teama_fouls - integer value of the number of Team A's fouls,
//             teamb_fouls - integer value of the number of Team B's fouls,
//             teama_yellow_cards - integer value of the number of Team A's yellow cards,
//             teamb_yellow_cards - integer value of the number of Team B's yellow cards,
//             teama_red_cards - integer value of the number of Team A's red cards,
//             teamb_red_cards - integer value of the number of Team B's red cards,
//     OUTPUTS: none, outputted to console

void execute_soccer_simulation();
// PURPOSE: Executes and begins simulation
//     INPUTS: none
//     OUTPUTS: none

void shot_at_target(string team_name, const int MAX_POSSIBILITIES_FOR_GOAL, int& team_shooting_score, int& team_shooting_shots_on_goal, int& team_shooting_shots_off_goal, int& opposition_shots_blocked) {
    // step1. declare and initialize variables
    int goal_determining_num = 0;
    
    // step2. generate random number from 0 to 3 that determines how the shot will play out
    goal_determining_num = rand() % (MAX_POSSIBILITIES_FOR_GOAL + 1);
    
    // step3. check what number the random number is and continue game accordingly
    if (goal_determining_num == 0) {
        // step3.1 if random number is 0, the goal is scored
        team_shooting_score += 1;
        team_shooting_shots_on_goal += 1;
        cout << team_name << " has scored a goal! Nice Shot! ";
    }
    else if (goal_determining_num == 1) {
        // step 3.2 if random number is 1, the shot is on goal, but saved
        team_shooting_shots_on_goal += 1;
        cout << team_name << " made a shot on goal, but it was saved by the goalie or last defender! Close! ";
    }
    else if (goal_determining_num == 2) {
        // step3.3 if random number is 2, the shot is off goal
        team_shooting_shots_off_goal += 1;
        cout << team_name << " made a shot off goal! ";
    }
    else if (goal_determining_num == 3) {
        // step3.4 if random number is 3, the shot is blocked
        opposition_shots_blocked += 1;
        cout << team_name << "'s shot was blocked by a player who is not the goalie! ";
    }
}

void foul_and_free_kick_or_penalty(string type_of_foul_kick, string opp_team_name, int& opp_team_fouls, int& opp_team_yellow_cards, int& opp_team_red_cards) {
    // step1. declare and initialize variables
    int card_determining_num = 0;
    const int MAX_POSSIBILITIES_FOR_CARD = 2;
    
    // step2. generate random number from 0 to 2 to determine which card is given for foul
    card_determining_num = rand() % (MAX_POSSIBILITIES_FOR_CARD + 1);
    
    // step3. check what the random number is and continue game accordingly
    if (card_determining_num == 0) {
        // step3.1 if random number is 0, there is no card given for foul
        opp_team_fouls += 1;
        cout << "The shot was off a " << type_of_foul_kick << ", from a foul by " << opp_team_name << ". No card was given for the foul!";
    }
    else if (card_determining_num == 1) {
        // step3.2 if random number is 1, a yellow card is given
        opp_team_fouls += 1;
        opp_team_yellow_cards += 1;
        cout << "The shot was off a " << type_of_foul_kick << ", from a foul by " << opp_team_name << ". A yellow card was given for the foul!";
    }
    else {
        // step3.3 if random number is 2, a red card is given
        opp_team_fouls += 1;
        opp_team_red_cards += 1;
        cout << "The shot was off a " << type_of_foul_kick << ", from a foul by " << opp_team_name << ". A red card was given for the foul!";
    }
}

void execute_half(int num_of_events, int& teama_score, int& teamb_score, int& teama_shots_on_goal, int& teamb_shots_on_goal, int& teama_shots_off_goal, int& teamb_shots_off_goal, int& teama_blocked_shots, int& teamb_blocked_shots, int& teama_fouls, int& teamb_fouls, int& teama_yellow_cards, int& teamb_yellow_cards, int& teama_red_cards, int& teamb_red_cards) {
    // step1. declare and initialize variables
    int event_type_num = 0;
    const int MAX_TYPES_OF_EVENTS = 6;
    const int MAX_POSSIBILITIES_FOR_GOAL = 3;
    const int MAX_POSSIBILITIES_FOR_PENALTY_GOAL = 2;
    
    // step2. loop through number of events in half
    for (int index = 1; index <= num_of_events; index++) {
        // step2.1 generate random number from 1 to 6 to determine what type of event will happen
        event_type_num = (rand() % MAX_TYPES_OF_EVENTS) + 1;
        
        // step2.2 check what random number is and continue game accordingly
        if (event_type_num == 1) {
            // step 2.2.1 if random number is 1, Team A has shot at target
            shot_at_target("Team A", MAX_POSSIBILITIES_FOR_GOAL, teama_score, teama_shots_on_goal, teama_shots_off_goal, teamb_blocked_shots);
            cout << endl << endl;;
            this_thread::sleep_for(chrono::seconds(3));
        }
        else if (event_type_num == 2) {
            // step 2.2.2 if random number is 2, Team B has shot at target
            shot_at_target("Team B", MAX_POSSIBILITIES_FOR_GOAL, teamb_score, teamb_shots_on_goal, teamb_shots_off_goal, teama_blocked_shots);
            cout <<endl << endl;
            this_thread::sleep_for(chrono::seconds(3));
        }
        else if (event_type_num == 3) {
            // step 2.2.3 if random number is 3, Team B has committed foul, Team A has free kick
            shot_at_target("Team A", MAX_POSSIBILITIES_FOR_GOAL, teama_score, teama_shots_on_goal, teama_shots_off_goal, teamb_blocked_shots);
            foul_and_free_kick_or_penalty("Free Kick", "Team B", teamb_fouls, teamb_yellow_cards, teamb_red_cards);
            cout <<endl << endl;
            this_thread::sleep_for(chrono::seconds(3));
        }
        else if (event_type_num == 4) {
            // step 2.2.4 if random number is 4, Team A has committed foul, Team B has free kick
            shot_at_target("Team B", MAX_POSSIBILITIES_FOR_GOAL, teamb_score, teamb_shots_on_goal, teamb_shots_off_goal, teama_blocked_shots);
            foul_and_free_kick_or_penalty("Free Kick", "Team A", teama_fouls, teama_yellow_cards, teama_red_cards);
            cout <<endl << endl;
            this_thread::sleep_for(chrono::seconds(3));
        }
        else if (event_type_num ==5) {
            // step 2.2.5 if random number is 5, Team B has committed foul close to goal, Team A has penalty kick
            shot_at_target("Team A", MAX_POSSIBILITIES_FOR_PENALTY_GOAL, teama_score, teama_shots_on_goal, teama_shots_off_goal, teamb_blocked_shots);
            foul_and_free_kick_or_penalty("Penalty Kick", "Team B", teamb_fouls, teamb_yellow_cards, teamb_red_cards);
            cout <<endl << endl;
            this_thread::sleep_for(chrono::seconds(3));
        }
        else {
            // step 2.2.5 if random number is 6, Team A has committed foul close to goal, Team B has penalty kick
            shot_at_target("Team B", MAX_POSSIBILITIES_FOR_PENALTY_GOAL, teamb_score, teamb_shots_on_goal, teamb_shots_off_goal, teama_blocked_shots);
            foul_and_free_kick_or_penalty("Penalty Kick", "Team A", teama_fouls, teama_yellow_cards, teama_red_cards);
            cout <<endl << endl;
            this_thread::sleep_for(chrono::seconds(3));
        }
    }
}

void output_stats(int teama_score, int teamb_score, int teama_shots_on_goal, int teamb_shots_on_goal, int teama_shots_off_goal, int teamb_shots_off_goal, int teama_blocked_shots, int teamb_blocked_shots, int teama_fouls, int teamb_fouls, int teama_yellow_cards, int teamb_yellow_cards, int teama_red_cards, int teamb_red_cards) {
    // step1. create a table outputting the current stats of the game
    cout << setw(16) << "" << setw(8) << "Team A:" << setw(8) << "Team B:" << endl;
    cout << setw(16) << "Score:" << setw(8) << teama_score << setw(8) << teamb_score << endl;
    cout << setw(16) << "Shots On Goal:" << setw(8) << teama_shots_on_goal << setw(8) << teamb_shots_on_goal << endl;
    cout << setw(16) << "Shots Off Goal:" << setw(8) << teama_shots_off_goal << setw(8) << teamb_shots_off_goal << endl;
    cout << setw(16) << "Blocked Shots:" << setw(8) <<  teama_blocked_shots << setw(8) << teamb_blocked_shots << endl;
    cout << setw(16) << "Fouls:" << setw(8) << teama_fouls << setw(8) << teamb_fouls << endl;
    cout << setw(16) << "Yellow Cards:" << setw(8) << teama_yellow_cards << setw(8) << teamb_yellow_cards << endl;
    cout << setw(16) << "Red Cards:" << setw(8) << teama_red_cards << setw(8) << teamb_red_cards << endl;
    this_thread::sleep_for(chrono::seconds(3));
}

void execute_soccer_simulation() {
    //step1. declare and initialize variables
    int num_events = 0;
    const int MAX_NUM_OF_EVENTS = 20;
    int first_half_events = 0;
    int second_half_events = 0;
    int teama_score = 0;
    int teamb_score = 0;
    int teama_shots_on_goal = 0;
    int teamb_shots_on_goal = 0;
    int teama_shots_off_goal = 0;
    int teamb_shots_off_goal = 0;
    int teama_blocked_shots = 0;
    int teamb_blocked_shots = 0;
    int teama_fouls = 0;
    int teamb_fouls = 0;
    int teama_yellow_cards = 0;
    int teamb_yellow_cards = 0;
    int teama_red_cards = 0;
    int teamb_red_cards = 0;
    
    // step2. set seed for randomization
    srand(static_cast<unsigned int>(time(0)));

    // step3. randomly generate total number of events in match from 1 to 20 and determine how many in each half
    num_events = (rand() % MAX_NUM_OF_EVENTS) + 1;
    first_half_events = num_events/2;
    second_half_events = num_events - first_half_events;
    
    // step4. output welcome message
    cout << "Welcome to the soccer match simulation, where Team A and Team B will be playing each other for the Cup\n" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    
    // step5. execute first half of match
    execute_half(first_half_events, teama_score, teamb_score, teama_shots_on_goal, teamb_shots_on_goal, teama_shots_off_goal, teamb_shots_off_goal, teama_blocked_shots, teamb_blocked_shots, teama_fouls, teamb_fouls, teama_yellow_cards, teamb_yellow_cards, teama_red_cards, teamb_red_cards);
    
    // step6. output stats of first half
    cout << "End of first half stats:" << endl;
    output_stats(teama_score, teamb_score, teama_shots_on_goal, teamb_shots_on_goal, teama_shots_off_goal, teamb_shots_off_goal, teama_blocked_shots, teamb_blocked_shots, teama_fouls, teamb_fouls, teama_yellow_cards, teamb_yellow_cards, teama_red_cards, teamb_red_cards);
    
    // step7. execute second half of match
    execute_half(second_half_events, teama_score, teamb_score, teama_shots_on_goal, teamb_shots_on_goal, teama_shots_off_goal, teamb_shots_off_goal, teama_blocked_shots, teamb_blocked_shots, teama_fouls, teamb_fouls, teama_yellow_cards, teamb_yellow_cards, teama_red_cards, teamb_red_cards);
    
    // step8. output end of game stats
    cout << "End of game stats:" << endl;
    output_stats(teama_score, teamb_score, teama_shots_on_goal, teamb_shots_on_goal, teama_shots_off_goal, teamb_shots_off_goal, teama_blocked_shots, teamb_blocked_shots, teama_fouls, teamb_fouls, teama_yellow_cards, teamb_yellow_cards, teama_red_cards, teamb_red_cards);
    
    // step9. determine and output team that won match
    if (teama_score > teamb_score) {
        cout << "\nTEAM A WINS THE SOCCER MATCH" << endl;
    }
    else if (teamb_score > teama_score) {
        cout << "\nTEAM B WINS THE SOCCER MATCH" << endl;
    }
    else {
        cout << "\nIT'S A TIE" << endl;
    }
}

int main() {
    execute_soccer_simulation();
}
