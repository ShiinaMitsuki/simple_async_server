#ifndef __SOCKET_BASE__H
#define __SOCKET_BASE__H 

#include "simple_async_svr_public.h" 
namespace simple_async_server
{
    /** 定义socket_base基类方法与属性
	 *  
	 */
	class socket_base  
	{ 
	public: 
	    socket_base(IO_SERVICE_PTR io); 
	    virtual ~socket_base();

    public:
        /**
        * @brief: 返回ip地址
        *
        * @param: 
        *
        * @return:         std::string
        */
        virtual std::string ip() = 0;

        /**
        * @brief: 返回端口号
        *
        * @param: 
        *
        * @return: uint16_t
        */
        virtual uint16_t port() = 0;
	public:
        /**
        * @brief: 开始工作！
        *
        * @param: IO_SERVICE_PTR io io抽象
        *
        * @return: bool
        */
        virtual bool start_work(IO_SERVICE_PTR io) = 0;
	private: 
        IO_SERVICE_PTR  m_io;
	}; 

	/** 定义socket_tcp基类方法与属性
	 * 
	 */
	class socket_base_tcp : public socket_base
	{ 
	public: 
	    typedef SHARED_PTR(ip::tcp::socket) socket_tcp_ptr;

	    socket_base_tcp(IO_SERVICE_PTR io); 
	    virtual ~socket_base_tcp();
        
    public:
        socket_tcp_ptr socket();

        virtual std::string ip();

        virtual uint16_t port();

        virtual bool start_work(IO_SERVICE_PTR io);
	protected:

	private: 
	    socket_tcp_ptr m_socket;
	}; 

	/** 定义socket_base_udp基类方法与属性
	 * 
	 */
	class socket_base_udp : public socket_base
	{ 
	public: 
	    typedef SHARED_PTR(ip::udp::socket) socket_udp_ptr;

	    socket_base_udp(IO_SERVICE_PTR io); 
	    virtual ~socket_base_udp();
    public:
        socket_udp_ptr socket();

        virtual std::string ip();

        virtual uint16_t port();
        
        virtual bool start_work(IO_SERVICE_PTR io);
	protected:

	private: 
	    socket_udp_ptr m_socket;
	}; 
}
#endif /* ifndef __SOCKET_BASE__H */
