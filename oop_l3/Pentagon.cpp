#include <iostream>
#include <vector>
#include <cmath>
#include "Pentagon.h"

const double PI = 3.1415926;

Pentagon::Pentagon() : _area(0)
{
    _points.resize(n);
    _center_point.first = 0;
    _center_point.second = 0;
}

Pentagon::Pentagon(std::vector<std::pair<double, double>> &points)
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

    double a = sqrt(pow(_points[0].first - points[1].first, 2) + pow(_points[0].second - points[1].second, 2));

    double h = (0.5*a) / (tan(PI/5));

    _area = 5*(0.5*h*a);

}

Pentagon::~Pentagon(){}

bool Pentagon::operator==(const Pentagon &other) const
{
    if(_points[0].first == other._points[0].first and 
        _points[0].second == other._points[0].second and
        _points[1].first == other._points[1].first and 
        _points[1].second == other._points[1].second and
        _points[2].first == other._points[2].first and 
        _points[2].second == other._points[2].second and
        _points[3].first == other._points[3].first and 
        _points[3].second == other._points[3].second and
        _points[4].first == other._points[4].first and 
        _points[4].second == other._points[4].second){
            return true;
        } else{
            return false;
        }
}

Pentagon& Pentagon::operator=(const Pentagon &other)
{
    _points = other.get_points();
    _center_point = other.get_center();
    _area = other.get_area();

    return *this;
}

Pentagon& Pentagon::operator=(Pentagon &&other)
{
    _points = std::move(other._points);
    _center_point = std::move(other._center_point);
    _area = std::move(other._area);

    return *this;
}

Pentagon::operator double() const {
    return get_area();
}
