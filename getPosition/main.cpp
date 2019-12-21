/**********************************************************************************
 *  ProjectName:   getPosition
 *  Brief :            select two points of a rectangle and get the coordinates of the four corners
 *  Author:        mk90
 *  Time:            2019-12-18  11:06:04
 *  Blog:            https://me.csdn.net/weixin_44100850
 *
***********************************************************************************/
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

cv::Mat src;
cv::Mat backup;
void on_mouse(int event, int x, int y, int flags, void* );
cv::Point Point1;
cv::Point Point2;
int counter = 1;

int main()
{
    src  = cv::imread("/home/mk90/Documents/OTB/TB50/basketball/img/0001.jpg");
    src.copyTo(backup);
//    src  = cv::imread("/home/mk90/Documents/F1/CameraTracking_Ui/img/20191213-17:14:05/100.jpg");

    cv::namedWindow("image", cv::WINDOW_NORMAL);
    cv::setMouseCallback("image", on_mouse);
    cv::imshow("image", src);
    cv::waitKey(0);
    return 0;
}

//比较简单的方法，每次点击获得一个点的坐标位置
//void on_mouse(int event, int x, int y, int flags, void*){
//    if (event ==  cv::EVENT_LBUTTONDOWN){
//        cout << "x: " << x << " y: " << y << endl;
//    }
//}

//按照需要的格式，每点击两个点之后，把两个点组成的矩形框的四个点的坐标显示出来
void on_mouse(int event, int x, int y, int flags, void*){
    if (event ==  cv::EVENT_LBUTTONDOWN){
        if (counter == 2){
            Point2.x = x;
            Point2.y = y;
            cout << "leftTop, rightTop, leftBottom, rightBottom: "
                      << Point1.x << "," << Point1.y << ","
                      << Point2.x << "," << Point1.y << ","
                      << Point1.x << "," << Point2.y << ","
                      << Point2.x << "," << Point2.y << endl << endl;
            cv::Point leftTopCorner;
            cv::Point rightBottomCorner;
            leftTopCorner.x = min(Point1.x, Point2.x);
            leftTopCorner.y = min(Point1.y, Point2.y);
            rightBottomCorner.x = max(Point1.x, Point2.x);
            rightBottomCorner.y = max(Point1.y, Point2.y);
            cv::rectangle(src, leftTopCorner, rightBottomCorner, cv::Scalar(0, 255, 0), 1, cv::LINE_AA, 0);
            cv::imshow("image", src);
            backup.copyTo(src);
            counter =1;
            return;
        }
        else if (counter == 1) {
            Point1.x = x;
            Point1.y = y;
            cv::drawMarker(src, Point1, cv::Scalar(0, 255, 0), cv::MARKER_CROSS, 10, 1, cv::LINE_AA);
            cv::imshow("image", src);
            backup.copyTo(src);
            counter++;
            cout << "You've selected one point, now select the second! " << endl;
        }
    }
}
