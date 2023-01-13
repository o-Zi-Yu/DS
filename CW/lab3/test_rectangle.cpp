#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "Rectangle.h"

int main(){
    Rectangle a = Rectangle(Point2D(4.0, 3.0),Point2D(17.0, 9.0));
    Rectangle b = Rectangle(Point2D(8.0, 5.0),Point2D(17.0, 16.0));
    print_rectangle(a);
    print_rectangle(b);
    Point2D c = Point2D(3.0, 4.0);
    Point2D d = Point2D(9.0, 8.0);
    a.add_point(c);
    a.add_point(d);
    std::cout << a.is_point_within(c) << std::endl;
    std::cout << b.is_point_within(d) << std::endl;
    print_rectangle(a);
    print_rectangle(b);

    std::vector<Point2D> e = points_in_both(a, b);
    //std::cout << e.size();
    for (int i = 0; i < e.size(); i++){
        std::cout << e[i].x() << ' ' << e[i].y() << std:: endl;
    }
}