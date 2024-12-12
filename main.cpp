#include <iostream>
#include <ostream>
#include <string>

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
        if(m_ressource_user.compare("") == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    private:
    std::string m_ressource_name;
    std::string m_ressource_user;

};

int main() {
    // tbd
    Printer printer_1("Printer_1","");
    std::cout << "Name: " << printer_1.GetRessourceName() << std::endl;
    std::cout << "User: " << printer_1.GetRessourceUser() << std::endl;
    std::cout << "In use: " << printer_1.GetRessourceInUse() << std::endl;

    printer_1.SetRessourceUser("EF-724");
    std::cout << "Name: " << printer_1.GetRessourceName() << std::endl;
    std::cout << "User: " << printer_1.GetRessourceUser() << std::endl;
    std::cout << "In use: " << printer_1.GetRessourceInUse() << std::endl;


    return 0;
}
