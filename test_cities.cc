/*
 * Tests the functionality of the Cities class and its members, and any free functions.
 */

#include "cities.hh"

Cities::permutation_t random_permutation(unsigned len); 

int main(int argc, char* argv[]) {
	// Tests the constructor and overloaded input and output operators
	Cities cities;
	if(argc == 1) {
		std::cin >> cities;
	} else {	
		std::ifstream fin(argv[1]);
		fin >> cities;
	}

	std::cout << cities;

	// Tests the total_path_distance method
	auto perm = cities.get_path();
	auto distance = cities.total_path_distance(perm);
	std::cout << "Distance looks to be " << distance << " units." << std::endl;
	std::cout << std::endl;
	
	// Tests the reorder method
	std::cout << "Now we're rearranging." << std::endl;
	Cities::permutation_t normal_order = {0, 1, 2, 3, 4};
	Cities cities1 = cities.reorder(normal_order);
	std::cout << "Should be the same." << std::endl << cities1;

	Cities::permutation_t switched = {3, 2, 4, 0, 1};
	Cities cities2 = cities.reorder(switched);
	std::cout << "Should be (15, 7), (15, 12), (7, 7), (10, 5), (2, 20)." << std::endl << cities2;
	
	// Tests the random_permutation method
	std::cout << std::endl << std::endl;
	std::cout << "Now we're playing with some random permutations. We have reorder and a generator, so we should"
		<< " be able to just produce whatever perms we like." << std::endl;
	std::cout << "Here, unchanged: " << std::endl << cities2;
	
	unsigned perm_length = 5;
	Cities::permutation_t perm1 = random_permutation(perm_length);
	Cities cities3 = cities2.reorder(perm1);
	std::cout << "New order: ";
	for(auto i = 0; i < 5; ++i) {
		std::cout << perm1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Correspondingly:" << std::endl << cities3;
	
	std::cout << std::endl << std::endl;
	Cities::permutation_t perm2 = random_permutation(perm_length);
	Cities cities4 = cities3.reorder(perm2);
	std::cout << "New order: ";
	for(auto i = 0; i < 5; ++i) {
		std::cout << perm2[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Correspondingly:" << std::endl << cities4;
}
