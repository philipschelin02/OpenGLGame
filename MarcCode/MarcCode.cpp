#include <stdio.h>
#include <iostream>

// comparison operators
// <, ==, <=, >, >=, !=
// arithmetic operators
// -, +, /, *, %
// assignment operator =
// compound assignment, +=, -=, &=, ...
// logical operators 
// &&, ||, !
// binary operators
// &, |, ~, ^, <<, >>
// member-of operator .
// member-of-pointer operator ->

using namespace std;

// Define a structure called "Euros" to represent a monetary value in Euros and cents
struct Euros {
    int euros;
    int cents;

    // Constructor to initialize Euros object with given values
    Euros(int euros, int cents) : euros{ euros }, cents{ cents } {}

    // Overload the subtraction operator "-" for Euros objects
    Euros operator-(const Euros& costs) const {
        Euros result = *this; // Create a copy of the current object
        result.euros -= costs.euros;
        result.cents -= costs.cents;

        // Normalize the cents to be positive
        while (result.euros > 0 && result.cents < 0) {
            result.euros--;
            result.cents += 100;
        }

        return result;
    }

    // Overload the compound subtraction assignment operator "-=" for Euros objects
    Euros& operator-=(const Euros& costs) {
        euros -= costs.euros;
        cents -= costs.cents;

        // Normalize the cents to be positive
        while (euros > 0 && cents < 0) {
            euros--;
            cents += 100;
        }

        return *this;
    }

    // Friend function to overload the multiplication operator "*" for Euros and integer
    friend Euros operator*(Euros money, int k);
};

// Overload the output stream operator "<<" to print Euros objects
ostream& operator<<(ostream& os, const Euros& s) {
    return (os << "Euros: " << s.euros << " Cents: " << s.cents);
}

// Friend function to overload the multiplication operator "*" for Euros and integer
static Euros operator*(Euros money, int k) {
    return Euros{
        money.euros * k,
        money.cents * k
    };
}

// Friend function to overload the multiplication operator "*" for integer and Euros
static Euros operator*(int k, const Euros& money) {
    return money * k;
}

// Define a structure called "Dollars" to represent a monetary value in Dollars and cents (not used in this code)
struct Dollars {
    int dollars;
    int cents;
};

int main() {
    // Create Euros objects
    Euros money{ 1, 22 };
    Euros costs{ 0, 99 };

    // Subtract costs from money using overloaded operator
    money -= costs;

    // Print the costs and remaining money
    cout << "These are the costs: " << costs << "\n";
    cout << "This is how much money I have: " << money;
}
