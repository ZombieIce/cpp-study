#include <iostream>
struct CircleStruct {
  int x, y;
  double radius;
};

class CircleClass {
public:
    CircleClass(int x, int y, double radius)
        :m_x{x}, m_y{y}, m_radius{radius}{}
    
private:
    int m_x, m_y;
    double m_radius;
};

int main(int argc, const char** argv) {
    CircleStruct myCircle {10, 10, 2.5};
    CircleClass myCircle2 {10, 10, 2.5};
    return 0;
}