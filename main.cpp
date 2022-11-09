#include <string>
#include "log3.hpp"

int main() {
    Log3::rank = 0;
    Log3::info(std::string("Hello!"));
    const auto me = []{return Log3::rank+1;}();
    Log3::info(me);
    return 0;
}
