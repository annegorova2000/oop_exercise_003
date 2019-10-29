#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include "Point_figure.hpp"

class Hexagon : public Figure {
    private:
        Point z;
        double R;
    public:
        Hexagon();
        Hexagon(Point x, double Rad);
        void output() override;
        double get_area() override;
        Point get_centre() override;   
};

#endif