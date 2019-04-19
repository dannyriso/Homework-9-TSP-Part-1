/*
 * API file for Travelling-Salesperson Cities class and utilities
 */

#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath> // For calculating the distance between cities
#include <random> // For the random_permutation method
#include <algorithm> // For std::shuffle
#include <iterator>

// Representation of an ordering of cities, each represented as a coord_t
class Cities {
	public:
		// A pair of integral coordinates for each city
		using coord_t = std::pair<int, int>;
		
		// An ordering of the cities in cities_t. Each value represents a unique index
		// into the current city ordering.
		using permutation_t = std::vector<unsigned int>;
		
		using nodes_t = std::vector<coord_t>;
		
	private:
		nodes_t coords_;
		permutation_t path_;
		
	public:
		Cities() = default;
		~Cities() = default;
		
		// Given a permutation, return a new Cities object where the order of the
		// cities reflects the original order of this class after reordering with
		// the given ordering. So for example, the ordering { 1, 0 } simply swaps
		// the first two elements (coordinates) in the new Cities object.
		Cities reorder(const permutation_t& ordering) const;
		
		// For a given permutation of the cities in this object,
		// compute how long (distance) it would take to traverse all the cities in the
		// order of the permutation, and then returning to the first city.
		// The distance between any two cities is computed as the Euclidean 
		// distance on a plane between their coordinates.
		double total_path_distance(const permutation_t& ordering) const;
		
		nodes_t get_coords() const;
		coord_t get_coord(unsigned int index) const;
		permutation_t get_path() const;
		void add_city(coord_t point, unsigned int index);
		
		friend std::ifstream& operator>>(std::ifstream&, Cities& cities);
		friend std::istream& operator>>(std::istream&, Cities& cities);
		friend std::ostream& operator<<(std::ostream&, const Cities& cities);
};
