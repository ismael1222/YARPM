#include "webview.h"
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = filesystem;


int main() {
    webview::webview w(true, nullptr);
    w.set_title("YARPM Test");
    w.set_size(800, 600, WEBVIEW_HINT_NONE);

    w.bind("sendBack", []( string msg) -> string {
        cout << "Got message from JS: " << msg << endl;
        return "\"Gotya\"";
    });

    string path = fs::absolute("index.html");
    w.init(R"(
        alert('If you see this, then it works');
    )");
//get HTML file
    w.navigate("file://" + path);
    w.run();
    return 0;
}