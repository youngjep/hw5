#ifndef WORDLE_H
#define WORDLE_H

#ifndef RECCHECK
#include <set>
#include <string>
#include <string>
#endif

/**
 * @brief Returns the list of all legal words in the provided dictionary
 *        that meet the criteria provided in the `in` and `floating`
 *        inputs.
 * 
 * @param [in] in - string of fixed, correct characters and `-`s to indicate
 *                  the length of string and locations that must be filled in
 * @param [in] floating  - Characters that must be used somewhere in the word
 * @param [in] dict - Dictionary of strings of legal words
 * @return std::set<std::string> - Set of all words that meet the criteria
 */
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict);

#endif

/*
In this program, you will write a tool to aide players of a Wordle-like game (it does not have the exact semantics of Wordle, but is similar). 
Suppose the user would like to know what English-language words exist that meet certain criteria (so they can think of potential guesses). 

INPUT
1.
The user will provide you an input of how many letters the word is, what letters have already been guessed in their correct location (akin to the green letters), 
2.
and a list of letters that they know MUST appear in the word (akin to the yellow letters, but without indicating where those letters CANNOT be). 

They will NOT provide the list of gray letters, meaning you will need to try all possible letters when trying to fill in a blank location in the word.

TASK
So your task will be to write a function (and any desired helper functions), to compute all possible English-language words that exist 

GIVEN
1. given a string containing the already-guessed letters that are in the correct location (we will refer to these as fixed letters since they may not change position 
and must stay in that location) 
2. and a string of the already-guessed letters that are MUST appear in the word somewhere 
(we will refer to these as floating letters since their position may be in any of the remaining locations). 

CLARIFICATION
Again, we are not actually writing code to play the game but code that can help players consider potential future guesses 
given some of the knowledge they’ve learned from previous guesses.

APPROACH
Your approach should be to generate all possible strings of **lower-case**, alpha characters that contain the fixed characters (in their given location), 
floating characters (in any locations), and fill in any remaining letters with all possible options and then check if any of those strings 
are true English-language words. We will provide a std::set<std::string> of all possible English-language words (i.e. essentially a dictionary) 
that you may use for this task (which we read from a provided file: dict-eng.txt).
 
*/