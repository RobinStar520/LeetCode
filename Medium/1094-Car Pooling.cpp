// There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

// You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

// Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

 

// Example 1:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
// Output: false
// Example 2:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 5
// Output: true
 

// Constraints:

// 1 <= trips.length <= 1000
// trips[i].length == 3
// 1 <= numPassengersi <= 100
// 0 <= fromi < toi <= 1000
// 1 <= capacity <= 105

/*
Approach:
    Sort the "trips" vector and count the passengers each time.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        sort(trips.begin(), trips.end(), [&](vector<int>& v1, vector<int>& v2) -> bool {
            return v1[1] < v2[1];
        });

        const int n = trips.size();
        vector<int> passengerCount(1001, 0);
        
        for (const auto& v : trips)
        {
            for (int i = v[1]; i < v[2]; ++i)
            {
                passengerCount[i] += v[0];
                if (passengerCount[i] > capacity)
                {
                    return false;
                }
            }
        }

        return true;
    }
};