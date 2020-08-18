CXX = g++
CXXFLAGS = -c -g -Wall -pedantic -std=c++14

BUILD = build
BINNAME = poliaart

all: compile doc


compile: build/Slice.o build/BaseMatrix.o build/FMatrix.o build/Matrix.o build/Addition.o build/Determinant.o build/GaussianElimination.o build/Merge.o build/Multiplication.o build/Operation.o build/Rank.o build/Split.o build/Subtraction.o build/Transposition.o build/Application.o build/Table.o build/main.o
	mkdir -p $(BUILD)
	$(CXX) $^ -o $(BINNAME)


run: compile
	./$(BINNAME)


doc:
	doxygen Doxyfile

clean:
	rm -rf $(BUILD)
	rm -rf doc
	rm -f $(BINNAME)
	

build/Slice.o: src/lib/matrices/Slice.cpp src/lib/matrices/Slice.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/BaseMatrix.o: src/lib/matrices/BaseMatrix.cpp src/lib/matrices/BaseMatrix.h src/lib/matrices/Slice.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/FMatrix.o: src/lib/matrices/FMatrix.cpp src/lib/matrices/FMatrix.h src/lib/matrices/BaseMatrix.h src/lib/matrices/Slice.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/Matrix.o: src/lib/matrices/Matrix.cpp src/lib/matrices/Matrix.h src/lib/matrices/Slice.h src/lib/matrices/BaseMatrix.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/Addition.o: src/lib/operations/Addition.cpp src/lib/operations/Addition.h src/lib/operations/../matrices/Matrix.h src/lib/operations/../matrices/Slice.h src/lib/operations/../matrices/BaseMatrix.h src/lib/operations/Operation.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/Determinant.o: src/lib/operations/Determinant.cpp src/lib/operations/Determinant.h src/lib/operations/../matrices/Matrix.h src/lib/operations/../matrices/Slice.h src/lib/operations/../matrices/BaseMatrix.h src/lib/operations/Operation.h 
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/GaussianElimination.o: src/lib/operations/GaussianElimination.cpp src/lib/operations/GaussianElimination.h src/lib/operations/../matrices/Matrix.h src/lib/operations/../matrices/Slice.h src/lib/operations/../matrices/BaseMatrix.h src/lib/operations/Operation.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/Merge.o: src/lib/operations/Merge.cpp src/lib/operations/Merge.h src/lib/operations/../matrices/Matrix.h src/lib/operations/../matrices/Slice.h src/lib/operations/../matrices/BaseMatrix.h src/lib/operations/Operation.h 
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/Multiplication.o: src/lib/operations/Multiplication.cpp src/lib/operations/Multiplication.h src/lib/operations/../matrices/Matrix.h src/lib/operations/../matrices/Slice.h src/lib/operations/../matrices/BaseMatrix.h src/lib/operations/Operation.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@

 
build/Operation.o: src/lib/operations/Operation.cpp src/lib/operations/Operation.h src/lib/operations/../matrices/Matrix.h src/lib/operations/../matrices/Slice.h src/lib/operations/../matrices/BaseMatrix.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/Rank.o: src/lib/operations/Rank.cpp src/lib/operations/Rank.h src/lib/matrices/Matrix.h src/lib/matrices/Slice.h src/lib/matrices/BaseMatrix.h src/lib/operations/Operation.h src/lib/operations/GaussianElimination.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/Split.o: src/lib/operations/Split.cpp src/lib/operations/Split.h src/lib/operations/../matrices/Matrix.h src/lib/operations/../matrices/Slice.h src/lib/operations/../matrices/BaseMatrix.h src/lib/operations/Operation.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/Subtraction.o: src/lib/operations/Subtraction.cpp src/lib/operations/Subtraction.h src/lib/operations/../matrices/Matrix.h src/lib/operations/../matrices/Slice.h src/lib/operations/../matrices/BaseMatrix.h src/lib/operations/Operation.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/Transposition.o: src/lib/operations/Transposition.cpp src/lib/operations/Transposition.h src/lib/operations/../matrices/Matrix.h src/lib/operations/../matrices/Slice.h src/lib/operations/../matrices/BaseMatrix.h src/lib/operations/Operation.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/Table.o: src/app/Table.cpp src/app/Table.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/Application.o: src/app/Application.cpp src/app/Application.h src/lib/matrices/Matrix.h src/lib/matrices/Slice.h src/lib/matrices/BaseMatrix.h src/lib/operations/Addition.h src/lib/operations/Operation.h src/lib/operations/Subtraction.h src/lib/operations/Multiplication.h src/lib/operations/Merge.h src/lib/operations/Split.h src/lib/operations/Transposition.h src/lib/operations/GaussianElimination.h src/lib/operations/Rank.h src/lib/operations/Determinant.h src/app/Table.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@


build/main.o: src/main.cpp src/app/Application.h src/lib/matrices/Matrix.h src/lib/matrices/Slice.h src/lib/matrices/BaseMatrix.h src/lib/operations/Addition.h src/lib/operations/Operation.h src/lib/operations/Subtraction.h src/lib/operations/Multiplication.h src/lib/operations/Merge.h src/lib/operations/Split.h src/lib/operations/Transposition.h src/lib/operations/GaussianElimination.h src/lib/operations/Rank.h src/lib/operations/Determinant.h src/app/Table.h
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@
