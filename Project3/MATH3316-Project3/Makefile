#
# Makefile 
# MATH3316-Project3
#
# Created by andy on 11/15/17.
# Copyright © 2017 andy. All rights reserved.
#

CXX = g++
CFLAGS = -std=c++14

BIN = bin/
DOC = doc/
LIB = lib/
RES = res/
ROOT = $(shell pwd)/
RP = $(DOC)reports/
SRC = src/

TARGETA = Project3_Part1
TARGETB_1 = Project3_Part2_1
TARGETB_2 = Project3_Part2_2
TARGETB_3 = Project3_Part2_3
TARGETC = Project3_Part3

PT1_FILES = newton_interpolator.cpp test_Newton_test.cpp 
PT2_1_FILES = lagrange_interpolator.cpp newton_interpolator.cpp interpolation_degree.cpp
PT2_2_FILES = lagrange_interpolator.cpp newton_interpolator.cpp Runge_uniform.cpp
PT2_3_FILES = lagrange_interpolator.cpp newton_interpolator.cpp Runge_Chebyshev.cpp
PT3_FILES = lagrange_interpolator.cpp application.cpp

LIBFILES = Matrix.cpp Vector.cpp

NOTEBOOK = $(DOC)RobertRash_MATH3316_Project3.ipynb

REPORT = $(RP)RobertRash_MATH3316_Project3.pdf

#################################
# All targets                   #
#################################

all: all_bin all_data all_reports

#################################
# Application binaries          #
#################################

all_bin: $(TARGETA) $(TARGETB_1) $(TARGETB_2) $(TARGETB_3) $(TARGETC)

$(TARGETA): 
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETA) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(PT1_FILES))

$(TARGETB_1):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETB_1) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(PT2_1_FILES))

$(TARGETB_2):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETB_2) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(PT2_2_FILES))

$(TARGETB_3):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETB_3) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(PT2_3_FILES))

$(TARGETC):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETC) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(PT3_FILES))

#################################
# Data files                    #
#################################

all_data: data_a data_b_1 data_b_2 data_b_3 data_c

data_a: $(TARGETA) 
	./$(BIN)$(TARGETA)

data_b_1: $(TARGETB_1)
	./$(BIN)$(TARGETB_1)

data_b_2: $(TARGETB_2)
	./$(BIN)$(TARGETB_2)

data_b_3: $(TARGETB_3)
	./$(BIN)$(TARGETB_3)

data_c: $(TARGETC)
	./$(BIN)$(TARGETC)

#################################
# Reports                       #
#################################

all_reports: $(REPORT)

$(REPORT): all_data $(NOTEBOOK)
	jupyter nbconvert --to pdf --execute $(NOTEBOOK) --output-dir $(ROOT)$(RP)

#################################
# Miscellaneous                 #
#################################

clean:
	rm -f ./$(addprefix $(BIN), $(TARGETA))
	rm -f ./$(addprefix $(BIN), $(TARGETB_1))
	rm -f ./$(addprefix $(BIN), $(TARGETB_2))
	rm -f ./$(addprefix $(BIN), $(TARGETB_3))
	rm -f ./$(addprefix $(BIN), $(TARGETC))
	rm -f ./$(DOC)*.nbconvert.ipynb
	rm -f ./$(RES)part1/*
	rm -f ./$(RES)part2/function/*
	rm -f ./$(RES)part2/runge_chebyshev/*
	rm -f ./$(RES)part2/runge_uniform/*
	rm -f ./$(RES)part3/*


