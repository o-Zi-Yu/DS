#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include "utilities.h"

class Polygon{
    public:
        Polygon(const std::string &input_name, const std::vector<Point> &input_points){
            name = input_name, num = input_points.size(), points = input_points;}
        bool HasAllEqualSides(){
            bool a = true;
            std::vector<int> side;
            for (int i = 0; i < num; i++){
                for (int j = i + 1; j < num; j++){
                    side.push_back(DistanceBetween(points[i], points[j]));
                }
            }
            for (int i = 0; i < side.size(); i++){
                if (side[i] != side[0]){
                    a = false;
                }
            }
            return a;
        }
        int getnum(){
            return numpoints;
        }
        virtual ~Polygon() {}
    protected:
        std::string name;
        int num;
        std::vector<Point> points;
};

class Rectangle: public Quadrilateral {
    public:
        Rectangle(const std::string &input_name, const std::vector<Point> &input_points) {
            name = input_name, points = input_points;}
};

class Square: public Rectangle {
    public:
        Square(const std::string &input_name, const std::vector<Point> &input_points) {
            name = input_name, points = input_points;}
};

class Triangle: public Square {
    public:
        Triangle(const std::string &input_name, const std::vector<Point> &input_points) {
            name = input_name, points = input_points;}
};

class IsoscelesTriangle: public Triangle {
    public:
        IsoscelesTriangle(const std::string &input_name, const std::vector<Point> &input_points) {
            name = input_name, points = input_points;}
};

class EquilateralTriangle: public IsoscelesTriangle{
    public:
        EquilateralTriangle(const std::string &input_name, const std::vector<Point> &input_points) {
            name = input_name, points = input_points;}
};
