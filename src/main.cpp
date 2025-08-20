#include "webview.h"
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = filesystem;
int main() {
    webview::webview w(true, nullptr);
    w.set_title("YARPM");
    int height = 800;
    int width = 700;
    w.set_size(height, width, WEBVIEW_HINT_MIN);
    w.set_size(height, width, WEBVIEW_HINT_MAX);

    w.bind("queryProcesses", [](string req) -> string {
        cout << req;
        return "\"Gotya\"";
    });
    string path = fs::absolute("index.html");
    //get HTML file
    w.navigate("file://" + path);
    w.run();
    return 0;
}