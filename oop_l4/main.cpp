#include <iostream>
#include <memory>

#include "Array.h"
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Functions.h"

#define pii std::pair<int,int>

int main(){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);

    Array<std::shared_ptr<Figure>> arr{a_ptr};    


    for(int i{0}; i < arr.size(); ++i){

        Figure* el = arr[i].get();

        if (el == nullptr) {
            std::cout << "The figure has been deleted" << std::endl;
        } 
        else if (typeid(Trapezoid<int>) == typeid(*el)) {
            get_center<Trapezoid<int>, int>(*(Trapezoid<int>*)el);

            print<Trapezoid<int>>(*(Trapezoid<int>*)el);

            std::cout << "Square Trapezoid = " << square<Trapezoid<int>, int>(*(Trapezoid<int>*)el) << std::endl;

        } 
    }
}
