#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include <string.h>
#include <opencv2/imgproc/imgproc_c.h>

Rect validPixROI1 ;
Rect validPixROI2 ;

Mat cameraMatrix1 = Mat::zeros(3, 3, CV_64F);
Mat cameraMatrix2 = Mat::zeros(3, 3, CV_64F);
Mat distCoeffs1 = Mat::zeros(5, 1, CV_64F);
Mat distCoeffs2 = Mat::zeros(5, 1, CV_64F);
Mat R = Mat::zeros(3, 3, CV_64F);
Mat T = Mat::zeros(3, 1, CV_64F);
Mat P1 = Mat::zeros(3, 4, CV_64F);
Mat P2 = Mat::zeros(3, 4, CV_64F);
Mat R1 = Mat::zeros(3, 3, CV_64F);
Mat R2 = Mat::zeros(3, 3, CV_64F);
Mat Q;
Mat RR=Mat::zeros(3, 3, CV_64F);
Mat map11,map21,map12,map22;
void permater(int x)
{
    if(x==1)
    {
         //相机一 内参
    cameraMatrix1.at<double>(0, 0) = 1.3513e+03;
    cameraMatrix1.at<double>(0, 1) = 0;
    cameraMatrix1.at<double>(0, 2) = 628.1604;

    cameraMatrix1.at<double>(1, 0) = 0;
    cameraMatrix1.at<double>(1, 1) = 1.3511e+03;
    cameraMatrix1.at<double>(1, 2) = 383.6009;

    cameraMatrix1.at<double>(2, 0) = 0;
    cameraMatrix1.at<double>(2, 1) = 0;
    cameraMatrix1.at<double>(2, 2) = 1;
    //相机二 内参
    cameraMatrix2.at<double>(0, 0) = 1.3556e+03;
    cameraMatrix2.at<double>(0, 1) = 0;
    cameraMatrix2.at<double>(0, 2) = 691.5902;

    cameraMatrix2.at<double>(1, 0) = 0;
    cameraMatrix2.at<double>(1, 1) = 1.3555e+03;
    cameraMatrix2.at<double>(1, 2) = 412.2236;

    cameraMatrix2.at<double>(2, 0) = 0;
    cameraMatrix2.at<double>(2, 1) = 0;
    cameraMatrix2.at<double>(2, 2) = 1;
    //相机一   畸变参数
     distCoeffs1.at<double>(0, 0) = -0.4356; // k1
    distCoeffs1.at<double>(1, 0) = 0.2390;  // k2
    distCoeffs1.at<double>(2, 0) = 0; //p1
    distCoeffs1.at<double>(3, 0) = 0; //p2
    distCoeffs1.at<double>(4, 0) = 0; //k3
    //相机二  畸变参数 
     distCoeffs2.at<double>(0, 0) = -0.4401; // k1
    distCoeffs2.at<double>(1, 0) = 0.2626;  // k2
    distCoeffs2.at<double>(2, 0) = 0; //p1
    distCoeffs2.at<double>(3, 0) = 0; //p2
    distCoeffs2.at<double>(4, 0) = 0; //k3

    //旋转转换矩阵
    R.at<double>(0, 0) = 1;
    R.at<double>(0, 1) = -1.9888e-04;
    R.at<double>(0, 2) = -0.0061;

    R.at<double>(1, 0) = -2.2428e-04;
    R.at<double>(1, 1) = 1;
    R.at<double>(1, 2) = -0.0042;

    R.at<double>(2, 0) = 0.0061;
    R.at<double>(2, 1) = 0.0042;
    R.at<double>(2, 2) = 1;
    //平移
    T.at<double>(0, 0) = 60.0013;
    T.at<double>(1, 0) = -0.1181;
    T.at<double>(2, 0) = 0.3540;
    }
    else{
         //相机一 内参
    cameraMatrix1.at<double>(0, 0) = 453.3683;
    cameraMatrix1.at<double>(0, 1) = 0;
    cameraMatrix1.at<double>(0, 2) = 159.6383;

    cameraMatrix1.at<double>(1, 0) = 0;
    cameraMatrix1.at<double>(1, 1) = 453.2678;
    cameraMatrix1.at<double>(1, 2) = 133.7621;

    cameraMatrix1.at<double>(2, 0) = 0;
    cameraMatrix1.at<double>(2, 1) = 0;
    cameraMatrix1.at<double>(2, 2) = 1;
    //相机二 内参
    cameraMatrix2.at<double>(0, 0) = 455.1281;
    cameraMatrix2.at<double>(0, 1) = 0;
    cameraMatrix2.at<double>(0, 2) = 176.3203;

    cameraMatrix2.at<double>(1, 0) = 0;
    cameraMatrix2.at<double>(1, 1) = 454.9641;
    cameraMatrix2.at<double>(1, 2) = 138.4340;

    cameraMatrix2.at<double>(2, 0) = 0;
    cameraMatrix2.at<double>(2, 1) = 0;
    cameraMatrix2.at<double>(2, 2) = 1;
    //相机一   畸变参数
     distCoeffs1.at<double>(0, 0) = -0.4352; // k1
    distCoeffs1.at<double>(1, 0) = 0.2152;  // k2
    distCoeffs1.at<double>(2, 0) = 0; //p1
    distCoeffs1.at<double>(3, 0) = 0; //p2
    distCoeffs1.at<double>(4, 0) = 0; //k3
    //相机二  畸变参数 
     distCoeffs2.at<double>(0, 0) = -0.4492; // k1
    distCoeffs2.at<double>(1, 0) = 0.3226;  // k2
    distCoeffs2.at<double>(2, 0) = 0; //p1
    distCoeffs2.at<double>(3, 0) = 0; //p2
    distCoeffs2.at<double>(4, 0) = 0; //k3

    //旋转转换矩阵
    R.at<double>(0, 0) = 1;
    R.at<double>(0, 1) = 1.7893e-04;
    R.at<double>(0, 2) = -0.0039;

    R.at<double>(1, 0) = -1.8727e-04;
    R.at<double>(1, 1) = 1;
    R.at<double>(1, 2) = -0.0021;

    R.at<double>(2, 0) = 0.0039;
    R.at<double>(2, 1) = 0.0021;
    R.at<double>(2, 2) = 1;
    //平移
    T.at<double>(0, 0) = 60.0013;
    T.at<double>(1, 0) = -0.1062;
    T.at<double>(2, 0) = 0.5076;
    }


}
int main(void)
{
  //设置参数
  permater(2);
   Size SZ=Size(320,240);
  //双目匹配
  stereoRectify( cameraMatrix1,  distCoeffs1,
                                  cameraMatrix2,  distCoeffs2,
                                SZ,  R,  T,
                                  R1,  R2,
                                  P1,  P2,
                                  Q,  CALIB_ZERO_DISPARITY,
                                  0,  SZ,&validPixROI1,&validPixROI2);// -1  为重要参数

      initUndistortRectifyMap( cameraMatrix1,  distCoeffs1,R1,P1,SZ, CV_32FC1,  map11,  map12 ); 
      initUndistortRectifyMap( cameraMatrix2,  distCoeffs2,R2,P2,SZ, CV_32FC1,  map21,  map22 ); 
      

  //打开图片进行remap
   string base="../";
   string name;


    int j=25;
    for(int i=0;i<j;i++)
    {
      
     name=std::to_string(i)+".jpg";
     //打开原图
     Mat tmp = imread(base+name);
     Mat tmp2=Mat(tmp.rows,tmp.cols/2,CV_8UC3);  
     Mat tmp3=Mat(tmp.rows,tmp.cols/2,CV_8UC3);  
     //原图分割
     tmp3=tmp.colRange(0,tmp.cols/2);
     tmp2=tmp.colRange(tmp.cols/2,tmp.cols);
     cout<<tmp2.cols<<endl;
     cout <<tmp3.cols<<endl;
     //remap
     Mat tmp4,tmp5,tmp6,tmp7;
     remap(tmp2,tmp4,map11,map12,INTER_LINEAR,BORDER_TRANSPARENT,0);
     remap(tmp3,tmp5,map21,map22,INTER_LINEAR,BORDER_TRANSPARENT,0);
     // 3 14
     if(i==5)
     {
         namedWindow("tmp4",WINDOW_FREERATIO);
         imshow("tmp4",tmp4);
         namedWindow("tmp5",WINDOW_FREERATIO);
         imshow("tmp5",tmp5);
        cout<<tmp4.size<<"\n"<<endl;
         cout<<tmp5.size<<"\n"<<endl;
         tmp6=tmp4.colRange(validPixROI1.x,validPixROI1.width+validPixROI1.x);
         tmp6=tmp6.rowRange(validPixROI1.y,validPixROI1.y+validPixROI1.height);
         tmp7=tmp5.colRange(validPixROI2.x,validPixROI2.width+validPixROI2.x);
         tmp7=tmp7.rowRange(validPixROI2.y,validPixROI2.y+validPixROI2.height);
         cout<<tmp6.size<<"\n"<<endl;
         cout<<tmp7.size<<"\n"<<endl;
         for(int p=0;p<20;p++)
         {
            if(40+p*40>tmp6.cols)
            break;
             line(tmp6,Point(0,40+p*40),Point(tmp6.cols,40+p*40),Scalar(0, 0, 255),1,8,0);
             line(tmp7,Point(0,40+p*40),Point(tmp6.cols,40+p*40),Scalar(0, 0, 255),1,8,0);
             

         }
         namedWindow("row",WINDOW_FREERATIO);
         imshow("row",tmp);
         namedWindow("lift",WINDOW_FREERATIO);
         imshow("lift",tmp7);
         namedWindow("right",WINDOW_FREERATIO);
         imshow("right",tmp6);
     }
     

    //rectangle(tmp4,validPixROI1.tl() , validPixROI1.br(), cv::Scalar(0, 255, 255), 2, 4);
     //rectangle(tmp5,validPixROI2.tl() , validPixROI2.br(), cv::Scalar(0, 255, 255), 2, 4);
     imwrite("./out/"+name+"_r"+".jpg",tmp5);
     imwrite("./out/"+name+"_l"+".jpg",tmp4);
      
   }
waitKey(0);

    return 0;
}