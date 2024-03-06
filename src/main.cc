#include <memory>
#include <thread>
#include "types.hpp"

#include "io.hpp"

int main(int argc, char** argv) {
    std::shared_ptr<Types::Robot_set> robot_set = std::make_shared<Types::Robot_set>;

    Io::Socket_interface socket_intrf;
    Io::Io_handler io(robot_set);

    std::thread io_thread(&Io::Io_handler::task, &io);
    std::thread socket_thread(&Io::Socket_interface::task, &socket_intrf);
    io_thread.join();
}
