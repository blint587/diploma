#include "parsers.hpp"

std::vector<std::string> munits::unparser(std::string unit) {
    const std::vector<munits::Metric> &rmatrix = munits::GetMatrix();
    std::vector<std::string> parsed = {"", "", ""};

    bool no_match = true;

    for (int u = 0; u < munits::_Last && no_match; ++u) {
        std::stringstream rp;
        { // composing the regex for each Unit type
            rp << "^(";
            const std::map<std::string, const std::shared_ptr<munits::ConverterFunction>> &prefixes = rmatrix[u].converter->Prefixes();
            int c1 = 0;
            for (auto prx = prefixes.begin(); prx != prefixes.end(); ++prx) {
                rp << prx->first << (c1 != prefixes.size() - 1 ? "|" : "");
                ++c1;
            }

            rp << ")?(";
            c1 = 0;
            const std::map<std::string, const std::shared_ptr<munits::Unit>> &units = rmatrix[u].converter->Units();
            for (auto unt = units.begin(); unt != units.end(); ++unt) {
                rp << unt->first << (c1 != units.size() - 1 ? "|" : "");
                ++c1;
            }

            rp << ")(\\-?[0-9])?$";
        }
        try {
            std::regex re(rp.str());
            std::sregex_iterator next(unit.begin(), unit.end(), re);
            std::sregex_iterator end;
            while (next != end) {
                std::smatch match = *next;

                if (std::string((std::basic_string<char, std::char_traits<char>, std::allocator<char>> &&) match[1]) +
                    std::string((std::basic_string<char, std::char_traits<char>, std::allocator<char>> &&) match[2]) +
                    std::string((std::basic_string<char, std::char_traits<char>, std::allocator<char>> &&) match[3]) ==
                    unit) {
                    no_match = false;
                    parsed[0] = match[1];
                    parsed[1] = match[2];
                    parsed[2] = match[3];
                }
                next++;
            }
        }
        catch (std::regex_error &e) {

        }
    }

    return parsed;
}

std::vector<std::string> munits::rparser(const std::string &token) {
    const std::vector<munits::Metric> &rmatrix = munits::GetMatrix();
    std::vector<std::string> parsed = {"", "", ""};

    bool no_match = true;

    for (int u = 0; u < munits::_Last && no_match; ++u) {
        if (!rmatrix[u].unit_resolve_mapping.empty()) {
            std::stringstream rp;
            { // composing the regex for each Unit type
                rp << "^(";
                const std::map<std::string, const std::shared_ptr<munits::ConverterFunction>> &prefixes = rmatrix[u].converter->Prefixes();
                int c1 = 0;
                for (auto prx = prefixes.begin(); prx != prefixes.end(); ++prx) {
                    rp << prx->first << (c1 != prefixes.size() - 1 ? "|" : "");
                    ++c1;
                }

                rp << ")?(";
                c1 = 0;

                for (auto unt = rmatrix[u].unit_resolve_mapping.begin();
                     unt != rmatrix[u].unit_resolve_mapping.end(); ++unt) {
                    rp << unt->first << (c1 != rmatrix[u].unit_resolve_mapping.size() - 1 ? "|" : "");
                    ++c1;
                }

                rp << ")(\\-?[0-9])?$";
            }
            try {
                std::regex re(rp.str());
                std::sregex_iterator next(token.begin(), token.end(), re);
                std::sregex_iterator end;
                while (next != end) {
                    std::smatch match = *next;

                    if (std::string((std::basic_string<char, std::char_traits<char>, std::allocator<char>> &&) match[1]) +
                        std::string((std::basic_string<char, std::char_traits<char>, std::allocator<char>> &&) match[2]) +
                        std::string((std::basic_string<char, std::char_traits<char>, std::allocator<char>> &&) match[3]) ==
                        token) {
                        no_match = false;
                        parsed[0] = match[1];
                        parsed[1] = match[2];
                        parsed[2] = match[3];
                    }
                    next++;
                }
            } catch (std::regex_error &e) {}
        }
    }

    return parsed;
}
