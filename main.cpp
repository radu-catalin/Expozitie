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
    protected:
        static const std::string context;
    public:
        BaseCar(std::string model = "", Colors color = WHITE, int speed = 0) : model(model), color(color), speed(speed) {}
        BaseCar &operator=(BaseCar &);
        friend std::istream &operator>>(std::istream &, BaseCar &);
        friend std::ostream &operator<<(std::ostream &, BaseCar &);

        std::string get_model() const;
        Colors get_color() const;
        int get_speed() const;
        static std::string get_context();

        void set_model(std::string model);
        void set_color(Colors color);
        void set_speed(int speed);

    protected:
        virtual void read(std::istream &);
        virtual void print(std::ostream &);
};

const std::string BaseCar::context = "Masina";

std::string BaseCar::get_context() {
    return BaseCar::context;
}

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
    out << "Model: " << this->model << "\n";
    out << "Culoare: ";
    switch (this->color) {
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

// Coupe
class Coupe : public BaseCar {
    private:
        static const int numberDoors = 2;
    protected:
        static const std::string context;
    public:
        Coupe(std::string model, Colors color, int speed);
        static int get_numberDoors();
        static std::string get_context();
};

Coupe::Coupe(std::string model = "", Colors color = WHITE, int speed = 0) : BaseCar(model, color, speed) {}

const std::string Coupe::context = "Coupe";

std::string Coupe::get_context() {
    return Coupe::context;
}

int Coupe::get_numberDoors() {
    return Coupe::numberDoors;
}

// ========================================================= //

// HotHatch
class HotHatch: public BaseCar {
    private:
        int horsepower;
    protected:
        static const std::string context;
    public:
        HotHatch(std::string model, Colors color, int speed, int horsepower);
        static std::string get_context();
        int get_horsepower();
        friend std::istream& operator>>(std::istream&, HotHatch&);
        friend std::ostream& operator<<(std::ostream&, HotHatch&);
    private:
        void read(std::istream&);
        void print(std::ostream&);
};

HotHatch::HotHatch(std::string model = "", Colors colors = WHITE, int speed = 0, int horsepower = 750): BaseCar(model, color, speed), horsepower(horsepower) {}

const std::string HotHatch::context = "Hot-Hatch";

std::string HotHatch::get_context() {
    return HotHatch::context;
}

int HotHatch::get_horsepower() {
    return this->horsepower;
}

void HotHatch::read(std::istream& in) {
    BaseCar::read(in);
    std::cout << "Cai putere: ";
    in >> this->horsepower;
    std::cout << "\n";
}

void HotHatch::print(std::ostream& out) {
    BaseCar::print(out);
    out << "Cai putere: " << this->horsepower << "\n";
}

std::istream& operator>>(std::istream& in, HotHatch& car) {
    car.read(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, HotHatch& car) {
    car.print(out);
    return out;
}

// ========================================================= //

// Supersport
class Supersport: public BaseCar {
    private:
        int horsepower;
    protected:
        static const std::string context;
    public:
        Supersport(std::string model, Colors color, int speed, int horsepower);
        static std::string get_context();
        int get_horsepower();
        friend std::istream& operator>>(std::istream&, Supersport&);
        friend std::ostream& operator<<(std::ostream&, Supersport&);
    private:
        void read(std::istream&);
        void print(std::ostream&);
};

Supersport::Supersport(std::string model = "", Colors colors = WHITE, int speed = 0, int horsepower = 750): BaseCar(model, color, speed), horsepower(horsepower) {}

const std::string Supersport::context = "Supersport";

std::string Supersport::get_context() {
    return Supersport::context;
}

int Supersport::get_horsepower() {
    return this->horsepower;
}

void Supersport::read(std::istream& in) {
    BaseCar::read(in);
    std::cout << "Cai putere: ";
    in >> this->horsepower;
    std::cout << "\n";
}

void Supersport::print(std::ostream& out) {
    BaseCar::print(out);
    out << "Cai putere: " << this->horsepower << "\n";
}

std::istream& operator>>(std::istream& in, Supersport& car) {
    car.read(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, Supersport& car) {
    car.print(out);
    return out;
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


        friend std::istream& operator>>(std::istream &in, Expozitie<masini> &exp) {
            std::cout << "n = ";
            in >> exp.n;
            exp.v = std::list< std::pair<masini, int> >();

            std::cout << "Introduceti masinile " << masini::get_context() <<":\n";
            for(int i = 0; i < exp.n; i++) {
                masini car;
                std::cin >> car;
                std::pair<masini, int> pr(car, -1);
                exp.v.push_back(pr);
            }

            return in;
        }

        friend std::ostream& operator<<(std::ostream &out, Expozitie<masini> &exp) {
            std::cout << "Masinile " << masini::get_context() << " citite sunt:\n\n";
            typename std::list< std::pair<masini, int> >::iterator it;
            for(it = exp.v.begin(); it != exp.v.end(); it++) {
                std::cout << "Masina " << std::distance(exp.v.begin(), it) << "\n";
                std::cout << it->first << "\n";
            }

            return out;
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
        void option3();
        void option4();
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
    std::cout << "3. Expozitie - Masini Hot-hatch\n";
    std::cout << "4. Expozitie - Masini Supersport\n";

    int opt;
    std::cin >> opt;

    switch (opt) {
        case 1:
            this->option1();
        break;
        case 2:
            this->option2();
        break;
        case 3:
            this->option3();
        break;
        case 4:
            this->option4();
        break;
    }
}

void Menu::backToMainMenu() {
    std::string opt;
    std::cout << "Apasa orice tasta urmata de enter pentru a te intoarce in meniul principala\n";
    std::cin >> opt;
    system("cls");
    this->mainMenu();
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

void Menu::option2() {
    system("cls");
    Expozitie<Coupe> coupe;
    std::cin >> coupe;

    system("cls");
    std::cout << coupe;

    this->backToMainMenu();
}

void Menu::option3() {
    system("cls");
    Expozitie<HotHatch> hotHatch;
    std::cin >> hotHatch;

    system("cls");
    std::cout << hotHatch;

    this->backToMainMenu();
}

void Menu::option4() {
    system("cls");
    Expozitie<Supersport> superSport;
    std::cin >> superSport;

    system("cls");
    std::cout << superSport;

    this->backToMainMenu();
}

int main() {
    (new Menu());
    return 0;
}
