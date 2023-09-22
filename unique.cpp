/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Aya Salama
 * Date        : 09/20/2023
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;

bool is_all_lowercase(const string &s)
{
    // TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
    for (size_t i = 0; i < s.size(); i++)
    {
        // if character at position i is greater or less than ASCII
        // integer values for lowercasse alphabets, then it is not a valid letter
        if (s.at(i) < 97 || s.at(i) > 122)
            return false;
    }
    return true;
}

bool all_unique_letters(const string &s)
{
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.

    // You MUST use only single unsigned integers and work with bitwise
    // and bitshifting operators only.  Using any other kind of solution
    // will automatically result in a grade of ZERO for the whole assignment.
    unsigned int corresponding_bit = 0; // used to check for duplicate characters using bitwise operations
    for (size_t i = 0; i < s.size(); i++)
    {
        // by sifting 1 as many bits to the right by the difference from the character at position i
        // and 'a', we can use this to check if there is a duplicate letter by taking this with "and" of corresponding_bit.
        // this works because (1 << (s.at(i) - 'a')) will have a unique value for each letter.
        if ((corresponding_bit & (1 << (s.at(i) - 97))) > 0)
            return false;
        corresponding_bit |= (1 << (s.at(i) - 97)); // takes into account that a letter was found
    }
    return true;
}

int main(int argc, char *const argv[])
{
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.
    if (argc != 2)
    {
        cerr << "Usage: ./unique <string>";
        return 1;
    }
    if (!is_all_lowercase(argv[1]))
    {
        cerr << "Error: String must contain only lowercase letters.";
        return 1;
    }
    else if (all_unique_letters(argv[1]))
        cout << "All letters are unique.";
    else
        cout << "Duplicate letters found.";
    return 0;
}