// Number Guessing Game - 3 Levels
// Level 1: 0 to 10
// Level 2: 0 to 50
// Level 3: 0 to 100

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));   // makes the random numbers different every time

    int level = 1;
    int maxNumber;
    int secretNumber;
    int guess;
    int numGuesses;
    bool gameOver = false;

    cout << "Welcome to the Number Guessing Game!" << endl;

    while (level <= 3 && gameOver == false)
    {
        // Set the range for each level
        if (level == 1)
        {
            maxNumber = 10;
        }
        else if (level == 2)
        {
            maxNumber = 50;
        }
        else
        {
            maxNumber = 100;
        }

        secretNumber = rand() % (maxNumber + 1);   // random number from 0 to maxNumber

        cout << endl;
        cout << "----- LEVEL " << level << " -----" << endl;
        cout << "I picked a number from 0 to " << maxNumber << "." << endl;
        cout << "How many guesses do you want? ";
        cin >> numGuesses;

        bool guessedRight = false;
        int count = 1;

        while (count <= numGuesses && guessedRight == false)
        {
            cout << "Guess " << count << ": ";
            cin >> guess;

            if (guess == secretNumber)
            {
                cout << "Correct! You got it!" << endl;
                guessedRight = true;
            }
            else if (guess < secretNumber)
            {
                cout << "Too low!" << endl;
            }
            else
            {
                cout << "Too high!" << endl;
            }

            count++;
        }

        if (guessedRight == true)
        {
            level++;   // move to the next level
        }
        else
        {
            cout << "You ran out of guesses. The number was " << secretNumber << "." << endl;
            gameOver = true;
        }
    }

    if (gameOver == false)
    {
        cout << endl << "You beat all 3 levels! You win!" << endl;
    }
    else
    {
        cout << "Game over! You reached level " << level << "." << endl;
    }

    return 0;
}
