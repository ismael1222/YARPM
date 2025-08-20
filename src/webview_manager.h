#pragma once
#include "webview.h"
#include <string>

class WebviewManager {
public:
    WebviewManager(int width, int height, const std::string &title);
    void run();
    void sendData();
private:
    webview::webview w;
    void setupBindings();
};
