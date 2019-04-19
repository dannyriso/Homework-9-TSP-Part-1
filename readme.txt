The Cities class represents the path taken by a traveling salesmen to visit all cities once and then return to home.

The input operator (>>) was overloaded in two different capacities - first for istream, allowing std::cin >> cities, and
then for ifstream, for reading in coordinates from a .tsv file. The two overloads were separated, even though ifstream
inherits from istream, so the user's input from std::cin could be controlled and reading in from a file would be
streamlined. However, both functions have more or less the same implementation. It reads in two integers, saves them as
an std::pair, and then adds a city with that pair to the Cities object.

The output operator (<<) runs through the vector of coordinates (coords_) owned by each Cities object and returns each one,
first integer, then a tab, then the next integer, then a newline. This makes reading it more efficient to read the points
into gnuplot.

The add_city(coord_t point, unsigned int index) method updates two attributes of the cities object - it adds a point
to the vector of std::pairs, which holds the coordinates of each city, and it adds an index to the vector of unsigned
ints which assign each point an index.

The total_path_distance(const permutation_t& ordering) const method calculates the distance between the cities as
ordered by the given permutation. It does so by taking each unsigned int from the permutation, in order, and calling
the city coordinates with that index, and then the following. It calculates the distance between these two cities using
the distance formula, and continues for each index in ordering. Once it reaches the end (when the index is equal to
the size of ordering), it loops back to the beginning city and calculates the final distance for that.

The reorder(const permutation_t& ordering) const method rearranges the nodes in a city and returns a new city with
the reordered nodes by going through each element of ordering, accessing the corresponding node from the old city,
and appending it to the new city. Thus, the new city's order matches the numbers passed in ordering.

The random_permutation(unsigned len) function creates a permutation_t of length len and uses std::shuffle to permute its
elements. The std::shuffle function does so by using a random number generator (in this case, 
std::default_random_engine(std::random_seed) to select two random elements from the permutation_t and swaps them, repeating
this for every element in perm to produce a random reordering.


The test_cities.cc file tests these methods and functions, ensuring that Cities objects can be created from files or
from user input. The functions are tested primarily with respect to five.tsv. The reorder() function is tested first with
manually entered permutation_t objects, and then random_permutation() is used to produce random reorderings.


The tsp.cc file reads in city coordinates from a file, or from user input if needed. It initializes variables for the
shortest distance and its corresponding Cities object, then prints the first distance with the iteration number 1. Even
though the program hasn't started iterating yet, this is an important step because the shortest distance is updated only
if the new distance is less than the existing shortest, which is untrue when they are the same value. This prevents the
same distance from being printed, but the initial distance does need that exception.

While iterating through a fixed number of loops, a new random_permutation is created, then the cities object reordered. The
distance of the new ordering is calculated, and if less than the prior shortest, the shortest distance and corresponding
Cities object are updated, and the iteration number and distance printed out.

Once all the iterations have been completed, the Cities object with the shortest distance is printed to the shortest.tsv
file, then the file is closed and the program returns successfully.


gnuplot wouldn't work on my computer, unable to connect the input to a graphics window, so there are not .gif attachments
in this assignment illustrating the program's work to find the most efficient path.
