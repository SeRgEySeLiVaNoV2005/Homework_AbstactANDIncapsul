#include <locale.h>
#include <fstream>
#include <string>

using namespace std;

class address {
private:
    string city;
    string street;
    int numberHouse;
    int numberFlat;
public:
    address(string city, string street, int numHouse, int numFlat) {
        this->city = city;
        this->street = street;
        this->numberHouse = numHouse;
        this->numberFlat = numFlat;
    }
    address() : city(""), street(""), numberHouse(0), numberFlat(0) {}

    string outputAddress() {
        return city + " " + street + " " + to_string(numberHouse) + " " + to_string(numberFlat);
    }
};
int main() {
    setlocale(LC_ALL, "Rus");

    ifstream date("in.txt");
    ofstream outDate("out.txt");
    int n;
    date >> n;
    string city, street;
    int numHouse, numFlat;
    address* listAddreses = new address[n];

    for (int i = 0; i < n; i++) {
        date >> city;
        date >> street;
        date >> numHouse;
        date >> numFlat;
        listAddreses[i] = address(city, street, numHouse, numFlat);
    }

    for (int i = n - 1; i >= 0; i--) {
        outDate << listAddreses[i].outputAddress() << endl;
    }
}
