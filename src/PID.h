#ifndef PID_H
#define PID_H

#include <vector>

class PID {
public:
    /*
    * Errors
    */
    double p_error;
    double i_error;
    double d_error;

    /*
    * Coefficients
    */
    double Kp;
    double Ki;
    double Kd;

    // initial public properties
    double steering_angle;
    double total_error;
    double int_cte;
    double prev_cte;
    double current_cte;
    bool first_run;
    bool first_throttle;
    int iter;
    double twiddle_params[3];

    /*
    * Constructor
    */
    PID();

    /*
    * Destructor.
    */
    virtual ~PID();

    /*
    * Initialize PID.
    */
    void Init(double Kp, double Ki, double Kd);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double cte);

    /*
    * Get the steering angle
    */
    double GetSteeringAngle();

    /*
    * Calculate the total PID error.
    */
    double TotalError();

    /*
    * Calculate the throttle.
    */
    double Throttle();
};

#endif /* PID_H */
