//author @Nishant

/*
Modify the program of Exercise 4 with a trackbar slider control from
Example 2-4 so that the user can dynamically vary the pyramid downsampling
reduction level by factors of between 2 and 8. You may skip writing this to disk,
but you should display the results.
*/

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int n; //global variable for the variation in factor of downsampling

void onTrackBar(int pos, void *){
    int n = pos;
}

int main(int argc, char** argv){
    VideoCapture cap(0);
    
    if(!cap.isOpened()){
        cout << "ERROR";
        return -1;
    }
    int s1 = 2;
    createTrackbar("Position", "Ex2", &s1, 8, onTrackBar);

    while(true){    
        Mat frame, output;
        
        cap >> frame;

        pyrDown(frame, output, Size((frame.col+1)/n), (frame.row+1)/n);

        imshow("ORIGINAL", frame);

        imshow("AFTER APPLYING pyrDown", output);

        waitKey(33);
    }
    destroyAllWindows();
    return 0;
}