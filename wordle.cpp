#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void wordleHelper(int index, std::string& current, std::set<std::string>& output, const std::string& floating, const std::set<std::string>& dict);

bool isValid(std::string, const std::string& floating, const std::set<std::string>& dict);

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in, // input ex) -i--
    const std::string& floating, // needs to have: dn
    const std::set<std::string>& dict)
{
    std::set<std::string> output;

    std::string current = in;

    std::cout << current << std::endl;
    /*
    for (int i = 0; i < in.size(); i++) 
    {
        if (currentStr[i] == '-') 
        {
            // then try somethingelse
            // 
        }
    }*/

    wordleHelper(0, current, output, floating, dict);
    
    return output;

}

// Define any helper functions here

void wordleHelper(int index, std::string& current, std::set<std::string>& output, const std::string& floating, const std::set<std::string>& dict) 
{
    if (index == current.size()) 
    {
        if (isValid(current, floating, dict)) 
        {
            output.insert(current);

        }
        return;
    }
    // if flaoting 

    // count how many blank space I have
    // blanck == floating
    // the possibility is just floating itself

    if (current[index] != '-') 
    {
        wordleHelper(index + 1, current, output, floating, dict); return;
    }

    for (int i = 0; i < 26; i++) 
    {
        current[index] = i + 'a';
        std::cout << "try " << static_cast<char>('a' + i) << " -> " << current << std::endl;

        wordleHelper(index + 1, current, output, floating, dict);

        current[index] = '-';
    }
}

bool isValid(std::string current, const std::string& floating, const std::set<std::string>& dict) //X
{
    if (dict.find(current) != dict.end()) 
    {
        bool found = true;

        for (int i = 0; i < floating.size(); i++) 
        {
            size_t foundPos = current.find(floating[i]);
            if (foundPos == std::string::npos) 
            {
                found = false;
            }
            else 
            {
                current[foundPos] = '-'; // mark them - if discovered cuz we want to see overlaps
            }
        }

        return found;
    }
    else return false;
}


/*

-i-- dn

aiaa
aiba
biaa
bias

// need to know maximum letters

*/