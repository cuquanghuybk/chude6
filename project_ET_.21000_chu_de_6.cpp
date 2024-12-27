#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Struct de luu thong tin mot thiet bi
struct Device {
    string name;          // Ten thiet bi
    string manufacturer;  // Nha san xuat
    string model;         // Ma model
    float price;          // Gia thiet bi
    int usageLevel;       // Muc do su dung (so lan su dung)
    string category;      // Hang muc
};

// Struct de luu thong tin muon tra thiet bi
struct BorrowInfo {
    string deviceName; // Ten thiet bi
    string borrower;   // Nguoi muon
    string dateBorrow; // Ngay muon
    string dateReturn; // Ngay tra (neu co)
};

vector<Device> devices;       // Danh sach cac thiet bi
vector<BorrowInfo> borrows;   // Danh sach muon tra thiet bi

// Ham nhap thong tin mot thiet bi
Device inputDevice() {
    Device device;
    cout << "\nNhap thong tin thiet bi:" << endl;
    cout << "Ten thiet bi: ";
    getline(cin, device.name);
    cout << "Nha san xuat: ";
    getline(cin, device.manufacturer);
    cout << "Ma model: ";
    getline(cin, device.model);
    cout << "Gia thiet bi: ";
    cin >> device.price;
    cin.ignore();
    cout << "Muc do su dung (so lan): ";
    cin >> device.usageLevel;
    cin.ignore();
    cout << "Hang muc: ";
    getline(cin, device.category);
    return device;
}

// Ham hien thi thong tin mot thiet bi
void displayDevice(const Device &device) {
    cout << "\nThong tin thiet bi:" << endl;
    cout << "Ten: " << device.name << endl;
    cout << "Nha san xuat: " << device.manufacturer << endl;
    cout << "Ma model: " << device.model << endl;
    cout << "Gia: " << device.price << " VND" << endl;
    cout << "Muc do su dung: " << device.usageLevel << " lan" << endl;
    cout << "Hang muc: " << device.category << endl;
}

// Ham them thiet bi vao danh sach
void addDevice() {
    Device device = inputDevice();
    devices.push_back(device);
    cout << "\nThiet bi da duoc them." << endl;
}

// Ham sua thong tin thiet bi
void editDevice() {
    cout << "\nNhap ten thiet bi can sua: ";
    string name;
    cin.ignore();
    getline(cin, name);

    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i].name == name) {
            cout << "\nNhap thong tin moi cho thiet bi:" << endl;
            devices[i] = inputDevice();
            cout << "\nThong tin thiet bi da duoc cap nhat." << endl;
            return;
        }
    }
    cout << "\nKhong tim thay thiet bi." << endl;
}

// Ham xoa thiet bi
void deleteDevice() {
    cout << "\nNhap ten thiet bi can xoa: ";
    string name;
    cin.ignore();
    getline(cin, name);

    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i].name == name) {
            devices.erase(devices.begin() + i);
            cout << "\nThiet bi da duoc xoa." << endl;
            return;
        }
    }
    cout << "\nKhong tim thay thiet bi." << endl;
}

// Ham muon thiet bi
void borrowDevice() {
    BorrowInfo borrow;
    cout << "\nNhap thong tin muon thiet bi:" << endl;
    cout << "Ten thiet bi: ";
    cin.ignore();
    getline(cin, borrow.deviceName);
    cout << "Nguoi muon: ";
    getline(cin, borrow.borrower);
    cout << "Ngay muon: ";
    getline(cin, borrow.dateBorrow);
    borrow.dateReturn = "Chua tra";

    borrows.push_back(borrow);
    cout << "\nThong tin muon da duoc luu." << endl;
}

// Ham tra thiet bi
void returnDevice() {
    cout << "\nNhap ten thiet bi can tra: ";
    string name;
    cin.ignore();
    getline(cin, name);

    for (size_t i = 0; i < borrows.size(); ++i) {
        if (borrows[i].deviceName == name && borrows[i].dateReturn == "Chua tra") {
            cout << "\nNhap ngay tra: ";
            getline(cin, borrows[i].dateReturn);
            cout << "\nThiet bi da duoc tra." << endl;
            return;
        }
    }
    cout << "\nKhong tim thay thong tin muon cho thiet bi nay." << endl;
}

// Ham hien thi danh sach muon tra
void displayBorrows() {
    if (borrows.empty()) {
        cout << "\nDanh sach muon tra trong!" << endl;
        return;
    }

    for (size_t i = 0; i < borrows.size(); ++i) {
        cout << "\nThong tin muon tra:" << endl;
        cout << "Ten thiet bi: " << borrows[i].deviceName << endl;
        cout << "Nguoi muon: " << borrows[i].borrower << endl;
        cout << "Ngay muon: " << borrows[i].dateBorrow << endl;
        cout << "Ngay tra: " << borrows[i].dateReturn << endl;
    }
}

// Ham tim kiem thiet bi
void searchDevice() {
    cout << "\nNhap ten thiet bi can tim: ";
    string name;
    cin.ignore();
    getline(cin, name);

    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i].name == name) {
            displayDevice(devices[i]);
            return;
        }
    }
    cout << "\nKhong tim thay thiet bi." << endl;
}

// Ham so sanh thiet bi theo gia tri
bool compareByPrice(const Device &a, const Device &b) {
    return a.price < b.price;
}

// Ham so sanh thiet bi theo muc do su dung
bool compareByUsage(const Device &a, const Device &b) {
    return a.usageLevel > b.usageLevel;
}

// Ham sap xep thiet bi theo gia tri
void sortDevicesByPrice() {
    sort(devices.begin(), devices.end(), compareByPrice);
    cout << "\nDanh sach thiet bi da duoc sap xep theo gia tri." << endl;
}

// Ham sap xep thiet bi theo muc do su dung
void sortDevicesByUsage() {
    sort(devices.begin(), devices.end(), compareByUsage);
    cout << "\nDanh sach thiet bi da duoc sap xep theo muc do su dung." << endl;
}

int main() {
    int choice;

    do {
        cout << "\nMENU:" << endl;
        cout << "1. Them thiet bi" << endl;
        cout << "2. Sua thong tin thiet bi" << endl;
        cout << "3. Xoa thiet bi" << endl;
        cout << "4. Hien thi danh sach thiet bi" << endl;
        cout << "5. Muon thiet bi" << endl;
        cout << "6. Tra thiet bi" << endl;
        cout << "7. Hien thi danh sach muon tra" << endl;
        cout << "8. Tim kiem thiet bi" << endl;
        cout << "9. Sap xep thiet bi theo gia tri" << endl;
        cout << "10. Sap xep thiet bi theo muc do su dung" << endl;
        cout << "11. Thoat" << endl;
        cout << "Lua chon: ";
        getline(cin,choice);
        
        
        switch (choice) {
        case 1:
            addDevice();
            break;
        case 2:
            editDevice();
            break;
        case 3:
            deleteDevice();
            break;
        case 4:
            if (devices.empty()) {
                cout << "\nDanh sach thiet bi trong!" << endl;
            } else {
                for (size_t i = 0; i < devices.size(); ++i) {
                    displayDevice(devices[i]);
                }
            }
            break;
        case 5:
            borrowDevice();
            break;
        case 6:
            returnDevice();
            break;
        case 7:
            displayBorrows();
            break;
        case 8:
            searchDevice();
            break;
        case 9:
            sortDevicesByPrice();
            break;
        case 10:
            sortDevicesByUsage();
            break;
        case 11:
            cout << "\nThoat chuong trinh." << endl;
            break;
        default:
            cout << "\nLua chon khong hop le!" << endl;
        }
    } while (choice != 11);

    return 0;
}
