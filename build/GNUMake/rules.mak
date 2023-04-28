###############################################################################
### Rules (include at the end)
###############################################################################

CXX_OBJ        = $(CXX_SRC:%.cpp=$(OBJ_DIR)/%.o)
CC_OBJ			= $(CC_SRC:%.c=$(OBJ_DIR)/%.o)
CXX_DEP 			= $(CXX_SRC:%.cpp=$(OBJ_DIR)/%.d)
CC_DEP 			= $(CC_SRC:%.c=$(OBJ_DIR)/%.d)
INC_PARAMS		= $(INC_DIR:%=-I%) 


all: $(CXX_OBJ) $(CC_OBJ)

$(OBJ_DIR)/%.o: %.cpp $(OBJ_DIR)/%.d
	$(MKDIR) $(@D)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(INC_PARAMS)

$(OBJ_DIR)/%.o: %.c $(OBJ_DIR)/%.d
	$(MKDIR) $(@D)
	$(CC) -c -o $@ $< $(CFLAGS) $(CPPFLAGS) $(INC_PARAMS)

$(OBJ_DIR)/%.d: %.cpp
	$(MKDIR) $(@D)
	$(CXX) -MM $< -MT $(OBJ_DIR)/$*.o $(INC_PARAMS) > $@

$(OBJ_DIR)/%.d: %.c
	$(MKDIR) $(@D)
	$(CXX) -MM $< -MT $(OBJ_DIR)/$*.o $(INC_PARAMS) > $@

-include $(CXX_DEP) $(CC_DEP)

.PHONY: all clean
clean:
	$(RMDIR) $(OBJ_DIR)

