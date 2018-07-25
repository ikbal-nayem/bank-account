#include<iostream>
#include<string>
#include<array>

using namespace std;

class database
{
    array<string, 20>usr_name;
    array<int, 20>balance;
    array<int, 20>account_number;
public:
    int top=0;
    void add(string name, int ac_no, int blnc)
    {
        usr_name[top]=name;
        account_number[top]=ac_no;
        balance[top]=blnc;
        top++;
    }

    int info(string name, int ac_no)
    {
      int cnt=0;
      for(int i=0; i<top; i++)
      {
        if(name==usr_name[i] && ac_no==account_number[i])
            return i;
        else
            cnt++;
      }
      if(cnt==top)
        return -1;
    }
    string name(int i)
    {
        return usr_name[i];
    }
    int blnc(int i)
    {
        return balance[i];
    }
    int acnt(int i)
    {
        return account_number[i];
    }

    void update(int i, int m, int up)
    {
        if(up==1)
            balance[i]+=m;
        else
            {
                if(balance[i]<m)
                    cout<<"Your account has no sufficiant balance to withdraw."<<endl<<endl;
                else
                    balance[i]-=m;
            }
    }

    void del(int i)
    {
        for(int j=i+1; j<top; j++)
        {
            usr_name[j-1]=usr_name[j];
            account_number[j-1]=account_number[j];
            balance[j-1]=balance[j];
        }
        top--;
    }
};

class account : private database
{
public:
    void add_ac()
    {
        string n;
        cout<<"Name: ";
        cin>>n;
//        cin.getline(n, 20);
        int a, b;
        cout<<"Account number: "; cin>>a;
        cout<<"Initial balance: "; cin>>b;
        add(n, a, b);
        cout<<"Account is ready."<<endl<<endl;
    }

    int display()
    {
        string n;
        cout<<"Name: ";
//        getline(cin, n);
        cin>>n;
        cout<<"Account number: ";
        int a, r; cin>>a;
        r = info(n, a);
        if(r>=0)
        {
            cout<<endl<<"Account name: "<<name(r)<<endl
                <<"Account number: "<<acnt(r)<<endl
                <<"Account balance: "<<blnc(r)<<endl<<endl;
            return r;
        }
        else{
            cout<<"Account not found named "<<n<<"!"<<endl<<endl;
            return -1;
            }
    }
    void display_all()
    {
        cout<<endl<<"\t -----------------------------------------------------------------"<<endl;
        cout<<"Name\tAccount No.\tBalance"<<endl;
        for(int i=0; i<top; i++)
        {
            cout<<name(i)<<"\t"<<acnt(i)<<"\t\t"<<blnc(i)<<endl;
        }
        cout<<endl<<"\t -----------------------------------------------------------------"<<endl;
    }

    void del_ac()
    {
        int i = display();
        if(i>=0)
        {
            char a;
            cout<<"Do you really want to delete this account?(y/n): ";
            cin>>a;
            if(a=='y')
            {
                del(i);
                cout<<"account deleted complete."<<endl<<endl;
            }
        }
    }

    void deposit()
    {
        int i, m;
        i = display();
        cout<<"Diposit amount: "; cin>>m;
        update(i, m, 1);
        cout<<"Update complete.Your new account balance is "<<blnc(i)<<endl<<endl;
    }

    void withdraw()
    {
        int i, m;
        i = display();
        cout<<"Withdraw amount: "; cin>>m;
        update(i, m, 2);
    }
};

main()
{
    int in;
    account ac;
    while(true)
    {
        cout<<"1. Creat account"<<endl
            <<"2. Display balance"<<endl
            <<"3. Deposit balance"<<endl
            <<"4. Withdraw balance"<<endl
            <<"5. Delete account"<<endl
            <<"6. Display all"<<endl
            <<"7. Exit"<<endl
            <<"Choose an above option: "; cin>>in;
        if(in==7)
            break;
        else if(in>0 && in<7)
        {
            switch(in)
            {
                case 1: ac.add_ac();
                break;
                case 2: ac.display();
                break;
                case 3: ac.deposit();
                break;
                case 4: ac.withdraw();
                break;
                case 5: ac.del_ac();
                break;
                case 6: ac.display_all();
                break;
            }
        }
        else
            break;
    }
    return 0;
}
