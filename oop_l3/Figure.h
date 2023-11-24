#pragma once
#include<iostream>
#include<vector>

class Figure
{
	friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
	friend std::ostream& operator>>(std::istream& is, Figure& figure);
    
    protected:
        Figure() {}
    public:
        virtual ~Figure() = default;
        virtual std::pair<double, double> get_center() const = 0;
        virtual double get_area() const = 0;
        virtual explicit operator double() const = 0;
    private:
        std::vector<std::pair<double, double>> _points;
        std::pair<double, double> _center_point;
        double _area = 0;
        int n = 0; //number of vertices



};