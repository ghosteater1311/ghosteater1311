#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

struct Record {
    std::string date;
    int count;
};

bool compareDates(const Record& r1, const Record& r2) {
    return r1.date < r2.date;
}

int main() {
    std::map<std::string, int> dateCounts;

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "*") break;

        std::istringstream iss(line);
        std::string date;
        iss >> date; 
        dateCounts[date]++;
    }

    std::vector<Record> records;
    for (const auto& entry : dateCounts) {
        records.push_back({entry.first, entry.second});
    }

    std::sort(records.begin(), records.end(), compareDates);

    for (const auto& record : records) {
        std::cout << record.date << " " << record.count << std::endl;
    }

    return 0;
}
