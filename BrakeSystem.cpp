#include "BrakeSystem.hpp"

BrakeSystem::BrakeSystem()
{}

void BrakeSystem::brakes_enable(){
    std::cout << "(called from BrakeSystem)\tBrakes enabled\n" << std::endl;
}
void BrakeSystem::brakes_disable(){
    std::cout << "(called from BrakeSystem)\tBrakes disabled\n" << std::endl;
}