###############################################################################
### Tools (include at the beginning).
### This version works with Windriver VxWorks 6.8 for Kuka controllers.
### To include set TOOLS_MAK to $(BASE_DIR)/test/tools_vxworks68.mak in paths.mak
###############################################################################
AR             = arpentium

MKDIR          = mkdir -p

RMDIR          = rm -rf

RM					= rm -f

CP					= cp -uf

CC             = ccpentium

CFLAGS		   = -DVXWORKS=68 -DPB_SYSTEM_HEADER=\"pb_syshdr.h\" \
					-mtune=pentium4 -march=pentium4 -O2 -pipe -fno-strict-aliasing -nostdinc -Wall -Wpointer-arith \
		  			-mrtp \
		  			-D_VX_CPU=_VX_PENTIUM4 -D_VX_TOOL_FAMILY=gnu -D_VX_TOOL=gnu -D_C99 -D_HAS_C9X  -D_NO_DLL_ \
					-DPB_FIELD_16BIT \
           		-I. \
           		-I$(WIND_USR)/h -I$(WIND_USR)/h/wrn/coreip \
           		-I${WIND_HOME}/gnu/4.1.2-vxworks-6.8/lib/gcc/i586-wrs-vxworks/4.1.2/include \
           		-I${WIND_HOME}/gnu/4.1.2-vxworks-6.8/lib/gcc/i586-wrs-vxworks/4.1.2/include-fixed \
           		-I${WIND_HOME}/gnu/4.1.2-vxworks-6.8/include/c++/4.1 \
           		-I${WIND_HOME}/gnu/4.1.2-vxworks-6.8/include/c++/4.1/i586-wrs-vxworks \
					
CXX            = c++pentium

CXXFLAGS       = $(CFLAGS) -ansi
#  specific path related to KUKA source code management -- does not work without KUKA Sources
LDFLAGS        = -Wl,-whole-archive -Wl,-no-whole-archive \
					-L$(WIND_HOME)/vxworks-6.8/target/lib/usr/lib/pentium/PENTIUM4/common
