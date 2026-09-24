#include <iostream>
#include <string>

using namespace std;

char toUpperChar(char c) {
    if (c >= 'a' && c <= 'z') return c - ('a' - 'A');
    return c;
}

char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    return c;
}

string toLowerString(string s) {
    for (int i = 0; i < (int)s.length(); i++) {
        s[i] = toLowerChar(s[i]);
    }
    return s;
}

int main() {
    //Bài 1
    cout << "--- 1. NHAP VA HIEN THI TEN CUA HANG ---\n";
    cout << "Nhap ten cua hang: ";
    string storeName;
    getline(cin, storeName);
    cout << "Chao mung den voi [" << storeName << "]!\n\n";

    //Bài 2
    cout << "--- 2. CHUAN HOA TEN MON AN ---\n";
    cout << "Nhap ten mon an can chuan hoa: ";
    string rawFood;
    getline(cin, rawFood);

    string cleanFood = "";
    int len = rawFood.length();
    int i = 0;
    while (i < len && rawFood[i] == ' ') i++;

    bool newWord = true;
    while (i < len) {
        if (rawFood[i] != ' ') {
            if (newWord) {
                cleanFood += toUpperChar(rawFood[i]);
                newWord = false;
            } else {
                cleanFood += toLowerChar(rawFood[i]);
            }
            i++;
        } else {
            while (i < len && rawFood[i] == ' ') i++;
            if (i < len) {
                cleanFood += ' ';
                newWord = true;
            }
        }
    }
    cout << "Ten mon sau khi chuan hoa: \"" << cleanFood << "\"\n\n";

    //Bài 3
    cout << "--- 3. TAO MA DON HANG ---\n";
    cout << "Nhap ten khach hang: ";
    string custName, phone;
    getline(cin, custName);
    cout << "Nhap so dien thoai: ";
    getline(cin, phone);

    string orderCode = "DH_";
    if (!custName.empty()) {
        orderCode += toUpperChar(custName[0]);
        for (int j = 0; j < (int)custName.length() - 1; j++) {
            if (custName[j] == ' ' && custName[j + 1] != ' ') {
                orderCode += toUpperChar(custName[j + 1]);
            }
        }
    }
    if (phone.length() >= 4) {
        orderCode += "_" + phone.substr(phone.length() - 4);
    } else {
        orderCode += "_" + phone;
    }
    cout << "Ma don hang duoc tao: " << orderCode << "\n\n";

    //Bài 4
    cout << "--- 4. KIEM TRA MON AN ---\n";
    string menu[4] = {"Banh mi", "Pho bo", "Tra sua", "Com tam"};
    cout << "Nhap ten mon can tim trong menu: ";
    string checkFood;
    getline(cin, checkFood);

    bool exists = false;
    for (int j = 0; j < 4; j++) {
        if (toLowerString(menu[j]) == toLowerString(checkFood)) {
            exists = true;
            break;
        }
    }
    if (exists) {
        cout << "=> Mon [" << checkFood << "] CO trong danh sach mon cua quan!\n\n";
    } else {
        cout << "=> Mon [" << checkFood << "] KHONG co trong thuc don.\n\n";
    }

    //Bài 6
    cout << "--- 6. THAY DOI TRANG THAI DON HANG ---\n";
    string sampleOrderIds[3] = {"DH01", "DH02", "DH03"};
    string sampleStatus[3] = {"Dang chuan bi", "Dang chuan bi", "Dang chuan bi"};

    cout << "Nhap ma don hang muon doi trang thai (DH01, DH02, DH03): ";
    string inputOrderId;
    getline(cin, inputOrderId);
    cout << "Nhap trang thai moi (Dang giao / Hoan thanh / Da huy): ";
    string newStatus;
    getline(cin, newStatus);

    bool updated = false;
    for (int j = 0; j < 3; j++) {
        if (sampleOrderIds[j] == inputOrderId) {
            sampleStatus[j] = newStatus;
            cout << "=> Don hang " << sampleOrderIds[j] << " cap nhat thanh: \"" << sampleStatus[j] << "\"\n\n";
            updated = true;
            break;
        }
    }
    if (!updated) cout << "Khong tim thay ma don hang vua nhap.\n\n";

    //Bài 7
    cout << "--- 7. TIM DON THEO TEN KHACH HANG ---\n";
    string customerList[3] = {"Nguyen Van An", "Tran Thi Mai", "An Binh"};
    string orderDesc[3] = {"Don DH01 (Banh mi)", "Don DH02 (Tra sua)", "Don DH03 (Com tam)"};

    cout << "Nhap tu khoa ten khach hang can tim: ";
    string searchKey;
    getline(cin, searchKey);

    cout << "Ket qua tim thay:\n";
    string lowerKey = toLowerString(searchKey);
    bool anyFound = false;
    for (int j = 0; j < 3; j++) {
        if (toLowerString(customerList[j]).find(lowerKey) != string::npos) {
            cout << "  - " << customerList[j] << ": " << orderDesc[j] << "\n";
            anyFound = true;
        }
    }
    if (!anyFound) cout << "  Khong tim thay don hang phu hop.\n";
    cout << "\n";

    //Bài 9
    cout << "--- 9. THONG KE MON AN BAN CHAY ---\n";
    string orderItems[5] = {"Banh mi", "Tra sua", "Banh mi", "Com tam", "Banh mi"};
    cout << "Nhap ten mon an can dem so don: ";
    string targetFood;
    getline(cin, targetFood);

    int countOrder = 0;
    for (int j = 0; j < 5; j++) {
        if (toLowerString(orderItems[j]) == toLowerString(targetFood)) {
            countOrder++;
        }
    }
    cout << "=> Mon [" << targetFood << "] xuat hien trong " << countOrder << " don hang.\n\n";

    //Bài 10
    cout << "--- 10. TAO THONG BAO GIAO HANG ---\n";
    cout << "Nhap ten khach: ";
    string nCust;
    getline(cin, nCust);
    cout << "Nhap ma don hang: ";
    string nOrder;
    getline(cin, nOrder);

    string notifyMsg = "Don hang [" + nOrder + "] cua [" + nCust + "] dang duoc giao den. Cam on ban!";
    cout << "\nThong bao hoan chinh:\n" << notifyMsg << "\n";

    return 0;
}