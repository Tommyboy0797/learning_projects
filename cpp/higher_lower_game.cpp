#include <iostream> //  is a header file library that lets us work with input and output objects, such as cout. These header things add stuff
using namespace std; // means i dont need to do stuff like std::cout << "hello" and just cout << "hello"

int main() { // always needs a main method

    int selected_number = 10; // number that it will be searching for, wasnt sure how to do random number.
    bool number_found = false; // loop condition
    int user_guess = 0; // variable for user guess

    while (number_found == false) { // while loop, ends when number found is true
        cout << "Enter number guess: ";
        cin >> user_guess; // take in the user guess and set it as user_guess
        if (user_guess > selected_number){ // if its greater:
            cout << "Guess is greater than number I am thinking of \n";
        } else if (user_guess < selected_number) { // if its less than:
            cout << "Guess is lower than the number I am thinking of \n";
        } else { // if its equal:
            cout << "You found the number! it was " << selected_number;
            number_found = true; // break the loop
        } 
    }

    return 0;
}