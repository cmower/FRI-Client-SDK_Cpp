###############################################################################
### Paths (include at the beginning but after BASE_DIR initialization)
###############################################################################
TOOLS_MAK			= tools.mak

BIN_DIR				= $(BASE_DIR)/bin
EXP_DIR				= $(BASE_DIR)/example
DOC_DIR				= $(BASE_DIR)/doc
INC_DIR        		= $(BASE_DIR)/include
LIB_DIR				= $(BASE_DIR)/lib
SRC_DIR				= $(BASE_DIR)/src
OBJ_DIR        		= obj

CLIENTBASE_DIR		= $(SRC_DIR)/base
CLIENTTRAFO_DIR		= $(SRC_DIR)/client_trafo
CONNECTION_DIR		= $(SRC_DIR)/connection
NANOPB_DIR			= $(SRC_DIR)/nanopb-0.2.8
PROTOBUF_DIR 		= $(SRC_DIR)/protobuf
PROTOBUF_GEN_DIR 	= $(SRC_DIR)/protobuf_gen
