#include <iostream>
#include <string>

using namespace std;

// ����������� ������� ������� �� ����
const int MAX_PENALTIES = 10;

// ���������, �� ����������� ������� ���������
struct PenaltyTicket {
    string description;
    float fineAmount;
};

// ���������, �� ����������� ��� ��� ���� �� ���� ������ ���������
struct CarData {
    string licensePlateNumber;
    PenaltyTicket penalties[MAX_PENALTIES];
    int numPenalties;
};

// ���� ���� ������� ��������� �� ����
void addPenalty(CarData& car, string description, float fine) {
    if (car.numPenalties < MAX_PENALTIES) {
        car.penalties[car.numPenalties].description = description;
        car.penalties[car.numPenalties].fineAmount = fine;
        car.numPenalties++;
        cout << "Penalty added successfully." << endl;
    }
    else {
        cout << "Maximum number of penalties reached for this car." << endl;
    }
}

// �������� �� ������ ��������� ��� ����
void printPenalties(const CarData& car) {
    cout << "License Plate Number: " << car.licensePlateNumber << endl;
    cout << "Penalties:" << endl;
    for (int i = 0; i < car.numPenalties; ++i) {
        cout << "Description: " << car.penalties[i].description << ", Fine Amount: " << car.penalties[i].fineAmount << endl;
    }
}

int main() {
    // ��������� ����� ��� ����
    CarData car1 = { "ABC123", {}, 0 };
    CarData car2 = { "XYZ456", {}, 0 };

    // ��������� �������
    addPenalty(car1, "Speeding", 100.0);
    addPenalty(car1, "Illegal Parking", 50.0);
    addPenalty(car2, "Running Red Light", 150.0);

    // ��������� ���������� ��� ������
    printPenalties(car1);
    printPenalties(car2);

    return 0;
}
