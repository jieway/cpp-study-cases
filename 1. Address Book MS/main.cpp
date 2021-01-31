#include <iostream>
#define MAX 1000
using namespace std;

struct Person{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct Addressbooks {
    struct Person personArray[MAX];
    int m_Size;
};

void showMenu(){
    cout << "***********************" << endl;
    cout << "***** 1. �����ϵ�� *****" << endl;
    cout << "***** 2. ��ʾ��ϵ�� *****" << endl;
    cout << "***** 3. ɾ����ϵ�� *****" << endl;
    cout << "***** 4. ������ϵ�� *****" << endl;
    cout << "***** 5. �޸���ϵ�� *****" << endl;
    cout << "***** 6. �����ϵ�� *****" << endl;
    cout << "***** 0. �˳�ͨѶ¼ *****" << endl;
    cout << "***********************" << endl;
}

// 1.0 ������ϵ��
void addPerson(Addressbooks * abs) {

    if (abs->m_Size == MAX) {
        cout << "ͨѶ¼������" ;
        return;
    }else {
        string name;
        cout << "������������" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout << "�������Ա�" << endl;
        cout << "1 -- ��"    << endl;
        cout << "2 -- Ů"    << endl;

        int sex = 0;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "����������������룡��1/2��" << endl;
        }

        cout << "���������䣺" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        cout << "������绰��" << endl;
        string telnum;
        cin >> telnum;
        abs->personArray[abs->m_Size].m_Phone = telnum;

        cout << "�������ַ��" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        //
        abs->m_Size++;
        cout << "��ӳɹ�������" << endl;

        // �����Ļ
        system("cls");
    }
}

// 2. ��ʾͨѶ¼�����е���ϵ��
void showPerson(Addressbooks * abs) {
    if (abs->m_Size == 0) {
        cout << "��ǰͨѶ¼Ϊ�գ�" << endl;
    }else {
        for (int i = 0; i < abs->m_Size;i++) {
            cout << "������" << abs->personArray[i].m_Name << "\t";
            cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů")  << "\t";
            cout << "���䣺" << abs->personArray[i].m_Age << "\t";
            cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
            cout << "��ַ��" << abs->personArray[i].m_Addr << endl;
        }
    }
}

int ifExists(Addressbooks * abs,string name) {
    if (abs->m_Size == 0){
        cout << "��ϵ���б�Ϊ�գ�" << endl;
    }else {
        for(int i = 0; i < abs->m_Size; i++){
            if (abs->personArray[i].m_Name == name){
                return i;
            }
        }
    }
    return -1;
}

// 3.0 ɾ��ָ����ϵ��
void deletePerson(Addressbooks * abs) {
    string name;
    cout << "������Ҫɾ������ϵ�ˣ�" ;
    cin >> name;
    int index = ifExists(abs,name);
    if (index == -1) {
        cout << "���޴���" << endl;
    }else {
        for(int i = index; i < abs->m_Size - 1; i++){
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;
        cout << "ɾ���ɹ���" << endl;
    }
    system("cls");
}

// 4. ����ָ����ϵ��
void findPerson(Addressbooks * abs) {
    string name;
    cout << "������Ҫ��ѯ����ϵ�ˣ�" ;
    cin >> name;
    int index = ifExists(abs,name);
    if (index == -1) {
        cout << "���޴���" << endl;
    }else {
        cout << "������" << abs->personArray[index].m_Name << "\t";
        cout << "�Ա�" << (abs->personArray[index].m_Sex == 1 ? "��" : "Ů")  << "\t";
        cout << "���䣺" << abs->personArray[index].m_Age << "\t";
        cout << "�绰��" << abs->personArray[index].m_Phone << "\t";
        cout << "��ַ��" << abs->personArray[index].m_Addr << endl;
    }

}

// 5. ������ϵ����Ϣ
void updatePerson(Addressbooks * abs){
    cout << "������Ҫ�޸ĵ���ϵ����Ϣ��" << endl;
    string name;
    cin >> name;
    int index = ifExists(abs,name);
    if (index != -1) {

        string name;
        cout << "������������" << endl;
        cin >> name;
        abs->personArray[index].m_Name = name;

        cout << "�������Ա�" << endl;
        cout << "1 -- ��"    << endl;
        cout << "2 -- Ů"    << endl;

        int sex = 0;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[index].m_Sex = sex;
                break;
            }
            cout << "����������������룡��1/2��" << endl;
        }

        cout << "���������䣺" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[index].m_Age = age;

        cout << "������绰��" << endl;
        string telnum;
        cin >> telnum;
        abs->personArray[index].m_Phone = telnum;

        cout << "�������ַ��" << endl;
        string address;
        cin >> address;
        abs->personArray[index].m_Addr = address;

        cout << "���³ɹ�������" << endl;

    }else {
        cout << "���޴��ˣ�" << endl;
    }
}

void deleteAllPerson(Addressbooks * abs) {
    abs->m_Size = 0;
    cout << "ͨѶ¼�Ѿ����ˣ�" << endl;
    system("cls");
}
int main() {
    Addressbooks abs;
    abs.m_Size = 0;
    int select = 0;
    while(true) {
        showMenu();
        cin >> select;
        switch(select) {
            case 1:     // 1. �����ϵ��
                addPerson(&abs);
                break;
            case 2:     // 2. ��ʾ��ϵ��
                showPerson(&abs);
                break;
            case 3:     // 3. ɾ����ϵ��
                deletePerson(&abs);
                break;
            case 4:     // 4. ������ϵ��
                findPerson(&abs);
                break;
            case 5:     // 5. �޸���ϵ��
                updatePerson(&abs);
                break;
            case 6:     // 6. �����ϵ��
                deleteAllPerson(&abs);
                break;
            case 0:     // 0. �˳�ͨѶ¼
                cout << "��ӭ�´�ʹ�ã�" << endl;
                return 0;
                break;
        }

    }
    return 0;
}
