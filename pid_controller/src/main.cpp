// pid_controller/main.cpp
#include <chrono>
#include <thread>
#include <iostream>
#include "../include/pid.hpp"

int main() {
    const double kp = 1.0;
    const double ki = 0.1;
    const double kd = 0.05;
    PIDController pid_controller(kp, ki, kd);

    pid_controller.setSetpoint(10.0); // Set desired setpoint

    double feedback = 0.0;
    double dt = 0.01; // Time step
    for (int i = 0; i < 1000; ++i) { // Simulate 10 seconds
        double output = pid_controller.update(feedback, dt);
        // Simulate process with feedback
        feedback += output * dt;

        std::cout << "Output: " << output << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(dt * 1000)));
    }

    return 0;
}
