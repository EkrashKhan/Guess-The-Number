#include <iostream>
#include <climits>
#include <limits>  // for numeric_limits
#include <ctime>   // for time()
using namespace std;

int minValue, maxValue;

// general input function
void inputInt(string prompt, int &var) {
    while (true) {
        cout << prompt;
        cin >> var;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
            cout << "Invalid input. Please enter an integer.\n";
        } else {
            break;
        }
    }
}

int main() {
    srand(time(0)); // seed random once

    char c;
    int attemptLimit, secret, guess, attemptsUsed;
    int bestScore = INT_MAX;
    bool playAgain;  

    do {
        // get valid range
        inputInt("Enter Minimum Value range: ", minValue);
        inputInt("Enter Maximum Value range: ", maxValue);
        while (minValue >= maxValue) {
            cout << "Minimum must be less than Maximum.\n";
            inputInt("Enter Minimum Value range: ", minValue);
            inputInt("Enter Maximum Value range: ", maxValue);
        }

        // get attempts
        inputInt("Enter attempt limit: ", attemptLimit);

        // generate secret
        secret = minValue + rand() % (maxValue - minValue + 1);
        attemptsUsed = 0;

        // guessing loop
        while (attemptLimit > 0) {
            inputInt("Enter your guess: ", guess);
            attemptsUsed++;

            if (guess == secret) {
                cout << "Congratulations, You won!\n";
                cout << "Attempts used: " << attemptsUsed << endl;

                if (attemptsUsed < bestScore) bestScore = attemptsUsed;
                cout << "Best Score so far: " 
                     << (bestScore == INT_MAX ? -1 : bestScore) << endl;
                break;
            }
            else if (guess < secret) {
                cout << "Too Low...\n";
            } else {
                cout << "Too High...\n";
            }

            cout << "Remaining attempts: " << --attemptLimit << endl;
        }

        if (guess != secret) {
            cout << "Out of attempts! Secret was: " << secret << endl;
        }

        // replay option
        while (true) {
            cout << "Play again? (y/n): ";
            cin >> c;
            if (c == 'y' || c == 'Y') { 
                playAgain = true; 
                break;
             }
            else if (c == 'n' || c == 'N') {
                
                playAgain = false;
                 break; 
                }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice.\n";
            }
        }

    } while (playAgain);

    return 0;
}
