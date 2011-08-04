#Set this to @ to keep the makefile quiet
#SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = Treadmill
TARGET_LIB = \
	lib/lib$(COMPONENT_NAME).a

TEST_TARGET = \
	$(COMPONENT_NAME)_tests

ACCEPTANCE_TEST_TARGET = \
	$(COMPONENT_NAME)_acceptance_tests

RANLIB = ranlib
#--- Inputs ----#
CPPUTEST_USE_MEM_LEAK_DETECTION = N
PROJECT_HOME_DIR = .
ifeq "$(CPPUTEST_HOME)" ""
    CPPUTEST_HOME = ../CppUTest
endif
ifeq "$(CSLIM_HOME)" ""
    CSLIM_HOME = ../cslim
endif
CPP_PLATFORM = Gcc

#CFLAGS are set to override malloc and free to get memory leak detection in C programs
CPPUTEST_CFLAGS += -std=c99
#GCOVFLAGS = -fprofile-arcs -ftest-coverage
CPPUTEST_WARNINGFLAGS =  -Wall# -Wextra -Werror -Wshadow -Wswitch-default -Wswitch-enum -Wconversion
#includes for all compiles
#a list of -I's are created from these directories

INCLUDE_DIRS =\
  .\
  include\
  include/*\
  $(CPPUTEST_HOME)/include/\
	$(CSLIM_HOME)/include/Com\
	$(CSLIM_HOME)/include/CSlim\
	tests

#SRC_DIRS is a list of source directories that make up the target library
#If test files are in these directories, their IMPORT_TEST_GROUPs need
#to be included in main to force them to be linked in.  By convention
#put them into an AllTests.h file in each directory
SRC_DIRS = \
	src\
	src/treadmill\
	src/util

#TEST_SRC_DIRS is a list of directories including
# - A test main (AllTests.cpp by convention)
# - OBJ files in these directories are included in the TEST_TARGET
# - Consequently - AllTests.h containing the IMPORT_TEST_GROUPS is not needed
# -
TEST_SRC_DIRS = \
	tests \
	tests/*

# - OBJ files in these directories are included in the TEST_TARGET
MOCKS_SRC_DIRS = \
	mocks\
	mocks/util\
	mocks/hardware

FIXTURE_SRC_DIRS = \
	fixtures

FIXTURE_CHEAT_DIRS = \
	cheat_fixtures

CSLIM_LIB = ../cslim/lib/libCSlim.a

#Flags to pass to ld
LDFLAGS +=
#LD_LIBRARIES += -lstdc++

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

FIXTURE_CHEAT_SRC =  $(call get_src_from_dir_list, $(FIXTURE_CHEAT_DIRS))
FIXTURE_CHEAT_OBJS = $(call src_to_o,$(FIXTURE_CHEAT_SRC))
STUFF_TO_CLEAN += $(FIXTURE_CHEAT_OBJS)

$(ACCEPTANCE_TEST_TARGET)_cheat : $(MOCKS_OBJS) $(FIXTURE_CHEAT_OBJS) $(CSLIM_LIB) $(PRODUCTION_CODE_START) $(TARGET_LIB) $(USER_LIBS) $(PRODUCTION_CODE_END) $(STDLIB_CODE_START) 
	$(SILENCE)echo Linking $@
	$(SILENCE)$(LINK.o) -o $@ $^ $(LD_LIBRARIES)

cheat: $(ACCEPTANCE_TEST_TARGET)_cheat

FIXTURE_TEST_SRC = $(call get_src_from_dir_list, $(FIXTURE_SRC_DIRS))
FIXTURE_OBJS = $(call src_to_o,$(FIXTURE_TEST_SRC))
STUFF_TO_CLEAN += $(FIXTURE_OBJS)

$(ACCEPTANCE_TEST_TARGET) : $(MOCKS_OBJS) $(FIXTURE_OBJS) $(CSLIM_LIB) $(PRODUCTION_CODE_START) $(TARGET_LIB) $(USER_LIBS) $(PRODUCTION_CODE_END) $(STDLIB_CODE_START) 
	$(SILENCE)echo Linking $@
	$(SILENCE)$(LINK.o) -o $@ $^ $(LD_LIBRARIES)

at: $(ACCEPTANCE_TEST_TARGET)

