#include <iostream>

using std::string;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
private:
    // string Name;
    string Company;
    int Age;

protected:
    string Name;

public:
    void setName(string name) {                      // setter
        Name = name;
    }
    string getName() {                               // getter
        return Name;
    }
    void setCompany(string company) {                // setter
        Company = company;
    }
    string getCompany() {                            // getter
        return Company;
    }
    void setAge(int age) {                           // setter
        if(age > 18) 
        Age = age;
    }
    int getAge() {                                   // getter
        return Age;
    }

    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    void IntroduceUrseslf() {
        std::cout << "Name : " << Name << std::endl;
        std::cout << "Company : " << Company << std::endl;
        std::cout << "Age : " << Age << std::endl;
    }

    void AskForPromotion() {
        if(Age > 30) {
            std::cout << Name << " Got Promoted " << std::endl;
        }
        else {
            std::cout << Name << " No Promotion for you " << std::endl;
        }
    }

    virtual void work() {
        std::cout << Name << "is cheking email, task, perforamnce etc" << std::endl;
    }

};

class Developer:public Employee {
public:
    string FavProgLang;
    Developer(string name, string company, int age, string favlanguage)
        :Employee(name, company, age)
    {
        FavProgLang = favlanguage;
    }

    void FixBug() {
        std::cout << Name << " Fixed Bug using " << FavProgLang << std::endl;
    }
    void work() {
        std::cout << Name << "is writing "<< FavProgLang << " code " << std::endl;
    }

};

class Teacher:public Employee {
public:
    string Subject;
    void PrepareLesson() {
        std::cout << Name << " is preparing " << Subject << " Lesson " << std::endl; 
    }
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }

    void work() {
        std::cout << Name << "is teaching "<< Subject << std::endl;
    }
};

int main() {
    Employee employee01 = Employee("Groot", "SCAM", 30);
    employee01.IntroduceUrseslf();

    Employee employee02 = Employee("Jack", "HP", 65);
    employee02.IntroduceUrseslf();

    employee01.setAge(5);
    std::cout << employee01.getName() << " is " << employee01.getAge() << " year old" << std::endl;
    
    employee01.AskForPromotion();
    employee02.AskForPromotion();

    Developer dev01 = Developer("gerrit", "HPTCL", 54, "CPP");
    dev01.FixBug();
    dev01.AskForPromotion();

    Teacher t01 = Teacher("Mario", "GHS", 45, "Psychology");
    t01.PrepareLesson();
    t01.AskForPromotion();

    // dev01.work();
    // t01.work();

    Employee* e1 = &dev01;
    Employee* e2 = &t01;

    e1 -> work();
    e2 -> work();
}