CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = imgview
SRC = imgview.cpp

.PHONY: all clean install

all: $(TARGET)

$(TARGET): $(SRC) stb_image.h
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

install: $(TARGET)
	install -m 755 $(TARGET) /usr/local/bin/
