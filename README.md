# PID Controller
This repository contains code in c++ to implement a PID controller. This code was submitted as part of []Udacity's Self Driving Car Engineer Nanodegree](https://in.udacity.com/course/self-driving-car-engineer-nanodegree--nd013/).

## Overview

The code contains an implementation of a PID controller. On running, the code automatically feeds steering angles to a simulator that runs a car around a track. The code uses the current CTE to track the new steering angle.

### Tuning

The task is to tune the P, I and D parameters to ensure the car drives in the track. Here is how the parameters impacted the Car's driving - 

1. *P = I = D = 0.0;*
The car only drives straight. The PID control has no effect.
2. *P = 1.0, D = I = 0.0;*
The car overshoots everytime and there is a lot of swerve. By the end of the first turn the highest value of the CTE was 4.13
3. *P=1.0, D=1.0, I=0.0;*
The car still overshoots and this time it is even worse. The car did not manage to even take the first turn. And the highest recorded CTE was 5.44. However this could be because of a high D value.
4. *P=1.0, D=0.0, I=1.0;*
Overshooting still exists. By the end of the first turn the maximum CTE was 3.8. Clearly the I value helps the car reach the ideal position.
5. *P=0.1, D=0.00025, I=1.5;*
The final value was arrived by manual adjusting the parameters. The D value was reduced to a very insignificant value as it gave the best performance. Increasing the I value kept the maximum CTE down.
### Variable Throttling

The throttle was set according to the current CTE and the steering angle. A huge steering angle braked the vehicle while straights were used to accelerate. The car acheived a max speed of 58 MPH.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)


