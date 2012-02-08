TARGET = urltotxt
SRC = urltotxt.cpp

TARGET:
	g++ -Wall $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

