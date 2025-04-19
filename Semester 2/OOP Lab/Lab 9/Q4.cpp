#include <iostream>
#include <string>

using namespace std;

//Abstract base class
class Student
{
public:
    virtual double getTuition(const string &status, int creditHours) const = 0;

    virtual ~Student() {}
};

class GraduateStudent : public Student
{
private:
    string researchTopic;

public:
    GraduateStudent() : researchTopic("") {}

    void setResearchTopic(const string &topic)
    {
        researchTopic = topic;
    }
    string getResearchTopic() const
    {
        return researchTopic;
    }

    double getTuition(const string &status, int creditHours) const override
    {
        if (status == "undergraduate")
        {
            return 200.0 * creditHours;
        }
        else if (status == "graduate")
        {
            return 300.0 * creditHours;
        }
        else if (status == "doctoral")
        {
            return 400.0 * creditHours;
        }
        else
        {
            cout << "Error: invalid status \"" << status << "\"\n";
            return 0.0;
        }
    }
};

int main()
{
    GraduateStudent gs;

    gs.setResearchTopic("Machine Learning in Healthcare");
    cout << "Research Topic: " << gs.getResearchTopic() << "\n\n";

    int credits = 12;
    cout << "Tuition for " << credits << " credit hours as UNDERGRAD: $"
         << gs.getTuition("undergraduate", credits) << "\n";

    cout << "Tuition for " << credits << " credit hours as GRADUATE: $"
         << gs.getTuition("graduate", credits) << "\n";

    cout << "Tuition for " << credits << " credit hours as DOCTORAL: $"
         << gs.getTuition("doctoral", credits) << "\n";

    return 0;
}
