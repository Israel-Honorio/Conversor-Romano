# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Nome do executável de teste
TEST_EXEC = testa_romanos

# Arquivos objeto
OBJS = romanos.o

.PHONY: all clean

all: $(TEST_EXEC)
	./$(TEST_EXEC)

compile: $(TEST_EXEC)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

cpplint: testa_romanos.cpp romanos.cpp romanos.hpp
	cpplint --exclude=catch.hpp *.cpp *.hpp

gcov: testa_romanos.cpp romanos.cpp romanos.hpp
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage romanos.cpp testa_romanos.cpp -o $(TEST_EXEC)
	./$(TEST_EXEC)
	gcov romanos.cpp

debug: romanos.cpp testa_romanos.cpp
	$(CXX) $(CXXFLAGS) -g romanos.cpp testa_romanos.cpp -o $(TEST_EXEC)
	gdb $(TEST_EXEC)

cppcheck: testa_romanos.cpp romanos.cpp romanos.hpp
	cppcheck --enable=warning --suppress=missingInclude .

valgrind: $(TEST_EXEC)
	valgrind --leak-check=full --track-origins=yes ./$(TEST_EXEC)

romanos.o: romanos.cpp romanos.hpp
	$(CXX) $(CXXFLAGS) -c romanos.cpp

$(TEST_EXEC): testa_romanos.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) testa_romanos.cpp -o $(TEST_EXEC)

clean:
	rm -rf *.o $(TEST_EXEC) *.gcda *.gcno *.gcov