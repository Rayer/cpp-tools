//
// Created by Rayer Tung on 15/07/2017.
//

#ifndef DAEMONIZER_DAEMONIZER_H
#define DAEMONIZER_DAEMONIZER_H

#include <string>

class IStrategy {
    std::string pid_file;
protected:
    IStrategy(std::string pid_file) {
        this->pid_file = pid_file;
    }
    virtual bool can_be_created() = 0;
};

class StopIfExist : IStrategy {
public:
    StopIfExist(const std::string &pid_file) : IStrategy(pid_file) {}
    virtual bool can_be_created() override {
        return true;
    }
};

class OverrideIfExist : IStrategy {
public:
    OverrideIfExist(const std::string &pid_file) : IStrategy(pid_file) {}
    virtual bool can_be_created() override {
        return true;
    }

};

class MultipleInstance : IStrategy {
public:
    MultipleInstance(const std::string &pid_file) : IStrategy(pid_file) {}
    virtual bool can_be_created() override {
        return true;
    }

};

template<typename Host>
class IDaemonHooks {
    virtual void before_start(Host& host) = 0;
    virtual void update(Host& host) = 0;
    virtual void cleanup(Host& host) = 0;
};


template<typename Host, typename Strategy = StopIfExist>
class Daemonizer : Strategy, IDaemonHooks<Host> {
protected:
    virtual Host* create_host() = 0;
public:
    Daemonizer(std::string pid_file) : Strategy(pid_file){

    }
};


#endif //DAEMONIZER_DAEMONIZER_H
