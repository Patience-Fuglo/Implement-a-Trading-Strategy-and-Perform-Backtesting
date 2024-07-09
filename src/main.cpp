#include <iostream>
#include "dual_class_arbitrage.h"
#include "bollinger_band_strategy.h"
#include "sector_based_pairs_trading.h"

int main() {
    std::cout << "Starting the Investment Thesis Project" << std::endl;
    
    // Dual Class Arbitrage Strategy
    runDualClassArbitrage();
    
    // Bollinger Band Strategy
    runBollingerBandStrategy();
    
    // Sector-Based Pairs Trading Strategy
    runSectorBasedPairsTrading();

    std::cout << "Investment Thesis Project Completed" << std::endl;
    return 0;
}
