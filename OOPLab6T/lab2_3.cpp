#include<iostream>
#include<cmath>

// Базовий клас
class Shape {
public:
    Shape() {
        std::cout << "Constructor of Shape is called" << std::endl;
    }

    virtual ~Shape() {
        std::cout << "Destructor of Shape is called" << std::endl;
    }

    virtual void input() = 0;
    virtual void output() = 0;
};

// Коло
class Circle : virtual public Shape {
protected:
    double radius;

public:
    Circle() {
        std::cout << "Constructor of Circle is called" << std::endl;
        radius = 0.0;
    }

    ~Circle() {
        std::cout << "Destructor of Circle is called" << std::endl;
    }

    void input() {
        std::cout << "Enter radius of circle: ";
        std::cin >> radius;
    }

    void output() {
        std::cout << "Circle radius: " << radius << ", Area: " << 3.1416 * radius * radius << std::endl;
    }
};

// Квадрат
class Square : virtual public Shape {
protected:
    double side;

public:
    Square() {
        std::cout << "Constructor of Square is called" << std::endl;
        side = 0.0;
    }

    ~Square() {
        std::cout << "Destructor of Square is called" << std::endl;
    }

    void input() {
        std::cout << "Enter side of square: ";
        std::cin >> side;
    }

    void output() {
        std::cout << "Square side: " << side << ", Area: " << side * side << std::endl;
    }
};

// Коло, вписане в квадрат (спадкований від класів Коло і Квадрат)
class CircleInSquare : public Circle, public Square {
public:
    CircleInSquare() {
        std::cout << "Constructor of CircleInSquare is called" << std::endl;
    }

    ~CircleInSquare() {
        std::cout << "Destructor of CircleInSquare is called" << std::endl;
    }

    void input() {
        Square::input();
        // радіус
        radius = side / 2;
    }

    void output() {
        Square::output();
        Circle::output();
    }
};

int main() {
    CircleInSquare cis;
    cis.input();
    cis.output();
    return 0;
}

