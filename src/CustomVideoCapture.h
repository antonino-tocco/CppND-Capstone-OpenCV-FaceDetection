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
        void StartCapture();
    private:
        std::unique_ptr<VideoCapture> _capture;
        std::unique_ptr<FaceDetector> _faceDetector;
};


#endif //HELLOWORLD_CUSTOMVIDEOCAPTURE_H
