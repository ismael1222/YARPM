#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string getLinuxProcesses() {
    std::string result = "[";
    char buffer[256];

    FILE* pipe = popen("ps -eo comm --no-headers", "r");
    if (!pipe) {
        return "[]";
    }

    bool first = true;
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::string line(buffer);
        line.erase(line.find_last_not_of("\n") + 1); // quitar newline
        std::istringstream iss(line);
        std::string name;
        if (!(iss >> name)) {
            continue;    // skip si algo raro
        }
        // Escapamos comillas y otros caracteres si hace falta
        std::replace(name.begin(), name.end(), '"', '\'');
        if (!first) {
            result += ",";
        }
        first = false;
        result += "\"" + name + "\"";
    }

    pclose(pipe);
    result += "]";
    return result;
}
