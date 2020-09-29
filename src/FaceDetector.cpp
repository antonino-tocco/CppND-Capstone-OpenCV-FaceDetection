//
// Created by Antonino Tocco on 28/09/2020.
//

#include "FaceDetector.h"
#include <iostream>

using namespace std;

FaceDetector::FaceDetector(const string& facesCascadePath, const string& eyesCascadePath):
    _facesCascade(new CascadeClassifier(facesCascadePath)), _eyesCascade(new CascadeClassifier(eyesCascadePath)) {}

FaceDetector::~FaceDetector() {
    delete _facesCascade;
    delete _eyesCascade;
}

void FaceDetector::DetectAndDisplay(Mat frame) {
    Mat frame_gray;
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );
    //-- Detect faces
    std::vector<Rect> faces;
    DetectFaces(frame_gray, faces);
    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4 );
        Mat faceROI = frame_gray( faces[i] );
        //-- In each face, detect eyes
        std::vector<Rect> eyes;
        DetectEyes(faceROI, eyes);
        for ( size_t j = 0; j < eyes.size(); j++ )
        {
            Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 4 );
        }
    }
    //-- Show what you got
    imshow( "Capture - Face detection", frame );
}

void FaceDetector::DetectFaces(Mat frame, vector<Rect>& faces) {
    _facesCascade->detectMultiScale( frame, faces);
}

void FaceDetector::DetectEyes(Mat frame, vector<Rect>& eyes) {
    _eyesCascade->detectMultiScale(frame, eyes);
}
