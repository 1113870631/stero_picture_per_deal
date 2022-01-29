#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include <string.h>
int main(void)
{

   string base="../";
   string name;


    int j=8;
    for(int i=0;i<j;i++)
    {
      
     name=std::to_string(i)+".jpg";
    //cout<<name<<endl;
     Mat tmp = imread(base+name);
     Mat tmp2=Mat(tmp.rows,tmp.cols/2,CV_8UC3);  
     Mat tmp3=Mat(tmp.rows,tmp.cols/2,CV_8UC3);  
     tmp2=tmp.colRange(0,tmp.cols/2);
     tmp3=tmp.colRange(tmp.cols/2+1,tmp.cols);
     //imshow("win",tmp);
     imwrite("out/"+name+"_R.jpg",tmp2);
     imwrite("out/"+name+"_L.jpg",tmp3);

    }
    
    waitKey(0);

    return 0;

}