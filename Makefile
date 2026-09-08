BUILD_DIR ?= build/native
BUILD_TYPE ?= Release

.PHONY: all configure test clean
all: configure
	cmake --build $(BUILD_DIR) --config $(BUILD_TYPE) --parallel

configure:
	cmake -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)

test: all
	ctest --test-dir $(BUILD_DIR) -C $(BUILD_TYPE) --output-on-failure

clean:
	cmake --build $(BUILD_DIR) --target clean
