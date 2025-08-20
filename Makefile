CXX := g++
CXXFLAGS := -std=c++17 -I./include
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)
TARGET := bin/yarpm

.PHONY: all linux windows run clean

all:
	@echo "chose 'make linux' or 'make windows'"

linux: CXXFLAGS += $(shell pkg-config --cflags gtk+-3.0 webkit2gtk-4.0)
linux: LDFLAGS := $(shell pkg-config --libs gtk+-3.0 webkit2gtk-4.0)
linux: $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)


windows: CXXFLAGS += -I"C:/path/to/Windows/Includes"
windows: LDFLAGS := -L"C:/path/to/Windows/Libs" -luser32 -lgdi32
windows: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
