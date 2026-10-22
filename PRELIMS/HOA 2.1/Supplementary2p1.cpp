#include <iostream>
#include <string>

class GroceryItem
{
protected:
    std::string name;
    double price;
    int quantity;

public:
    // Problem 1 Constructor
    GroceryItem(std::string n = "", double p = 0, int q = 0)
    {
        name = n;
        price = p;
        quantity = q;
    }

    // Problem 1 Destructor
    virtual ~GroceryItem() {}

    // Problem 1 Copy Constructor
    GroceryItem(const GroceryItem &other)
    {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Problem 1 Copy Assignment Operator
    GroceryItem &operator=(const GroceryItem &other)
    {
        if (this != &other)
        {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    virtual std::string getType() = 0;

    // Problem 1 Function to calculate total
    double calculateSum() const
    {
        return price * quantity;
    }

    // Problem 1 Function to display item details
    void display()
    {
        std::cout << "Type: " << getType() << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: PHP " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Item Total: PHP " << calculateSum() << std::endl;
    }
};

// Problem 1 Fruit Class
class Fruit : public GroceryItem
{
public:
    Fruit(std::string n, double p, int q)
        : GroceryItem(n, p, q) {}

    ~Fruit() {}

    Fruit(const Fruit &other)
        : GroceryItem(other) {}

    Fruit &operator=(const Fruit &other)
    {
        GroceryItem::operator=(other);
        return *this;
    }

    std::string getType()
    {
        return "Fruit";
    }
};

// Problem 1 Vegetable Class
class Vegetable : public GroceryItem
{
public:
    Vegetable(std::string n, double p, int q)
        : GroceryItem(n, p, q) {}

    ~Vegetable() {}

    Vegetable(const Vegetable &other)
        : GroceryItem(other) {}

    Vegetable &operator=(const Vegetable &other)
    {
        GroceryItem::operator=(other);
        return *this;
    }

    std::string getType()
    {
        return "Vegetable";
    }
};

// Problem 3 Function to calculate total price of all items
double TotalSum(GroceryItem *list[], int size)
{
    double total = 0;

    for (int i = 0; i < size; i++)
    {
        if (list[i] != nullptr)
        {
            total += list[i]->calculateSum();
        }
    }

    return total;
}

int main()
{
    const int SIZE = 4;

    // Problem 2 Create GroceryList array using dynamic memory
    GroceryItem *GroceryList[SIZE];

    GroceryList[0] = new Fruit("Apple", 10, 7);
    GroceryList[1] = new Fruit("Banana", 10, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50, 10);

    // Problem 2 Display all grocery items
    std::cout << "JENNA'S GROCERY LIST\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        GroceryList[i]->display();
        std::cout << "--------------------------\n";
    }

    // Problem 3Display total amount
    std::cout << "\nTotal Amount to Pay: PHP "
              << TotalSum(GroceryList, SIZE)
              << std::endl;

    // Problem 4 Delete Lettuce and dde-allocate memory
    std::cout << "\nDeleting Lettuce...\n";

    delete GroceryList[3];
    GroceryList[3] = nullptr;

    std::cout << "Updated Total Amount: PHP "
              << TotalSum(GroceryList, SIZE)
              << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        delete GroceryList[i];
        GroceryList[i] = nullptr;
    }

    return 0;
}