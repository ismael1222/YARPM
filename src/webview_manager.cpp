#include "webview_manager.h"
#include <iostream>
#include <filesystem>

WebviewManager::WebviewManager(int width, int height, const std::string &title)
    : w(true, nullptr) {
    w.set_title(title);
    //min and max = non-resizeable thingy
    w.set_size(width, height, WEBVIEW_HINT_MIN);
    w.set_size(width, height, WEBVIEW_HINT_MAX);
    //cpp js comms
    setupBindings();
    //open file
    std::string path = std::filesystem::absolute("index.html");
    w.navigate("file://" + path);
}

void WebviewManager::setupBindings() {
    w.bind("queryProcesses", [](std::string req) -> std::string {
        std::cout << req << std::endl;
        return "\"Gotyaaa\"";
        // placeholder
    });
}

void WebviewManager::run() {
    w.run();
}
