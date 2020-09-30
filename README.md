# CPPND: Capstone OpenCV Face Detection


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* opencv >= 4.0
  * All OSes: [click here for installation instructions](https://docs.opencv.org/master/df/d65/tutorial_table_of_content_introduction.html)
## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./FaceDetection`.

##Classes

###Application

The application class is the main entry point of the program.
It use a lock_guard for start the capture method on the CustomVideoCapture class instance _capture
The member variable _capture is a unique_ptr to CustomVideoCapture.

###CustomVideoCapture

This class is responsible to start the opencv VideoCapture and run faces and eyes detection on FaceDetector class instance _faceDetector;
It use two unique_ptr, one for VideoCapture instance and one for FaceDetector for avoid memory management issues.

###FaceDetector
This class is responsible for detect faces and eyes and show it.
It use two unique_ptr for two different CascadeClassifier, one for faces and one for eyes.
The DetectAndDisplay method accept a Mat& reference as params and call private method DetectFaces and DetectEyes for retrieves faces and eyes bounds.
 
 
No delete calls are needed in all the program because all member variables use smart pointers in form of unique_ptr.