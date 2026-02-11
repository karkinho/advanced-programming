CXX = g++
CXXFLAGS = -Iinclude -Wall -Werror -Wextra -Wpedantic
LDFLAGS  = -lraylib -lm
OBJDIR := obj
TARGET := app
SRC_DIR := src

SRCS := $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

debug: CXXFLAGS += -g -DDEBUG # -fsanitize=address -fsanitize=leak
debug: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

mem: CXXFLAGS += -fsanitize=address -fsanitize=leak
mem: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

log: CXXFLAGS += -DLOG
log: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)
	rm -r $(OBJDIR)
