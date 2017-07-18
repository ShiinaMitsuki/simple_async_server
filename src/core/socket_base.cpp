#include "socket_base.h" 
namespace simple_async_server
{ 
     
    socket_base::socket_base(IO_SERVICE_PTR io)
	{
	}

	socket_base::~socket_base()
	{
	}
	////////////////////////////////////////////////////////////
	socket_base_tcp::socket_base_tcp(IO_SERVICE_PTR io)
	    : socket_base(io)
	{
        m_socket = NEW_SHARED_PTR(ip::tcp::socket, *io);
	}

    socket_base_tcp::socket_tcp_ptr socket_base_tcp::socket()
	{ 
	    return m_socket; 
	} 

    std::string socket_base_tcp:: ip()
    { 
        return socket()->remote_endpoint().address().to_string();
    } 
    
    uint16_t socket_base_tcp::port()
    {
       return (uint16_t)socket()->remote_endpoint().port();
    } 
    
	socket_base_tcp::~socket_base_tcp()
	{
	}

	bool socket_base_tcp::start_work(IO_SERVICE_PTR io)
	{
		return true;
	}
	////////////////////////////////////////////////////////////
	socket_base_udp::socket_base_udp(IO_SERVICE_PTR io)
	    : socket_base(io)
	{
        m_socket = NEW_SHARED_PTR(ip::udp::socket, *io);
	}

	socket_base_udp::~socket_base_udp()
	{
	}

    socket_base_udp::socket_udp_ptr socket_base_udp::socket()
	{ 
	    return m_socket;
	} 

    std::string socket_base_udp::ip()
    { 
        return socket()->remote_endpoint().address().to_string(); 
    } 

    u_int16_t socket_base_udp::port()
    { 
        return (uint16_t)socket()->remote_endpoint().port(); 
    } 

	bool socket_base_udp::start_work(IO_SERVICE_PTR io)
	{
		return true;
	}
};
