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
    cout << "***** 1. 添加联系人 *****" << endl;
    cout << "***** 2. 显示联系人 *****" << endl;
    cout << "***** 3. 删除联系人 *****" << endl;
    cout << "***** 4. 查找联系人 *****" << endl;
    cout << "***** 5. 修改联系人 *****" << endl;
    cout << "***** 6. 清空联系人 *****" << endl;
    cout << "***** 0. 退出通讯录 *****" << endl;
    cout << "***********************" << endl;
}

// 1.0 增加联系人
void addPerson(Addressbooks * abs) {

    if (abs->m_Size == MAX) {
        cout << "通讯录已满！" ;
        return;
    }else {
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout << "请输入性别：" << endl;
        cout << "1 -- 男"    << endl;
        cout << "2 -- 女"    << endl;

        int sex = 0;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入错误，请重新输入！（1/2）" << endl;
        }

        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        cout << "请输入电话：" << endl;
        string telnum;
        cin >> telnum;
        abs->personArray[abs->m_Size].m_Phone = telnum;

        cout << "请输入地址：" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        //
        abs->m_Size++;
        cout << "添加成功！！！" << endl;

        // 清空屏幕
        system("cls");
    }
}

// 2. 显示通讯录中所有的联系人
void showPerson(Addressbooks * abs) {
    if (abs->m_Size == 0) {
        cout << "当前通讯录为空！" << endl;
    }else {
        for (int i = 0; i < abs->m_Size;i++) {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女")  << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "地址：" << abs->personArray[i].m_Addr << endl;
        }
    }
}

int ifExists(Addressbooks * abs,string name) {
    if (abs->m_Size == 0){
        cout << "联系人列表为空！" << endl;
    }else {
        for(int i = 0; i < abs->m_Size; i++){
            if (abs->personArray[i].m_Name == name){
                return i;
            }
        }
    }
    return -1;
}

// 3.0 删除指定联系人
void deletePerson(Addressbooks * abs) {
    string name;
    cout << "请输入要删除的联系人：" ;
    cin >> name;
    int index = ifExists(abs,name);
    if (index == -1) {
        cout << "查无此人" << endl;
    }else {
        for(int i = index; i < abs->m_Size - 1; i++){
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;
        cout << "删除成功！" << endl;
    }
    system("cls");
}

// 4. 查找指定联系人
void findPerson(Addressbooks * abs) {
    string name;
    cout << "请输入要查询的联系人：" ;
    cin >> name;
    int index = ifExists(abs,name);
    if (index == -1) {
        cout << "查无此人" << endl;
    }else {
        cout << "姓名：" << abs->personArray[index].m_Name << "\t";
        cout << "性别：" << (abs->personArray[index].m_Sex == 1 ? "男" : "女")  << "\t";
        cout << "年龄：" << abs->personArray[index].m_Age << "\t";
        cout << "电话：" << abs->personArray[index].m_Phone << "\t";
        cout << "地址：" << abs->personArray[index].m_Addr << endl;
    }

}

// 5. 更新联系人信息
void updatePerson(Addressbooks * abs){
    cout << "请输入要修改的联系人信息：" << endl;
    string name;
    cin >> name;
    int index = ifExists(abs,name);
    if (index != -1) {

        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[index].m_Name = name;

        cout << "请输入性别：" << endl;
        cout << "1 -- 男"    << endl;
        cout << "2 -- 女"    << endl;

        int sex = 0;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[index].m_Sex = sex;
                break;
            }
            cout << "输入错误，请重新输入！（1/2）" << endl;
        }

        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[index].m_Age = age;

        cout << "请输入电话：" << endl;
        string telnum;
        cin >> telnum;
        abs->personArray[index].m_Phone = telnum;

        cout << "请输入地址：" << endl;
        string address;
        cin >> address;
        abs->personArray[index].m_Addr = address;

        cout << "更新成功！！！" << endl;

    }else {
        cout << "查无此人！" << endl;
    }
}

void deleteAllPerson(Addressbooks * abs) {
    abs->m_Size = 0;
    cout << "通讯录已经空了！" << endl;
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
            case 1:     // 1. 添加联系人
                addPerson(&abs);
                break;
            case 2:     // 2. 显示联系人
                showPerson(&abs);
                break;
            case 3:     // 3. 删除联系人
                deletePerson(&abs);
                break;
            case 4:     // 4. 查找联系人
                findPerson(&abs);
                break;
            case 5:     // 5. 修改联系人
                updatePerson(&abs);
                break;
            case 6:     // 6. 清空联系人
                deleteAllPerson(&abs);
                break;
            case 0:     // 0. 退出通讯录
                cout << "欢迎下次使用！" << endl;
                return 0;
                break;
        }

    }
    return 0;
}
