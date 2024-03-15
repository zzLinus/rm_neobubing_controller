#ifndef __SOCKET_INTERFACE__
#define __SOCKET_INTERFACE__

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstdio>
#include <cstring>
#include <memory>

#include "types.hpp"

namespace Io
{

    class Client_socket_interface
    {
       public:
        Client_socket_interface(std::shared_ptr<Types::Robot_set> robot_set);
        ~Client_socket_interface();
        void task();   // send thread
		//void task1();  // send thread
        void task2();  // read thread
        inline void pack();

       private:
        int64_t port_num, sockfd;
        sockaddr_in serv_addr, cli_addr;
        struct hostent *server;
        char buffer[256];
		char buffer_w[256];
        char buffer_r[256];
        std::string host_name;
        std::shared_ptr<Types::Robot_set> p_robot_set;

       public:
       private:
    };
}  // namespace Io

#endif
