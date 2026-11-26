
#include <iostream>
#include <vector>
using namespace std;

// Observer Interface
class Observer
{
public:
    virtual void update(string message) = 0;
    virtual ~Observer() {}
};

// Email Notification
class Email : public Observer
{
private:
    string email;

public:
    Email(string e)
    {
        email = e;
    }

    void update(string message)
    {
        cout << "Email sent to " << email
             << ": " << message << endl;
    }
};

// SMS Notification
class SMS : public Observer
{
private:
    string phone;

public:
    SMS(string p)
    {
        phone = p;
    }

    void update(string message)
    {
        cout << "SMS sent to " << phone
             << ": " << message << endl;
    }
};

// Singleton Pattern
class NotificationManager
{
private:
    static NotificationManager* instance;

    NotificationManager() {}

    vector<Observer*> observers;

public:
    static NotificationManager* getInstance()
    {
        if (instance == nullptr)
        {
            instance = new NotificationManager();
        }

        return instance;
    }

    void subscribe(Observer* observer)
    {
        observers.push_back(observer);
    }

    void notifyAll(string message)
    {
        cout << "Sending Notifications..." << endl;

        for (Observer* observer : observers)
        {
            observer->update(message);
        }
    }
};

NotificationManager* NotificationManager::instance = nullptr;

// Factory Pattern
class NotificationFactory
{
public:
    static Observer* createNotification(string type, string contact)
    {
        if (type == "Email")
            return new Email(contact);

        if (type == "SMS")
            return new SMS(contact);

        return nullptr;
    }
};

int main()
{
    string message =
        "University examination starts tomorrow!";

    NotificationManager* manager =
        NotificationManager::getInstance();

    Observer* email =
        NotificationFactory::createNotification(
            "Email", "student@gmail.com");

    Observer* sms =
        NotificationFactory::createNotification(
            "SMS", "9876543210");

    manager->subscribe(email);
    manager->subscribe(sms);

    cout << "Event Triggered: " << message << endl;

    manager->notifyAll(message);

    delete email;
    delete sms;

    return 0;
}
