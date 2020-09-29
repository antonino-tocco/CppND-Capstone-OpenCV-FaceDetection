//
// Created by Antonino Tocco on 29/09/2020.
//

#ifndef HELLOWORLD_CUSTOMVIDEOCAPTURE_H
#define HELLOWORLD_CUSTOMVIDEOCAPTURE_H

#include <opencv2/opencv.hpp>
#include "FaceDetector.h"

using namespace std;
using namespace cv;

class CustomVideoCapture {
    public:
        CustomVideoCapture(const string& faceCascadePath, const string& eyesCascadePath);
        ~CustomVideoCapture();
        void StartCapture();
    private:
        VideoCapture* _capture;
        FaceDetector* _faceDetector;
};


#endif //HELLOWORLD_CUSTOMVIDEOCAPTURE_H
