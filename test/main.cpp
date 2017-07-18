///
/// 简易asio异步服务器框架
///

#include "asio_server.h" 

int main(int argc, char *argv[]) 
{
    simple_asio_server svr;

    svr.start(8000);

    return 0;		
}
