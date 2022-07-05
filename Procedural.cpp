
/*

Academic Integrity Checklist
1. I understand that I am responsible for being honest and ethical in this assessment as per Policy
2. The assessment was completed by my own efforts and I did not collaborate with any other
person for ideas or answers.
3. This is the first time I have submitted this assessment (either partially or entirely) for academic
evaluation.

Student Name: Ismail Hussein    Student ID: 6536177

Ismail Hussein (by typing my name here I affirm my agreement to the foregoing statements)

*/

#include <iostream>
#include <string>

using namespace std;

void Menu() { //function to display the Menu

    cout << endl << "Welcome my friend, to DesertLand Resort!"
        << endl << "Press 'h' to see rules of card game..."
        << endl << "Press 's' to play simple card game...."
        << endl << "Press 'q' to quit"
        << endl << "Input your choice" << endl;

}

void Rules(char letter) { // Rules function

    try
    {
        switch (letter) {
        case 'h': // h to show the rules
            cout << endl << "-) The rules of the game:"
                << endl << "1) The player will play a card game with the computer (banker) for a total of five (5) rounds"
                << endl << "2) The player will start with $500 credit points and each round, the bet is fixed at $10 points"
                << endl << "3) The player will win if his hand has a value higher than the banker and he wins $10 points,"
                << endl << "otherwise he loses the same amount to banker"
                << endl << "(REMINDER) The Ace is the lowest card which is equal to 1"
                << endl << "(REMINDER) The King is the highest card which is equal to 13"
                << endl << "(REMINDER) If the banker has the same number like the player, the banker wins" << endl;
            break;

        case 's': // empty case because a function for case s has been made seperatly

            break;

        case 'q': // to leave the game
            throw 20; // an integer will be thrown and later be catched to show an exception
            break;

        default:
            throw 20.0; // a double will be thrown and later be catched to show an exception
            break;


        }
    }
    catch (int e) // to catch the integer that was thrown and display message
    {
        cout << "Left game" << endl;

    }
    catch (double x) // to catch the double that was thrown and display message
    {
        cout << "Please make the letter lower case or choose a valid letter and try again" << endl;
    }

}

void StartGame(char letter, int* round, int* credits) { // function to start the game

    try
    {

        if (letter == 's') {

            *round = *round + 1; // incrementing rounds
            cout << endl << "Game round number: " << *round;

            cout << endl << "Starting game, Shuffling and dealing cards" << endl;

            int Banker = rand() % 13 + 1; // generating random numbers
            int Player = rand() % 13 + 1; // generating random numbers

            if (Banker >= Player)
            {

                cout << "Player hand holds: " << Player << endl;
                cout << "Banker hand holds: " << Banker << endl;
                cout << "Banker wins!" << endl;
                *credits = *credits - 10; // decrementing credits
                cout << "Player credits: " << *credits << endl;

            }

            if (Player > Banker)
            {

                cout << "Player hand holds: " << Player << endl;
                cout << "Banker hand holds: " << Banker << endl;
                cout << "Player wins!" << endl;
                *credits = *credits + 10; // incrementing credits
                cout << "Player credits: " << *credits << endl;

            }
        }
    }
    catch (int e) // to catch the integer that was thrown and display message
    {
        cout << "Left game" << endl;
    }
    catch (double x) // to catch the double that was thrown and display message
    {
        cout << "Please make the letter lower case or choose a valid letter and try again" << endl;
    }
}

void PrintOption() // function to print a message
{
    cout << endl << "Select 'q' if you do not wish to continue" << endl
        << "Select 's' to play the game" << endl;
}

char Rounds(char letter, int* round, int* credits) {// function to make the user enter more letters

    switch (letter) {

    case 'q':
        throw 20;
        break;

    case 's':
        StartGame(letter, round, credits);
        break;

    default:
        throw 20.0;
        break;
    }

}

int main()
{

    try
    {
        srand((unsigned)time(0));//function that seeds the random number generator used by the rand()

        Menu(); //calling Menu function

        char letter;
        cin >> letter; //inputing first letter

        Rules(letter); //Putting the letter inputted into the Rules function

        int round = 0;
        int credits = 500; 

        StartGame(letter, &round, &credits); //Adding the letter,round, and credits in StartGame function

        if (letter != 'q' && letter == 'h' || letter == 's') { //if the user entered any letter but not q the code below will run

            PrintOption();                                     

            char letter1; 
            cin >> letter1; //inputing second letter

            Rounds(letter1, &round, &credits); //Calling the round function to make the user choose an option

            /////////////////////////////////////////////////

            PrintOption();

            char letter2;
            cin >> letter2; //inputing third letter

            Rounds(letter2, &round, &credits); //Calling the round function to make the user choose an option

            /////////////////////////////////////////////////

            PrintOption();

            char letter3;
            cin >> letter3; //inputing fourth letter

            Rounds(letter3, &round, &credits); //Calling the round function to make the user choose an option

            /////////////////////////////////////////////////

            PrintOption();

            char letter4;
            cin >> letter4; //inputing fifth letter

            Rounds(letter4, &round, &credits); //Calling the round function to make the user choose an option

            /////////////////////////////////////////////////

            if (letter == 'h') {

                PrintOption();

                char letter5;
                cin >> letter5; //if the user entered h at the beginning this will be the 5th letter

                Rounds(letter5, &round, &credits);//Calling the round function to make the user choose an option
            }
            else {
                cout << endl << "The game ended" << endl;
            }
        }
    }
    catch (int e) // to catch the integer that was thrown and display message
    {
        cout << "Left game" << endl;
    }
    catch (double x) // to catch the double that was thrown and display message
    {
        cout << endl << "Please make the letter lower case or choose a valid letter and try again" << endl;
    }


};