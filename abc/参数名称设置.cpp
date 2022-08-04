#include rosros.h
int main(int argc,char argv[])
{
    rosinit(argc,argv,hello);
    rosNodeHandle nh;
    
        使用rosparam来设置参数
    
   1、全局
   rosparamset(radiusA,100);
   2、相对
   rosparamset(radiusA,100);
   3、私有
    rosparamset(~radiusA,100);
    

    
    使用NOdeandle设置参数
    
   nh.setParam(radius_nh_A,1000);全局，其他同
    return 0;
}
