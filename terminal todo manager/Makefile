CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = todo
SRCDIR = src
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/todo.cpp
HEADERS = $(SRCDIR)/todo.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

.PHONY: clean install