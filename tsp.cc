// Reads in a .tsv file and calculates, out of 1 000 000 iterations, the shortest path between all cities given in the
// .tsv file. Once it's been found, prints the shortest distance and iteration number to shortest.tsv.

#include "cities.hh"
#include <iostream>
#include <fstream>

Cities::permutation_t random_permutation(unsigned len); 

int main(int argc, char* argv[]) {
	Cities cities;
	if(argc == 1) {
		std::cin >> cities;
	} else {	
		std::ifstream fin(argv[1]);
		fin >> cities;
	}
	
	unsigned path_len = cities.get_path().size();
	auto short_dist = cities.total_path_distance(cities.get_path());
	auto short_path = cities;
	std::cout << 1 << "\t" << short_dist << std::endl;

	for(auto i = 1; i <= 1000000; ++i) {
		auto perm = random_permutation(path_len);
		cities = cities.reorder(perm);
		auto new_dist = cities.total_path_distance(cities.get_path());
		if(new_dist < short_dist) {
			short_dist = new_dist;
			short_path = cities;
			std::cout << i << "\t" << new_dist << std::endl;
		}
	}
	
	std::ofstream out("shortest.tsv");
	out << short_path;
	out.close();

	return 0;
}
