#include <iostream>
#include <memory>

//#include "Task1.h"
//#include "Task2.h"
//#include "Task3.h"
//#include "Task4.h"

#include "../include/Task5.h"

int main(int argc, char** argv)
{
    // We have to use command line arguments (CLI) in the format ./a.out <space> filename.ext <space> task number.
    // argv[0] is ./a.out; argv[1] is filename.ext; argv[2] is the task number
    // Based on argv[2], we will have to make a switch case.
    switch(stoi(argv[2])) {
      case 5: {
        unique_ptr<Task5> task5(new Task5(argv[1]));
        task5->read();
        task5->write();  
        break;
      }
      /*case 2 :
      case 3 :
      case 4 :
      case 1 :*/
      
      default:
        cout << "No task match";
    }
    // similarly for Task2, Task3, Task4, Task5
    return 0;
}
