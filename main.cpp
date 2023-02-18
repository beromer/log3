#include <string>
#include "log3.hpp"

int main() {
    std::string name{"Brian"};
    Log3::rank = 0;
    Log3::colorable = true;
    Log3::verbosity = 5;
    Log3::info("Hello {} from rank {}!",name,Log3::rank);
    Log3::error("Can't find rank {}!",Log3::rank);
    Log3::errorRank(0,"Can't find rank {}!",Log3::rank);
    Log3::errorAll("Can't find rank {}!",Log3::rank);
    Log3::warning("Can't find rank {}!",Log3::rank);
    Log3::warningRank(0,"Can't find rank {}!",Log3::rank);
    Log3::warningAll("Can't find rank {}!",Log3::rank);
    Log3::message("Can't find rank {}!",Log3::rank);
    Log3::messageRank(0,"Can't find rank {}!",Log3::rank);
    Log3::messageAll("Can't find rank {}!",Log3::rank);
    Log3::debug("Can't find rank {}!",Log3::rank);
    Log3::debugRank(0,"Can't find rank {}!",Log3::rank);
    Log3::debugAll("Can't find rank {}!",Log3::rank);

    Log3::rank = 1;
    Log3::colorable = true;
    Log3::verbosity = 5;
    Log3::info("Hello {} from rank {}!",name,Log3::rank);
    Log3::infoAll("Hello from non-zero rank!");
    Log3::error("Can't find rank {}!",Log3::rank);

    Log3::rank = 0;
    Log3::colorable = false;
    Log3::verbosity = 5;
    Log3::info("Hello {} from rank {}!",name,Log3::rank);
    Log3::error("Can't find rank {}!",Log3::rank);

    Log3::rank = 0;
    Log3::colorable = true;
    Log3::verbosity = 1;
    Log3::info("Hello {} from rank {}!",name,Log3::rank);
    Log3::error("Can't find rank {}!",Log3::rank);

    Log3::rank = 3;
    Log3::colorable = true;
    Log3::verbosity = 5;
    Log3::info("Hello {} from rank {}!",name,Log3::rank);
    Log3::infoRank(3,"Testing Rank 3 '{}'",name);
    Log3::infoRank(5,"Testing Rank 5 '{}'",name);
    Log3::error("Can't find rank {}!",Log3::rank);

    Log3::rank = 0;
    Log3::banner("Logging Complete!\n");

    return 0;
}
