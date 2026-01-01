#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <fstream>
#include <cmath>
#include <string>

namespace math_utils {

struct Point {
    double x, y;
};

double distance(const Point& a, const Point& b = {0, 0}) {
    return std::sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

Point centroid(const std::vector<Point>& v) {
    Point sum = std::accumulate(v.begin(), v.end(), Point{0,0},
        [](Point a, const Point& b){
            return Point{a.x + b.x, a.y + b.y};
        });
    return {
        static_cast<double>(sum.x / v.size()),
        static_cast<double>(sum.y / v.size())
    };
}

}

namespace student_records {

struct Student {
    std::string ime, prezime;
    int bodovi;
};

}

int main() {
    std::vector<int> nums = {1,2,3,4,5,8,16,7,9};

    auto it = std::find_if(nums.begin(), nums.end(), [](int x){ return x % 2; });
    if (it != nums.end()) std::cout << *it << std::endl;

    int odd_count = std::count_if(nums.begin(), nums.end(), [](int x){ return x % 2; });
    std::cout << odd_count << std::endl;

    int odd_sum = std::accumulate(nums.begin(), nums.end(), 0,
        [](int s, int x){ return x % 2 ? s + x : s; });
    if (odd_count)
        std::cout << static_cast<double>(odd_sum) / odd_count << std::endl;

    std::replace_if(nums.begin(), nums.end(),
        [](int x){ return x && (x & (x - 1)) == 0; }, 2);

    std::sort(nums.begin(), nums.end(), [](int a, int b){
        if (a % 2 == b % 2) return a < b;
        return a % 2 == 0;
    });

    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::ifstream pf("points.txt");
    std::vector<math_utils::Point> points(
        (std::istream_iterator<math_utils::Point>(pf)),
        std::istream_iterator<math_utils::Point>());

    std::sort(points.begin(), points.end(),
        [](const math_utils::Point& a, const math_utils::Point& b){
            return math_utils::distance(a) < math_utils::distance(b);
        });

    int q1 = std::count_if(points.begin(), points.end(),
        [](const math_utils::Point& p){ return p.x > 0 && p.y > 0; });
    std::cout << q1 << std::endl;

    auto c = math_utils::centroid(points);
    std::cout << c.x << " " << c.y << std::endl;

    std::transform(points.begin(), points.end(), points.begin(),
        [](math_utils::Point p){ return math_utils::Point{p.x + 5, p.y + 3}; });

    points.erase(std::remove_if(points.begin(), points.end(),
        [](const math_utils::Point& p){ return p.x < 0 && p.y < 0; }),
        points.end());

    for (auto& p : points)
        std::cout << p.x << " " << p.y << std::endl;

    std::ifstream sf("studenti.txt");
    std::vector<student_records::Student> students(
        (std::istream_iterator<student_records::Student>(sf)),
        std::istream_iterator<student_records::Student>());

    auto bodovi_u_ocjenu = [](int b){
        if (b < 40) return 1;
        if (b < 55) return 2;
        if (b < 70) return 3;
        if (b < 85) return 4;
        return 5;
    };

    students.erase(std::remove_if(students.begin(), students.end(),
        [](const student_records::Student& s){ return s.bodovi < 40; }),
        students.end());

    std::transform(students.begin(), students.end(), students.begin(),
        [&](student_records::Student s){
            s.bodovi = bodovi_u_ocjenu(s.bodovi);
            return s;
        });

    double avg = std::accumulate(students.begin(), students.end(), 0.0,
        [](double s, const student_records::Student& st){
            return s + static_cast<double>(st.bodovi);
        }) / students.size();

    std::sort(students.begin(), students.end(),
        [](const student_records::Student& a, const student_records::Student& b){
            return a.prezime < b.prezime;
        });

    for (auto& s : students)
        std::cout << s.ime << " " << s.prezime << " " << s.bodovi << std::endl;

    std::cout << avg << std::endl;
}
