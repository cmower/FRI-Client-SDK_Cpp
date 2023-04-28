###############################################################################
### Rules (include at the end)
###############################################################################

OBJ        		= $(SOURCES:%.cpp=$(OBJ_DIR)/%.o)
DEP 				= $(SOURCES:%.cpp=$(OBJ_DIR)/%.d)
INC_PARAMS		= $(INC_DIR:%=-I%) 

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(CXXFLAGS) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.cpp $(OBJ_DIR)/%.d
	$(MKDIR) $(@D)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(INC_PARAMS)

$(OBJ_DIR)/%.d: %.cpp
	$(MKDIR) $(@D)
	$(CXX) -MM $< -MT $(OBJ_DIR)/$*.o $(INC_PARAMS) > $@

-include $(DEP)

clean:
	$(RMDIR) $(OBJ_DIR)
	$(RM) $(TARGET)

install:
	$(MKDIR) $(BIN_DIR)
	$(CP) $(TARGET) $(BIN_DIR)

uninstall:
	$(RM) $(BIN_DIR)/$(TARGET)

.PHONY: all install clean uninstall
