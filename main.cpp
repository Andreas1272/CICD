#include <iostream>
#include <list>
#include <ostream>
#include <string>
#include <unordered_map>

enum class Event{CreateRessourceSelected, ShowAllRessourcesSelected, EditRessourceSelected};
enum class RessourceType{Room, Printer, Computer, Licence};


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
    Manager() = default;
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
        std::cout << "Create new ressource:\n";
        DisplayRessourceTypes();

        int choice;
        std::cin >> choice;

        if (menu_ressources.find(choice) != menu_ressources.end())
        {
            switch (menu_ressources[choice])
            {
                case (RessourceType::Room):
                    CreateNewRoom();
                    break;
                case (RessourceType::Printer):
                    CreateNewPrinter();
                    break;
                case (RessourceType::Computer):
                    CreateNewComputer();
                    break;
                case (RessourceType::Licence):
                    CreateNewLicence();
                    break;
            }
        }
        else
        {
            std::cout << "Canceled.\n";
        }

    }

    void CreateNewRoom()
    {
        std::cout << "Create new room" << std::endl;
    }

    void CreateNewPrinter()
    {
        std::cout << "Create new printer" << std::endl;
        std::cout << "Name: " << std::endl;
        std::string name;
        std::cin >> name;
        printer_list.push_back(new Printer(name, ""));
        std::cout << "New printer created" << std::endl;
    }

    void CreateNewComputer()
    {
        std::cout << "Create new computer" << std::endl;
    }

    void CreateNewLicence()
    {
        std::cout << "Create new licence" << std::endl;
    }

    void ShowAllRessources()
    {
        ShowAllPrinters();
    }

    void EditRessource()
    {
        std::cout << "Edit ressource. Choose the ressource type you want to edit." << std::endl;
        DisplayRessourceTypes();

        int choice;
        std::cin >> choice;

        if (menu_ressources.find(choice) != menu_ressources.end())
        {
            switch (menu_ressources[choice])
            {
                case (RessourceType::Room):
                    break;
                case (RessourceType::Printer):
                    EditPrinter();
                    break;
                case (RessourceType::Computer):
                    break;
                case (RessourceType::Licence):
                    break;
            }
        }
        else
        {
            std::cout << "Canceled.\n";
        }
    }



    private:
    std::list<Printer*> printer_list;

    std::unordered_map<int, RessourceType> menu_ressources =
    {
    {1, RessourceType::Room},
    {2, RessourceType::Printer},
    {3, RessourceType::Computer},
    {4, RessourceType::Licence}
    };

    void DisplayRessourceTypes()
    {
        std::cout << "1. Room\n";
        std::cout << "2. Printer\n";
        std::cout << "3. Computer\n";
        std::cout << "4. Licence\n";
        std::cout << "Any other input to cancel\n";
        std::cout << "Choice: ";
    }


    void ShowAllPrinters()
    {
        std::cout << "Printer: " << std::endl;
        for (Printer* n : printer_list)
        {
            std::cout << n->GetRessourceName() << std::endl;
        }
    }

    void EditPrinter(){
        ShowAllPrinters();
        // Hier weiter
        std::cout << "Name eingeben: " << std::endl;
        std::string name;
        std::cin >> name;

    }

};


int main() {

    Manager manager;

    // Printer printer_1("Printer_1","");
    // std::cout << "Name: " << printer_1.GetRessourceName() << std::endl;
    // std::cout << "User: " << printer_1.GetRessourceUser() << std::endl;
    // std::cout << "In use: " << printer_1.GetRessourceInUse() << std::endl;

    // printer_1.SetRessourceUser("EF-724");
    // std::cout << "Name: " << printer_1.GetRessourceName() << std::endl;
    // std::cout << "User: " << printer_1.GetRessourceUser() << std::endl;
    // std::cout << "In use: " << printer_1.GetRessourceInUse() << std::endl;

    std::unordered_map<int, Event> menu = {
        {1, Event::CreateRessourceSelected},
        {2, Event::ShowAllRessourcesSelected},
        {3, Event::EditRessourceSelected}
    };

    while (true)
    {
        std::cout << "Select your choice:\n";
        std::cout << "1. Create ressource\n";
        std::cout << "2. Show all ressources\n";
        std::cout << "3. Edit ressource\n";
        std::cout << "Any other input to terminate\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;

        if (menu.find(choice) != menu.end()) {
            manager.HandleEvent(menu[choice]);
        } else {
            std::cout << "Terminated.\n";
            break;
        }

        std::cout << "\n";

    }

    return 0;

}
