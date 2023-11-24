#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include "Figure.h"

class Pentagon : public Figure
{
    friend std::ostream& operator<<(std::ostream& os, const Pentagon& pent);
    friend std::istream& operator>>(std::istream& is, Pentagon& pent);
    public:
        Pentagon();
        Pentagon(std::vector<std::pair<double, double>>& points);
        virtual ~Pentagon();

        std::vector<std::pair<double, double>> get_points() const {
            return _points;
        }
        std::pair<double, double> get_center() const override {
            return _center_point;
        }

        double get_area() const override{
            return _area;
        }

        bool operator==(const Pentagon &other) const;
        Pentagon& operator=(const Pentagon &other);
        Pentagon& operator=(Pentagon &&other);

        explicit operator double() const override;
    private:
        std::vector<std::pair<double, double>> _points;
        std::pair<double, double> _center_point;
        double _area = 0;
        int n = 5;
};

inline std::ostream& operator<<(std::ostream& os, const Pentagon& pent)
{
    std::vector<std::pair<double, double>> points = pent.get_points();
    os<<"Points: "<<std::endl;
    for (int i = 0; i<5; i++){
        os<<"Point "<<i+1<<": ["<<points[i].first<<", "<<points[i].second<<"];"<<std::endl;
    }
    return os;
}

inline std::istream& operator>>(std::istream& is, Pentagon& pent)
{
    std::vector<std::pair<double, double>> v(5);

    for (int i = 0; i < 5; i++) {
        std::cout << "Enter x and y " << i + 1 << " points: ";
        is >> v[i].first >> v[i].second;
    }
    pent = Pentagon(v);

    return is;
}



