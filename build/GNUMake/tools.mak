###############################################################################
### Tools (include at the beginning).
### This version should work with Linux and the GNU Compiler Collection.
###############################################################################
AR             = ar

MKDIR          = mkdir -p

RMDIR          = rm -rf

RM					= rm -f

CP					= cp -uf

CC             = gcc

CFLAGS		   = -O2 -Wall \
					-DHAVE_SOCKLEN_T \
					-DPB_SYSTEM_HEADER=\"pb_syshdr.h\" \
					-DPB_FIELD_16BIT \
					-DHAVE_STDINT_H \
					-DHAVE_STDDEF_H \
					-DHAVE_STDBOOL_H \
					-DHAVE_STDLIB_H \
					-DHAVE_STRING_H 
					
CXX            = g++

CXXFLAGS       = $(CFLAGS)
 
LDFLAGS        = 
