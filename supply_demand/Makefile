SRC=App.cpp SupplyDemandManager.cpp
OUTNAME=app

# C++ Compiler command
CXX = g++

# C++ Compiler options
#CXXFLAGS = -O3 -fomit-frame-pointer -pipe -DNDEBUG -pedantic-errors -Wimplicit -Wparentheses -Wreturn-type -Wcast-qual -Wall -Wpointer-arith -Wwrite-strings -Wconversion -Wno-unknown-pragmas  

all:
	$(CXX) $(SRC) -o $(OUTNAME) $(CXXFLAGS) $(CXXLINKFLAGS) $(LIBS) $(INCL)

clean: 

	rm -rf $(OUTNAME)

run:
	./$(OUTNAME)

debug: 
	g++ -g $(SRC) -o $(OUTNAME) $(CXXFLAGS) $(CXXLINKFLAGS) $(LIBS) $(INCL)
