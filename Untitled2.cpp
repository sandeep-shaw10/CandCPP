#include <iostream>

using namespace std;

class triangle {

    const int *_base, *_height;

public:
	triangle(int b, int h) : _base(b), _height(h) { } // Line-1

    // LINE-1: Complete Constructor definition

    ~triangle() {
        delete _base, _height; // Line-2
        // LINE-2: Complete destructor to delete both data pointers

    }
    double area();
};

double area(int *_base, int *_height){  // LINE-3: Complete function header
return 0.5 * *_base * *_height;
}

int main() {
    int a, b;

    cin >> a >> b;
    triangle r(a, b);
    cout << r.area();

    return 0;
}



