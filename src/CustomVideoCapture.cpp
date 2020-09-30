//
// Created by Antonino Tocco on 29/09/2020.
//

#include "CustomVideoCapture.h"
#define CAMERA_ID 0

using namespace std;
using namespace cv;


CustomVideoCapture::CustomVideoCapture(const string& faceCascadePath, const string& eyesCascadePath):
    _capture(std::make_unique<VideoCapture>()), _faceDetector(std::make_unique<FaceDetector>(faceCascadePath, eyesCascadePath)) {};


void CustomVideoCapture::StartCapture() {
    if (_capture == nullptr) return;
    try {
        _capture->open(CAMERA_ID);
        if (!_capture->isOpened()) {
            return;
        }
        Mat frame;
        while (_capture->read(frame)) {
            if (frame.empty()) {
                break;
            }
            _faceDetector->DetectAndDisplay(frame);
            if( waitKey(10) == 27 ) {
                break;
            }
        }
    } catch (const exception& ex) {
        std::cout << "Exception on capture " << ex.what() << std::endl;
    }
}