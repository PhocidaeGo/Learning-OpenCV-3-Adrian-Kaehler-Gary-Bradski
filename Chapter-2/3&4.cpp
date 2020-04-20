//author @Nishant

/*
3. Use the capture and store code in Example 2-11 together with the PyrDown()
code of Example 2-6 to create a program that reads from a camera and stores
downsampled color images to disk.

4. Modify the code in Exercise 3 and combine it with the window display code in
Example 2-2 to display the frames as they are processed.
*/

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv){
    VideoCapture cap(0);
    
    if(!cap.isOpened()){
        cout << "ERROR";
        return -1;
    }

    Size size(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(CAP_PROP_FPS);

    VideoWriter writer("output2.avi", CV_FOURCC('M','J','P','G'), fps, size);

    if(!writer.isOpened()){
        cout << "Cannot save the video to a file" << endl;
        cin.get(); //wait for any key press
    }

    while(true){    
        Mat frame, output;
        
        cap >> frame;

        pyrDown(frame, output);

        writer.write(output);

        imshow("ORIGINAL", frame);
        imshow("AFTER APPLYING pyrDown", output);

        waitKey(33);
    }
    destroyAllWindows();
    return 0;
}