#include <iostream>
#include <set>
#include <vector>
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

/**********************************
 *     SELECT A RANDOM WORD      *
 **********************************/
string randomWord() {
        vector<string> words = {
        "apple", "banana", "cherry", "dragonfruit", "elderberry",
        "fig", "grape", "honeydew", "iceberg", "jackfruit",
        "kiwi", "lemon", "mango", "nectarine", "orange",
        "papaya", "quince", "raspberry", "strawberry", "tangerine",
        "ugli", "vanilla", "watermelon", "xigua", "yam",
        "zucchini", "pear", "plum", "coconut", "blueberry"
    };

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);

    uniform_int_distribution<int> distribution(0, words.size() - 1);

    int randomIndex = distribution(generator);

    string randomElement = words[randomIndex];

    //cout << "Vector elements: ";
    //for (string element : words) {
    //    cout << element << " ";
    //}
//
    //cout << endl;

    return randomElement;
};

void display() 
{
    string word = randomWord();
    vector<vector<string>> hangmanStages = {
        {
            "  _____    ",
            " |     |   ",
            "       |   ",
            "       |   ",
            "       |   ",
            "    ___|___",
            " "
        },
        {
            "  _____    ",
            " |     |   ",
            " O     |   ",
            "       |   ",
            "       |   ",
            "    ___|___",
            " "
        },
        {
            "  _____    ",
            " |     |   ",
            " O     |   ",
            " |     |   ",
            "       |   ",
            "    ___|___",
            " "
        },
        {
            "  _____    ",
            " |     |   ",
            " O     |   ",
            "/|     |   ",
            "       |   ",
            "    ___|___",
            " "
        },
        {
            "  _____    ",
            " |     |   ",
            " O     |   ",
            "/|\\    |   ",
            "       |   ",
            "    ___|___",
            " "
        },
        {
            "  _____    ",
            " |     |   ",
            " O     |   ",
            "/|\\    |   ",
            "/      |   ",
            "    ___|___",
            " "
        },
        {
            "  _____    ",
            " |     |   ",
            " O     |   ",
            "/|\\    |   ",
            "/ \\    |   ",
            "    ___|___",
            " "
        }
    };

    vector<char> hidden;
    vector<char> wrong;

    for (int i = 0; i < word.size(); i++) 
    {
        hidden.push_back('_');
    }


    
    bool done = false;
    while (done != true)
    {
        //for (int i = 0; i <= 100; ++i) {
        //    // Clear the screen and move cursor to top-left (1;1)
        //    // \033[2J clears the entire screen
        //    // \033[1;1H moves the cursor to row 1, column 1
        //    std::cout << "\033[2J\033[1;1H";
        //}
        int stage = wrong.size();
        if (stage >= hangmanStages.size())
            stage = hangmanStages.size() - 1; // prevent overflow if too many wrong guesses

        for (const string &line : hangmanStages[stage]) {
            cout << line << endl;
        }

        for (char letter : hidden)
        {
            cout << letter << " ";
        }

        cout << endl;
        cout << " " << endl;

        char userInput;

        // User guesses a letter
        cout << "Select a letter: " << endl;
        cin >> userInput;

        // Convert userInput to lowercase letters
        char lowerInput = tolower(userInput);

        // Add correct letters to the hidden vector
        // Put incorrect letters in wrong list
        if (lowerInput >= 'a' && lowerInput <= 'z')
        {
            bool found = false;
            for (int i = 0; i < word.size(); i++) 
            {
                if (word[i] == lowerInput)
                {
                    hidden[i] = lowerInput;
                    found = true;
                }

            }
            if (!found) {
                wrong.push_back(lowerInput);

            }
        }
        else if (!(lowerInput >= 'A' && lowerInput <= 'Z'))
        {
            cout << "Please select a valid letter (A-Z)." << endl;
        }

        // Win condition
        if (!(find(hidden.begin(), hidden.end(), '_') != hidden.end()))
        {
            for (const string &line : hangmanStages[wrong.size()]) 
            {
                cout << line << endl;
            }

            for (char letter : hidden)
            {
                cout << letter << " ";
            }
            cout << endl;
            cout << "Congratulations, you guessed " << word << "!" << endl;
            cout << "Would you like to play again? y/n" << endl;
            done = true;
        }
        // Lose condition
        else if (wrong.size() >= 6)
        {
            // Show final hangman stage again
            for (const string &line : hangmanStages.back()) 
            {
                cout << line << endl;
            }
            cout << "Sorry, you lose." << endl;
            cout << "Would you like to play again? y/n" << endl;
            done = true;
        }
    }
}

int main() 
{
    char playAgain = 'y';  // start by assuming the player wants to play

    while (tolower(playAgain) == 'y')
    {
        display();

        cout << "Play again? (y/n): ";
        cin >> playAgain;

        // clear the console a bit for readability
        cout << "\n--------------------------------------\n\n";
    }

    cout << "Thanks for playing!\n";

    return 0;
};