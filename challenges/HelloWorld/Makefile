# Compiler
JAVAC = javac

# Source and target directories
SRC = src
BIN = bin

# All Java source files
SRCS := $(shell find $(SRC) -name "*.java")
# Corresponding class files
CLASSES := $(SRCS:$(SRC)/%.java=$(BIN)/%.class)

# Default target
all: $(CLASSES)

# How to build class files
$(BIN)/%.class: $(SRC)/%.java
	@mkdir -p $(dir $@)
	$(JAVAC) -d $(BIN) $<

# Clean build artifacts
clean:
	rm -rf $(BIN)

.PHONY: all clean