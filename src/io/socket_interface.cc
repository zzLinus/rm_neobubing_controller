#include "socket_interface.hpp"

#include <arpa/inet.h>

namespace Io
{
    void Client_socket_interface::task() {
        while (1) {
            printf("send to\n");
            bzero(buffer, 256);
            pack();
            int n = sendto(
                sockfd,
                (const char *)buffer,
                sizeof(Types::Robot_set),
                MSG_CONFIRM,
                (const struct sockaddr *)&serv_addr,
                sizeof(serv_addr));
            if (n > 0) {
                // printf("1 write to server\n");
            }
        }
    }

    // void Client_socket_interface::task1() {
    //     while (1) {
    //         bzero(buffer_w, 256);
    //         pack();
    //         int n = sendto(
    //             sockfd,
    //             (const char *)buffer_w,
    //             sizeof(Types::Robot_set),
    //             MSG_CONFIRM,
    //             (const struct sockaddr *)&serv_addr,
    //             sizeof(serv_addr));
    //         if (n > 0) {
    //             printf("2 write to server\n");
    //         }
    //     }
    // }

    void Client_socket_interface::task2() {
        while (1) {
            printf("read from\n");
            bzero(buffer_r, 256);
            socklen_t len = sizeof(serv_addr);
            int n = recvfrom(sockfd, buffer_r, 256, MSG_WAITALL, (struct sockaddr *)&serv_addr, &len);
            if (n > 0) {
                // printf("read from server\n");
            }

            // printf("%d %s\n", 2, buffer_r);
        }
    }

    inline void Client_socket_interface::pack() {
        for (size_t i = 0; i < sizeof(Types::Robot_set); i++) {
            buffer[i] = *((uint8_t *)p_robot_set.get() + i);
        }
    }

    Client_socket_interface::Client_socket_interface(std::shared_ptr<Types::Robot_set> robot_set)
        : port_num(51718),
          // host_name("zzarch"),
          // host_name("192.168.123.110"),
          host_name("192.168.123.110"),
          p_robot_set(robot_set) {
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            printf("ERROR opening socket");
        }

        serv_addr.sin_family = AF_INET;
        // bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
        // serv_addr.sin_addr.s_addr = inet_addr("192.168.123.110");
        serv_addr.sin_addr.s_addr = inet_addr("192.168.123.147");
        serv_addr.sin_port = htons(51718);
    }

    Client_socket_interface::~Client_socket_interface() {
    }
}  // namespace Io
