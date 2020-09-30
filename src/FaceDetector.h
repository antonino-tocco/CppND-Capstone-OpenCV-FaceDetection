//
// Created by Antonino Tocco on 28/09/2020.
//

#include <opencv2/opencv.hpp>
#include <vector>

#ifndef HELLOWORLD_FACE_DETECTOR_H
#define HELLOWORLD_FACE_DETECTOR_H

using namespace cv;
using namespace std;

class FaceDetector {
    public:
        FaceDetector(const string& facesCascadePath, const string& eyesCascadePath);
        void DetectAndDisplay(const Mat& frame);
    private:
        void DetectFaces(const Mat& frame, vector<Rect>& faces);
        void DetectEyes(const Mat& frame, vector<Rect>& eyes);
        std::unique_ptr<CascadeClassifier> _facesCascade;
        std::unique_ptr<CascadeClassifier> _eyesCascade;
};


#endif //HELLOWORLD_FACE_DETECTOR_H
