#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<unordered_map>
int main(){
    float gpa = 0.0;
    int subjects;
    std::cout<<"Enter number of subjects: \n";
    std::cin>>subjects;
    if(subjects <= 0) return 1;

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

    std::unordered_map<std::string,int> Gradep={
        {"O",10},{"A+",9},{"A",8},
        {"B+",7},{"B",6},{"C",5},{"F",0}
    };

    for(int i=0;i<subjects;i++){
        gpa = gpa + (Gradep[Grade[i]]*credit[i]);
    }

    int credits=0;
    for(int i=0;i<subjects;i++){
        credits += credit[i];
    }

    gpa = gpa/credits;

    std::cout<<"GPA = "<<std::fixed << std::setprecision(2)<<gpa;
}