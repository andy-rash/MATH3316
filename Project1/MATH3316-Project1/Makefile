#
# Makefile 
# MATH3316-Project1
#
#  Created by andy on 9/25/17.
#  Copyright © 2017 andy. All rights reserved.
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

TARGETA = Project1_Part1
TARGETB = Project1_Part2
TARGETC = Project1_Part3

PT1FILES = nest.cpp proj1_a.cpp
PT2FILES = proj1_b.cpp
PT3FILES = proj1_c.cpp

LIBFILES = Matrix.cpp Vector.cpp

NOTEBOOK = $(DOC)RobertRash_MATH3316_Project1.ipynb

REPORT = $(RP)RobertRash_MATH3316_Project1.pdf

#################################
# All targets                   #
#################################

all: all_bin all_data all_reports

#################################
# Application binaries          #
#################################

all_bin: $(TARGETA) $(TARGETB) $(TARGETC)

$(TARGETA): 
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETA) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(PT1FILES))

$(TARGETB):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETB) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(PT2FILES))

$(TARGETC):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETC) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(PT3FILES))

#################################
# Data files                    #
#################################

all_data: data_a data_b data_c

data_a: $(TARGETA) 
	./$(BIN)$(TARGETA)

data_b: $(TARGETB)
	./$(BIN)$(TARGETB)

data_c: $(TARGETC)
	./$(BIN)$(TARGETC)

#################################
# Reports                       #
#################################

all_reports: $(REPORT)

$(REPORT): data_a data_b data_c $(NOTEBOOK)
	jupyter nbconvert --to pdf --execute $(NOTEBOOK) --output-dir $(ROOT)$(RP)

#################################
# Miscellaneous                 #
#################################

clean:
	rm -f ./$(addprefix $(BIN), $(TARGETA))
	rm -f ./$(addprefix $(BIN), $(TARGETB))
	rm -f ./$(addprefix $(BIN), $(TARGETC))
	rm -f ./$(DOC)*.nbconvert.ipynb
	rm -f ./$(RES)part1/*
	rm -f ./$(RES)part2/*
	rm -f ./$(RES)part3/*


