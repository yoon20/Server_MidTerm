// chatClient.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
//�����ε��̶� ?? ��ø�ؼ� �̸��� ���� ���� ��
//�������̵��̶�?? �θ�Ŭ������ �ż��带 ����Ŭ������ �������ؼ� ���

#include <iostream>
#include <thread>
//thread ������ ���̺귯��
#include <chrono>
//chrono �ð����õ� ���̺귯��
#include <string>
#include <mutex>

using namespace std;

string Atk = "��������";
mutex Atk_Damage;

void Hp(string Aname, string Bname)
{
	cout << "\n\n";
	cout << Aname << ":" << Bname << " �õ�" << endl;
	cout << Aname << ":" << Bname << " 2ȸ�õ�" << endl;
	this_thread::sleep_for(std::chrono::milliseconds(1000));
}


void GetDamage(string name) {
	Atk_Damage.lock();
	Atk = name;
	Hp("System", Atk);
	this_thread::sleep_for(std::chrono::milliseconds(5000));//5��
	cout << "System:" << name << " �����߽����ϴ�";
	Atk_Damage.unlock();
}

void main() {

	thread Alpa(GetDamage,  "Beta�� ����"); //thread2
	thread Beta(GetDamage,  "Alpa�� ����");//thre1

	Alpa.join();
	Beta.join();

}
