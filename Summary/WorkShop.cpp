#include <iostream>
#include <string>
#include <vector>
using namespace std;

//////////////////////////////////////////////////////
// Potion 클래스: 물약 객체를 나타냄
//////////////////////////////////////////////////////
class Potion {
private:
    string name_;                // 물약 이름
    int price_;                  // 물약 가격
    vector<string> ingredients_; // 물약을 만들 때 필요한 재료 목록

public:
    // 생성자
    Potion(const string& name, int price, const vector<string>& ingredients)
        : name_(name), price_(price), ingredients_(ingredients) {
    }

    // getter 함수
    string GetName() const { return name_; }
    int GetPrice() const { return price_; }
    const vector<string>& GetIngredients() const { return ingredients_; }

    // 물약의 전체 정보 출력
    void PrintInfo() const {
        cout << "[이름: " << name_ << ", 가격: " << price_ << "G, 재료: ";
        for (size_t i = 0; i < ingredients_.size(); i++) {
            cout << ingredients_[i];
            if (i < ingredients_.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

//////////////////////////////////////////////////////
// Workshop 클래스: 공방 관리
//////////////////////////////////////////////////////
class Workshop {
private:
    vector<Potion> potions_;  // 공방에 보관된 물약들

public:
    // 물약 추가
    void AddPotion(const Potion& potion) {
        potions_.push_back(potion);
    }

    // 전체 물약 출력
    void PrintAllPotions() const {
        if (potions_.empty()) {
            cout << "(현재 공방에 등록된 물약이 없습니다.)" << endl;
            return;
        }
        for (const auto& p : potions_) {
            p.PrintInfo();
        }
    }

    // 이름으로 검색
    void SearchByName(const string& name) const {
        for (const auto& p : potions_) {
            if (p.GetName() == name) {
                cout << "검색 성공!" << endl;
                p.PrintInfo();
                return;
            }
        }
        cout << "해당 이름의 물약을 찾을 수 없습니다." << endl;
    }

    // 재료로 검색
    void SearchByIngredient(const string& ingredient) const {
        bool found = false;
        for (const auto& p : potions_) {
            for (const auto& ing : p.GetIngredients()) {
                if (ing == ingredient) {
                    if (!found) cout << "검색된 물약 목록:" << endl;
                    p.PrintInfo();
                    found = true;
                    break; // 같은 물약에서 중복 재료 확인 방지
                }
            }
        }
        if (!found) {
            cout << "해당 재료가 포함된 물약을 찾지 못했습니다." << endl;
        }
    }
};

//////////////////////////////////////////////////////
// 실행 예제 (main 함수) - 메뉴 기반
//////////////////////////////////////////////////////
int main() {
    Workshop workshop;

    // 샘플 물약 등록
    workshop.AddPotion(Potion("치유 물약", 50, { "허브", "물" }));
    workshop.AddPotion(Potion("마나 물약", 70, { "마법가루", "물" }));
    workshop.AddPotion(Potion("힘의 물약", 100, { "오크심장", "허브" }));

    int choice;
    string input;

    while (true) {
        cout << "\n=== 연금술 공방 관리 시스템 ===" << endl;
        cout << "1. 전체 물약 보기" << endl;
        cout << "2. 이름으로 검색" << endl;
        cout << "3. 재료로 검색" << endl;
        cout << "0. 종료" << endl;
        cout << "메뉴 선택: ";
        cin >> choice;
        cin.ignore(); // 버퍼에 남은 개행문자 제거

        if (choice == 0) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }

        switch (choice) {
        case 1:
            workshop.PrintAllPotions();
            break;
        case 2:
            cout << "검색할 물약 이름을 입력하세요: ";
            getline(cin, input);
            workshop.SearchByName(input);
            break;
        case 3:
            cout << "검색할 재료를 입력하세요: ";
            getline(cin, input);
            workshop.SearchByIngredient(input);
            break;
        default:
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}
