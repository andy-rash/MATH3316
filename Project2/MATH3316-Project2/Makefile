#
# Makefile 
# MATH3316-Project2
#
#  Created by andy on 10/12/17.
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

TARGETA = Project2_Part1
TARGETB = Project2_Part2

PT1FILES = test_newton.cpp 
PT2FILES = kepler.cpp

LIBFILES = Matrix.cpp Vector.cpp

NOTEBOOK = $(DOC)RobertRash_MATH3316_Project2.ipynb

REPORT = $(RP)RobertRash_MATH3316_Project2.pdf

#################################
# All targets                   #
#################################

all: all_bin all_data all_reports

#################################
# Application binaries          #
#################################

all_bin: $(TARGETA) $(TARGETB)

$(TARGETA): 
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETA) $(addprefix $(SRC), $(PT1FILES))

$(TARGETB):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETB) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(PT2FILES))

#################################
# Data files                    #
#################################

all_data: data_b 

data_b: $(TARGETB)
	./$(BIN)$(TARGETB)

#################################
# Reports                       #
#################################

all_reports: $(REPORT)

$(REPORT): data_b $(NOTEBOOK)
	jupyter nbconvert --to pdf --execute $(NOTEBOOK) --output-dir $(ROOT)$(RP)

#################################
# Miscellaneous                 #
#################################

clean:
	rm -f ./$(addprefix $(BIN), $(TARGETA))
	rm -f ./$(addprefix $(BIN), $(TARGETB))
	rm -f ./$(DOC)*.nbconvert.ipynb
	rm -f ./$(RES)part2/*


