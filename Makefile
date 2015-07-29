program_NAME := textinascii
program_SRC_DIR := ./src/*
program_BUILD_DIR := ./bin
program_C_SRCS := $(wildcard $(program_SRC_DIR)/*.c)
program_CXX_SRCS := $(wildcard $(program_SRC_DIR)/*.cpp)
program_BUILD_BIN := $(program_BUILD_DIR)/$(program_NAME)
program_C_OBJS := ${program_C_SRCS:.c=.o}
program_CXX_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_OBJS := $(program_C_OBJS) $(program_CXX_OBJS)
program_INCLUDE_DIRS :=
program_LIBRARY_DIRS :=
program_LIBRARIES :=

CPPFLAGS += $(foreach includedir,$(program_INCLUDE_DIRS),-I$(includedir))
LDFLAGS += $(foreach librarydir,$(program_LIBRARY_DIRS),-L$(librarydir))
LDFLAGS += $(foreach library,$(program_LIBRARIES),-l$(library))

.PHONY: all clean distclean

all: $(program_NAME)

$(program_NAME): $(program_OBJS)
	@mkdir -p bin
	$(LINK.cc) $(program_OBJS) -o $(program_BUILD_BIN)

clean:

	@- $(RM) $(program_OBJS)
	@- $(RM) $(program_BUILD_BIN)
	@rmdir ./bin

distclean: clean
