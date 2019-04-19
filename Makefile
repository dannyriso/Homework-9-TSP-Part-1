CXX=g++ -std=c++17
CXXFLAGS=-Wall -Wextra -pedantic -Werror -O0 -g

all: tsp test_cities

tsp : tsp.o cities.o
	$(CXX) $(CXXFLAGS) -o $@ $^

test_cities : test_cities.o cities.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.cc %.hh
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf *.o tsp cities test_cities shortest.tsv speed.tsv
