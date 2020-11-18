# A sample Makefile for building Google Test and using it in user
# tests.  Please tweak it to suit your environment and project.  You
# may want to move it to your project's root directory.
#
# SYNOPSIS:
#
#   make [all]  - makes everything.
#   make TARGET - makes the given target.
#   make clean  - removes all files generated by make.

# Please tweak the following variable definitions as needed by your
# project, except GTEST_HEADERS, which you can use in your own targets
# but shouldn't modify.

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = /Users/javier/Desktop/carrera/practicaPOO/googletest-release-1.8.1/googletest/
# Where to find user code.
# USER_DIR = ../samples

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread -std=gnu++11

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = persona_unittest jugador_unittest crupier_unittest ruleta_unittest

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.
# make comienza con el primer target, el "default goal"
# que incluye $(TEST) y, por tanto, intentará constriur cada uno de esos ejecutables
all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o ??XX.txt

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

persona.o : persona.h persona.cc

crupier.o: crupier.h crupier.cc persona.h persona.cc

jugador.o: jugador.h jugador.cc persona.h persona.cc

ruleta.o: ruleta.h ruleta.cc jugador.h jugador.cc persona.h persona.cc crupier.h crupier.cc

persona_unittest.o : persona_unittest.cc persona.h persona.cc

crupier_unittest.o : crupier_unittest.cc crupier.h crupier.cc persona.h persona.cc

jugador_unittest.o : jugador_unittest.cc jugador.h jugador.cc persona.h persona.cc

ruleta_unittest.o : ruleta_unittest.cc jugador.h jugador.cc ruleta.h ruleta.cc persona.h persona.cc crupier.h crupier.cc

persona_unittest : persona.o persona_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
	
crupier_unittest : crupier.o persona.o crupier_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

jugador_unittest : jugador.o persona.o jugador_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

ruleta_unittest : ruleta.o persona.o jugador.o crupier.o ruleta_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

