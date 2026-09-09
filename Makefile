BUILD_DIR ?= build/native
BUILD_TYPE ?= Release
DESKTOP ?= ON
CMAKE_ARGS ?=

.PHONY: all configure test package install clean
all: configure
	cmake --build $(BUILD_DIR) --config $(BUILD_TYPE) --parallel

configure:
	cmake -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) -DLEGACY_DESKTOP=$(DESKTOP) $(CMAKE_ARGS)

test: all
	ctest --test-dir $(BUILD_DIR) -C $(BUILD_TYPE) --output-on-failure

package: test
	cpack --config $(BUILD_DIR)/CPackConfig.cmake -C $(BUILD_TYPE) -B $(BUILD_DIR)/packages

install: all
	cmake --install $(BUILD_DIR) --config $(BUILD_TYPE) $(INSTALL_ARGS)

clean:
	cmake --build $(BUILD_DIR) --target clean
