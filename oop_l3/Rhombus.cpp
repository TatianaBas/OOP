#include <iostream>
#include <vector>
#include <cmath>
#include "Rhombus.h"

Rhombus::Rhombus() : _area(0)
{
    _points.resize(n);
    _center_point.first = 0;
    _center_point.second = 0;
}

Rhombus::Rhombus(std::vector<std::pair<double, double>> &points)
{
    std::cout<<"Vector of points constructor"<<std::endl;
    if(points.size() != n){
        throw std::invalid_argument("Wrong number of points!");
    }

    for(int i = 0; i < n; i++){
        _points.push_back(points[i]);
        _center_point.first += _points.back().first / n;
        _center_point.second += _points.back().second / n;
    }


    double diag1 = std::sqrt(std::pow(_points[0].first - points[2].first, 2) + std::pow(_points[0].second - _points[2].second, 2));
    double diag2 = std::sqrt(std::pow(_points[1].first - points[3].first, 2) + std::pow(_points[1].second - _points[3].second, 2));

    _area = 0.5*diag1*diag2;

}

Rhombus::~Rhombus(){}

bool Rhombus::operator==(const Rhombus &other) const
{
    if(_points[0].first == other._points[0].first and 
    _points[0].second == other._points[0].second and
    _points[1].first == other._points[1].first and 
    _points[1].second == other._points[1].second and
    _points[2].first == other._points[2].first and 
    _points[2].second == other._points[2].second and
    _points[3].first == other._points[3].first and 
    _points[3].second == other._points[3].second){
        return true;
    } else{
        return false;
    }
}

Rhombus& Rhombus::operator=(const Rhombus &other)
{
    _points = other.get_points();
    _center_point = other.get_center();
    _area = other.get_area();

    return *this;
}

Rhombus& Rhombus::operator=(Rhombus &&other)
{
    _points = std::move(other._points);
    _center_point = std::move(other._center_point);
    _area = std::move(other._area);

    return *this;
}

Rhombus::operator double() const {
    return get_area();
}