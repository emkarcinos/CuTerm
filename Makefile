TARGET := CuTerm_sample

BUILD_DIR := bin
SRC_DIR := src
INC_DIR := include

SRCS := $(shell find $(SRC_DIR) -name *.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

INC_FLAGS := $(addprefix -I,$(INC_DIR))

CPPFLAGS := $(INC_FLAGS) --std=c++17 -Wall


$(BUILD_DIR)/$(TARGET): $(OBJS)
	echo $(LDFLAGS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)/*