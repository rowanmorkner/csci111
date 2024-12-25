// Copyright Michael Larson
// Last modified: 18 Sep 2022

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;  //NOLINT

enum pick {
    rock,
    paper,
    scissors,
    quit,
    invalid
};

pick computerChoice();
pick playerChoice(char c);

int main() {
    int seed = 0;
    char choice = 0;
    int won = 0, lost = 0, draw = 0;
    pick computer = rock, player = rock;
    int round = 1;

    cerr << "Welcome to Chin Chan Pu!" << endl;
    cerr << "Please enter a non-zero number for static mode, or 0 for dynamic mode: " << endl;
    cin >> seed;

    if (seed == 0) {
        srand(time(0));
        cerr << "Entering dynamic mode!" << endl;
    } else {
        srand(seed);
        cerr << "Entering static mode!" << endl;
    }

    do {
        cerr << "Round " << round << endl;
        cerr << "Enter your choice (R for rock, P for paper, S for Scissors, or Q for quit): ";
        cin >> choice;

        player = playerChoice(choice);

        if (player < quit) {
            computer = computerChoice();
            switch (player - computer) {
                case -2:
                case 1:
                    cerr << "You win!\n" << endl;
                    won++;
                    break;
                case 2:
                case -1:
                    cerr << "Loser.\n" << endl;
                    lost++;
                    break;
                default:
                    cerr << "Draw.\n" << endl;
                    draw++;
            }
            round++;
        } else if (player == invalid) {
            cerr << "Invalid choice. Try again.\n" << endl;
        }
    } while (player != quit);

    round--;
    cerr << "\nThank you for playing" << endl;
    cout << "You suffered through " << round << " round(s)." << endl;
    cout << "Won: " << won << " Lost: " << lost << " Tied: " << draw << endl;
}

pick computerChoice() {
    pick selection;
    switch (rand() % 3) {
        case 0:
            selection = rock;
            break;
        case 1:
            selection = paper;
            break;
        case 2:
            selection = scissors;
            break;
        default:
            cerr << "Something went wrong with computer choice" << endl;
            exit(1);
    }
    return selection;
}

pick playerChoice(char c) {
    pick selection;

    switch (toupper(c)) {
        case 'R':
            selection = rock;
            break;
        case 'P':
            selection = paper;
            break;
        case 'S':
            selection = scissors;
            break;
        case 'Q':
            selection = quit;
            break;
        default:
            selection = invalid;
    }
    return selection;
}
