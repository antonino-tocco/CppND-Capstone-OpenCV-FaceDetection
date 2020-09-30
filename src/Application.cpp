//
// Created by Antonino Tocco on 30/09/2020.
//

#include <thread>
#include "Application.h"

using namespace std;


Application::Application(const string& faceCascadePath, const string& eyeCascadePath) {
    _capture = std::make_unique<CustomVideoCapture>(faceCascadePath, eyeCascadePath);
}

void Application::Start() {
    try {
        std::lock_guard<std::mutex> _lock(_mutex);
       _capture->StartCapture();
    } catch (const std::exception& ex) {
        std::cout << "Lock failed " << ex.what() << std::endl;
    }
}