include CONFIG.cfg

CC = gcc
LD = gcc

TEST_INP_TYPE = in
TEST_OUT_TYPE = out
TEST_LOG_TYPE = log

EXEC = $(BUILD_DIR)/$(NAME)
OBJECTS = $(BUILD_DIR)/sorter.o $(BUILD_DIR)/file_handler.o $(BUILD_DIR)/argvalidate.o $(BUILD_DIR)/sortings.o
DEPS = $(OBJECTS:.o=.d)

MAIN_LOG = log.txt
LOGS = $(patsubst $(TEST_DIR)/%.$(TEST_INP_TYPE), $(TEST_DIR)/%.$(TEST_LOG_TYPE), $(wildcard $(TEST_DIR)/*.$(TEST_INP_TYPE)))




.PHONY: all check clean


all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(LD) $^ -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(CC) -c $< -o $@

-include $(DEPS)

$(BUILD_DIR):
	mkdir -p $@


check:  $(LOGS)
	@if [  "$$(cat log.txt)" != "OK"  ] ; then \
        exit 1 ; \
    fi

$(TEST_DIR)/%.$(TEST_LOG_TYPE): $(TEST_DIR)/%.$(TEST_INP_TYPE) $(TEST_DIR)/%.$(TEST_OUT_TYPE) $(EXEC)
	python3 test.py $^


clean:
	$(RM) $(EXEC) $(OBJECTS) $(DEPS) $(MAIN_LOG) $(LOGS)
