#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define HOURS_IN_DAY 24
#define HOURS_IN_YEAR 365 * HOURS_IN_DAY
#define NUMBER_OF_PLANTS 25



class PowerPlant
{
    public:

        int id_number;
        string plant_name;
        double capacity;
        double variable_cost;
    
};

typedef double DEMAND_T, CAPACITY;

//double demand[HOURS_IN_DAY];

//double cumulative_capacity[NUMBER_OF_PLANTS];


// fill in test values
#include "test_header.h"

int marginal_id[sizeof(demand) / sizeof(double)] = {};

int main(int argc, char *argv[])
{
    int current_index = 0;

    // start on index 0 for both demand and plant arrays 

    // Loop through each element i of the demand array

    // if demand_array[i] >= plant_cum_capacity[j]
    //      marginal_id = i


    for(int i = 0; i < (sizeof(demand) / sizeof(DEMAND_T)); i++)
    {
        static bool is_going_up = true;
        static int looking_index = 0;

        // check if we're going up
        if (is_going_up)
        {
            // if so, check if the current demand is greater than current 
            // cummulative capacity
            if (demand[i] > cumulative_capacity[looking_index])
            {
                // if so, switch to going down
                is_going_up = false;
            }
            while (demand[i] > cumulative_capacity[looking_index])
            {
                // keep incrementing the capacity index until 
                // it is greater than demand
                looking_index++;
            }
            // once capacity index is greater than demand, return that index
            marginal_id[i] = looking_index;
        }
        else
        {
            if (demand[i] < cumulative_capacity[looking_index])
            {
                is_going_up = true;
            }
            while (demand[i] < cumulative_capacity[looking_index])
            {
                looking_index--;
            }
            marginal_id[i] = looking_index + 1;
        }
    }

    // print output to test

    cout << "Marginal plants per hour:\n";
    for (int i = 0; i < HOURS_IN_DAY; i++)
    {
        cout << "Hour " << i << ": " << marginal_id[i] << endl;
    }

    return 0;
}



















