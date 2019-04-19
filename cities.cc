/* 
 * Implementation of the Cities class and its methods, as well as free functions
 */

#include "cities.hh"

Cities Cities::reorder(const permutation_t& ordering) const {
	Cities cities;
	
	auto new_index = 0;
	for(auto old_city_index : ordering) {
		auto new_city_next = get_coord(old_city_index);
		cities.add_city(new_city_next, new_index);
		++new_index;
	}
	return cities;
}

double Cities::total_path_distance(const permutation_t& ordering) const {
	double distance = 0;
	for(auto index : ordering) {
		auto city1 = get_coord(index);
		coord_t city2;
		
		// Checks that the next city is within the bounds of the permutation; if not, every city has been
		// visited, and the salesman returns home.
		if((index + 1) < ordering.size()) {
			city2 = get_coord(index + 1);
		} else {
			city2 = get_coord(0);
		}
		distance += std::sqrt(std::pow(std::abs(city1.first - city2.first), 2) + (std::pow(std::abs(city1.second - city2.second), 2)));
	}
	return distance;
}

Cities::nodes_t Cities::get_coords() const {
	return coords_;
}
Cities::coord_t Cities::get_coord(unsigned int index) const {
	return coords_[index];
}
Cities::permutation_t Cities::get_path() const {
	return path_;
}

void Cities::add_city(Cities::coord_t point, unsigned int index) {
	coords_.push_back(point);
	path_.push_back(index);
}

std::istream& operator>>(std::istream& in, Cities& cities) {
	std::cout << "How many cities must the salesman visit?" << std::endl;
	int num_cities;
	in >> num_cities;
	std::cout << "Enter city coordinates by typing two numbers separated by a space." << std::endl;
	for(auto i = 0; i < num_cities; ++i) {
		int x, y;
		in >> x >> y;
		Cities::coord_t point = std::make_pair(x, y);
		cities.add_city(point, i);
	}
	return in;
}

std::ifstream& operator>>(std::ifstream& in, Cities& cities) {
	int x, y;
	auto index = 0;
	while(in >> x >> y) {
		Cities::coord_t point = std::make_pair(x, y);
		cities.add_city(point, index);
		++index;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Cities& cities) {
	for(auto coord : cities.get_coords()) {
		out << coord.first << "\t" << coord.second << std::endl;
	}
	return out;
}

Cities::permutation_t random_permutation(unsigned len) {
	Cities::permutation_t perm;
	for(unsigned i = 0; i < len; ++i) {
		perm.push_back(i);
	}
	
	std::random_device seed;
	std::default_random_engine rand(seed());
	std::shuffle(perm.begin(), perm.end(), rand);
	return perm;
}
