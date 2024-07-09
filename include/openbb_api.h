#ifndef OPENBB_API_H
#define OPENBB_API_H

#include <string>
#include <vector>

class OpenBBAPI {
public:
    OpenBBAPI(const std::string& apiKey);
    std::vector<std::string> fetchData(const std::string& symbol, const std::string& startDate, const std::string& endDate);

private:
    std::string apiKey;
};

#endif // OPENBB_API_H
