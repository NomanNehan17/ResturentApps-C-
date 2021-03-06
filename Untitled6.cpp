//Name-Abdullah_Al-Noman
//Id-C211017

/*
██████╗░███████╗░██████╗████████╗░█████╗░██╗░░░██╗██████╗░░█████╗░███╗░░██╗████████╗
██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔══██╗██║░░░██║██╔══██╗██╔══██╗████╗░██║╚══██╔══╝
██████╔╝█████╗░░╚█████╗░░░░██║░░░███████║██║░░░██║██████╔╝███████║██╔██╗██║░░░██║░░░
██╔══██╗██╔══╝░░░╚═══██╗░░░██║░░░██╔══██║██║░░░██║██╔══██╗██╔══██║██║╚████║░░░██║░░░
██║░░██║███████╗██████╔╝░░░██║░░░██║░░██║╚██████╔╝██║░░██║██║░░██║██║░╚███║░░░██║░░░
╚═╝░░╚═╝╚══════╝╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝░░░╚═╝░░░
*/


#include<bits/stdc++.h>
using namespace std;

///for owner list file
class ownerFile
{
    public:
        string ID,NAME,NUMBER;
};

class ownerFile ownerList[100];
int z;

///for reading or getting the data from ownerList.txt file
void ownerListRead()
{
    z = 0;
    ifstream ownerDataBase("ownerList.txt");
    while ((ownerDataBase>>ownerList[z].ID))
    {
        ownerDataBase>>ownerList[z].NAME;
        ownerDataBase>>ownerList[z].NUMBER;
        z++;
    }
    ownerDataBase.close();
}

///for foodMenu file
class menuFile
{
    public:
        int menuNumber,foodPrice,foodQuantity;
        string foodName;
};

class menuFile foodlist[100];
int f;

///reading food list file
void foodListRead()
{
    f = 0;
    ifstream foodDataBase("FoodMenu.txt");
    while ((foodDataBase>>foodlist[f].menuNumber))
    {
        foodDataBase>>foodlist[f].foodName;
        foodDataBase>>foodlist[f].foodPrice;
        foodDataBase>>foodlist[f].foodQuantity;
        f++;
    }
    foodDataBase.close();
}

///class for customerPanel file
class customerfile
{
    public:
        string userName,password;
};

class customerfile customerList[1000];
int c;

///reading customerPanel file
void customerPanelRead()
{
    c = 0;
    ifstream customerDB("customerPanel.txt");
    while(customerDB>>customerList[c].userName)
    {
        customerDB>>customerList[c].password;
        c++;
    }
    customerDB.close();
}


///see all food of foodMenu file
void seeAllFood()
{
    system("color 09");
    foodListRead();
    for(int i = 0;i < f;i++)
    {
        cout << "\t\t\tMenu Number:" << foodlist[i].menuNumber << endl;
        cout << "\t\t\tFood Name:" << foodlist[i].foodName << endl;
        cout << "\t\t\tPrice:" << foodlist[i].foodPrice << endl;
        cout << "\t\t\tStock Available:" << foodlist[i].foodQuantity << endl << endl;

    }
}


class owner
{
    private:
        string id,name,number;
    public:
        ///getting owner info
        void ownerInfo()
        {
            system("cls");
            cout << "Enter your ID." << endl;
            cin >> id;
            cout <<"Enter your name." << endl;
            cin >> name;
            cout <<"Enter your number." << endl;
            cin >> number;
        }

        ///checking the owner in owner list file
        int ownerChecking()
        {
            ownerListRead();
            bool found = false;
            for(int i = 0;i < z;i++)
            {
                if((id == ownerList[i].ID) && (name == ownerList[i].NAME) && (number == ownerList[i].NUMBER))
                {
                    found = true;
                    break;
                }
            }
            if(found)
                return 1;
            else
                return 0;
        }

        ///those are the thing a ownercan do in this owner pannel
        int ownerSelection()
        {
            system("cls");
            system("color 07");
            int select;
            cout << "Access Granted!!! \n \n \n" << endl;
            cout<<"To Add items in menu press 1:"<<endl;
            cout<<"To Edit items press 2:"<<endl;///name,price,quantity
            cout <<"To delete item press 3:" << endl;
            cout<<"To add owner press 4:"<<endl;
            cout<<"To edit owner press 5:"<<endl;
            cout<<"To delete owner press 6:"<<endl;
            cout <<"To See all the owner press 7:" << endl;
            cout<<"To see all the food press 8:"<<endl;
            cout<<"To Skip press 9:"<<endl;
            cin>>select;
            return select;
        }

        ///adding new food in foodMenu file
        void addItems()
        {
            ///system("cls");
            system("color 0E");
            ///foodListRead();
            int price,menuNum,quantity,select;
            string name;
            cout << "How many item do you want to add?" << endl;
            cin >> select;
            ofstream addFood("FoodMenu.txt",ios::app);
            for(int i=1;i<=select;i++)
            {
                cout << "Enter the menu number:" << endl;
                cin >> menuNum;
                cout << "Enter the food name:" << endl;
                cin >> name;
                cout << "Enter the food price:" << endl;
                cin >> price;
                cout << "Enter the food quantity:" << endl;
                cin >> quantity;
                if(i == 1)
                    addFood<<endl<<menuNum<<endl;
                else
                    addFood<<menuNum<<endl;
                addFood<<name<<endl;
                addFood<<price<<endl;
                if(i == select)
                    addFood<<quantity;
                else
                    addFood<<quantity<<endl;
            }
            addFood.close();
        }


        ///editing particular food in foodMenu file
        void editItems()
        {
            ///system("cls");
            system("color 0E");
            int price,menuNum,quantity,select,menuEdit;
            string name;
            cout << "How many item do you want to edit?" << endl;
            cin >> select;

            for(int i = 1;i <= select;i++)
            {
                foodListRead();
                ofstream editFood("FoodMenu.txt");
                cout << "Which menu do you want to edit?" << endl;
                cin >> menuEdit;
                cout << "Enter the new food name:" << endl;
                cin >> name;
                cout << "Enter the new food price:" << endl;
                cin >> price;
                cout << "Enter the new food quantity:" << endl;
                cin >> quantity;

                for(int j = 0;j < f;j++)
                {
                    if(foodlist[j].menuNumber == menuEdit)
                    {
                        editFood<<foodlist[j].menuNumber<<endl;
                        editFood<<name<<endl;
                        editFood<<price<<endl;
                        editFood<<quantity<<endl;
                    }
                    else
                    {
                        editFood<<foodlist[j].menuNumber<<endl;
                        editFood<<foodlist[j].foodName<<endl;
                        editFood<<foodlist[j].foodPrice<<endl;
                        editFood<<foodlist[j].foodQuantity<<endl;
                    }
                }
                editFood.close();
            }
        }

        ///deleting particular item from food menu file
        void deleteItem()
        {
            ///system("cls");
            system("color 0E");
            int menuNum,select;
            cout << "How many item do you want to delete?" << endl;
            cin >> select;
            for(int i = 1;i <= select;i++)
            {
                foodListRead();
                ofstream deleteFood("FoodMenu.txt");
                cout << "Which menu number do you want to delete?" << endl;
                cin >> menuNum;
                for(int j = 0;j < f;j++)
                {
                    if(foodlist[j].menuNumber == menuNum)
                        continue;
                    else
                    {
                        deleteFood<<foodlist[j].menuNumber<<endl;
                        deleteFood<<foodlist[j].foodName<<endl;
                        deleteFood<<foodlist[j].foodPrice<<endl;
                        deleteFood<<foodlist[j].foodQuantity<<endl;
                    }
                }
                deleteFood.close();
            }
        }

        ///adding new owner in ownerList file
        void addOwner()
        {
            ///system("cls");
            system("color 0E");
            ///ownerListRead();
            int select;
            string id,name,number;
            cout << "How many owner do you want to add?" << endl;
            cin>> select;
            ofstream addOwner("ownerList.txt",ios::app);
            for(int i = 1;i <= select;i++)
            {
                cout << "Enter id of new owner:" << endl;
                cin >> id;
                cout << "Enter name of new owner:" << endl;
                cin >> name;
                cout << "Enter number of new owner:" << endl;
                cin >> number;
                if(i == 1)
                    addOwner<<endl<<id<<endl;
                else
                    addOwner<<id<<endl;
                addOwner<<name<<endl;
                if(i == select)
                    addOwner<<number;
                else
                    addOwner<<number<<endl;
            }
            addOwner.close();
        }

        ///Editing particular owner info
        void editOwner()
        {
            ///system("cls");
            system("color 0E");
            int select;
            string name,id,number,editOw;
            cout << "How many owner's info do you want to edit?" << endl;
            cin >> select;
            for(int i = 1;i <= select;i++)
            {
                ownerListRead();
                ofstream editOwner("ownerList.txt");
                cout << "Whose info do you want to edit?Enter his id."<<endl;
                cin >> editOw;
                cout << "Enter the new id:" << endl;
                cin >> id;
                cout << "Enter the new name:" << endl;
                cin >> name;
                cout << "Enter the new number:" << endl;
                cin >> number;
                for(int j = 0;j < z;j++)
                {
                    if(ownerList[j].ID == editOw)
                    {
                        editOwner<<id<<endl;
                        editOwner<<name<<endl;
                        editOwner<<number<<endl;
                    }
                    else
                    {
                        editOwner<<ownerList[j].ID<<endl;
                        editOwner<<ownerList[j].NAME<<endl;
                        editOwner<<ownerList[j].NUMBER<<endl;
                    }
                }
                editOwner.close();
            }
        }

        ///deleting particular owner from ownerList file
        void deleteOwner()
        {
            ///system("cls");
            system("color 0E");
            int select;
            string id;
            cout << "How many owner do you want to delete?" << endl;
            cin >> select;
            for(int i = 1;i <= select;i++)
            {
                ownerListRead();
                ofstream deleteOwner("ownerList.txt");
                cout << "Enter the id of particular owner which you want to delete." << endl;
                cin >> id;
                for(int j = 0;j < z;j++)
                {
                    if(ownerList[j].ID == id)
                        continue;
                    else
                    {
                        deleteOwner<<ownerList[j].ID<<endl;
                        deleteOwner<<ownerList[j].NAME<<endl;
                        deleteOwner<<ownerList[j].NUMBER<<endl;
                    }
                }
                deleteOwner.close();
            }
        }

        ///see all owner of ownerList file
        void seeAllOwner()
        {
            system("color 02");
            ownerListRead();
            for(int i = 0;i < z;i++)
            {
                cout << "\t\t\tOwner ID:"<<ownerList[i].ID << endl;
                cout << "\t\t\tOwner NAME:"<<ownerList[i].NAME << endl;
                cout << "\t\t\tOwner NUMBER:"<<ownerList[i].NUMBER << endl << endl;

            }
        }
};

int amount = 0;
vector < pair<string,int> > vc;

int quantityChecking(string name,int quantity)
{
    foodListRead();
    int found = 0;
    for(int j = 0;j < f;j++)
    {
        if(foodlist[j].foodName == name)
        {
            if(foodlist[j].foodQuantity >= quantity)
            {
                amount += (foodlist[j].foodPrice * quantity);
                found = 1;
            }
        }
        if(found)
        {
            ofstream remainingQuan("FoodMenu.txt");
            for(int i = 0;i < f;i++)
            {
                remainingQuan<<foodlist[i].menuNumber<<endl;
                remainingQuan<<foodlist[i].foodName<<endl;
                remainingQuan<<foodlist[i].foodPrice<<endl;
                if(foodlist[i].foodName == name)
                    remainingQuan<<foodlist[i].foodQuantity - quantity<<endl;
                else
                    remainingQuan<<foodlist[i].foodQuantity<<endl;
            }
            remainingQuan.close();
            return 1;
        }
    }
    return 0;
}


class customer
{
    public:
        int customercheck()
        {
            system("cls");
            int select;
            cout << "Enter 1 for signIN." << endl;
            cout << "Enter 2 for signUP." << endl;
            cout << "Enter 0 for exit." << endl;
            cin>>select;
            if(select == 1)
            {
                again:
                    system("cls");
                    customerPanelRead();
                    string usermail,password;
                    cout << "Enter your email address:" << endl;
                    cin >> usermail;
                    cout << "Enter your password:" << endl;
                    cin >> password;
                    for(int i = 0;i < c;i++)
                    {
                        if((customerList[i].userName == usermail) && (customerList[i].password == password))
                            return 1;
                    }
                    system("color 04");
                    cout << "Invalid email address or password.Try again" << endl;
                    goto again;
            }
            else if(select == 2)
            {
                start:
                    system("cls");
                    ///system("cls");
                    customerPanelRead();
                    string usermail,password;
                    cout << "Enter your email address:" << endl;
                    cin >> usermail;
                    cout << "Enter your password:" << endl;
                    cin >> password;
                    for(int i = 0;i < c;i++)
                    {
                        if(customerList[i].userName == usermail)
                        {
                            system("color 04");
                            cout << "This usermail already existed.Try with another one." << endl;
                            goto start;
                        }
                    }
                    ofstream addCustomer("customerPanel.txt",ios::app);
                    addCustomer<<endl<<usermail<<endl;
                    addCustomer<<password;
                    addCustomer.close();
                    system("color 02");
                    cout << "..SignUp Successfully Done.." << endl;
                    return 1;
            }
            else
                return 0;
        }


        int customerSelection()
        {
            system("cls");
            system("color 07");
            int select;
            cout<<"\t\t\t============================="<<endl;
            cout<<"\t\t\tWelcome to Resturant"<<endl;
            cout<<"\t\t\t============================="<<endl;
            cout<<endl;

            cout<<"1.To See all food enter 1."<<endl;
            cout<<"2.To Order food enter 2."<<endl;
            cout <<"3.To exit enter 0."<<endl;
            cin >> select;
            return select;
        }

        ///ordering food from the food menu file
        void orderFood()
        {
            string name;
            int quantity,select;
            cout << "How many food do you want to order?";
            cin >> select;
            for(int i = 1;i <= select;i++)
            {
                int available;
                cout << "Enter the " << i << " food name that you want to order:";
                cin >> name;
                again:
                    system("color 07");
                    cout << "Enter the quantity:";
                    cin >> quantity;
                    available = quantityChecking(name,quantity);
                    if(available)
                    {
                        vc.push_back({name,quantity});
                        system("cls");
                    }
                    else
                    {
                        system("cls");
                        string check;
                        system("color 04");
                        cout << "Sorry!We do not have that much of quantity.Do you want to order less?" << endl;
                        cin >> check;
                        if(toupper(check[0])=='Y')
                        {
                            system("cls");
                            goto again;
                        }
                        else
                            return;
                    }
            }

            system("color 02");
            for(int i = 0;i < vc.size();i++)
            {
                cout << "\t\t\tYou ordered:" << vc[i].first << endl;
                cout << "\t\t\tQuantity:" << vc[i].second << endl;
            }
            cout<<endl;
            cout<<"\t\t\t============================="<<endl;
            cout << "\t\t\tYour total bill is:" << amount << endl;
            cout<<"\t\t\t============================="<<endl;
        }
};


int main()
{
        system("cls");
        int check,found = 0;
        cout <<"\t\t\tDAKCIL RESTAURENT"<< endl;
        cout<<endl;

        cout << "To enter as a owner click 1:" << endl;
        cout << "To enter as a customer click 2:" << endl;
        cin >> check;
        if(check == 1)
        {
            owner object;
            object.ownerInfo();
            if(object.ownerChecking())
            {
                again:
                    found = object.ownerSelection();
                    if(found == 1)
                    {
                        system("cls");
                        object.addItems();
                    }
                    else if(found == 2)
                    {
                        system("cls");
                        object.editItems();
                    }
                    else if(found == 3)
                    {
                        system("cls");
                        object.deleteItem();
                    }
                    else if(found == 4)
                    {
                        system("cls");
                        object.addOwner();
                    }
                    else if(found == 5)
                    {
                        system("cls");
                        object.editOwner();
                    }
                    else if(found == 6)
                    {
                        system("cls");
                        object.deleteOwner();
                    }
                    else if(found == 7)
                    {
                        system("cls");
                        object.seeAllOwner();
                    }
                    else if(found == 8)
                    {
                        system("cls");
                        seeAllFood();
                    }
                    else if(found == 9)
                    {
                        system("cls");
                        return 0;
                    }
            }
            else
            {
                system("cls");
                system("color 04");
                cout << "You are not in our server.Contact with your authority." << endl;
                return 0;
            }
            cout<<"----------------------"<<endl;
            string s;
            cout << "Do you want to run it again?" << endl;
            cin >> s;
            if(toupper(s[0]) == 'Y')
                goto again;
            else
                return 0;
        }
        else if(check == 2)
        {
            customer object;
            int sel = object.customercheck();
            if(sel == 0)
                return 0;
            else
            {
                start:
                    int select;
                    select = object.customerSelection();
                    if(select == 1)
                    {
                        system("cls");
                        seeAllFood();
                    }
                    else if(select == 2)
                    {
                        system("cls");
                        object.orderFood();
                    }
                    else if(select == 0)
                        return 0;
                    cout<<"----------------------"<<endl;
                    string s;
                    cout << "Do you want to run it again?" << endl;
                    cin >> s;
                    if(toupper(s[0]) == 'Y')
                        goto start;
                    else
                        return 0;
            }
        }
    return 0;
}
