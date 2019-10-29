/* Егорова Анна Владимировна М8O-207Б-18
Разработать классы согласно варианту задания, классы должны наследоваться от базового класса Figure. Фигуры являются фигурами вращения. Все классы должны поддерживать набор общих методов:
1.       Вычисление геометрического центра фигуры;
2.       Вывод в стандартный поток вывода std::cout координат вершин фигуры; 3. Вычисление площади фигуры;
Фигуры: восьмиугольник, шестиугольник, пятиугольник.
Создать программу, которая позволяет:
•       Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
•       Сохранять созданные фигуры в динамический массив std::vector<Figure*>
•       Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для каждой фигуры в массиве геометрический центр, координаты вершин и площадь.
•       Необходимо уметь вычислять общую площадь фигур в массиве.
•       Удалять из массива фигуру по индексу;
*/


#include "source/Point_figure.hpp"
#include "source/Octagon.hpp"
#include "source/Hexagon.hpp"
#include "source/Pentagon.hpp"

void help() {
    std::cout << "add = add figure" << std::endl;
    std::cout << "delete = delete figure" << std::endl;
    std::cout << "print = show information about figure" << std::endl;
    std::cout << "print_all = show information about all figures" << std::endl;
    std::cout << "size = the size of our array of figures" << std::endl;
    std::cout << "all_area = the sum area of all figures" << std::endl;
    std::cout << "exit = exit" << std::endl;
}

void simple_add(std::vector<Figure*>& figures) {
    std::cout << "Press pe to add pentagon, o to add octagon, h to add Hexagon" << std::endl;
    std::string inf;
    Pentagon *pe = nullptr;
    Hexagon *h = nullptr;
    Octagon *o = nullptr;
    std::cin >> inf;
    if (inf == "pe") {
        std::cout << "Please, your center coordinate and circle radius" << std::endl;
        double x1,y1,R;
        std::cin >> x1 >> y1 >> R;
        Point p(x1,y1);
        try {
				pe = new Pentagon(p,R);
                figures.push_back(dynamic_cast<Figure*>(pe));
			} catch (std::logic_error& err) {
                delete pe;
				std::cout << err.what() << std::endl;
            }
    } else if (inf == "h") {
        std::cout << "Please, your center coordinate and circle radius" << std::endl;
        double x1,y1,R;
        std::cin >> x1 >> y1 >> R;
        Point p(x1,y1);
        try {
				h = new Hexagon(p,R);
                figures.push_back(dynamic_cast<Figure*>(h));
			} catch (std::logic_error& err) {
                delete h;
				std::cout << err.what() << std::endl;
            }
    } else if (inf == "o") {
        std::cout << "Please, your center coordinate and circle radius" << std::endl;
        double x1,y1,R;
        std::cin >> x1 >> y1 >> R;
        Point p(x1,y1);
        try {
				o = new Octagon(p,R);
                figures.push_back(dynamic_cast<Figure*>(o));
			} catch (std::logic_error& err) {
                delete o;
				std::cout << err.what() << std::endl;
			}
    }
}

std::vector<Figure*> delete_el(std::vector<Figure*>& figures, int del) {
    int i = 0;
    std::vector<Figure*> n_figures;
    while(i < figures.size()) {
        if(i != del) {
            n_figures.push_back(figures[i]);
        }
        i++;
    }
    figures.clear();
    return n_figures;   
}


int main() {
    std::cout << std::fixed;
    std::cout.precision(3);
    std::vector<Figure*> figures;
    std::string data;
    int i;
    help();
    while(std::cin >> data) {
        if(data == "add") {
            simple_add(figures);
        } else if(data == "delete") { 
            std::cout << "Index = ";
            std::cin >> i;
            if(i < 0 || i >= figures.size()) {
                std::cout << "Error" << std::endl;
            } else {
               delete figures[i];
               figures = delete_el(figures, i);
            }
        } else  if(data == "print") {
            std::cout << "Index : ";
            std::cin >> i;
            if(i < 0 || i >= figures.size()) {
                std::cout << "Error" << std::endl;
            } else {
                figures[i]->output();
                 std::cout << "center ";
                figures[i]->get_centre().P_output();
                std::cout << "Area : " << figures[i]->get_area() << std::endl;
            }
        } else if(data == "print_all") {
            for(int j = 0; j < figures.size(); j++) {
                std::cout << j << "-st figure" << std::endl;
                figures[j]->output();
                std::cout << "center ";
                figures[j]->get_centre().P_output();
                std::cout << "Area : " << figures[j]->get_area() << std::endl;
            }
        } else if(data == "size") {
            std::cout << figures.size() << std::endl;
        } else if(data == "all_area") {
            double b = 0;
            for(int j = 0; j < figures.size(); j++) {
                b = b + figures[j]->get_area();
            }
            std:: cout << "Area of all fiqures : " << b << std::endl;
        } else if(data == "exit") {
            for(int j = 0; j < figures.size(); j++) {
                delete figures[j];
            }
            return 0;
        }
    }
    return 0;
}