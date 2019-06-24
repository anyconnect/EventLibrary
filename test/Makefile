CPP=g++
CPPFLAGS=-I. -std=c++11 -ldl -pthread
DEPS = Test.h EventService.h
OBJ = Test.o

%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CPPFLAGS)

TARGET = eventtest

all: $(TARGET)

clean: 
	rm -f $(OBJ) $(TARGET)


$(TARGET): $(OBJ)
	$(CPP) -o $@ $^ $(CPPFLAGS)
