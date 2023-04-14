#include <iostream>
#include <vector>
import employee;
import database;

int main(int argc, char **argv) {
  // std::cout << Record::DefaultRaiseAndDemeritAmount << std::endl;
  // Record::Employee emp {"Jane", "Doe"};
  // emp.setFirstName("John");
  // emp.setLastName("Doe");
  // emp.setEmployeeNumber(71);
  // emp.setSalary(50'000);
  // emp.promote();
  // emp.promote(50);
  // emp.hire();
  // emp.display();

  Record::Database myDB;
  Record::Employee& emp1{myDB.addEmployee("Greg", "Wallis")};
  emp1.fire();

  Record::Employee& emp2{myDB.addEmployee("Marc", "White")};
  emp2.setSalary(100'000);

  Record::Employee& emp3{myDB.addEmployee("John", "Doe")};
  emp3.setSalary(10'000);
  emp3.promote();

  std::cout << "all employees: " << std::endl << std::endl;
  myDB.displayAll();

  std::cout << std::endl << "current employees: " << std::endl << std::endl;
  myDB.displayCurrent();

  std::cout << std::endl << "former employees: " << std::endl << std::endl;
  myDB.displayFormer();

  return 0;
}
