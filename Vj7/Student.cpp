#include "Student.h"

void UniversityConstants::print_university_rules() {
    std::cout << MAX_ETCS_PER_YEAR << " " << REQUIRED_ECTS_PER_YEAR << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Course& c) {
    return os << c.name << " " << c.code << " " << c.ects;
}

std::istream& operator>>(std::istream& is, Course& c) {
    return is >> c.name >> c.code >> c.ects;
}

int Student::total_students = 0;

Student::Student()
    : id(0), year(1), enrolled_courses(nullptr), enrolled_count(0),
      completed_courses(nullptr), completed_count(0) {
    total_students++;
}

Student::Student(int id, std::string n, std::string p, int y)
    : id(id), name(n), study_program(p), year(y),
      enrolled_courses(nullptr), enrolled_count(0),
      completed_courses(nullptr), completed_count(0) {
    total_students++;
}

Student::~Student() {
    delete[] enrolled_courses;
    delete[] completed_courses;
    total_students--;
}

Student::Student(const Student& s) : Student(s.id, s.name, s.study_program, s.year) {}

Student& Student::operator=(const Student& s) {
    if (this != &s) {
        id = s.id;
        name = s.name;
        study_program = s.study_program;
        year = s.year;
    }
    return *this;
}

Student::Student(Student&& s) noexcept { *this = std::move(s); }

Student& Student::operator=(Student&& s) noexcept {
    id = s.id;
    name = std::move(s.name);
    study_program = std::move(s.study_program);
    year = s.year;
    enrolled_courses = s.enrolled_courses;
    enrolled_count = s.enrolled_count;
    completed_courses = s.completed_courses;
    completed_count = s.completed_count;
    s.enrolled_courses = nullptr;
    s.completed_courses = nullptr;
    return *this;
}

int Student::get_total_students() {
    return total_students;
}

void Student::enroll_course(const Course& c) {
    Course* tmp = new Course[enrolled_count + 1];
    for (size_t i = 0; i < enrolled_count; i++) tmp[i] = enrolled_courses[i];
    tmp[enrolled_count++] = c;
    delete[] enrolled_courses;
    enrolled_courses = tmp;
}

void Student::complete_course(size_t i) {
    Course* tmp = new Course[completed_count + 1];
    for (size_t j = 0; j < completed_count; j++) tmp[j] = completed_courses[j];
    tmp[completed_count++] = enrolled_courses[i];
    delete[] completed_courses;
    completed_courses = tmp;
}

Student& Student::operator+=(const Course& c) {
    enroll_course(c);
    return *this;
}

Student& Student::operator++() {
    if (completed_count * 5 >= UniversityConstants::REQUIRED_ECTS_PER_YEAR)
        year++;
    return *this;
}

Student Student::operator++(int) {
    Student tmp = *this;
    ++(*this);
    return tmp;
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    return os << s.id << " " << s.name << " " << s.study_program << " " << s.year;
}

std::istream& operator>>(std::istream& is, Student& s) {
    return is >> s.id >> s.name >> s.study_program >> s.year;
}

void StudentOffice::moveStudent(Student& s, std::string p) {
    s.study_program = std::move(p);
}

void StudentOffice::enroll_student(Student& s, const Course& c) {
    if (s.enrolled_count * 5 < UniversityConstants::MAX_ETCS_PER_YEAR)
        s += c;
}

void StudentOffice::process_exam_results(Student& s) {
    if (s.enrolled_count > 0)
        s.complete_course(0);
}

void StudentOffice::update_student_years(std::vector<Student>& v) {
    for (auto& s : v) ++s;
}

int main() {
    std::vector<Student> students;
    students.emplace_back(1, "Ana", "IT", 1);

    Course c{"Mat", "MAT1", 5};
    StudentOffice so;

    so.enroll_student(students[0], c);
    so.process_exam_results(students[0]);
    so.update_student_years(students);

    std::cout << students[0] << std::endl;
}
