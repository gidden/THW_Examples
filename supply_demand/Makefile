SRC=App.cpp SupplyDemandManager.cpp
OUTNAME=app

# C++ Compiler command
CXX = g++

# C++ Compiler options
CXXFLAGS = -O3  

all:
	$(CXX) $(SRC) -o $(OUTNAME) $(CXXFLAGS)

clean: 

	rm -rf $(OUTNAME)

run:
	./$(OUTNAME)

debug: 
	g++ -g $(SRC) -o $(OUTNAME) $(CXXFLAGS)
