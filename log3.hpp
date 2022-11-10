#pragma once
#ifndef LOG3_HPP_INCLUDED
#define LOG3_HPP_INCLUDED

#include <iostream>
#include <ctime>
#include <iomanip>
#include <fmt/core.h>
#include <fmt/chrono.h>

struct Log3{
    static std::string getTime(){
        std::time_t time = std::time(nullptr);
        return fmt::format("{:%Y-%m-%d %H:%M:%S}",fmt::localtime(time));
    }
    inline static int rank = 0;
    template<typename T>
    static void info(T message){
        std::cout << fmt::format("[{}] INFO: {}",getTime(),message) << std::endl;
    }
};

#endif // LOG3_HPP_INCLUDED
