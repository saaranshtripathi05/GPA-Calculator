#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include <algorithm>
#include<unordered_map>

void calculateSGPA();
void calculateCGPA();

int main(){
    
    while(true){

    int input;
    std::cout<<"Enter a Choice:\n";
    std::cout<<"1.CALCULATE SGPA\n";
    std::cout<<"2.CALCULATE CGPA\n";
    std::cout<<"3.Exit\n";

    std::cout<<"Your Choice: ";
    std::cin>>input;

    switch(input){
        case 1:
            calculateSGPA();
            break;

         case 2:
            calculateCGPA();
            break;
        case 3:
             exit(EXIT_SUCCESS);
        default:
             std::cout<<"Enter a valid option number\n";
            }
    }
}

std::unordered_map<std::string,int> Gradep={
        {"O",10},{"A+",9},{"A",8},
        {"B+",7},{"B",6},{"C",5},{"F",0}
    };

void calculateSGPA(){
    float gpa = 0.0;
    int subjects;
    std::cout<<"Enter number of subjects: \n";
    std::cin>>subjects;
    if(subjects <= 0) return;

    std::vector<int>credit(subjects);
    std::vector<std::string>Grade(subjects);

    std::cout<<"Enter credits of each subjects\n";

    for(int i=0;i<subjects;i++){
        std::cin>>credit[i];
    }

    std::cout<<"Enter Grades of each subjects\n";

    for(int i=0;i<subjects;i++){
        std::cin>>Grade[i];
    }
    for(int i = 0; i < subjects; i++) {

    std::transform(Grade[i].begin(),
                   Grade[i].end(),
                   Grade[i].begin(),
                   ::toupper);

    gpa += Gradep[Grade[i]] * credit[i];
}


    int credits=0;
    for(int i=0;i<subjects;i++){
        credits += credit[i];
    }

    gpa = gpa/credits;

    std::cout<<"GPA = "<<std::fixed << std::setprecision(2)<<gpa<<std::endl;
}

void calculateCGPA(){
    int sem;
    std::cout<<"Enter number of semesters:\n";
    std::cin>>sem;
    std::vector<float>sgpa(sem);

    std::cout<<"Enter SGPA of each semester: \n";
    
    for(int i=0;i<sem;i++){
        std::cin>>sgpa[i];
    }

    float cgpa=0;

    for(int i=0;i<sem;i++){
        cgpa+=sgpa[i];
    }

    cgpa = cgpa/sem;

    std::cout<<"CGPA is: "<<std::fixed<<std::setprecision(2)<<cgpa<<"\n";
}