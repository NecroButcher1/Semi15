#include "List1.h"
void menu();
int main()
{
    srand(time(NULL));
    List1<int> k;
    int chm=0,len,elem;
    while(chm!=6){
        menu();
        cin>>chm;
        while((chm<1)||(chm>6)||(!cin)){
            system("cls");
            cin.clear();
            cin.ignore(32767,'\n');
            menu();
            cin>>chm;
        }
        if(chm==1){
            system("cls");
            k.make_empty();
            cout<<"Lenght : ";
            cin>>len;
            for(unsigned i=0;i<len;i++){
                system("cls");
                cout<<"Elem["<<i<<"]"<<" :";
                cin>>elem;
                while(!cin){
                    system("cls");
                    cin.ignore(32767,'\n');
                    cin.clear();
                    cout<<"Elem["<<i<<"]"<<" :";
                    cin>>elem;
                }
                k.Insert(elem);
            }
            chm=0;
        }
        if(chm==2){
            system("cls");
            k.make_empty();
            cout<<"Lenght : ";
            cin>>len;
            for(unsigned i=0;i<len;i++){
                elem=rand()%200-100;
                k.Insert(elem);
            }
            chm=0;
        }
        if(chm==3){
            system("cls");
            k.err_clear();
            k.move_beg();
            cout<<"[";
            if(k.get_err()==EMPTY_OBJ)cout<<"EMPTY";
            else{
                while((k.get_err()!=END)&&(k.get_err()!=EMPTY_OBJ)){
                    k.Extract(elem);
                    cout<<elem<<" ";
                }
            }
            cout<<"]";
            cout<<endl;
            chm=0;
            k.make_empty();
        }
        if(chm==4){
            system("cls");
            k.err_clear();
            k.move_beg();
            cout<<"[";
            if(k.get_err()==EMPTY_OBJ)cout<<"EMPTY";
            else{
                 while((k.get_err()!=END)&&(k.get_err()!=EMPTY_OBJ)){
                    k.get(elem);
                    cout<<elem<<" ";
                    k.move_forward();
                }
            }
            cout<<"]";
            cout<<endl;
            k.err_clear();
            chm=0;
        }
    }
    return 0;
}
void menu(){
    cout<<"+======================+============================+"<<endl;
    cout<<"|[1] Fill List         |     [2] Fill random number |"<<endl;
    cout<<"|[3] See and delete    |     [4] See                |"<<endl;
    cout<<"|[5] Sort              |     [6] Exit               |"<<endl;
    cout<<"+======================+============================+"<<endl;
    cout<<">>";
}
