
$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

install: $(TARGET)
	mkdir -p $(BINDIR)
	mv $(TARGET) $(BINDIR)/$(TARGET)

clean:
	rm -rf $(BINDIR)
	rm -rf $(TARGET)
	rm -rf *.o