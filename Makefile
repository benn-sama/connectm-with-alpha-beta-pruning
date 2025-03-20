HEADERS = game/connect-m.hpp game/game.hpp game/UI.hpp game/node.hpp players/computer.hpp players/human.hpp 
TEST_SOURCES = tests/connect-m-test-1.cpp tests/ui-test-1.cpp tests/node-test-1.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
MAIN_SOURCES = main.cpp game/connect-m.cpp game/game.cpp game/UI.cpp game/node.cpp players/computer.cpp players/human.cpp
MAIN_OBJECTS = $(MAIN_SOURCES:.cpp=.o)
TEST_TARGETS = $(TEST_SOURCES:.cpp=.out)
MAIN_TARGET = connect_m_executable

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I.

.PHONY: all run-test main run-main clean

all: $(TEST_TARGETS) $(MAIN_TARGET)

$(TEST_TARGETS): %.out: %.o game/connect-m.o game/game.o game/UI.o game/node.o players/computer.o players/human.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(MAIN_TARGET): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

tests/%.o: tests/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

game/%.o: game/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

players/%.o: players/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run-test: $(TEST_TARGETS)
	for test in $(TEST_TARGETS); do ./$$test; done

main: $(MAIN_TARGET)

run-main: main
	./$(MAIN_TARGET)

clean:
	rm -f $(TEST_OBJECTS) $(TEST_TARGETS) $(MAIN_OBJECTS) $(MAIN_TARGET)