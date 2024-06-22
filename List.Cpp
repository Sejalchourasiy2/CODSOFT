#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct todolist
{
    int id;
    string task;
};

int ID;

void banner();
void addTask();
void showTask();
int searchTask();
void DeleteTask();
void updateTask();
int main()
{
    system("cls");
    while (true)
    {
        banner();
        cout << "\n\t1. Add Task";
        cout << "\n\t2. show Task";
        cout << "\n\t3. search Task";
        cout << "\n\t4. Delete Task";
        cout << "\n\t5. update Task";

        int choice;
        cout << "\n\t Enter Choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addTask();
            break;

        case 2:
            showTask();
            break;

        case 3:
            searchTask();
            break;

        case 4:
            DeleteTask();
            break;

        case 5:
            updateTask();
            break;

        default:
            break;
        }
    }

    return 0;
}

void banner()
{
    cout << "_______________________________________" << endl;
    cout << " \t       MY TO DO LIST                " << endl;
    cout << "_______________________________________" << endl;
}

void addTask()
{
    system("cls");
    banner();
    todolist todo;
    cout << "enter new task : " << endl;
    cin.get();
    getline(cin, todo.task);
    char save;
    cout << "save? (Y/N):";
    cin >> save;
    if (save == 'Y')
    {
        ID++;
        ofstream fout;
        fout.open("todo.exe", ios::app);
        fout << "\n"
             << ID;
        fout << "\n"
             << todo.task;
        fout.close();

        char more;
        cout << "Add more task? (Y/N): ";
        cin >> more;
        if (more == 'Y')
        {
            addTask();
        }
        else
        {
            system("cls");
            cout << "Added Successfully!" << endl;
            return;
        }
    }
    system("cls");
}

void showTask()
{
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.exe");
    cout << "Task: " << endl;

    while (fin.eof())
    {
        fin >> todo.id;
        fin.ignore();
        getline(fin, todo.task);
        if (todo.task != "")
        {
            cout << "\t" << todo.id << ": " << todo.task << endl;
        }
        else
        {
            cout << "\t Empty!" << endl;
        }
    }
    fin.close();
    char exit;
    cout << "Exit? (Y/N):";
    cin >> exit;
    if (exit != 'Y')
    {
        showTask();
    }
    system("cls");
}

int searchTask()
{
    system("cls");
    banner();
    int id;
    cout << "Enter task id :";
    cin >> id;
    todolist todo;
    ifstream fin("todo.exe");
    while (!fin.eof())
    {
        fin >> todo.id;
        fin.ignore();
        getline(fin, todo.task);
        if (todo.id == id)
        {
            system("cls");
            cout << "\t" << ": " << todo.task << endl;
            return id;
        }
    }
    system("cls");
    cout << "Not Found" << endl;
    return 0;
}

void DeleteTask()
{
    system("cls");
    int id = searchTask();
    if (id != 0)
    {
        char del;
        cout << "\n\tDelete? (Y/N):";
        cin >> del;

        if (del == 'Y')
        {
            todolist todo;
            ofstream tempFile;
            tempFile.open("temp.exe");
            ifstream fin;
            fin.open("todo.exe");
            int index = 1;
            while (!fin.eof())
            {
                fin >> todo.id;
                fin.ignore();
                getline(fin, todo.task);
                if(todo.id != id){
                    tempFile << "\n" << index;
                    tempFile << "\n" << todo.task;
                    index++;
                    ID--;
                }
            }
            fin.close();
            tempFile.close();
            remove("todo.exe");
            rename("temp.exe","todo.exe");
            system("cls");
            cout << "\n\tDeleted Successfully!" << endl;

        }
        else{
            system("cls");
            cout << "\n\tNot Deleted..X" << endl;
        }
    }
}

void updateTask()
{
    system("cls");
    int id = searchTask();
    if (id != 0)
    {
        char update;
        cout << " \n Ener dat for update :" << endl;
        cout << "\n\tupdated? (Y/N):";
        cin >> update;

        if (update == 'Y')
        {
            todolist todo;
            ofstream tempFile;
            tempFile.open("temp.exe");
            ifstream fin;
            fin.open("todo.exe");
            int index = 1;
            while (!fin.eof())
            {
                fin >> todo.id;
                fin.ignore();
                getline(fin, todo.task);
                if(todo.id != id){
                    tempFile << "\n" << index;
                    tempFile << "\n" << todo.task;
                    index++;
                    ID--;
                }
            }
            fin.close();
            tempFile.close();
            rename("temp.exe","todo.exe");
            
            system("cls");
            cout << "\n\tUpdated Successfully!" << endl;

        }
        else{
            system("cls");
            cout << "\n\tNot updated..X" << endl;
        }
    }
}