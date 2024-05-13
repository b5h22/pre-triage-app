#include <iostream>
#include "Utils.h"
#include "Menu.h"
using namespace std;
namespace seneca {
  void Menu::indent() const {
    for (int j = 0; j < m_numTabs * 3; j++) {
      cout << " ";
    }
  }

  Menu::Menu(const char* menuContent, int numberOfTabs) {
    m_text = new char[U.strlen(menuContent) + 1];
    U.strcpy(m_text, menuContent);
    m_numOptions = 0;
    for (size_t i = 0; i < U.strlen(m_text); i++) {
      if (m_text[i] == '\n') {
        m_numOptions++;
      }
    }
    m_numTabs = numberOfTabs;
  };

  Menu::~Menu() {
    delete[] m_text;
  }

  void Menu::display() const {
    for (int i = 0; m_text[i] != '\0'; i++) {
      if (i == 0 || m_text[i - 1] == '\n'){
        indent();
      }
      cout << m_text[i];
    }
    cout << endl;
    indent();
    cout << "0- Exit" << endl;
    indent();
    cout << "> ";
  }
  
  int& Menu::operator>>(int& selection) {
    bool valid = false;
    display();
    do
    {
      cin >> selection;
      if (selection < 0 || selection > m_numOptions) {
        cout << "Invalid value enterd, retry[0 <= value <= " << m_numOptions << "]: ";
      } else if (cin.fail()) {
        cout << "Bad integer value, try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
      } else if (cin.get() != '\n') {
        cout << "Only enter an integer, try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
      } else {
        valid = true;
      }
    } while (!valid);
    return selection;
  }
}