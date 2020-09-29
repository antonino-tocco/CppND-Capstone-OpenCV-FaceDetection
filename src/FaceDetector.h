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
        ~FaceDetector();
        void DetectAndDisplay(Mat frame);
    private:
        void DetectFaces(Mat frame, vector<Rect>& faces);
        void DetectEyes(Mat frame, vector<Rect>& eyes);
        CascadeClassifier* _facesCascade;
        CascadeClassifier* _eyesCascade;
};


#endif //HELLOWORLD_FACE_DETECTOR_H
