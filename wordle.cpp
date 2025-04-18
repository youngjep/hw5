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
void wordleHelper(int index, std::string& current, std::set<std::string>& output, std::string floating, int remainingBlankSpace, const std::set<std::string>& dict);

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in, // input ex) -i--
    const std::string& floating, // needs to have: dn
    const std::set<std::string>& dict)
{
    std::set<std::string> output;

    std::string current = in;

    //std::cout << current << std::endl;
    
    int remainingBlankSpace = 0;
    for (int i = 0; i < in.size(); i++) 
    {
        if (in[i] == '-') 
        {
            remainingBlankSpace++;
        }
    }

    wordleHelper(0, current, output, floating, remainingBlankSpace, dict);
    
    return output;

}

// Define any helper functions here

void wordleHelper(int index, std::string& current, std::set<std::string>& output, std::string floating, int remainingBlankSpace, const std::set<std::string>& dict) 
{
    if (index == current.size() || remainingBlankSpace == 0) 
    {
        if (floating.empty() && dict.find(current) != dict.end()) 
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
        wordleHelper(index + 1, current, output, floating, remainingBlankSpace, dict); 
        return;
    }
    

    if (remainingBlankSpace == floating.size())
    {
        for (int i = 0; i < floating.size(); i++)  
        {
            char ch = floating[i];
            current[index] = ch;
            std::string tempFloating = floating;
            tempFloating.erase(tempFloating.find(ch), 1);
            wordleHelper(index + 1, current, output, tempFloating, remainingBlankSpace - 1, dict);
            current[index] = '-';
        }
    }
    else  
    {

        for (int i = 0; i < 26; i++)
        {
            size_t foundPos = floating.find(i + 'a');
            string tempFloating = floating;
    
            if (foundPos != std::string::npos) 
            {
                tempFloating.erase(foundPos, 1);
            }
    
            current[index] = i + 'a';
    
            wordleHelper(index + 1, current, output, tempFloating, remainingBlankSpace - 1, dict);
    
            current[index] = '-';
        }
    }
}


/*

-i-- dn

aiaa
aiba
biaa
bias

// need to know maximum letters

*/