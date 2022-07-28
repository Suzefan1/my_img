①初始化ROS节点
作用：ROS初始化
参数：1、argc------封装实参的个数（n+1）
          2、argv------封装参数的数组（字符串）
          3、name-----为节点命名，具有唯一性
          4、options---节点启动选项
返回值：void
使用：1、argc 与 argv的使用、
	如果按照ROS中的特定格式传入实参，呢么ROS可以加以使用，比如用来设置全局参数，给节点命名
          2、options的使用
	节点名称需要保证唯一，会导致一个问题：同个节点不能重复使用
	需求：特定场景下，需要一个节点多次启动且能正常运行
	使用时：ros::init_options::AnonyumousName
	解决：设置启动项；创建ROS节点时，会在用户自定义节点名称后产生随机数，避免重名问题


②话题服务对象
作用：创建发布者对象
模板：被发布消息的类型
参数：1、话题名称
         2、队列长度
         3、latch（可选）    如果设置为true，会保存发布方的最后一条消息，并且新的订阅对象连接到发布方时，发布方会将这条消息发送给订阅者
使用：latch设置为true的作用。以静态地图发布为例子，方案一：可以使用固定频率发送地图数据，但是效率低。方案二：可以将地图发布对象的latch设置为true，并且发布方只发布一次数据，每当订阅者连接时，将地图数据发送给订阅者（只发送一次），这样提高了数据的发送效率。

③回旋函数
ros::spin() 是进入了循环执行回调函数，而 ros::spinOnce() 只会执行一次回调函数(没有循环)，在 ros::spin() 后的语句不会执行到，而 ros::spinOnce() 后的语句可以执行。

④时间---时刻
now函数会将当前时刻封装并返回
当前时刻：now被调用执行的那一刻
参考系：1970年1月1日 00：00：00
ros::Time right_now = ros::Time::now();
ros_INFO("当前时刻:%.2f",right_now.toSec());
ros_INFO("当前时刻:%d",right_now.sec);
/////////////////
ros::Time t1(20,2323232323);//设定指定时刻
ros_INFO("t1= %.2f",t1.tosec());
ros::Time t2(100.333);//设定指定时刻
ros_INFO("t2= %.2f",t1.tosec());

时间---持续时间
ros::Duration du(4.5);
du.sleep();

时间---运算
1、获取开始执行的时刻
ros::Time begin =ros::Time::now();
2、模拟运行时间
ros::Duration du1(5);
3、计算结束时刻 = 开始+持续时间
ros::Time stop =begin +du1;

时间---运行频率
ros::Rate rate (1);

时间---定时器//定时器启动后要自己调用ros::spin()
ros::Timer = nh.createTimer(ros::Duration(1),cb);//时间间隔，回调函数，是否一次性，自动启动（当设置为false需要手动调用timer.start())
void cb(const ros::TimerEvent& event)
{
	ROS_INFO("");
}

⑤节点生命周期
ros::ok();
ros::shutdown();

⑥其他类型
ROS_DEBUG("调试信息")；//不会打印在控制台
ROS_INFO("一般信息")；
ROS_WARN("警告信息")；
ROS_ERROR("错误信息")；
ROS_FATAL("严重信息")；