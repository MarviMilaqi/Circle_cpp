
/*
Si implementi in C++ una classe Point che descrive un punto nel piano Cartesiano. Si definiscano i seguenti costruttori e metodi:
 - un costruttore a partire da due coordinate
 - un costruttore senza parametri che inizializza il punto all'origine
 - un metodo che visualizzi le informazioni relative al punto
 - due metodi che spostano il punto rispettivamente orizzontalmente e verticalmente di una certa distanza
 - un metodo che stabilisce se il punto è uguale ad un altro punto

Si implementi una classe Circle. Un cerchio è un punto che, oltre alle coordinate del centro, ha un raggio. Si definiscano i seguenti costruttori e metodi:
 - un costruttore senza parametri che inizializzi il cerchio a "origine con raggio uno"
 - un costruttore a partire da due coordinate e un raggio
 - un costruttore a partire da due coordinate, che assegni come raggio uno
 - un metodo che visualizzi le informazioni relative al cerchio
 - un metodo che scali la dimensione del cerchio di una certa quantità, moltiplicandone il raggio per tale quantità
 - un metodo che stabilisce se il cerchio e' uguale ad un altro cerchio
 */

#include <iostream>
using namespace std;

class Point {
private:
    double x;
    double y;
public:
    // Costruttore senza parametri
    Point() : x(0.0), y(0.0) {}
    // Costruttore a partire da due coordinate
    Point(double x, double y) : x(x), y(y) {}

    // Metodo visualizza info
    void display() const {
        cout << "Point(" << x << ", " << y << ")\n";
    }

    // Metodo sposta orizzolintamente
    void moveHorizontally(double distance) {
        x += distance;
    }

    // Metodo sposta verticalmente
    void moveVertically(double distance) {
        y += distance;
    }

    // Metodo che stabilisce se il punto è uguale ad un altro punto
    bool isEqual(const Point& other) const {
        return x == other.x && y == other.y;
    }

};

class Circle : public Point {
private:
    double radius;
public:
    // Costruttore senza parametri
    Circle() : Point(), radius(1.0) {}

    // Costruttore a partire da due coordinate e un raggio
    Circle(double x, double y, double radius) : Point(x,y), radius(radius) {}

    // Costruttore a partire da due coordinate, che assegni come raggio uno
    Circle(double x, double y) : Point(x,y), radius(1.0) {}

    // Metodo che visualizzi le informazioni relative al cerchio
    void display() const {
        cout << "Circle: center = ";
        Point::display();
        cout << "Radius = " << radius << endl;
    }

    // Metodo che scali la dimensione del cerchio di una certa quantità, moltiplicandone il raggio per tale quantità
    void scali(double factor) {
        radius *= factor;
    }

    // Metodo che stabilisce se il cerchio e' uguale ad un altro cerchio
    bool isEqual(const Circle& other) const {
        return Point::isEqual(other) && radius == other.radius;
    }
};

int main() {
    Point p1(3, 4);
    Point p2;
    p1.display();
    p2.display();

    Circle c1;
    Circle c2(5, 6, 2);
    Circle c3(7, 8);
    c1.display();
    c2.display();
    c3.display();
    c2.scali(3);
    c2.display();

    return 0;
}
