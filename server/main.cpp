#include "trading_exchange_server.h"
#include <fstream>

int main() {
    try {
        nlohmann::json j;
        std::ifstream ifs(CONFIG_PATH);
        if (!ifs.good()) {
            throw std::runtime_error("Error: Config file isn't open!");
        }
        ifs >> j;
        std::cout << j["SQLConnection"]["Host"] << std::endl;
        boost::asio::io_service io_service;
        TradingExchangeServer s(io_service);

        io_service.run();
    } catch (std::exception &e) {
        std::cerr << "Server exception: " << e.what() << "\n";
    }

    return 0;
}