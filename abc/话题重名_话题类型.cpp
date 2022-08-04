#include "ros/ros.h"
#include "std_msgs/String.h"
int main(int argc,char *argv[])
{
    ros::init(argc,argv,"hello");
    ros::NodeHandle nh;
    //1、全局 ---话题名称需要以/开头，这种情况和下和节点（命名空间没有关系
    // 2、相对  ---非/开头
    //3、私有 ---需要创建特定nodehandle nh("~"),需要注意：如果私有的NH创建的话题以/ 开 头（全局话题），生成的话题是全局的非私有
    //全局话题优先界别最高
  
     // ros::Publisher pub =nh.advertise<std_msgs::String>("/yuyy/chatter",1000);
     
    //ros::Publisher pub =nh.advertise<std_msgs::String>("yyy/chatter",1000);
    
    //ros::NodeHandle nh("~");
    ros::Publisher pub =nh.advertise<std_msgs::String>("chatter",1000);
    while(ros::ok())
    {

    }
    return 0;
}