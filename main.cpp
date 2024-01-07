#include <iostream>
#include <vector>

using namespace std;

struct Applicant {
    string name;
    string email;
    string resume;
    string coverLetter;
};

struct JobOpportunity {
    string position;
    string description;
    int vacancies;
    vector<Applicant> applicants;
};

void displayJobOpportunities(const vector<JobOpportunity>& opportunities) {
    cout << "Available Job Opportunities:\n";
    for (size_t i = 0; i < opportunities.size(); ++i) {
        cout << i + 1 << ". " << opportunities[i].position << "\n";
        cout << "   " << opportunities[i].description << "\n";
        cout << "   Vacancies: " << opportunities[i].vacancies << "\n\n";
    }
}

void applyForJob(JobOpportunity& opportunity, const Applicant& applicant) {
    if (opportunity.vacancies > 0) {
        opportunity.applicants.push_back(applicant);
        opportunity.vacancies--;
        cout << "Application submitted successfully!\n\n";
    } else {
        cout << "Sorry, no vacancies available for this position.\n\n";
    }
}

int main() {
    vector<JobOpportunity> jobOpportunities = {
        {"Software Engineer", "Develop and maintain software applications.", 3, {}},
        {"Data Analyst", "Analyze and interpret complex data sets.", 2, {}},
        {"Web Developer", "Design and build responsive web applications.", 2, {}}
        // Add more job opportunities as needed
    };

    displayJobOpportunities(jobOpportunities);

    int choice;
    cout << "\nEnter the number corresponding to the job you want to apply for: ";
    cin >> choice;

    if (choice >= 1 && choice <= static_cast<int>(jobOpportunities.size())) {
        Applicant user;
        cout << "Enter your name: ";
        cin.ignore(); // to consume the newline character left in the buffer
        getline(cin, user.name);
        cout << "Enter your email: ";
        getline(cin, user.email);
        cout << "Enter the path to your resume file: ";
        getline(cin, user.resume);
        cout << "Enter the path to your cover letter file: ";
        getline(cin, user.coverLetter);

        applyForJob(jobOpportunities[choice - 1], user);
    } else {
        cout << "Invalid choice. Exiting...\n";
    }

    return 0;
}
