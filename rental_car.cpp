#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car {
private:
    string make;
    string model;
    int year;
    double dailyRate;
    bool isAvailable;

public:
    Car(string make, string model, int year, double dailyRate)
        : make(make), model(model), year(year), dailyRate(dailyRate), isAvailable(true) {}

    void rent() {
        isAvailable = false;
    }

    void returnCar() {
        isAvailable = true;
    }

    bool isCarAvailable() const {
        return isAvailable;
    }

    double getDailyRate() const {
        return dailyRate;
    }

    void display() {
        cout << "Make: " << make << "\nModel: " << model << "\nYear: " << year
             << "\nDaily Rate: " << dailyRate << "\nAvailable: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

class Customer {
private:
    string name;
    int age;

public:
    Customer(string name, int age) : name(name), age(age) {}

    void display() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

class CarRentalSystem {
private:
    vector<Car> cars;
    vector<Customer> customers;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void addCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    void rentCar(int carIndex, int customerIndex) {
        if (carIndex >= 0 && carIndex < cars.size() &&
            customerIndex >= 0 && customerIndex < customers.size()) {
            Car& car = cars[carIndex];
            if (car.isCarAvailable()) {
                Customer& customer = customers[customerIndex];
                car.rent();
                cout << "Car rented by " << customerIndex << " for $" << car.getDailyRate() << " per day." << endl;
            } else {
                cout << "Car is not available for rent." << endl;
            }
        } else {
            cout << "Invalid car or customer index." << endl;
        }
    }

    void returnCar(int carIndex) {
        if (carIndex >= 0 && carIndex < cars.size()) {
            Car& car = cars[carIndex];
            if (!car.isCarAvailable()) {
                car.returnCar();
                cout << "Car returned successfully." << endl;
            } else {
                cout << "Car is already available." << endl;
            }
        } else {
            cout << "Invalid car index." << endl;
        }
    }

    void displayCars() {
        cout << "Car Inventory:" << endl;
        for (int i = 0; i < cars.size(); ++i) {
            cout << "Car " << i + 1 << ":" << endl;
            cars[i].display();
            cout << "-----------------------------" << endl;
        }
    }

    void displayCustomers() {
        cout << "Customer List:" << endl;
        for (int i = 0; i < customers.size(); ++i) {
            cout << "Customer " << i + 1 << ":" << endl;
            customers[i].display();
            cout << "-----------------------------" << endl;
        }
    }
};

int main() {
    CarRentalSystem rentalSystem;

    // Adding cars and customers
    rentalSystem.addCar(Car("Toyota", "Camry", 2023, 50.0));
    rentalSystem.addCar(Car("Honda", "Civic", 2023, 45.0));
    rentalSystem.addCustomer(Customer("Virat Kohli", 32));
    rentalSystem.addCustomer(Customer("Rohit Sharma", 35));

    int choice;
    int carIndex, customerIndex;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Display Car Inventory\n";
        cout << "2. Display Customer List\n";
        cout << "3. Rent a Car\n";
        cout << "4. Return a Car\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rentalSystem.displayCars();
                break;
            case 2:
                rentalSystem.displayCustomers();
                break;
            case 3:
                cout << "Enter the car index: ";
                cin >> carIndex ;
                cout << "Enter the customer index: ";
                cin>> customerIndex;
                rentalSystem.rentCar(carIndex - 1, customerIndex - 1); // Subtract 1 to convert to 0-based index
                break;
            case 4:
                cout << "Enter the car index: ";
                cin >> carIndex;
                rentalSystem.returnCar(carIndex - 1); // Subtract 1 to convert to 0-based index
                break;
            case 5:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

