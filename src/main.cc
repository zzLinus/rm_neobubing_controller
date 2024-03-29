#include <memory>
#include <thread>

#include "io.hpp"
#include "types.hpp"

int main(int argc, char** argv) {
    std::shared_ptr<Types::Robot_set> robot_set;
    robot_set = std::make_shared<Types::Robot_set>();

    Io::Client_socket_interface socket_intrf(robot_set);
    Io::Io_handler io(robot_set);

    std::thread io_thread(&Io::Io_handler::task, &io);
    std::thread socket_thread(&Io::Client_socket_interface::task, &socket_intrf);  // write
	 //std::thread socket_thread1(&Io::Client_socket_interface::task1, &socket_intrf); // write
    std::thread socket_thread2(&Io::Client_socket_interface::task2, &socket_intrf);  // read

    io_thread.join();
    socket_thread.join();
	 //socket_thread1.join();
    socket_thread2.join();
}
