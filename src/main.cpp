#include <iostream>
#include <thread>
#include "CustomVideoCapture.h"

using namespace std;

int main() {
    try {
        string faceCascadePath = "./src/data/face_cascade.xml";
        string eyeCascadePath = "./src/data/eye_cascade.xml";
        CustomVideoCapture videoCapture(faceCascadePath, eyeCascadePath);
        videoCapture.StartCapture();
    } catch (const exception& ex) {
        std::cout << "Exception " << ex.what() << std::endl;
    }
    return 0;
}