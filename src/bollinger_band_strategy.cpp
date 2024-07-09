#include "bollinger_band_strategy.h"
#include "openbb_api.h"
#include <iostream>
#include <fstream>
#include <cmath>

void runBollingerBandStrategy() {
    std::cout << "Running Bollinger Band Strategy..." << std::endl;
    
    OpenBBAPI api(OPENBB_API_KEY);
    auto data = api.fetchData("AAPL", "2020-01-01", "2023-01-01");

    // Calculate Bollinger Bands (simplified example)
    const int period = 20;
    std::vector<double> sma;
    std::vector<double> upper_band;
    std::vector<double> lower_band;

    for (size_t i = period; i < data.size(); ++i) {
        double sum = 0;
        for (size_t j = i - period; j < i; ++j) {
            sum += std::stod(data[j]);
        }
        double avg = sum / period;
        sma.push_back(avg);

        double sum_sq_diff = 0;
        for (size_t j = i - period; j < i; ++j) {
            sum_sq_diff += std::pow(std::stod(data[j]) - avg, 2);
        }
        double stddev = std::sqrt(sum_sq_diff / period);
        upper_band.push_back(avg + 2 * stddev);
        lower_band.push_back(avg - 2 * stddev);
    }

    // Save results
    std::ofstream results("results/bollinger_band_strategy_results.txt");
    for (size_t i = 0; i < sma.size(); ++i) {
        results << sma[i] << "," << upper_band[i] << "," << lower_band[i] << std::endl;
    }
    results.close();

    std::cout << "Bollinger Band Strategy Completed" << std::endl;
}
