#ifndef __SIMPLE_ASIO_SERVER__H
#define __SIMPLE_ASIO_SERVER__H 

#include "simple_async_svr_public.h" 
#include "socket_base.h" 

/** 简易asio异步服务器;
 * 
 */

class simple_asio_server
{ 
public: 

#define IO_ACCEPTOR_PTR SHARED_PTR(ip::tcp::acceptor)
    typedef SHARED_PTR(simple_async_server::socket_base) socket_ptr;
    typedef std::list<socket_ptr> socket_list;

    enum proto_type
    { 
        proto_unknow = -1,
        proto_tcp    = 0,
        proto_udp    = 1
    }; 

public:
    simple_asio_server(); 
    virtual ~simple_asio_server();
public:
    /**
    * @brief 启动服务器 tcp/udp
    * 阻塞调用线程,直到任务队列中不再有任务
    * @param port 监听端口, proto 协议类型 proto_tcp proto_udp
    *
    * @return void
    */
    void start(uint16_t port, proto_type proto = proto_tcp);
    /**
    * @brief 停止
    *
    * @param 
    *
    * @return bool
    */
    bool stop();
protected:
    /**
    * @brief 以tcp方式启动服务器
    *
    * @param port 
    *
    * @return bool
    */
    bool start_tcp(uint16_t port);

    /**
    * @brief 以udp方式启动服务器
    *
    * @param port
    *
    * @return bool
    */
    bool start_udp(uint16_t port);
    /**
    * @brief 接受socket处理函数
    *
    * @param new_socket_ptr 远端socket error 错误码
    *
    * @return bool
    */
    virtual void on_accept(
            socket_ptr new_socket_ptr, 
            const boost::system::error_code& error);
private:
    /**
    * @brief 提交异步接收远端socket请求到任务队列 tcp 
    *
    * @param
    *
    * @return bool
    */
    void asyn_accept();
private: 
    IO_SERVICE_PTR  m_io_service_ptr;   // 先只使用一个io_service 
    IO_ACCEPTOR_PTR m_io_acc_ptr;       // 接受连接
    socket_list     m_socket_li;        // 接受的客户端socket链表   
    bool            m_running;          // 启动标志
    uint16_t        m_port;             // 监听端口
    proto_type      m_proto;            // 使用协议类型
}; 

#endif /* ifndef __SIMPLE_ASIO_SERVER__H */
