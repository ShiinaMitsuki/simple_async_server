#include "asio_server.h"

simple_asio_server::simple_asio_server()
{
    m_running        = false;
    m_port           = 0;
    m_proto          = proto_unknow;
    m_io_acc_ptr     = nullptr;
    m_io_service_ptr = NEW_SHARED_PTR(io_service);
}

simple_asio_server::~simple_asio_server()
{
}

bool simple_asio_server::stop()
{
	return true;
}

void simple_asio_server::start(uint16_t port, proto_type proto)
{
    if (m_running)
    {
        throw format("Server is Running on Port:%d") % m_port;
    } 

    if (proto == proto_tcp)
    {
        m_running = start_tcp(port); 
    } 
    else 
    {
        m_running = start_udp(port); 
    } 
    
    if (m_running)
    {
        m_port  = port;
        m_proto = proto;
        m_io_service_ptr->run();
    } 
}

bool simple_asio_server::start_tcp(uint16_t port)
{
    ip::tcp::endpoint ep(
            ip::tcp::v4(),
            port);
    
    if (m_io_acc_ptr == nullptr)
    {
        m_io_acc_ptr = NEW_SHARED_PTR(ip::tcp::acceptor, *m_io_service_ptr, ep);
        asyn_accept();
    } 

	return true;
}

bool simple_asio_server::start_udp(uint16_t port)
{
    // ToDo...
	return true;
}

void simple_asio_server::asyn_accept()
{
    // new tcp remote socket
    SHARED_PTR(simple_async_server::socket_base_tcp) new_socket_ptr = NEW_SHARED_PTR(
            simple_async_server::socket_base_tcp, m_io_service_ptr);

    m_io_acc_ptr->async_accept(
        *(new_socket_ptr->socket()),
        bind(&simple_asio_server::on_accept, this, new_socket_ptr, _1));
}

void simple_asio_server::on_accept(
		socket_ptr new_socket_ptr, 
		const boost::system::error_code& error)
{
    if (error)
    {
        // handle error
    }
    else 
    {
        cout << format("accept client at %s:%d") % new_socket_ptr->ip() % new_socket_ptr->port() << endl;
        new_socket_ptr->start_work(m_io_service_ptr); 
        m_socket_li.push_back(new_socket_ptr);
        asyn_accept();
    } 
}

