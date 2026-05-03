.PHONY: prod test run test-run clean

prod: $(APP_BIN)

test: BUILD := test
test: $(TEST_BIN)

run: prod
	@echo "==================== Running application... ====================="
	$(APP_BIN)

test-run: test
	$(TEST_BIN)

clean:
	$(RM) $(PRJ_ROOT)/build

$(BINDIR):
	$(MKDIR_P) $@

$(OBJDIR):
	$(MKDIR_P) $@

$(APP_BIN): $(APP_OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(TEST_BIN): $(TEST_OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(PRJ_ROOT)/%.c | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
