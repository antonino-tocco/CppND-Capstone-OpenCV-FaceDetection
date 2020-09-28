//
// Created by Antonino Tocco on 28/09/2020.
//

#include <opencv2/opencv.hpp>
#include <vector>

#ifndef HELLOWORLD_FACE_DETECTOR_H
#define HELLOWORLD_FACE_DETECTOR_H


class FaceDetector {
    public:
        std::vector<Rect> DetectFaces();
        std::vector<Rect> DetectEyes();
    private:
        Cascade _facesCascade;
        Cascade _eyesCascade;
};


#endif //HELLOWORLD_FACE_DETECTOR_H
