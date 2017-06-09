#include "PID.h"
#include <math.h>
#include <iostream>
#include <numeric>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

double max_cte = 0.0;

/*
 * Initialize the PID class with the parameters
 * @param double p_Kp - the proportional factor
 * @param double p_Ki - the integral factor
 * @param double p_Kd - the differential factor
 */
void PID::Init(double p_Kp, double p_Ki, double p_Kd) {
    Kp = p_Kp;
    Kd = p_Kd;
    Ki = p_Ki;

    // initialize the total error and the flag
    total_error = 0.0;
    int_cte = 0.0;
    first_run = true;
    first_throttle = true;
    iter = 0;
}

/*
 * Update the new CTE error
 * @param double cte - the cross track error
 */
void PID::UpdateError(double cte) {

    // increase the iterations
    iter++;

    // if first run set previous_cte and cte to the same value, else store the previous value
    if (first_run) {
        current_cte = cte;
        prev_cte = current_cte;
        first_run = false;
    } else {
        prev_cte = current_cte;
        current_cte = cte;
    }

    if (current_cte > max_cte) {
        max_cte = current_cte;
    }

    std::cout << "Max CTE is " << max_cte << std::endl;
    total_error = (total_error + cte) / iter;
}

/*
 * Normalize the angle to be between -1 to 1
 * @param double angle - the non-normalize angle
 * @return the normalize angle
 */
double normalizeAngle(double angle) {

    // reset the angle to be between -1 to 1
    if (angle < -1.0) {
        return -1.0;
    } else if (angle > 1.0) {
        return 1.0;
    }

    return angle;
}

/*
 * Get the current steering angle based on the cte
 * @return the steering angle according to the cte
 */
double PID::GetSteeringAngle() {

    // get the difference in the cte
    double dt_cte = current_cte - prev_cte;

    // sum the total error
    int_cte = int_cte + current_cte;

    // calculate the new steering angle and return
    steering_angle = -Kp * current_cte - Kd * dt_cte - Ki * int_cte;

    std::cout << "Steering Angle is " << steering_angle << " Current CTE is " << current_cte << " Sum error is "
              << int_cte << std::endl;

    return normalizeAngle(steering_angle);
}

/*
 * Get the total error
 * @return the total error
 */
double PID::TotalError() {
    return total_error;
}

/*
 * Get the throttle based on the steering angle and cte
 * @return the recommended throttle
 */
double PID::Throttle() {

    // if throttling for the first time return a nominal value
    if (first_throttle) {
        first_throttle = false;

        // quick start :p
        return 0.8;
    }

    // if steering angle indicates straight road and the cte is less than return a higher throttle angle
    if (steering_angle > -0.05 && steering_angle < 0.05 && current_cte > -0.3 && current_cte < 0.3) {
        return 0.7;
    }

    if (steering_angle > -0.25 && steering_angle < 0.25) {
        return 0.3;
    }

    // brake if the steering angle is huge, passenger comfort!
    if ((steering_angle < -0.4 || steering_angle > 0.4)) {
        return -0.15;
    }

    // return the default throttle
    return 0.2;
}

