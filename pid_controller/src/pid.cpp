// pid_controller/pid.cpp
#include "../include/pid.hpp"

PIDController::PIDController(double kp, double ki, double kd)
    : kp_(kp), ki_(ki), kd_(kd), setpoint_(0.0), integral_(0.0), prev_error_(0.0) {}

void PIDController::setSetpoint(double setpoint) {
    setpoint_ = setpoint;
    integral_ = 0.0;
    prev_error_ = 0.0;
}

double PIDController::update(double feedback, double dt) {
    double error = setpoint_ - feedback;
    integral_ += error * dt;
    double derivative = (error - prev_error_) / dt;

    double output = kp_ * error + ki_ * integral_ + kd_ * derivative;

    prev_error_ = error;
    return output;
}
