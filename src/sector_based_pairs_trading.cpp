#include "sector_based_pairs_trading.h"
#include "openbb_api.h"
#include <iostream>
#include <fstream>

void runSectorBasedPairsTrading() {
    std::cout << "Running Sector-Based Pairs Trading Strategy..." << std::endl;
    
    OpenBBAPI api(OPENBB_API_KEY);
    auto data_stock1 = api.fetchData("XOM", "2020-01-01", "2023-01-01");
    auto data_stock2 = api.fetchData("CVX", "2020-01-01", "2023-01-01");

    // Calculate trading signals (simplified example)
    std::vector<double> spreads;
    for (size_t i = 0; i < data_stock1.size(); ++i) {
        double spread = std::stod(data_stock1[i]) - std::stod(data_stock2[i]);
        spreads.push_back(spread);
    }

    // Save results
    std::ofstream results("results/sector_based_pairs_trading_results.txt");
    for (const auto& spread : spreads) {
        results << spread << std::endl;
    }
    results.close();

    std::cout << "Sector-Based Pairs Trading Strategy Completed" << std::endl;
}
