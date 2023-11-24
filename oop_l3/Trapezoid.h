#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include "Figure.h"

class Trapezoid : public Figure
{
    friend std::ostream& operator<<(std::ostream& os, const Trapezoid& trap);
    friend std::istream& operator>>(std::istream& is, Trapezoid& trap);
    public:
    Trapezoid();
    Trapezoid(std::vector<std::pair<double, double>>& points);
    virtual ~Trapezoid();

    std::vector<std::pair<double, double>> get_points() const {
        return _points;
    }
    std::pair<double, double> get_center() const override {
        return _center_point;
    }

    double get_area() const override{
    return _area;
}

    bool operator==(const Trapezoid &other) const;
    Trapezoid& operator=(const Trapezoid &other);
    Trapezoid& operator=(Trapezoid &&other);

    explicit operator double() const override;
    private:
    std::vector<std::pair<double, double>> _points;
    std::pair<double, double> _center_point;
    double _area = 0;
    int n = 4;
};

inline std::ostream& operator<<(std::ostream& os, const Trapezoid& trap)
{
    std::vector<std::pair<double, double>> points = trap.get_points();
    os<<"Points: "<<std::endl;
    for (int i = 0; i<4; i++){
        os<<"Point "<<i+1<<": ["<<points[i].first<<", "<<points[i].second<<"];"<<std::endl;
    }
    return os;
}

inline std::istream& operator>>(std::istream& is, Trapezoid& trap)
{
    std::vector<std::pair<double, double>> v(4);

    for (int i = 0; i < 4; ++i) {
        std::cout << "Enter x and y " << i + 1 << " points: ";
        is >> v[i].first >> v[i].second;
    }
    trap = Trapezoid(v);

    return is;
}

