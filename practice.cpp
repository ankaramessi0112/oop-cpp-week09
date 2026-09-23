#include <iostream>
#include <string>
using namespace std;

struct Food {
    string id;
    string name;
    double price;
    int quantity;
    // Nhap thong tin mon an
    void input() {
        cout << "Nhap ID mon an: ";
        getline(cin, id);
        cout << "Nhap ten mon an: ";
        getline(cin, name);
        cout << "Nhap gia mon an: ";
        cin >> price;
        cout << "Nhap so luong mon an: ";
        cin >> quantity;
        cin.ignore();
    }

    void output() const {
        cout << "\t[Ma: " << id << " | Ten: " << name 
             << " | Gia: " << price << " | Ton kho: " << quantity << "]\n";
    }

};

struct Order {
    string id;
    string customerName;
    string address;
    Food food;
    int foods[100];
    int foodCount = 0;
    int quantity;
    string status; // Cho giao, hoan thanh, huy

};

struct nhaHang {
    string name;
    string address;
    string phone;
    Food foods[100];
    int foodCount = 0;
    Order orders[100];
    int orderCount = 0;

    // Nhap thong tin cua hang
    void inputInfo() {
        cout << "Nhap ten cua hang: ";
        getline(cin, name);
        cout << "Nhap dia chi: ";
        getline(cin, address);
        cout << "Nhap so dien thoai: ";
        getline(cin, phone);
    }

    // Them mon an moi
    void addFood() {
        if (foodCount >= 100) return;
        foods[foodCount].input();
        foodCount++;
    }

    // Hien thi danh sach mon an
    void showMenu() const {
        cout << "\n=== MENU CUA HANG ===\n";
        for (int i = 0; i < foodCount; i++) {
            foods[i].output();
        }
    }

    // Tim mon an theo ma hoac ten
    void findFood(string keyword) const {
        for (int i = 0; i < foodCount; i++) {
            if (foods[i].id == keyword || foods[i].name == keyword) {
                foods[i].output();
                return;
            }
        }
        cout << "Khong tim thay mon an!\n";
    }

    // Cap nhat gia hoac so luong mon
    void updateFood(string foodId, double newPrice, int newQty) {
        for (int i = 0; i < foodCount; i++) {
            if (foods[i].id == foodId) {
                foods[i].price = newPrice;
                foods[i].quantity = newQty;
                cout << "Cap nhat thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay ma mon an!\n";
    }
};

int main()
{
    nhaHang nh;
    nh.inputInfo(); 
    nh.addFood();
    nh.showMenu();

}