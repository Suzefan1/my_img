#includerosros.h
#includeplumbing_headhello.h

namespace hello_ns{
    void MyHellorun()
    {
        ROS_INFO(run函数执行);
    }
}

int main(int argc,char argv[])
{   setlocale(LC_ALL,);
    rosinit(argc,argv,hello_head);
    hello_nsMyHello myHello;
    myHello.run();
    return 0;
}