//
// Created by Antonino Tocco on 29/09/2020.
//

#include "CustomVideoCapture.h"
#define CAMERA_ID 0

using namespace std;
using namespace cv;


CustomVideoCapture::CustomVideoCapture(const string& faceCascadePath, const string& eyesCascadePath):
    _capture(new VideoCapture()), _faceDetector(new FaceDetector(faceCascadePath, eyesCascadePath)) {};

CustomVideoCapture::~CustomVideoCapture() {

}


void CustomVideoCapture::StartCapture() {
    if (_capture == nullptr) return;

    try {
        _capture->open(CAMERA_ID);
        if (!_capture->isOpened()) {
            Mat frame;
            while (_capture->read(frame)) {
                if (frame.empty()) {
                    continue;
                }
                _faceDetector->DetectAndDisplay(frame);
            }
        }
    } catch (const exception& ex) {

    }
}