module;
#include <stdexcept>
import employee;
module database;
namespace Record {
Employee &Database::addEmployee(const std::string &firstName,
                                const std::string &lastName) {
  Employee theEmployee{firstName, lastName};
  theEmployee.setEmployeeNumber(m_nextEmployeeNumber);
  theEmployee.hire();
  m_employees.push_back(theEmployee);
  return m_employees.back();
}

Employee &Database::getEmployee(int employeeNumber) {
  for (size_t i = 0; i < m_employees.size(); i++) {
    if (m_employees[i].getEmployeeNumber() == employeeNumber) {
      return m_employees[i];
    }
  }
  throw std::logic_error{"No employee found."};
}

Employee &Database::getEmployee(const std::string &firstName,
                                const std::string &lastName) {
  for (size_t i = 0; i < m_employees.size(); i++) {
    if (m_employees[i].getFirstName() == firstName &&
        m_employees[i].getLastName() == lastName) {
      return m_employees[i];
    }
  }
  throw std::logic_error{"No employee found."};
}

void Database::displayAll() const {
  for (size_t i = 0; i < m_employees.size(); i++) {
    m_employees[i].display();
  }
  //   for (const auto &employee : m_employees) {
  //     employee.display();
  //   }
}

void Database::displayCurrent() const {
  for (size_t i = 0; i < m_employees.size(); i++) {
    if (m_employees[i].isHired()) {
      m_employees[i].display();
    }
  }
}

void Database::displayFormer() const {
  for (size_t i = 0; i < m_employees.size(); i++) {
    if (!m_employees[i].isHired()) {
      m_employees[i].display();
    }
  }
}

} // namespace Record
