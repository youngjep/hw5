#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please

#endif

#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here

bool scheduleHelper(const AvailabilityMatrix& avail, const size_t dailyNeed, const size_t maxShifts, DailySchedule& sched, std::map<Worker_T, int>& shifts, size_t row, size_t col);

// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below

    std::map<Worker_T, int> shifts;

    sched.resize(avail.size());

    return scheduleHelper(avail, dailyNeed, maxShifts, sched, shifts, 0, 0);

}
/*
 It is likely easiest to recurse over each place in the schedule 
 (i.e. the 2D sched matrix). Each recursive call would be responsible for filling in one of the n*d schedule openings, 
 ensuring the constraints of availability and the maximum number of shifts allowed for each worker is met.
*/
bool scheduleHelper(const AvailabilityMatrix& avail, const size_t dailyNeed, const size_t maxShifts, DailySchedule& sched, std::map<Worker_T, int>& shifts, size_t row, size_t col) 
{
    if (row == avail.size())  
    {
        return true;
    }
   

    if (col == avail[0].size()) 
    {
        if (sched[row].size() == dailyNeed) 
        {
            return scheduleHelper(avail, dailyNeed, maxShifts, sched, shifts, row + 1, 0); 
        }
        // meaning if there's only dailyneeded amount and reached end of column
        else return false; //otherwise this is false
    }


    if (avail[row][col]) 
    {
        if (shifts[col] < maxShifts) 
        {
            shifts[col]++;
            sched[row].push_back(col);

            bool status = scheduleHelper(avail, dailyNeed, maxShifts, sched, shifts, row, col + 1);
            
            if (!status) 
            {
                sched[row].pop_back();
                shifts[col]--;
            }
            else return true;

        }
        
    } 

    return scheduleHelper(avail, dailyNeed, maxShifts, sched, shifts, row, col + 1); 
  
}