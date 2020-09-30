#include <iostream>
#include <thread>
#include "Application.h"

using namespace std;

int main() {
    try {
        string faceCascadePath = "./src/data/face_cascade.xml";
        string eyeCascadePath = "./src/data/eye_cascade.xml";
        Application app(faceCascadePath, eyeCascadePath);
        app.Start();
    } catch (const exception& ex) {
        std::cout << "Exception " << ex.what() << std::endl;
    }
    return 0;
}