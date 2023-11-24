#pragma once
#include <iostream>
#include <memory>

#include "Functions.h"

template <class T>
class Array{
public:
    Array(){
        _capable = 10;
        _size = 0;
        _array = std::shared_ptr<T[]>(new T[_capable]);

        for (int i = 0; i < _capable; ++i)
            _array[i] = nullptr;
    }       

    Array(int size){
        _capable = size * 2;
        _size = 0;
        _array = std::shared_ptr<T[]>(new T[_capable]);

        for (int i = 0; i != _capable; ++i)
            _array[i] = nullptr;
    }   

    Array(const std::initializer_list<T> &t){
            _size = t.size();
        _capable = _size * 2;
        _array = std::shared_ptr<T[]>(new T[_capable]);
        int i = 0;
        for (auto &c : t)
            _array[i++] = c;
    
        for (int i = _size; i < _capable; ++i){
            _array[i++] = nullptr;
    }
    }

    Array(const Array &other){
        _capable = other._capable;
        _size = other._size;   
        _array = std::shared_ptr<T[]>(new T[_capable]);

        for (int i = 0; i < _size; ++i)
            _array[i] = other._array[i];
    }

    Array(Array &&other){
        _capable = other._capable;
        _size = other._size;
        _array = other._array;

        other._capable = 0;
        other._size = 0;
        other._array = nullptr;
    }

    ~Array(){
        _size = 0;
        _capable = 0;
    }

    T& operator[](int index){
        if (index >= _size)
            throw std::invalid_argument("The array index is out of range");
        return _array[index];
    }

    Array<T>& operator=(Array<T>& other){
        _capable = other._capable;
        _size = other._size;
        for(int i = 0; i < _size; ++i){
            _array[i] = other._array[i];
        }
        for(int i{_size}; i < _capable; ++i){
            _array[i] = nullptr;
        }

        return *this;
    }

    Array<T>& operator=(Array<T>&& other){
        _capable = other._capable;
        _size = other._size;
        for(int i = 0; i < _size; ++i){
            _array[i] = other._array[i];
        }
        for(int i{_size}; i < _capable; ++i){
            _array[i] = nullptr;
        }

        other.~Array();

        return *this;
    }

    bool operator==(Array<T>&other){
        if(_size == other._size){
            for(int i = 0; i < _size; ++i){
                if(_array[i] != other._array[i]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    int size() const{
        return _size;
    }

    void delete_elem(int index){
        for(int i{index}; i < _size - 1; ++i){
            _array[i] = _array[i + 1];
        }
        _array[_size - 1] = nullptr;
        --_size;
    }

    void push_back(const T& elem){
        if(_size == _capable){
            _capable *= 2;
            std::shared_ptr<T[]> tmp = std::shared_ptr<T[]>(new T[_capable]);
            for(int i = 0; i < _size; ++i){
                tmp[i] = _array[i];
            }
            for(int i{_size}; i < _capable; ++i){
                tmp[i] = nullptr;
            }
            _array = tmp;
            _array[_size++] = elem;
        }
        else{
            _array[_size++] = elem;
        }   
    }

    double sum() const{
        double s = 0.0;

        for(int i = 0; i < _size; ++i){
            s += (double)(*_array[i]);
        }

        return s;
    }

private:
    int _size;
    int _capable;
    std::shared_ptr<T[]> _array;
};


