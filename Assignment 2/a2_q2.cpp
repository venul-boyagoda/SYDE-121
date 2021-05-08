//****************************************************************************
// Student Name: Venul Boyagoda
// Student Number:20909488
//
// SYDE 121 Assignment: 2
// Filename: a2_q2
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Baseball Dropped from Drone
// Purpose: Create table for distance ball has travelled each second for 30 seconds,
// then determine time for ball 15000 high to drop and reach the ground
// Due Date: Friday, October 9, 2020
//**************************************************************

/*
 Output for step 2:
 Time (in sec):   Distance during interval (in m):   Total Distance (in m):
 0                 0.000                                   0.000
 1                 4.903                                   4.903
 2                 14.710                                   19.613
 3                 24.517                                   44.130
 4                 34.323                                   78.453
 5                 44.130                                   122.583
 6                 53.937                                   176.520
 7                 63.743                                   240.263
 8                 73.550                                   313.813
 9                 83.357                                   397.169
 10                 93.163                                   490.332
 11                 102.970                                   593.302
 12                 112.776                                   706.079
 13                 122.583                                   828.662
 14                 132.390                                   961.052
 15                 142.196                                   1103.248
 16                 152.003                                   1255.251
 17                 161.810                                   1417.061
 18                 171.616                                   1588.677
 19                 181.423                                   1770.100
 20                 191.230                                   1961.330
 21                 201.036                                   2162.366
 22                 210.843                                   2373.209
 23                 220.650                                   2593.859
 24                 230.456                                   2824.315
 25                 240.263                                   3064.578
 26                 250.070                                   3314.648
 27                 259.876                                   3574.524
 28                 269.683                                   3844.207
 29                 279.490                                   4123.696
 30                 289.296                                   4412.992
 31                 299.103                                   4712.095
 32                 308.909                                   5021.005
 33                 318.716                                   5339.721
 34                 328.523                                   5668.244
 35                 338.329                                   6006.573
 36                 348.136                                   6354.709
 37                 357.943                                   6712.652
 38                 367.749                                   7080.401
 39                 377.556                                   7457.957
 40                 387.363                                   7845.320
 41                 397.169                                   8242.489
 42                 406.976                                   8649.465
 43                 416.783                                   9066.248
 44                 426.589                                   9492.837
 45                 436.396                                   9929.233
 46                 446.203                                   10375.436
 47                 456.009                                   10831.445
 48                 465.816                                   11297.261
 49                 475.623                                   11772.883
 50                 485.429                                   12258.312
 51                 495.236                                   12753.548
 52                 505.042                                   13258.591
 53                 514.849                                   13773.440
 54                 524.656                                   14298.096
 54.31               5.325                                 14462.502
 54.32               5.326                                 14467.828
 54.33               5.327                                 14473.156
 54.34               5.328                                 14478.484
 54.35               5.329                                 14483.813
 54.36               5.330                                 14489.144
 54.37               5.331                                 14494.475
 54.38               5.332                                 14499.807
 54.39               5.333                                 14505.141
 54.40               5.334                                 14510.475
 54.41               5.335                                 14515.810
 54.42               5.336                                 14521.146
 54.43               5.337                                 14526.484
 54.44               5.338                                 14531.822
 54.45               5.339                                 14537.161
 54.46               5.340                                 14542.501
 54.47               5.341                                 14547.842
 54.48               5.342                                 14553.185
 54.49               5.343                                 14558.528
 54.50               5.344                                 14563.872
 54.51               5.345                                 14569.217
 54.52               5.346                                 14574.563
 54.53               5.347                                 14579.910
 54.54               5.348                                 14585.258
 54.55               5.349                                 14590.607
 54.56               5.350                                 14595.957
 54.57               5.351                                 14601.308
 54.58               5.352                                 14606.660
 54.59               5.353                                 14612.013
 54.60               5.354                                 14617.367
 54.61               5.355                                 14622.722
 54.62               5.356                                 14628.077
 54.63               5.357                                 14633.434
 54.64               5.358                                 14638.792
 54.65               5.359                                 14644.151
 54.66               5.360                                 14649.511
 54.67               5.361                                 14654.871
 54.68               5.362                                 14660.233
 54.69               5.363                                 14665.596
 54.70               5.364                                 14670.960
 54.71               5.365                                 14676.324
 54.72               5.366                                 14681.690
 54.73               5.367                                 14687.057
 54.74               5.368                                 14692.424
 54.75               5.369                                 14697.793
 54.76               5.370                                 14703.162
 54.77               5.371                                 14708.533
 54.78               5.372                                 14713.904
 54.79               5.373                                 14719.277
 54.80               5.374                                 14724.651
 54.81               5.374                                 14730.025
 54.82               5.375                                 14735.401
 54.83               5.376                                 14740.777
 54.84               5.377                                 14746.154
 54.85               5.378                                 14751.533
 54.86               5.379                                 14756.912
 54.87               5.380                                 14762.293
 54.88               5.381                                 14767.674
 54.89               5.382                                 14773.056
 54.90               5.383                                 14778.440
 54.91               5.384                                 14783.824
 54.92               5.385                                 14789.209
 54.93               5.386                                 14794.595
 54.94               5.387                                 14799.983
 54.95               5.388                                 14805.371
 54.96               5.389                                 14810.760
 54.97               5.390                                 14816.150
 54.98               5.391                                 14821.541
 54.99               5.392                                 14826.934
 55.00               5.393                                 14832.327
 55.01               5.394                                 14837.721
 55.02               5.395                                 14843.116
 55.03               5.396                                 14848.512
 55.04               5.397                                 14853.909
 55.05               5.398                                 14859.307
 55.06               5.399                                 14864.706
 55.07               5.400                                 14870.106
 55.08               5.401                                 14875.507
 55.09               5.402                                 14880.909
 55.10               5.403                                 14886.312
 55.11               5.404                                 14891.716
 55.12               5.405                                 14897.121
 55.13               5.406                                 14902.527
 55.14               5.407                                 14907.933
 55.15               5.408                                 14913.341
 55.16               5.409                                 14918.750
 55.17               5.410                                 14924.160
 55.18               5.411                                 14929.571
 55.19               5.412                                 14934.982
 55.20               5.413                                 14940.395
 55.21               5.414                                 14945.809
 55.22               5.415                                 14951.224
 55.23               5.416                                 14956.639
 55.24               5.417                                 14962.056
 55.25               5.418                                 14967.474
 55.26               5.419                                 14972.892
 55.27               5.420                                 14978.312
 55.28               5.421                                 14983.732
 55.29               5.422                                 14989.154
 55.30               5.423                                 14994.576
 55.31               5.424                                 15000.000
 HIT GROUND          HIT GROUND                            HIT GROUND
 
 Tested values 0, 30, 100, 5000, 9876, 546789 for part 1 as time to fall
 even though assignment only specified 30, to be sure the program works.
 Used online calculator and determined that distance in the end and interval distances
 were correct for all values.
 
 Tested values 107, 300, 4567, 15000, 104567 for part 2 as height of the ball
 even though assignment only specified 15000, to be sure program works.
 Used online calculator and determined that time, distance in the end and interval distances
 were correct for all values.
 
 Since part 1 uses int for time, range of values would be from 0 to 2147483647 which is the greatest
 value int can hold.
 
 For part two, since the distance is a double, range of values would be from 0 to 2^64-1 which is the
 greatest value double can hold.
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void display_distance_fallen();
// Purpose: Calculates and outputs table for distance travelled in 30 seconds
//      INPUTS: nothing
//      OUTPUTS: nothing

void time_to_fall_15000();
// Purpose: Calculate and outputs second table for time passed until 15000m high ball hits ground
//      INPUTS: nothing
//      OUTPUTS: nothing

void execute_a2_q2();
// Purpose: Runs the steps of the program

void display_distance_fallen ()
{
    // [setup] declare and initialize variables
    double interval_distance = 0;
    double total_distance = 0;
    int time_passed = 0;
    int time_to_fall = 30;
    const int RESOLUTION = 1;
    const double GRAVITY = 9.80665;
    
    // step1. output beginning titles of table
    cout << "Time (in sec):   " << "Distance during interval (in m):   " << "Total Distance (in m):" << endl;
    
    // step2.1 loop through each second until 30 and cacluate interval distance and total distance
    for (time_passed = 0; time_passed <= time_to_fall; time_passed += RESOLUTION)
    {
        total_distance = (GRAVITY * pow(time_passed, 2)) / 2;
        if (time_passed == 0)
            interval_distance = 0;
        else
            interval_distance = total_distance - (GRAVITY * pow((time_passed - 1) , 2)) / 2;
        
        // step2.2 output time passed with no decimals and distances to 3 decimal places in table
        cout << fixed << setprecision(0) << time_passed << "                 ";
        cout << fixed << setprecision(3) << interval_distance << "                                   "
        << total_distance << endl;
    }
    
}

void time_to_fall_15000()
{
    // [setup] declare and initialize variables
    double total_distance = 15000;
    double time_passed = 0;
    double interval_distance = 0;
    double time_to_fall = 0;
    const double GRAVITY = 9.80665;
    const int RESOLUTION1 = 1;
    const double RESOLUTION2 = 0.01;
    
    // step1. output 2nd table titles
    cout << "\n\nPART2" << endl;
    cout << "Time (in sec):   " << "Distance during interval (in m):   " << "Total Distance (in m):" << endl;
    
    // step2.1 calculate time for ball to hit ground using total distance ball will fall
    time_to_fall = sqrt(2 * total_distance / GRAVITY);
    
    // step2.2 similar to first table, loop through each second until 1 second before ball hits ground and calculate
    // interval and total distances
    for (time_passed = 0; time_passed <= (time_to_fall - 1); time_passed += RESOLUTION1)
    {
        total_distance = (GRAVITY * pow(time_passed, 2)) / 2;
        if (time_passed == 0)
            interval_distance = 0;
        else
            interval_distance = total_distance - (GRAVITY * pow((time_passed - 1) , 2)) / 2;
        
        // step2.3 output time passed with no decimals and distances to 3 decimal places in table
        cout << fixed << setprecision(0) << time_passed << "                 ";
        cout << fixed << setprecision(3) << interval_distance << "                                   "
        << total_distance << endl;
    }
    
    // step2.3 loop through each remaining 0.01 second until ball hits ground and calculate interval and total distances
    for (time_passed = (time_to_fall-1); time_passed <= time_to_fall; time_passed += RESOLUTION2)
    {
        total_distance = (GRAVITY * pow(time_passed, 2)) / 2;
        if (time_passed == 0)
            interval_distance = 0;
        else
            interval_distance = total_distance - (GRAVITY * pow((time_passed - RESOLUTION2) , 2)) / 2;
        
        // step2.4 output time passed with 2 decimals and distances to 3 decimal places in table
        cout << fixed << setprecision(2) << time_passed << "               ";
        cout << fixed << setprecision(3) << interval_distance << "                                 "
        << total_distance << endl;
    }
    
    // step3. output that ball has hit the ground
    cout << "HIT GROUND" << "          ";
    cout << "HIT GROUND" << "                            "
    << "HIT GROUND" << endl;
}

void execute_a2_q2()
{
    // step1. calculate and output first table for distance travelled in 30 seconds
    display_distance_fallen();
    
    // step2. calculate and output second table for time passed until 15000m ball hits ground
    time_to_fall_15000();
}

int main()
{
    execute_a2_q2();
}
