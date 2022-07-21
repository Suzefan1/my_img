#include "ros/ros.h"
/*
    参数的演示查询
    实现：ros::NodeHandle

        param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        getParam(键,存储结果的变量)
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached键,存储结果的变量)--提高变量获取效率
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1，参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量

    二、ros::param ----- 与 NodeHandle 类似

*/
int main(int argc,char *argv[])
{   
    //设置编码
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"get_param_c");
    ros::NodeHandle nh;
    //ros::NodeHandle 
    //1、param
    double radius=nh.param("radius",0.5);
    ROS_INFO("radius = %.2f",radius);


    //2、getParam
    double radius2=0.0;
    bool result = nh.getParam("radius",radius2);
    if(result)
    {
        ROS_INFO("获取的半径是：%.2f",radius2);
    }
    else
    {
        ROS_INFO("结果不存在");
    }
    //3、getParamCached()与2类似，只是性能上有所提升，一般测试不出来
    int nh_int_value;
    nh.getParamCached("nh_int",nh_int_value);
    ROS_INFO("通过缓存获取数据:%d",nh_int_value);

    //4、getParaNames
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto && name :names)
    {
        ROS_INFO("遍历到的元素:%s",name.c_str());
    }
    //5、hasParam
    bool flag1=nh.hasParam("radius");
    bool flag2=nh.hasParam("radiuxxx");
    ROS_INFO("radius存在马 %d",flag1);
    ROS_INFO("radiuxxx存在马 %d",flag2);

    //6、searchParam(参数一，参数二)
    std::string key;
    nh.searchParam("radius",key);
    ROS_INFO("搜索结果：%s",key.c_str());

    //ros::param
    double radius_param=ros::param::param("radius",100.5);
    ROS_INFO("radius_param=%2f",radius_param);
    
    std::vector<std::string> names_param;
    ros::param::getParamNames(names_param);
    for(auto &&name : names_param)
    {
        ROS_INFO("键：%s",name.c_str());

    }

    return 0;
}