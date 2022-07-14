#include "ros/ros.h"
#include "std_msgs/String.h"
/*
实现流程:
        1.包含头文件
        ROS中文本类型--->std_msgs/String.h
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 句柄
        4.创建安订阅者 对象
        5.处理订阅的数据
        6.spin函数
*/
void domsg(const std_msgs::String::ConstPtr& msg)
{//通过msg获取并操作订阅到的数据
    ROS_INFO("催化订阅到的数据：%s", msg->data.c_str());

}
int main(int argc, char* argv[])//const去除
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "cuiHua");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("chatter", 10, domsg);
    ros::spin();//官方建议
    return 0;
}