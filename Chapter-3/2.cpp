//author @Nishant

/*
Compact matrix and vector types:
a. Using the cv::Mat33f and cv::Vec3f objects (respectively), create a 3 × 3
matrix and 3-row vector.
b. Can you multiply them together directly? If not, why not?
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv){
    Matx33f M(1, 2, 3, 4, 5, 6, 7, 8, 9); 

	Vec3f V (1,2,3);

    Mat A = Mat(M);
	Mat B = Mat(V);
	Mat AB1 = A*B;      //vector multiplication
	Mat AB2 = A.mul(B); //multiplication

    return 0;
}