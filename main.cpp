#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>

enum Colors {
    WHITE,
    BLACK,
    RED,
    BLUE,
    GREEN,
};

// Error
class CustomError {
    public:
        std::string name;
        CustomError(std::string errorMessage) {
            this->name = errorMessage + "\n";
        }
};
// ========================================================= //

// BaseCar Class
class BaseCar {
    protected:
        std::string model;
        Colors color;
        int speed;
        // TODO: remove static variable from the abstract class
    private:
        static const int numberSeats = 4;

    public:
        BaseCar(std::string model = "", Colors color = WHITE, int speed = 0) : model(model), color(color), speed(speed) {}
        BaseCar &operator=(BaseCar &);
        friend std::istream &operator>>(std::istream &, BaseCar &);
        friend std::ostream &operator<<(std::ostream &, BaseCar &);

        std::string get_model() const;
        Colors get_color() const;
        int get_speed() const;

        static int get_numberSeats();

        void set_model(std::string model);
        void set_color(Colors color);
        void set_speed(int speed);

    protected:
        virtual void read(std::istream &);
        virtual void print(std::ostream &);
};

void BaseCar::read(std::istream &in) {
    std::string str;
    int value;
    std::cout << "Model: ";
    in >> str;
    this->model = str;

    std::cout << "Culoare (0 - Alb, 1 - Negru, 3 - Rosu, 4 - Albastru, 5 - Verde):  ";
    in >> value;
    this->color = (Colors)value;

    std::cout << "Viteza maxima (km/h): ";
    in >> value;
    this->speed = value;
}

void BaseCar::print(std::ostream &out) {
    out << "-----------------------------\n";
    out << "Model: " << this->model << "\n";
    out << "Culoare: ";
    switch (this->color)
    {
    case 0:
        out << "Alba";
        break;
    case 1:
        out << "Neagra";
        break;
    case 3:
        out << "Rosie";
        break;
    case 4:
        out << "Albastra";
        break;
    case 5:
        out << "Verde";
        break;
    }
    out << "\n";

    out << "Viteza: " << this->speed << "\n";
}

BaseCar &BaseCar::operator=(BaseCar &car) {
    this->model = car.model;
    this->color = car.color;
    this->speed = car.speed;

    return *this;
}

std::istream &operator>>(std::istream &in, BaseCar &car) {
    car.read(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, BaseCar &car) {
    car.print(out);
    return out;
}

// getters
std::string BaseCar::get_model() const {
    return this->model;
}

int BaseCar::get_numberSeats() {
    return BaseCar::numberSeats;
}

Colors BaseCar::get_color() const {
    return this->color;
}

int BaseCar::get_speed() const {
    return this->speed;
}

// setters
void BaseCar::set_model(std::string model) {
    this->model = model;
}

void BaseCar::set_color(Colors color) {
    this->color = color;
}

void BaseCar::set_speed(int speed) {
    this->speed = speed;
}
// ========================================================= //

// CoupeCar
class CoupeCar : public BaseCar {
    private:
        static const int numberSeats = 2;

    public:
        CoupeCar(std::string model, Colors color, int speed);
        static int get_numberSeats();
};

CoupeCar::CoupeCar(std::string model = "", Colors color = WHITE, int speed = 0) : BaseCar(model, color, speed) {}

int CoupeCar::get_numberSeats() {
    return CoupeCar::numberSeats;
}

// Template Expozitie
template <class masini> class Expozitie {
    private:
        std::list< std::pair<masini, int> > v;
        int n;

    public:
        Expozitie(masini *p = NULL, int n = 0) {
            this->n = n;
            if (n != 0 && p != NULL) {
                for (int i = 0; i < this->n; i++) {
                    std::pair<masini, int> pr(p[i], -1);
                    this->v.push_back(pr);
                }
            }
        }

        Expozitie(Expozitie &exp) {
            this->n = exp.n;
            this->v = new std::list< std::pair<masini, int> >;
            for (int i = 0; i < this->n; i++)
            {
                std::pair<masini, int> pr(exp.v[i].first, exp.v[i].second);
                this->v.push_back(pr);
            }
        }

        // ~Expozitie() {
        //     delete[] this->v;
        // }

        friend std::istream& operator>>(std::istream &in, Expozitie<masini> &exp) {
            std::cout << "n = \n";
            in >> exp.n;
            // exp.v = new std::list< std::pair<masini, int> >;

            std::cout << "Introduceti masinile:\n";
            for(int i = 0; i < exp.n; i++) {
                masini* car = new masini();
                std::cin >> car;
                std::pair<masini, int> pr(car, -1);
                exp.v.push_back(pr);
            }

            return in;
        }
        int get_n();
};

template <class masini> int Expozitie<masini>::get_n() {
    return this->n;
}


// ========================================================= //

// Menu
class Menu {
    public:
        Menu();

    private:
        void mainMenu();
        void option1();
        void option2();
        void backToMainMenu();
};

Menu::Menu() {
    this->mainMenu();
}

void Menu::mainMenu() {
    system("cls");
    std::cout << "Alege o optiune:\n\n";
    std::cout << "1. Citeste n obiecte: \n";
    std::cout << "2. Expozitie - Masini Coupe\n";

    int opt;
    std::cin >> opt;

    switch (opt)
    {
    case 1:
        this->option1();
    break;
    case 2:
        this->option2();
    break;
    }
}

void Menu::option2() {
    system("cls");
    Expozitie<CoupeCar> coupe;
    // std::cin >> coupe;
    this->backToMainMenu();
}

void Menu::option1() {
    system("cls");
    int n;
    std::cout << "n = ";
    std::cin >> n;

    try {
        if (n <= 0) {
            throw new CustomError("n trebuie sa fie > 0");
        }

        BaseCar *cars = new BaseCar[n];
        for (int i = 0; i < n; i++) {
            std::cin >> cars[i];
        }

        delete[] cars;
    } catch (CustomError *e) {
        std::cout << e->name;
    }

    this->backToMainMenu();
}

void Menu::backToMainMenu() {
    std::string opt;
    std::cout << "Apasa orice tasta urmata de enter pentru a te intoarce in meniul principala\n";
    std::cin >> opt;
    system("cls");
    this->mainMenu();
}

int main() {
    //   CoupeCar* car = new CoupeCar();
    //   std::cin >> *car;
    //   car->set_model("BMW");
    //   std::cout << CoupeCar::get_numberSeats();
    (new Menu());
    // Expozitie<CoupeCar> *e = new Expozitie<CoupeCar>();

    return 0;
}
