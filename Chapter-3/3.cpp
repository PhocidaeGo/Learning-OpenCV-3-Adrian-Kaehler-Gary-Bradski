//author @Nishant

/*
Compact matrix and vector template types:
a. Using the cv::Mat<> and cv::Vec<> templates (respectively), create a 3 × 3
matrix and 3-row vector.
b. Can you multiply them together directly? If not, why not?
c. Try type-casting the vector object to a 3 × 1 matrix, using the cv::Mat<> tem‐
plate. What happens now?
*/

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat_<float> M2(3,3);

	M2.at<float>(0,0)=1;  
	M2.at<float>(0,1)=2;  
	M2.at<float>(0,2)=3;  
	M2.at<float>(1,0)=4;  
	M2.at<float>(1,1)=5;  
	M2.at<float>(1,2)=6;  
	M2.at<float>(1,0)=4;  
	M2.at<float>(1,1)=5;  
	M2.at<float>(1,2)=6;

	Vec<float,3> V2(1,2,3);

    //b. It cannot be,becase M2 and V2 are not in the same type
	//c. It can be  multiplied by type-casting the vector object to a 3 × 1 matrix(becasue Mat_ is just a type of Mat)
	Mat B = Mat(V2);
	Mat AB3 = M2*B;      //vector multiplication
	Mat AB4 = M2.mul(B); //multiplication
	waitKey();
    return 0;
}