#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int auto_scale(std::vector<int> average_utils, int num_instances) {
    int poll = 0;
    for(int num : average_utils)
        if(poll > 0) poll--;
        else {
            if(num > 60 && num_instances <= 1e8) num_instances *= 2, poll += 10;
            else if(num < 25 && num_instances > 1) num_instances = (num_instances + 1) / 2, poll += 10;
        }
    return num_instances;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> average_utils = get_words<int>();
    int num_instances;
    std::cin >> num_instances;
    ignore_line();
    int res = auto_scale(average_utils, num_instances);
    std::cout << res << '\n';
}
