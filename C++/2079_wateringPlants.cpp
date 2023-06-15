/**
You want to water n plants in your garden with a watering can. The plants are arranged in a row and are labeled from 0 to n - 1 from left to right where the ith plant is located at x = i. There is a river at x = -1 that you can refill your watering can at.

Each plant needs a specific amount of water. You will water the plants in the following way:

Water the plants in order from left to right.
After watering the current plant, if you do not have enough water to completely water the next plant, return to the river to fully refill the watering can.
You cannot refill the watering can early.
You are initially at the river (i.e., x = -1). It takes one step to move one unit on the x-axis.

Given a 0-indexed integer array plants of n integers, where plants[i] is the amount of water the ith plant needs, and an integer capacity representing the watering can capacity, return the number of steps needed to water all the plants.



Example 1:

Input: plants = [2,2,3,3], capacity = 5
Output: 14
Explanation: Start at the river with a full watering can:
- Walk to plant 0 (1 step) and water it. Watering can has 3 units of water.
- Walk to plant 1 (1 step) and water it. Watering can has 1 unit of water.
- Since you cannot completely water plant 2, walk back to the river to refill (2 steps).
- Walk to plant 2 (3 steps) and water it. Watering can has 2 units of water.
- Since you cannot completely water plant 3, walk back to the river to refill (3 steps).
- Walk to plant 3 (4 steps) and water it.
Steps needed = 1 + 1 + 2 + 3 + 3 + 4 = 14.
 */

// Perf 79% Mem 70%

class Solution {
public:
    int wateringPlants(const vector<int>& plants, int capacity) {

        // no steps if no plants
        if (plants.size() == 0)
        {
            return 0;
        }

        int steps = 0;
        int nextindex = 0;
        int currentcapacity = capacity;

        for (int i = 0; i < plants.size(); i++) // Go through each plant
        {
            if (currentcapacity - plants[i] >= 0) // If you can water the current plant, water it and move to the next one.
            {
                currentcapacity -= plants[i];
                steps++;
            }
            else // If you can't water the current plant, go to water + come back + water the plant + go to the next plant
            {
                currentcapacity = capacity - plants[i];
                steps += 2 * i + 1;
            }

        }

        return steps;
    }
};

