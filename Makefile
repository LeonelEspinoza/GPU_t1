BUILD=build
WDIRS=src/ test/

.PHONY: build init clean test run

init:
	@cmake -S . -B $(BUILD)

build:
	mkdir -p $(BUILD)
	cmake --build $(BUILD) -j 10

test:
	@GTEST_COLOR=1 ctest --test-dir $(BUILD) --output-on-failure

clean:
	rm -rf .cache Testing build

watch: init
	@find $(WDIRS) | entr -s "make build"
