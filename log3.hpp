#pragma once
#ifndef LOG3_HPP_INCLUDED
#define LOG3_HPP_INCLUDED

#include <iostream>
#include <ctime>
#include <iomanip>
#include <fmt/core.h>
#include <fmt/chrono.h>
#include <fmt/color.h>

struct Log3{

private:
    inline static std::string msgFormat{"[{}] {:>6}: {}\n"};
    inline static std::string msgFormatR{"[{}] {:>6}: ({}) {}\n"};
    // Basic Functions
    static std::string getTime(){
        std::time_t time = std::time(nullptr);
        return fmt::format("{:%Y-%m-%d %H:%M:%S}",fmt::localtime(time));
    }

    static void vlog(fmt::text_style style, const std::string& levelName, fmt::string_view format, fmt::format_args args){
        if (colorable)
            fmt::print(style,msgFormat,getTime(),levelName,fmt::vformat(format,args));
        else
            fmt::print(msgFormat,getTime(),levelName,fmt::vformat(format,args));
        std::cout << std::flush;
    }

    static void vlog(const std::string& levelName, fmt::string_view format, fmt::format_args args){
        fmt::print(msgFormat,getTime(),levelName,fmt::vformat(format,args));
        std::cout << std::flush;
    }

    static void vlogRank(fmt::text_style style, const std::string& levelName, fmt::string_view format, fmt::format_args args){
        if (colorable)
            fmt::print(style, msgFormatR,getTime(),levelName,rank,fmt::vformat(format,args));
        else
            fmt::print(msgFormatR,getTime(),levelName,rank,fmt::vformat(format,args));
        std::cout << std::flush;
    }

    static void vlogRank(const std::string& levelName, fmt::string_view format, fmt::format_args args){
        fmt::print(msgFormatR,getTime(),levelName,rank,fmt::vformat(format,args));
        std::cout << std::flush;
    }

public:
    // properties
    inline static int rank = 0;
    inline static int verbosity = 5;
    inline static bool colorable = true;

    // Error Logging Functions
    template<typename S, typename... Args>
    static void error(const S& format, Args&&... args){
        if (rank !=0) return;
        if (verbosity < 1) return;
        vlog(fmt::emphasis::bold | fmt::fg(fmt::color::red),"ERROR",format, fmt::make_format_args(args...));
    }
    template<typename S, typename... Args>
    static void errorAll(const S& format, Args&&... args){
        if (verbosity < 1) return;
        vlogRank(fmt::emphasis::bold | fmt::fg(fmt::color::red),"ERROR",format, fmt::make_format_args(args...));
    }
    template<typename S, typename... Args>
    static void errorRank(const int r, const S& format, Args&&... args){
        if (rank !=r) return;
        if (verbosity < 1) return;
        vlogRank(fmt::emphasis::bold | fmt::fg(fmt::color::red),"ERROR",format, fmt::make_format_args(args...));
    }

    // Warning Logging Functions
    template<typename S, typename... Args>
    static void warning(const S& format, Args&&... args){
        if (rank !=0) return;
        if (verbosity < 2) return;
        vlog(fmt::emphasis::bold | fmt::fg(fmt::color::yellow),"WARNING",format, fmt::make_format_args(args...));
    }
    template<typename S, typename... Args>
    static void warningAll(const S& format, Args&&... args){
        if (verbosity < 2) return;
        vlogRank(fmt::emphasis::bold | fmt::fg(fmt::color::yellow),"WARNING",format, fmt::make_format_args(args...));
    }
    template<typename S, typename... Args>
    static void warningRank(const int r, const S& format, Args&&... args){
        if (rank !=r) return;
        if (verbosity < 2) return;
        vlogRank(fmt::emphasis::bold | fmt::fg(fmt::color::yellow),"WARNING",format, fmt::make_format_args(args...));
    }

    // Message Logging Functions
    template<typename S, typename... Args>
    static void message(const S& format, Args&&... args){
        if (rank !=0) return;
        if (verbosity < 3) return;
        vlog(fmt::emphasis::bold | fmt::fg(fmt::color::blue),"MESSAGE",format, fmt::make_format_args(args...));
    }
    template<typename S, typename... Args>
    static void messageAll(const S& format, Args&&... args){
        if (verbosity < 3) return;
        vlogRank(fmt::emphasis::bold | fmt::fg(fmt::color::blue),"MESSAGE",format, fmt::make_format_args(args...));
    }
    template<typename S, typename... Args>
    static void messageRank(const int r, const S& format, Args&&... args){
        if (rank !=r) return;
        if (verbosity < 3) return;
        vlogRank(fmt::emphasis::bold | fmt::fg(fmt::color::blue),"MESSAGE",format, fmt::make_format_args(args...));
    }

    // Info Logging functions
    template<typename S, typename... Args>
    static void info(const S& format, Args&&... args){
        if (rank !=0) return;
        if (verbosity < 4) return;
        vlog("INFO",format, fmt::make_format_args(args...));
    }
    template<typename S, typename... Args>
    static void infoAll(const S& format, Args&&... args){
        if (verbosity < 4) return;
        vlogRank("INFO",format, fmt::make_format_args(args...));
    }
    template<typename S, typename... Args>
    static void infoRank(const int r, const S& format, Args&&... args){
        if (rank !=r) return;
        if (verbosity < 4) return;
        vlogRank("INFO",format, fmt::make_format_args(args...));
    }

    // Debug Logging Functions
    template<typename S, typename... Args>
    static void debug(const S& format, Args&&... args){
        if (rank !=0) return;
        if (verbosity < 5) return;
        vlog(fmt::emphasis::bold | fmt::fg(fmt::color::purple),"DEBUG",format, fmt::make_format_args(args...));
    }
    template<typename S, typename... Args>
    static void debugAll(const S& format, Args&&... args){
        if (verbosity < 5) return;
        vlogRank(fmt::emphasis::bold | fmt::fg(fmt::color::purple),"DEBUG",format, fmt::make_format_args(args...));
    }
    template<typename S, typename... Args>
    static void debugRank(const int r, const S& format, Args&&... args){
        if (rank !=r) return;
        if (verbosity < 5) return;
        vlogRank(fmt::emphasis::bold | fmt::fg(fmt::color::purple),"DEBUG",format, fmt::make_format_args(args...));
    }

    // Banner Logging Functions
    template<typename S, typename... Args>
    static void banner(const S& format, Args&&... args){
        if (rank !=0) return;
        fmt::print(fmt::emphasis::bold | fmt::fg(fmt::color::green),"[{}] {}",getTime(),fmt::vformat(format, fmt::make_format_args(args...)));
    }
};

#endif // LOG3_HPP_INCLUDED
