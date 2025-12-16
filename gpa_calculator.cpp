#include<iostream>
#include<vector>
#include<string>
int main(){
    float gpa = 0.0,subjects;
    std::cout<<"Enter number of subjects: \n";
    std::cin>>subjects;

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

    std::vector<int> Gradep(subjects);
    for(int i=0;i<subjects;i++){
        if(Grade[i] == "O"){
            Gradep[i] = 10;
        }
        else if(Grade[i] == "A+"){
            Gradep[i] = 9;
        }
        else if(Grade[i] == "A"){
            Gradep[i] = 8;
        }
        else if(Grade[i] == "B+"){
            Gradep[i] = 7;
        }
        else if(Grade[i] == "B"){
            Gradep[i] = 6;
        }
        else if(Grade[i] == "C"){
            Gradep[i] = 5;
        }
        else if(Grade[i] == "F"){
            Gradep[i] = 0;
        }
    }

    for(int i=0;i<subjects;i++){
        gpa = gpa + (Gradep[i]*credit[i]);
    }

    int credits=0;
    for(int i=0;i<subjects;i++){
        credits += credit[i];
    }

    gpa = gpa/credits;

    std::cout<<"GPA = "<<gpa;
}