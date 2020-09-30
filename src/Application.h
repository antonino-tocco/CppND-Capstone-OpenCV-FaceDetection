//
// Created by Antonino Tocco on 30/09/2020.
//

#ifndef FACEDETECTION_APPLICATION_H
#define FACEDETECTION_APPLICATION_H


#include "CustomVideoCapture.h"

class Application {
    public:
        Application(const string& faceCascadePath, const string& eyeCascadePath);
        void Start();
    private:
        std::unique_ptr<CustomVideoCapture> _capture;
        std::mutex _mutex;
};


#endif //FACEDETECTION_APPLICATION_H
