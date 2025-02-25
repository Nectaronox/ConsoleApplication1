// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::string;
using std::cin;


class Item{
private:
	string itemquality;
	string itemType; // 아이템 종류
	int itemattackPower;
	int itemdefencePower;
	int itemgivehp;
	int itemgivemp;
public:
	Item( string t, int ap, int dp, int givehp, int givemp, string q) : itemType(t), itemattackPower(ap), itemdefencePower(dp), itemgivehp(givehp), itemgivemp(givemp), itemquality(q) {}

	static Item getItemrandomgenerated() {
		string iTypes[] = { "shield", "sword", "staff"};
		string iqua[] = { "노말", "레어", "유니크", "전설", "신화"};

		int bsat;
		int bsdf;
		int bsgh;
		int bsgm;

		int iTindex = rand() % 3;
		int iqindex = rand() % 5;
		if (iTindex == 0) {
			bsat = 10;
			bsdf = 60;
			bsgh = 200;
			bsgm = 10;
		}
		else if (iTindex == 1) {
			bsat = 50;
			bsdf = 40;
			bsgh = 100;
			bsgm = 80;
		}
		else {
			bsat = 60;
			bsdf = 10;
			bsgh = 30;
			bsgm = 300;
		}
		bsat += 1 + 30 * iqindex;
		bsdf = 1 + 40 * iqindex;
		return Item(iTypes[iTindex], bsat, bsdf,bsgh,bsgm, iqua[iqindex]);
	}
	string getItemType() const {
		return itemType;
	}
	
	int getItemattackPower() const {
		return itemattackPower;
	}
	int getItemdefencePower() const {
		return itemdefencePower;
	}
	int getItemgivehp() const {
		return itemgivehp;
	}
	int getItemgivemp() const {
		return itemgivemp;
	}
	string getItemquality() const {
		return itemquality;
	}
	void Itemgeneratealim() {
				cout << itemType << "아이템이 생성되었습니다. 이 아이템은 공격력이" << itemattackPower << 
					"이고 방어력이" << itemdefencePower <<  " mp를 " << itemgivemp << " hp를 " << itemgivehp<< "입니다." << endl;
	};
	void Iteminformation() {
		cout << itemType << "이 아이템은 공격력이" << itemattackPower << "등급이" << itemquality <<
			"이고 방어력이" << itemdefencePower << " mp를 " << itemgivemp << " hp를 " << itemgivehp << "입니다." << endl;
	};
};
class Monster {
private:
	string type; // 몬스터 종류
	string grade;

	int monattackpower; // 몬스터 공격력
	int monhp; // 몬스터 체력
public:
	Monster(string t, int monap, string g, int monhp) : type(t), monattackpower(monap), grade(g), monhp(monhp) {}

	static Monster getMonsterrandomgenerated() {
		string types[] = { "goblin", "lizardman", "orc", "highorc", "troll", "ogre", "twinheadorge", "dragon" };
		string grades[] = { "F", "E", "D", "C", "B", "A", "S", "SS", "SSS", "EX" };

		int montypeindex = rand() % 8;
		int mongradeindex = rand() % 10;

		int basehp = 50 + 30 * montypeindex;
		basehp += 1 + 1 * mongradeindex;
		int baseattack = 10 + 30 * montypeindex;
		baseattack += 1 + 1 * mongradeindex;

		return Monster(types[montypeindex], baseattack, grades[mongradeindex], basehp);
	}
	string getType() const {
		return type;
	}
	int getMonattackpower() const {
		return monattackpower;
	}
	int getmonhp() const {
		return monhp;
	}
	void setmonhp(int newhp) {
		monhp = newhp;
	}
	string getgrade() const {
		return grade;
	}

	void Monstergeneratealim() {
		cout << type << "몬스터가 생성되었습니다. 이 몬스터는 피가" <<
			monhp << "이고 공격력이" << monattackpower << "입니다." << endl;
	}
};
class Player {
private:
	string job; // 플레이어 직업
	int plylevel; // 플레이어 레벨
	int plyhp; // 플레이어 체력
	int plymp; // 플레이어 마나
	int plyexp; // 플레이어 경험
	int plypower; // 플레이어 공격력
	int plydefense;
	std::vector<Item> inventory;
	Item* equippedItem;


public:
	Player(string j) : job(j), plylevel(1), plyhp(100), plymp(10), plyexp(1),
		plypower(30), plydefense(20), equippedItem(nullptr) {
	}

	void Playerjob(string job) {
		if (job == "전사") {
			plyhp += 150;
			plymp += 40;
			plypower += 800;
			plydefense += 30;
		}
		else if (job == "마법사") {
			plyhp += 100;
			plymp += 200;
			plypower += 100;
			plydefense += 5;
		}
		else if (job == "방패전사") {
			plyhp += 200;
			plymp += 20;
			plypower += 30;
			plydefense += 100;
		}
		else {
			cout << "잘못된 직업입니다." << endl;
		};
	}

	void Playerlevelup() {
		if (plyexp >= 100) {
			plylevel += 1;
			plyexp -= 100;
			plyhp += 10;
			plymp += 10;
			plypower += 5;
			plydefense += 3;
		}
		else {
			cout << "경험치가 부족합니다." << endl;
		};
	}

	void itemget(Item item) {
		inventory.push_back(item);
		plypower += item.getItemattackPower();
		plydefense += item.getItemdefencePower();
		plyhp += item.getItemgivehp();
		plymp += item.getItemgivemp();
		cout << "아이템을 장착하였습니다." << endl;
	}

	void checkinventory() {
		cout << " == 인벤토리 == " << endl;
		for (int i = 0; i < inventory.size(); i++) {
			cout << i + 1 << "번째 아이템은" << endl;
			inventory[i].Iteminformation();
		}
	}

	/*void UseSkill() {
		int skill;

		if (plymp >= 20) {
			cout << "스킬이 성공적으로 사용되었습니다." << endl;
			plymp -= 20;
			int skill = plypower * rand() % 20;
		}
		else {
			cout << "스킬이 실패하였습니다." << endl;
			int skill = 0;
		}
	}
	*/

	void playerheal() {
		int plyheal = rand() % 3 * plydefense * 1 / 10;
		plyhp += plyheal;
		cout << "플레이어가" << plyheal << "만큼 굳건해졌습니다." << endl;
	}

	bool Battle(Player& player, Monster& monster) {
		monster.Monstergeneratealim();
		while (player.plyhp > 0 && monster.getmonhp() > 0) {
			cout << "플레이어의 턴입니다" << endl;

			int playerjustattack = rand() % 10 * player.plypower;
			monster.setmonhp(monster.getmonhp() - playerjustattack);
			cout << "플레이어가" << playerjustattack << "만큼 공격했습니다." << endl;

			if (plyhp > 0 && monster.getmonhp() <= 0) {
				cout << "플레이어가 승리했습니다." << endl;
				break;
			}
			else {
				cout << "몬스터의 턴입니다." << endl;
				int monsterjustattack = rand() % 10 * monster.getMonattackpower();
				player.plyhp -= monsterjustattack / player.plydefense;
				cout << "몬스터가" << monsterjustattack << "만큼 공격했습니다." << endl;
				player.playerheal();
			}
			}
		if (player.plyhp <= 0) {
			cout << "플레이어가 패배했습니다." << endl;
			return false;
		}
		else {
			player.plyexp += 10;
			player.Playerlevelup();
			Item item = Item::getItemrandomgenerated();
			player.itemget(item);
			return true;
		}
		return true;
	}
	string getjob() const {
		return job;
	}
	int getplylevel() const {
		return plylevel;
	}
	int getplyhp() const {
		return plyhp;
	}
	int getplymp() const {
		return plymp;
	}
	int getplyexp() const {
		return plyexp;
	}
	int getplypower() const {
		return plypower;
	}
	int getplydefense() const {
		return plydefense;
	}
};

int main() {
	cout << "운빨rpg 게임에 오신 것을 환영합니다" << endl;
	cout << "당신의 이름을 입력해주세요" << endl;
	string name;
	cin >> name;
	cout << "당신의 용감한 이름은 " << name << " 입니다." << endl;
	cout << "당신의 직업을 선택해주세요" << endl;
	cout << "전사, 마법사, 방패전사" << endl;
	string job;
	cin >> job;
	Player player(job);
	cout << "당신의 직업은 " << job << "입니다." << endl;
	bool gamerunning = true;
	while (gamerunning == true) {
		cout << "이제 무엇을 할지 정해주세요" << endl;
		cout << "1. 전투하기\n2. 인벤토리 창 확인하기\n3. 플레이어 정보 확인하기\n4. 게임 종료하기" << endl;
		int choice;
		cin >> choice;

		switch (choice) {
		case 1: {
			Monster monster = Monster::getMonsterrandomgenerated();
			player.Battle(player, monster);
			break;
		}

		case 2: {
			player.checkinventory();
			break;
		}
		case 3: {
			cout << "플레이어의 정보는 다음과 같습니다." << endl;
			cout << "직업은" << player.getjob() << "이고 레벨은" << player.getplylevel() << "입니다." << endl;
			cout << "체력은" << player.getplyhp() << "이고 마나는" << player.getplymp() << "입니다." << endl;
			cout << "공격력은" << player.getplypower() << "이고 방어력은" << player.getplydefense() << "입니다." << endl;
			break;
		}
		case 4: {
			gamerunning = false;
			cout << "게임을 종료합니다." << endl;
			break;
		}
		default: {
			cout << "잘못된 입력입니다." << endl;
			break;
		}
		}
	}
	cout << "게임을 종료합니다" << endl;
	return 0;
};


