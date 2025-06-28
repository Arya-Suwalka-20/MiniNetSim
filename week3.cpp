#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;

// ------------------ Base Shape Class ------------------
class Shape {
protected:
    int x = 0, y = 0;

public:
    virtual int getShape() const = 0;
    virtual void display(sf::RenderWindow &window) const = 0;

    void setCoordinates(int x1, int y1) {
        x = x1;
        y = y1;
    }

    pair<int, int> getCoordinates() const {
        return {x, y};
    }

    virtual ~Shape() {}
};

// ------------------ Rectangle Class ------------------
class Rectangle : public Shape {
protected:
    int length, breadth;

public:
    Rectangle() : length(0), breadth(0) {}
    Rectangle(int l, int b) : length(l), breadth(b) {}

    int getLength() const { return length; }
    int getBreadth() const { return breadth; }
    int getArea() const { return length * breadth; }
    int getPerimeter() const { return 2 * (length + breadth); }

    virtual void setDimensions(int l, int b) {
        length = l;
        breadth = b;
    }

    bool isSquare() const { return length == breadth; }

    int getShape() const override { return 0; }

    void display(sf::RenderWindow &window) const override {
        sf::RectangleShape rect(sf::Vector2f(length, breadth));
        rect.setPosition(x, y);
        rect.setFillColor(sf::Color::Green);
        window.draw(rect);
    }
};

// ------------------ Square Class ------------------
class Square : public Rectangle {
public:
    Square() : Rectangle(0, 0) {}
    Square(int side) : Rectangle(side, side) {}

    void setSide(int side) {
        length = breadth = side;
    }

    void setDimensions(int l, int b) override {
        if (l != b) {
            cout << "Error: Square sides must be equal!" << endl;
        } else {
            length = breadth = l;
        }
    }

    int getShape() const override { return 1; }

    void display(sf::RenderWindow &window) const override {
        sf::RectangleShape square(sf::Vector2f(length, length));
        square.setPosition(x, y);
        square.setFillColor(sf::Color::Yellow);
        window.draw(square);
    }
};

// ------------------ Ellipse Class ------------------
class Ellipse : public Shape {
protected:
    int semiMajor, semiMinor;

public:
    Ellipse() : semiMajor(0), semiMinor(0) {}
    Ellipse(int a, int b) : semiMajor(a), semiMinor(b) {}

    void setAxes(int a, int b) {
        semiMajor = a;
        semiMinor = b;
    }

    int getXLength() const { return semiMajor; }
    int getYLength() const { return semiMinor; }

    int getShape() const override { return 3; }

    void display(sf::RenderWindow &window) const override {
        sf::CircleShape ellipse(1.f); // radius 1
        ellipse.setScale(semiMajor, semiMinor);
        ellipse.setPosition(x, y);
        ellipse.setFillColor(sf::Color::Blue);
        window.draw(ellipse);
    }
};

// ------------------ Circle Class ------------------
class Circle : public Ellipse {
public:
    Circle() : Ellipse(0, 0) {}
    Circle(int r) : Ellipse(r, r) {}

    void setRadii(int r) {
        semiMajor = semiMinor = r;
    }

    int getRadii() const {
        return semiMajor;
    }

    int getShape() const override { return 2; }

    void display(sf::RenderWindow &window) const override {
        sf::CircleShape circle(semiMajor);
        circle.setPosition(x, y);
        circle.setFillColor(sf::Color::Red);
        window.draw(circle);
    }
};

// ------------------ Canvas Class ------------------
class Canvas {
private:
    vector<Shape*> shapes;

public:
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void displayCanvas() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Canvas");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);
            for (auto shape : shapes) {
                shape->display(window);
            }
            window.display();
        }
    }
};

// ------------------ Main ------------------
int main() {
    Rectangle* rect = new Rectangle(100, 50);
    rect->setCoordinates(50, 50);

    Square* sq = new Square(80);
    sq->setCoordinates(200, 100);

    Ellipse* e = new Ellipse(50, 25);
    e->setCoordinates(400, 200);

    Circle* c = new Circle(40);
    c->setCoordinates(600, 100);

    Canvas canvas;
    canvas.addShape(rect);
    canvas.addShape(sq);
    canvas.addShape(e);
    canvas.addShape(c);

    canvas.displayCanvas();

    return 0;
}
