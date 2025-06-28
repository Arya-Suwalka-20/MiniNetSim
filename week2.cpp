#include<bits/stdc++.h>
using namespace std;

class Shape{
protected:
    int x=0;
    int y=0;

public:
    // creating pure virtual function
    // must be overridden in every subclass
    virtual int getShape() const = 0;

    void setCoordinates(int x1, int y1){
        x = x1;
        y = y1;
    }

    pair<int, int> getCoordinates() const {
        return {x, y};
    }
};

class Rectangle : public Shape{
protected:
    int length;
    int breadth;

public:
    Rectangle(){
        length = 0;
        breadth = 0;
    }

    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }

    int getLength() const{
        return length;
    }

    int getBreadth() const{
        return breadth;
    }

    int getArea() const{
        return length*breadth;
    }

    int getPerimeter() const{
        return 2*(length+breadth);
    }

    bool isSquare() const{
        if(length==breadth) return true;
        return false;
    }

    virtual void setDimensions(int l, int b){
        length = l;
        breadth = b;
    }

    int getShape() const override{
        return 0;
    }

};

class Square : public Rectangle{
public:
    Square(int side){
        length = side;
        breadth = side;
    }
    
    Square(){
        length = 0;
        breadth = 0;
    }

    void setSide(int side){
        length = side;
        breadth = side;
    }

    void setDimensions(int l , int b) override{
        if(l!=b) cout << "Error: A square must have equal sides." << endl;
        else{
            length = l;
            breadth = b;
        }
    }

    int getShape() const override{
        return 1;
    }

};

class Ellipse : public Shape{
protected:
    int semiMajor;
    int semiMinor;
public:
    Ellipse(){
        semiMajor = 0;
        semiMinor = 0;
    }
    
    Ellipse(int a, int b){
        semiMajor = a;
        semiMinor = b;
    }

    void setAxes(int a, int b){
        semiMajor = a;
        semiMinor = b;
    }

    int getXLength() const{
        return semiMajor;
    }

    int getYLength() const{
        return semiMinor;
    }

    int getShape() const override{
        return 3;
    }
};

class Circle : public Ellipse{
public:
    Circle(){
        semiMajor = 0;
        semiMinor = 0;
    }

    Circle(int r){
        semiMajor = r;
        semiMinor = r;
    }
    
    int getRadii() const{
        return semiMajor;
    }

    void setRadii(int r){
        semiMajor = r;
        semiMinor = r;
    }

    int getShape() const override{
        return 2;
    }
};