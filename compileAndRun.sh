g++ -std=c++17 -I./include src/main.cpp -o bin/yarpm `pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0` \
&& ./bin/yarpm