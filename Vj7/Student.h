#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <vector>

struct UniversityConstants {
    static const int MAX_ETCS_PER_YEAR = 60;
    static const int REQUIRED_ECTS_PER_YEAR = 45;
    static void print_university_rules();
};

struct Course {
    std::string name;
    std::string code;
    int ects;

    friend std::ostream& operator<<(std::ostream&, const Course&);
    friend std::istream& operator>>(std::istream&, Course&);
};

class StudentOffice;

class Student {
private:
    int id;
    std::string name;
    std::string study_program;
    int year;

    Course* enrolled_courses;
    size_t enrolled_count;
    Course* completed_courses;
    size_t completed_count;

    static int total_students;

public:
    Student();
    Student(int, std::string, std::string, int);
    ~Student();

    Student(const Student&);
    Student& operator=(const Student&);
    Student(Student&&) noexcept;
    Student& operator=(Student&&) noexcept;

    static int get_total_students();

    void enroll_course(const Course&);
    void complete_course(size_t);

    Student& operator+=(const Course&);
    Student& operator++();
    Student operator++(int);

    friend std::ostream& operator<<(std::ostream&, const Student&);
    friend std::istream& operator>>(std::istream&, Student&);
    friend class StudentOffice;
};

class StudentOffice {
public:
    void moveStudent(Student&, std::string);
    void enroll_student(Student&, const Course&);
    void process_exam_results(Student&);
    void update_student_years(std::vector<Student>&);
};

#endif
