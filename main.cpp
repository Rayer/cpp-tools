#include <iostream>
#include "Daemonizer.h"

class HelloWorldService {
public:
    void on_service() {
        std::cout << "Hello World Daemon!" << std::endl;
    }
};

class HelloWorldDaemon : Daemonizer<HelloWorldService> {
public:
    HelloWorldDaemon(const std::string &pid_file) : Daemonizer(pid_file) {}

private:
    HelloWorldService *create_host() override {
        return nullptr;
    }
};

int main() {
    HelloWorldDaemon h("/tmp/pid.pid");
    return 0;
}