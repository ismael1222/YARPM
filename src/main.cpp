#include "webview.h"
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    webview::webview w(true, nullptr);
    w.set_title("YARPM Test");
    w.set_size(800, 600, WEBVIEW_HINT_NONE);

    // Función que JS puede llamar
    w.bind("fromCpp", [](std::string msg) -> std::string {
        std::cout << "Mensaje recibido desde JS: " << msg << std::endl;
        return "\"Recibido\""; // Promise result en JS
    });

    // Llamada inicial a JS desde C++
    w.init(R"(
        alert('Hola desde C++!');
    )");

    // Ruta absoluta al index.html
    std::string path = fs::absolute("index.html");
    w.navigate("file://" + path);

    // Loop principal
    w.run();
    return 0;
}