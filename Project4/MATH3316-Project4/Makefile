#
# Makefile 
# MATH3316-Project4
#
# Created by andy on 11/28/17.
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
PT1_1_SRC = src/part1/
PT1_2_SRC = src/part1/gauss/
PT2_SRC = src/part2/

TARGETA_1 = Project4_Part1_1
TARGETA_2 = Project4_Part1_2
TARGETB = Project4_Part2

PT1_1_FILES = numerical_integrator.cpp test_basic_rules.cpp 
PT1_2_FILES = composite_Gauss2.cpp test_Gauss2.cpp
PT2_FILES = test_carbon.cpp

LIBFILES = Matrix.cpp Vector.cpp

NOTEBOOK = $(DOC)RobertRash_MATH3316_Project4.ipynb

REPORT = $(RP)RobertRash_MATH3316_Project4.pdf

#################################
# All targets                   #
#################################

all: all_bin all_data all_reports

#################################
# Application binaries          #
#################################

all_bin: $(TARGETA_1) $(TARGETA_2) $(TARGETB)

$(TARGETA_1): 
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETA_1) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(PT1_1_SRC), $(PT1_1_FILES))

$(TARGETA_2):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETA_2) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(PT1_2_SRC), $(PT1_2_FILES))

$(TARGETB):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETB) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(PT2_SRC), $(PT2_FILES))

#################################
# Data files                    #
#################################

all_data: data_a_1 data_a_2 data_b 

data_a_1: $(TARGETA_1) 
	./$(BIN)$(TARGETA_1)

data_a_2: $(TARGETA_2)
	./$(BIN)$(TARGETA_2)

data_b: $(TARGETB)
	./$(BIN)$(TARGETB)

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
	rm -f ./$(addprefix $(BIN), $(TARGETA_1))
	rm -f ./$(addprefix $(BIN), $(TARGETA_2))
	rm -f ./$(addprefix $(BIN), $(TARGETB))
	rm -f ./$(DOC)*.nbconvert.ipynb
	rm -f ./$(RES)/part1/*
	rm -f ./$(RES)/part2/*

