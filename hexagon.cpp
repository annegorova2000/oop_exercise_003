#include "Hexagon.hpp"

Hexagon::Hexagon() : z(0,0), R(0)
{}

Hexagon::Hexagon(Point x, double Rad) : z(x), R(Rad)
{
    if(R <= 0) {
        throw std::logic_error("always R > 0");
    }
}

void Hexagon::output() {
    std::cout << "Coordinates of Hexagon: " << std::endl;
    double angle;
    for(int i = 0; i < 6; i++) {
        angle =  M_PI * i / 3;
        Point(R * cos(angle) + z.x(),R * sin(angle) + z.y()).P_output() ;
    }
}

double Hexagon:: get_area() {
    return 3 * sin(M_PI / 3) * R * R;
}

Point Hexagon::get_centre() {
    return z;
}