EXECUTABLE = swpathtracer

CXX = g++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic

ifeq ($(DEBUG), 1)
CXXFLAGS += -DDEBUG -O0 -g3
else
CXXFLAGS += -DNDEBUG -O3 -g0
endif

CPPFLAGS += -MMD \
			-I../../../../work/common/glm-0.9.7.0 \
			-I/usr/local/include

LDFLAGS = -L/usr/lib/gcc/x86_64-linux-gnu/4.8 \
		  -L/usr/lib/x86_64-linux-gnu \
		  -L/usr/lib \
	      -L/usr/local/lib

LDLIBS = -lpthread

SOURCES = $(wildcard *.cpp buffer/*.cpp camera/*.cpp integrator/*.cpp loader/*.cpp materials/*.cpp primitives/*.cpp scenes/*.cpp shapes/*.cpp)

OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $^ -o $@ $(LDLIBS)

.cpp.o:

-include $(OBJECTS:.o=.d)

.PHONY: clean distclean

clean:
	rm -f *.o *.d */*.o */*.d *.ppm

distclean: clean
	rm $(EXECUTABLE)

