#include "socket_interface.hpp"

namespace Io
{
    void Client_socket_interface::task() {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            printf("ERROR opening socket");
        }
        server = gethostbyname(host_name.c_str());
        if (server == NULL) {
            fprintf(stderr, "ERROR, no such host\n");
            exit(0);
        }
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(port_num);

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            printf("ERROR connecting");
        }

        int i = 0;
        while (1) {
            bzero(buffer, 256);
            pack();
            int n = write(sockfd, buffer, sizeof(Types::Robot_set));

            if (n < 0) {
                printf("ERROR writing to socket");
            }

            printf("%d %s\n", 1, buffer);
        }
    }

    void Client_socket_interface::task2() {
        while (1) {
            bzero(buffer, 256);
            int n = read(sockfd, buffer, 255);

            if (n < 0) {
                printf("ERROR reading from socket");
            }

            printf("%d %s\n", 2, buffer);
        }
    }

    inline void Client_socket_interface::pack() {
        for (size_t i = 0; i < sizeof(Types::Robot_set); i++) {
            // printf("%d\n", *((uint8_t *)p_robot_set.get() + i));
            buffer[i] = *((uint8_t *)p_robot_set.get() + i);
        }
    }

    Client_socket_interface::Client_socket_interface(std::shared_ptr<Types::Robot_set> robot_set)
        : port_num(51718),
          //host_name("zzarch"),
		   host_name("192.168.123.110"),
          // host_name("192.168.123.82"),
          p_robot_set(robot_set) {
    }

    Client_socket_interface::~Client_socket_interface() {
    }
}  // namespace Io
