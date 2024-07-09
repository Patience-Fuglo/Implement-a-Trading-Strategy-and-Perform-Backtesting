#include "dual_class_arbitrage.h"
#include "openbb_api.h"
#include <iostream>
#include <fstream>

void runDualClassArbitrage() {
    std::cout << "Running Dual Class Arbitrage Strategy..." << std::endl;
    
    OpenBBAPI api(OPENBB_API_KEY);
    auto data_GOOG = api.fetchData("GOOG", "2020-01-01", "2023-01-01");
    auto data_GOOGL = api.fetchData("GOOGL", "2020-01-01", "2023-01-01");

    // Calculate arbitrage opportunities (simplified example)
    std::vector<double> arbitrage_opportunities;
    for (size_t i = 0; i < data_GOOG.size(); ++i) {
        double spread = std::stod(data_GOOG[i]) - std::stod(data_GOOGL[i]);
        arbitrage_opportunities.push_back(spread);
    }

    // Save results
    std::ofstream results("results/dual_class_arbitrage_results.txt");
    for (const auto& spread : arbitrage_opportunities) {
        results << spread << std::endl;
    }
    results.close();

    std::cout << "Dual Class Arbitrage Strategy Completed" << std::endl;
}
