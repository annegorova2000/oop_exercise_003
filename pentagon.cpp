#include "Pentagon.hpp"

Pentagon::Pentagon() : z(0,0), R(0)
{}

Pentagon::Pentagon(Point x, double Rad) : z(x), R(Rad)
{
    if(R <= 0) {
        throw std::logic_error("always R > 0");
    }
}

void Pentagon::output() {
    std::cout << "Coordinates of Pentagon: " << std::endl;
    double angle;
    for(int i = 0; i < 5; i++) {
        angle =  2*M_PI * i / 5;
        Point(R * cos(angle) + z.x(), R * sin(angle) + z.y()).P_output() ;
    }
}

double Pentagon:: get_area() {
    return 5 * sin(2*M_PI / 5) * R * R;
}

Point Pentagon::get_centre() {
    return z;
}