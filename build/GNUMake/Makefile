BASE_DIR	= ../..
include $(BASE_DIR)/build/GNUMake/paths.mak
include $(BASE_DIR)/build/GNUMake/paths_lbr.mak
include $(BASE_DIR)/build/GNUMake/$(TOOLS_MAK)

include $(BASE_DIR)/build/GNUMake/targets.mak

TARGETLIB 		= libFRIClient.a

SOURCE_DIRS		= $(CLIENTBASE_DIR) \
				  	  $(CLIENTLBR_DIR) \
				  	  $(CLIENTTRAFO_DIR) \
				 	  $(CONNECTION_DIR) \
					  $(NANOPB_DIR) \
				 	  $(PROTOBUF_DIR) \
				 	  $(PROTOBUF_GEN_DIR)

EXAMPLE_DIRS 	= $(EXP_DIR)/LBRJointSineOverlay \
					  $(EXP_DIR)/LBRCartesianOverlay \
					  $(EXP_DIR)/LBRTorqueSineOverlay \
					  $(EXP_DIR)/LBRWrenchSineOverlay \
					  $(EXP_DIR)/LBRClientTemplate \
					  $(EXP_DIR)/TransformationProvider \
					  $(EXP_DIR)/SimulatedTransformationProvider \
					  $(EXP_DIR)/IOAccess

SOURCE_DIRS_OBJS	= $(SOURCE_DIRS:%=%/$(OBJ_DIR)/*.o)


