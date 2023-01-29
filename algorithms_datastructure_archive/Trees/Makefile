CXX = clang++
SOURCE_CXX = main.cpp
TARGET = dummyObjectFile
LDFLAGS_COMMON = -std=c++2a

all:
	$(CXX) $(SOURCE_CXX) $(LDFLAGS_COMMON) -o $(TARGET)

clean:
	rm -rf *.o $(TARGET) main main.dSYM .idea