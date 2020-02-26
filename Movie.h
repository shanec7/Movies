#include <iostream>
#include <vector>
#include <map>
class Movie;
class Customer;
class Inventory;

using namespace std;

class MovieStore{
public:
    MovieStore();
    ~MovieStore();
    bool borrow(Movie*, int);
    bool returnMovie(Movie*, int);
    void inventory();
    void history(int);
private:
    map<int, Customer*> Customers;
    Inventory Stock;
};

class Inventory{
public:
    void displayInventory();
private:
    map<string, Movie*> Comedies;
    map<string, Movie*> Dramas;
    map<string, Movie*> Classics;
    bool addMovie(char, string);
    bool borrowMovie(char, string);
    bool returnMovie(char, string);
};

class Customer{
public:
    Customer(int, string, string);
    ~Customer();
    int getID() const;
    string getFirstName() const;
    string getLastName() const;
    string parseTransaction(string&);
private:
    int CustomerID;
    string FirstName;
    string LastName;
    vector<string> TransactionHistory;
};

class History{
public:
    void displayHistory();
    void clearHistory();
    void displayLastTransaction();
private:
    vector<string> TransactionHistory;
};

class Transaction{
public:
    bool borrow(string);
    bool returnM(string); // was return changed to returnM for return movie
private:
};

class Borrow : public Transaction{
public:
private:
    bool borrowMovie(char, string);
};

class Return : public Transaction{
public:
private:
    bool returnMovie(char, string);
};

// need to template class
class HashMap{
public:
    HashMap();
    HashMap(char, MovieFactory*);
    ~HashMap();
    bool contains(int);
    void insert(T, T);
    void add(searchKey, newItem);
private:
    key_pair<T,T>;
};

class MovieFactory {
public:
    virtual Movie *create() const = 0;
private:
};
class Movie{
public:
    static Movie *create(const string&);
    virtual ~Movie() = default;
    static void registerType(const string&, MovieFactory*);
    virtual bool operator>(const Movie&) = 0;
public:

private:
    int Stock;
    string Title;
    string YearRelease;
    string DirectorFirst;
    string DirectorLast;
    HashMap(char, MovieFactory*) Factories;
};


class Comedy : public Movie {
public:
    Comedy();
private:
};

class ComedyFactory  : public MovieFactory{
public:
    ComedyFactory();
    Movie* create() const override{ return new Comedy();};
private:
};

class Drama : public Movie {
public:
private:
};

class DramaFactory : public MovieFactory{
public:
    DramaFactory();
    Movie* create() const override{ return new Drama();};
private:
};

class Classics : public Movie {
public:
private:
    string MajorActorFirst;
    string MajorActorLast;
    int ReleaseMonth;
};

class ClassicsFactory  : public MovieFactory{
public:
    ClassicsFactory();
    Movie* create() const override{ return new Classics();};
private:
};
