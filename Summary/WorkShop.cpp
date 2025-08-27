#include <iostream>
#include <string>
#include <vector>
using namespace std;

//////////////////////////////////////////////////////
// Potion Ŭ����: ���� ��ü�� ��Ÿ��
//////////////////////////////////////////////////////
class Potion {
private:
    string name_;                // ���� �̸�
    int price_;                  // ���� ����
    vector<string> ingredients_; // ������ ���� �� �ʿ��� ��� ���

public:
    // ������
    Potion(const string& name, int price, const vector<string>& ingredients)
        : name_(name), price_(price), ingredients_(ingredients) {
    }

    // getter �Լ�
    string GetName() const { return name_; }
    int GetPrice() const { return price_; }
    const vector<string>& GetIngredients() const { return ingredients_; }

    // ������ ��ü ���� ���
    void PrintInfo() const {
        cout << "[�̸�: " << name_ << ", ����: " << price_ << "G, ���: ";
        for (size_t i = 0; i < ingredients_.size(); i++) {
            cout << ingredients_[i];
            if (i < ingredients_.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

//////////////////////////////////////////////////////
// Workshop Ŭ����: ���� ����
//////////////////////////////////////////////////////
class Workshop {
private:
    vector<Potion> potions_;  // ���濡 ������ �����

public:
    // ���� �߰�
    void AddPotion(const Potion& potion) {
        potions_.push_back(potion);
    }

    // ��ü ���� ���
    void PrintAllPotions() const {
        if (potions_.empty()) {
            cout << "(���� ���濡 ��ϵ� ������ �����ϴ�.)" << endl;
            return;
        }
        for (const auto& p : potions_) {
            p.PrintInfo();
        }
    }

    // �̸����� �˻�
    void SearchByName(const string& name) const {
        for (const auto& p : potions_) {
            if (p.GetName() == name) {
                cout << "�˻� ����!" << endl;
                p.PrintInfo();
                return;
            }
        }
        cout << "�ش� �̸��� ������ ã�� �� �����ϴ�." << endl;
    }

    // ���� �˻�
    void SearchByIngredient(const string& ingredient) const {
        bool found = false;
        for (const auto& p : potions_) {
            for (const auto& ing : p.GetIngredients()) {
                if (ing == ingredient) {
                    if (!found) cout << "�˻��� ���� ���:" << endl;
                    p.PrintInfo();
                    found = true;
                    break; // ���� ���࿡�� �ߺ� ��� Ȯ�� ����
                }
            }
        }
        if (!found) {
            cout << "�ش� ��ᰡ ���Ե� ������ ã�� ���߽��ϴ�." << endl;
        }
    }
};

//////////////////////////////////////////////////////
// ���� ���� (main �Լ�) - �޴� ���
//////////////////////////////////////////////////////
int main() {
    Workshop workshop;

    // ���� ���� ���
    workshop.AddPotion(Potion("ġ�� ����", 50, { "���", "��" }));
    workshop.AddPotion(Potion("���� ����", 70, { "��������", "��" }));
    workshop.AddPotion(Potion("���� ����", 100, { "��ũ����", "���" }));

    int choice;
    string input;

    while (true) {
        cout << "\n=== ���ݼ� ���� ���� �ý��� ===" << endl;
        cout << "1. ��ü ���� ����" << endl;
        cout << "2. �̸����� �˻�" << endl;
        cout << "3. ���� �˻�" << endl;
        cout << "0. ����" << endl;
        cout << "�޴� ����: ";
        cin >> choice;
        cin.ignore(); // ���ۿ� ���� ���๮�� ����

        if (choice == 0) {
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }

        switch (choice) {
        case 1:
            workshop.PrintAllPotions();
            break;
        case 2:
            cout << "�˻��� ���� �̸��� �Է��ϼ���: ";
            getline(cin, input);
            workshop.SearchByName(input);
            break;
        case 3:
            cout << "�˻��� ��Ḧ �Է��ϼ���: ";
            getline(cin, input);
            workshop.SearchByIngredient(input);
            break;
        default:
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0;
}
