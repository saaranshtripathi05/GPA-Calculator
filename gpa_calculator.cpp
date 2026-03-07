#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
#include <limits>

const std::unordered_map<std::string, int> Gradep = {
    {"O", 10}, {"A+", 9}, {"A", 8},
    {"B+", 7}, {"B", 6}, {"C", 5}, {"F", 0}
};

int getPositiveInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value > 0) {
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a positive integer.\n";
    }
}

double getValidGradePoint(const std::string& prompt) {
    std::string grade;
    while (true) {
        std::cout << prompt;
        std::cin >> grade;
        std::transform(grade.begin(), grade.end(), grade.begin(), ::toupper);

        auto it = Gradep.find(grade);
        if (it != Gradep.end()) {
            return it->second;
        }
        std::cout << "Invalid grade. Use: O, A+, A, B+, B, C, F  → try again.\n";
    }
}

void calculateSGPA() {
    std::cout << "\n--- SGPA Calculator ---\n";

    int subjects = getPositiveInt("Enter number of subjects: ");

    std::vector<int> credits(subjects);
    std::vector<std::string> grades(subjects);
    std::vector<double> points(subjects);

    std::cout << "\nEnter credits for each subject:\n";
    for (int i = 0; i < subjects; ++i) {
        credits[i] = getPositiveInt("  Subject " + std::to_string(i + 1) + " credits: ");
    }

    std::cout << "\nEnter grades for each subject:\n";
    double total_points = 0.0;
    int total_credits = 0;

    for (int i = 0; i < subjects; ++i) {
        double gp = getValidGradePoint("  Subject " + std::to_string(i + 1) + " grade: ");
        points[i] = gp;
        grades[i] = ""; 
        total_points += gp * credits[i];
        total_credits += credits[i];
    }

    std::cout << "\nYou entered:\n";
std::cout << "+----------+----------+------------+\n";
std::cout << "| Subject  | Credits  | Grade Pt.  |\n";
std::cout << "+----------+----------+------------+\n";

for (int i = 0; i < subjects; ++i) {
    std::cout << "| " 
              << std::left  << std::setw(8)  << (i + 1)   << " "
              << "| " << std::right << std::setw(8)  << credits[i] << " "
              << "| " << std::right << std::setw(10) << std::fixed << std::setprecision(1) << points[i] << " |\n";
}

std::cout << "+----------+----------+------------+\n";

    if (total_credits == 0) {
        std::cout << "Error: Total credits cannot be zero.\n";
        return;
    }

    double sgpa = total_points / total_credits;
    std::cout << "\nYour SGPA = " << std::fixed << std::setprecision(2) << sgpa << "\n\n";
}

void calculateCGPA() {
    std::cout << "\n--- CGPA Calculator (weighted by credits) ---\n";

    int semesters = getPositiveInt("Enter number of semesters: ");

    std::vector<double> sgpas(semesters);
    std::vector<int> sem_credits(semesters);

    double total_points = 0.0;
    int total_credits = 0;

    for (int i = 0; i < semesters; ++i) {
        std::cout << "\nSemester " << (i + 1) << ":\n";

        double sgpa_input;
        while (true) {
            std::cout << "  SGPA of semester " << (i + 1) << ": ";
            if (std::cin >> sgpa_input && sgpa_input >= 0.0 && sgpa_input <= 10.0) {
                sgpas[i] = sgpa_input;
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a valid SGPA (0.0 to 10.0).\n";
        }
        // ─────────────────────────────────────────────────────────────────

        sem_credits[i] = getPositiveInt("  Total credits in semester " + std::to_string(i + 1) + ": ");

        total_points += sgpas[i] * sem_credits[i];
        total_credits += sem_credits[i];
    }

    if (total_credits == 0) {
        std::cout << "Error: Total credits cannot be zero.\n";
        return;
    }

    double cgpa = total_points / total_credits;

    std::cout << "\nSummary:\n";
    std::cout << "+-----------+----------+--------+\n";
    std::cout << "| Semester  | Credits  | SGPA   |\n";
    std::cout << "+-----------+----------+--------+\n";

    for (int i = 0; i < semesters; ++i) {
        std::cout << "| " << std::left << std::setw(9) << (i + 1)
                  << " | " << std::right << std::setw(8) << sem_credits[i]
                  << " | " << std::right << std::setw(6) << std::fixed << std::setprecision(2) << sgpas[i] << " |\n";
    }

    std::cout << "+-----------+----------+--------+\n";

    std::cout << "\nYour CGPA = " << std::fixed << std::setprecision(2) << cgpa << "\n\n";
}

int main() {
    while (true) {
        std::cout << "\n=== GPA Calculator ===\n"
                  << "1. Calculate SGPA\n"
                  << "2. Calculate CGPA (weighted)\n"
                  << "3. Exit\n"
                  << "Choice: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                calculateSGPA();
                break;
            case 2:
                calculateCGPA();
                break;
            case 3:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please select 1–3.\n";
                continue;
        }

        std::cout << "\nPress Enter to return to menu...\n";
        std::cin.get();  
    }
}