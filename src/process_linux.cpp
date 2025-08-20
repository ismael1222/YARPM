#include "process_linux.h"
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

//json utils
json loadJson(const std::string &path) {
    std::ifstream f(path);
    if (!f.is_open()) {
        return json::object();
    }
    json j;
    f >> j;
    return j;
}

void saveJson(const std::string &path, const json &j) {
    std::ofstream f(path);
    f << j.dump(4); //indent
}

//main func
std::string getLinuxProcesses() {
    //processes
    std::vector<std::string> processes;
    char buffer[256];

    FILE* pipe = popen("ps -eo comm --no-headers", "r");
    if (!pipe) {
        return "[]";
    }

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::string line(buffer);
        line.erase(line.find_last_not_of("\n") + 1);
        std::istringstream iss(line);
        std::string name;
        if (!(iss >> name)) {
            continue;
        }
        std::replace(name.begin(), name.end(), '"', '\'');
        processes.push_back(name);
    }
    pclose(pipe);

//load jsons
    json userList = loadJson("userList.json");
    json defaults = loadJson("defaultList.json");

    json result = json::array();
    std::set<std::string> seen; //no dupe processes
    bool changed = false;

    for (const auto &proc : processes) {
        if (seen.count(proc)) {
            continue;
        }
        seen.insert(proc);

        if (userList.contains(proc)) {
            result.push_back(userList[proc]);
        } else if (defaults.contains(proc)) {
            result.push_back(defaults[proc]);
            userList[proc] = defaults[proc]; // add to userlist too
            changed = true;
        }
        //no process? no add.
    }

    if (changed) {
        saveJson("userList.json", userList);
    }

    // 5️⃣ Devolver JSON como string
    return result.dump();
}
