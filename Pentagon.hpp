#ifndef PENTAGON_HPP
#define PENTAGON_HPP

#include "Point_figure.hpp"

class Pentagon : public Figure {
    private:
        Point z;
        double R;
    public:
        Pentagon();
        Pentagon(Point x, double Rad);
        void output() override;
        double get_area() override;
        Point get_centre() override;   
};

#endif