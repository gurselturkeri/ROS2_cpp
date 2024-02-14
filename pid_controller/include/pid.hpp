// A . cpp file contains the implementation of C++ code, 
// while a . hpp is a header file that contains the declarations 
// of classes, functions, and variables.

// pid_controller/pid.hpp
#pragma once

class PIDController {
public:
    PIDController(double kp, double ki, double kd);

    void setSetpoint(double setpoint);
    double update(double feedback, double dt);

private:
    double kp_;
    double ki_;
    double kd_;
    double setpoint_;
    double integral_;
    double prev_error_;
};
