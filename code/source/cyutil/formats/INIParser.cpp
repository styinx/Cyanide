#include "cyutil/formats/INIParser.hpp"

#include <algorithm>
#include <fstream>
#include <regex>
#include <sstream>

namespace cyanide
{
namespace cyutil
{

    static inline void ltrim(std::string& s)
    {
        s.erase(s.begin(),
                std::find_if(s.begin(), s.end(), [](int ch) { return !std::isspace(ch); }));
    }

    static inline void rtrim(std::string& s)
    {
        s.erase(
        std::find_if(s.rbegin(), s.rend(), [](int ch) { return !std::isspace(ch); }).base(),
        s.end());
    }

    static inline void trim(std::string& s)
    {
        ltrim(s);
        rtrim(s);
    }

    static inline std::string ltrimc(std::string s)
    {
        ltrim(s);
        return s;
    }

    static inline std::string rtrimc(std::string s)
    {
        rtrim(s);
        return s;
    }

    static inline std::string trimc(std::string s)
    {
        trim(s);
        return s;
    }

    static std::vector<std::string> split(std::string haystack, char needle)
    {
        std::vector<std::string> result;
        std::istringstream       iss(haystack);

        for(std::string token; std::getline(iss, token, needle);)
        {
            result.push_back(std::move(token));
        }
        return result;
    }

    static std::string join(std::vector<std::string> haystack, const std::string needle)
    {
        std::string result;

        for(const auto& s: haystack)
        {
            result += s + needle;
        }
        return result.substr(0, result.rfind(needle) - 1);
    }

    static bool blank(std::string haystack)
    {
        return haystack.find_first_not_of(' ') == std::string::npos;
    }

    INIParser::INIParser(String filename)
        : filename(filename)
    {
    }

    void INIParser::read()
    {
        std::ifstream in(filename, std::ios::in);

        String line;
        while(std::getline(in, line))
        {
            if(line[0] == '#' || blank(line)) { continue; }

            Vector<String> args = split(line, '=');
            if(args.size() < 2)
            {
                // err
            }

            String key = trimc(args[0]);
            String val = trimc(args[1]);
            INIValue  value;

            std::smatch match;
            auto reg_c = std::regex(R"(\'.*\')");
            auto reg_i8 = std::regex(R"(0[xX][0-9a-fA-F]{1,2})");
            auto reg_i16 = std::regex(R"(0[xX][0-9a-fA-F]{1,4})");
            auto reg_s32 = std::regex(R"(0[xX][0-9a-fA-F]{1,8}|[\+\-]?[1-2]?\d{1,9})"); // careful! information lost
            auto reg_u32 = std::regex(R"(0[xX][0-9a-fA-F]{1,8}|[\+]?[1-2]?\d{1,9})"); // careful! information lost
            auto reg_s64 = std::regex(R"(0[xX][0-9a-fA-F]{1,8}|[\+\-]?[1-9]?\d{1,18})"); // careful! information lost
            auto reg_u64 = std::regex(R"(0[xX][0-9a-fA-F]{1,8}|[\+]?[1-9]?\d{1,18})"); // careful! information lost
            auto reg_f = std::regex(R"([\+\-]?(\d{0,18}\.\d{1,18})?)"); // careful! information lost
            auto reg_s = std::regex(R"(\".*\")");

            if(std::regex_match(val, std::regex("([Ff]alse|[Tt]rue)")))
            {
                if(val == "True" || val == "true") value = true;
                if(val == "False" || val == "false") value = false;
            }
            if(std::regex_match(val, reg_c))
            {
                // char
            }
            else if(std::regex_search(val, match, reg_i8))
            {
                value = static_cast<Uint8>(std::stoul(match.str(0)));
            }
            else if(std::regex_search(val, match, reg_i16))
            {
                value = static_cast<Uint16>(std::stoul(match.str(0)));
            }
            else if(std::regex_search(val, match, reg_u32))
            {
                value = static_cast<Uint32>(std::stoul(match.str(0)));
            }
            else if(std::regex_search(val, match, reg_s32))
            {
                value = static_cast<Sint32>(std::stoi(match.str(0)));
            }
            else if(std::regex_search(val, match, reg_f))
            {
                value.set<float>(std::stof(match.str(0)));
            }
            else if(std::regex_match(val, reg_s))
            {
                // string
            }
            else
            {
                //invalid
            }
            dictionary[args[0]] = value;
        }
    }

    void INIParser::write()
    {
        if(changed)
        {
            std::ofstream out(filename, std::ios::out);
            for(auto& line: dictionary)
            {
                String key   = line.first;
                Any    value = line.second;
                out << key << " = " << std::any_cast<std::string>(value) << "\n";
            }
        }
    }

}  // namespace cyutil
}  // namespace cyanide