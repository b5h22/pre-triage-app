#ifndef SENECE_MENU_H
#define SENECE_MENU_H
namespace seneca {
  class Menu {
    char* m_text{};
    int m_numOptions{};
    int m_numTabs{};
    void indent() const;
  public:
    Menu(const char* menuContent, int numberOfTabs = 0);
    virtual ~Menu();
    Menu(const Menu& toCopy) = delete;
    Menu& operator=(const Menu& toCopy) = delete;
    void display() const;
    int& operator>>(int& Selection);
  };
}
#endif