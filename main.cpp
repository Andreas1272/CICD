#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>

enum class Event{CreateRessourceSelected, ShowAllRessourcesSelected, EditRessourceSelected};


class Ressource
{
    public:

    // tbd: Constructor?

    ~Ressource() = default;

    //virtual void AddRessource(std::string ressource_name) = 0;
    //virtual void EditRessource(std::string ressource_name) = 0;
    //virtual void DeleteRessource(std::string ressource_name) = 0;
    virtual void SetRessourceName(std::string ressource_name) = 0;
    virtual std::string GetRessourceName() = 0;
    virtual void SetRessourceUser(std::string ressource_user) = 0;
    virtual std::string GetRessourceUser() = 0;
    virtual bool GetRessourceInUse() = 0;
};

class Printer : public Ressource {
    public:
    Printer(std::string ressource_name, std::string ressource_user): m_ressource_name{ressource_name}, m_ressource_user{ressource_user} {};

    ~Printer() = default;

    void SetRessourceName(std::string ressource_name)
    {
        m_ressource_name = ressource_name;
    }

    std::string GetRessourceName()
    {
        return m_ressource_name;
    }

    void SetRessourceUser(std::string ressource_user)
    {
        m_ressource_user = ressource_user;
    }

    std::string GetRessourceUser()
    {
        return m_ressource_user;
    }

    bool GetRessourceInUse()
    {
        return(m_ressource_user.compare("") != 0);
    }

    private:
    std::string m_ressource_name;
    std::string m_ressource_user;

};

class Manager
{
    public:
    // tbd: Constructor

    ~Manager() = default;
    void HandleEvent(Event event)
    {
        switch (event)
        {
            case Event::CreateRessourceSelected:
                CreateNewRessource();
                break;
            case Event::ShowAllRessourcesSelected:
                ShowAllRessources();
                break;
            case Event::EditRessourceSelected:
                EditRessource();
                break;
            default:
                break;
        }
    }

    void CreateNewRessource()
    {
        std::cout << "Create new ressource" << std::endl;
        std::cout << "Ressource name: " << std::endl;
        std::string name;
        std::cin >> name;
        std::cout << "New ressource name: " << name << std::endl;
    }

    void ShowAllRessources()
    {
        std::cout << "ShowAllRessourcesSelected" << std::endl;
    }

    void EditRessource()
    {
        std::cout << "EditRessourceSelected" << std::endl;
    }


    private:

};


int main() {
    // tbd

    Manager manager;

    Printer printer_1("Printer_1","");
    std::cout << "Name: " << printer_1.GetRessourceName() << std::endl;
    std::cout << "User: " << printer_1.GetRessourceUser() << std::endl;
    std::cout << "In use: " << printer_1.GetRessourceInUse() << std::endl;

    printer_1.SetRessourceUser("EF-724");
    std::cout << "Name: " << printer_1.GetRessourceName() << std::endl;
    std::cout << "User: " << printer_1.GetRessourceUser() << std::endl;
    std::cout << "In use: " << printer_1.GetRessourceInUse() << std::endl;

    std::unordered_map<int, Event> menu = {
        {1, Event::CreateRessourceSelected},
        {2, Event::ShowAllRessourcesSelected},
        {3, Event::EditRessourceSelected}
    };

    while (true)
    {
        std::cout << "Select your choice:\n";
        std::cout << "1. Create Ressource\n";
        std::cout << "2. Show all ressources\n";
        std::cout << "3. Edit ressource\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;

        if (menu.find(choice) != menu.end()) {
            manager.HandleEvent(menu[choice]);
        } else {
            std::cout << "Invalid choice.\n";
        }

        std::cout << "\n";
    }

    return 0;

}
