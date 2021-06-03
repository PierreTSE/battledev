template<typename T>
ostream& operator<<(ostream& out, const vector <T>& v) {
    out << '{';
    for (auto it = v.begin(); it != v.end() - 1; it++)
        out << *it << ", ";
    if (!v.empty())
        out << *(v.end() - 1);
    out << '}' << endl;
    return out;
}

template<typename T, typename U>
ostream& operator<<(ostream& out, const pair <T, U>& p) { return out << '{' << p.first << ", " << p.second << '}'; }

template<typename IT>
IT first_diff(IT first1, IT last1, IT first2) {
    while (first1 != last1) {
        if (*first1 != *first2)
            return first1;
        ++first1;
        ++first2;
    }
    return last1;
}

template<typename T>
bool in_range(const T& value, const T& min, const T& max) { return !(max < value || value < min); }

template<typename T>
bool in_range_s(const T& value, const T& min, const T& max) { return (min < value && value < max); }

template<typename T>
bool point_in_rect(const T& x, const T& y, const T& x_min, const T& x_max, const T& y_min, const T& y_max) {
    return in_range(x, x_min, x_max) && in_range(y, y_min, y_max);
}

template<typename T>
bool point_in_rect_s(const T& x, const T& y, const T& x_min, const T& x_max, const T& y_min, const T& y_max) {
    return in_range_s(x, x_min, x_max) && in_range_s(y, y_min, y_max);
}

template<typename T>
bool point_in_circle(const T& x, const T& y, const T& x_o, const T& y_o, const T& radius) {
    return !(radius * radius < ((x - x_o) * (x - x_o)
                                + (y - y_o) * (y - y_o)));
}

template<typename T>
bool point_in_circle_s(const T& x, const T& y, const T& x_o, const T& y_o, const T& radius) {
    return ((x - x_o) * (x - x_o) + (y - y_o) * (y - y_o)) < radius * radius;
}

template<typename T>
string to_string(const T& value) {
    ostringstream oss;
    oss << value;
    return oss.str();
}

template<typename T>
T from_str(const string& str) {
    istringstream iss;
    iss.str(str);
    T value;
    iss >> value;
    if (iss.fail())
        throw exception();
    return value;
}

double dist(double x1, double y1, double x2, double y2) { return hypot(x1 - x2, y1 - y2); }

//-------------------------------------------------------------------------------------------------------------------------------

// Knapsack

struct Item {
    double value = 0, weight = 0;
    bool divisible = true;

    Item(double value, double weight, bool divisible = true) : value(value), weight(weight), divisible(divisible) {}
};

double greedyKnapsack(double capacity, vector <Item> items) {
    // sorting Item by decreasing value ratio
    sort(items.rbegin(), items.rend(), [](Item const& a, Item const& b) { return a.value / a.weight < b.value / b.weight; });

    double currWeight = 0;  // Current weight in knapsack
    double finalValue = 0; // Result (value in Knapsack)

    for (auto const& item : items) {
        // If adding Item won't overflow, add it completely
        if (currWeight + item.weight <= capacity) {
            currWeight += item.weight;
            finalValue += item.value;
        }
            // If we can't add current Item, add fractional part of it
        else if (item.divisible) {
            auto remain = capacity - currWeight;
            finalValue += item.value * (remain / item.weight);
            break;
        }
    }

    return finalValue;
}