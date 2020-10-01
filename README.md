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

##Rubrics

###Loops, Functions, I/O

1. A variety of control structures are used in the project. The project code is clearly organized into functions.
Use while loop in CustomVideoCapture on line 24.
All the classes are structured with multiple methods.

2. The project reads data from an external file or writes data to a file as part of the necessary operation of the program.
The FaceDetector class read from face_cascade.xml and eye_cascade.xml on file FaceDetector.cpp, line 11.

###Object Oriented Programming
1. The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
All the project is ased on 3 classes, Application, CustomVideoCapture and FaceDetector.
The structure of classes is in header files Application.h, CustomVideoCapture.h and FaceDetector.h.

2. All class data members are explicitly specified as public, protected, or private.
All class define access modifiers for class members such as private or public.
The instance variables are private for don't break encapsulation.

3. All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.
All the class member functions have function names that document the effect of using it.

4. Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified.
As you can view the program use composition for get the results.
The Application class "use" the class member _capture (Application.h, line 16) of type CustomVideoCapture that "use" member variables _faceDetector (CustomVideoCapture.h, line 20).
FaceDetector use two member variables of type CascadeClassifier (FaceDetector.h, line 21-22)

###Memory Management
1. At least two variables are defined as references, or two functions use pass-by-reference in the project code.
The public method DetectAndDisplay (FaceDetector.h, line 17) from FaceDetector and the private methods DetectFaces and DetectEyes (FaceDetector.h, line 19-20) use pass by reference.

2. The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr. The project does not use raw pointers.
Classes use a lot of smart pointer as member variables.
It use unique_ptr for _capture member on Application class (Application.h, line 16), _capture and _faceDetector on CustomVideoCapture class (CustomVideoCapture.h, line 19-20), _faceCascade and _eyeCascade on FaceDetector class (FaceDetector.h, line 21-22)

###Concurrency
No need for multiple threads in this simple project.

1. A mutex or lock (e.g. std::lock_guard or `std::unique_lock) is used to protect data that is shared across multiple threads in the project code.
The application class use a std::lock_guard on Start method for avoid multiple capture start (Application.cpp, line 17).