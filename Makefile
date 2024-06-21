# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 $(shell find $(INCLUDE_DIR) -type d -exec echo -I{} \;)

# Directories
SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib
INCLUDE_DIR = include
TEST_DIR = test

# Libraries
STATIC_LIBS = $(LIB_DIR)/libdata_structures.a $(LIB_DIR)/libsorting.a $(LIB_DIR)/libutils.a
DYNAMIC_LIBS = $(LIB_DIR)/libvisualization.so

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/**/*.cpp) $(SRC_DIR)/main.cpp

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Target
TARGET = $(BUILD_DIR)/visual_algo

all: $(TARGET)

run: $(TARGET) install
	$(TARGET)

# Build target executable
$(TARGET): $(OBJ_FILES) $(STATIC_LIBS) $(DYNAMIC_LIBS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ_FILES) $(STATIC_LIBS) 

# Build static libraries
$(LIB_DIR)/libdata_structures.a: $(BUILD_DIR)/data_structures/array.o
	ar rcs $@ $^

$(LIB_DIR)/libsorting.a: $(BUILD_DIR)/sorting/bubble_sort.o
	ar rcs $@ $^

$(LIB_DIR)/libutils.a: $(BUILD_DIR)/utils/random_generator.o
	ar rcs $@ $^

# Build dynamic library
$(LIB_DIR)/libvisualization.so: $(BUILD_DIR)/visualization/visualize.o
	$(CXX) -shared -o $@ $^

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -fPIC -c -o $@ $<

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)/*.a $(LIB_DIR)/*.so

# Install libraries
install: $(STATIC_LIBS) $(DYNAMIC_LIBS)
	install -m 644 $(STATIC_LIBS) /usr/local/lib/
	install -m 755 $(DYNAMIC_LIBS) /usr/local/lib/
	ldconfig

# uninstall libraries
uninstall:
	rm -f /usr/local/lib/libdata_structures.a
	rm -f /usr/local/lib/libsorting.a
	rm -f /usr/local/lib/libutils.a
	rm -f /usr/local/lib/libvisualization.so
	ldconfig
	

.PHONY: all run clean install
