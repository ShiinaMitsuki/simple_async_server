#ifndef __SIMPLE_ASYNC_SVR_PUBLIC__H
#define __SIMPLE_ASYNC_SVR_PUBLIC__H 

#include <boost/asio.hpp> 
#include <boost/shared_ptr.hpp> 
#include <boost/scoped_ptr.hpp> 
#include <boost/bind.hpp> 
#include <boost/format.hpp> 
#include <list> 
#include <string> 
#include <exception> 
#include <iostream>  

using namespace boost::asio;
//using boost::shared_ptr;
using boost::bind;
using boost::format;
using std::cout;
using std::endl;

#define SHARED_PTR(__type) boost::shared_ptr<__type>
#define NEW_SHARED_PTR(__type, ...) SHARED_PTR(__type)(new __type(__VA_ARGS__))

#define IO_SERVICE_PTR SHARED_PTR(io_service)


#endif /* ifndef __SIMPLE_ASYNC_SVR_PUBLIC__H */
