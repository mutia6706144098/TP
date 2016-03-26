#include "spell.h"

void MenuEditDistance();
void MenuTree();
int main();
tree t;

void MenuUtama(){
    int pil;
    system("cls");
    gotoxy(0,2);cout << "==============================================================================" << endl;
    gotoxy(28,5);cout << "-----------------------------" <<endl;
    gotoxy(28,6);cout << "**                         **" <<endl;
    gotoxy(28,7);cout << "**      SPELL CHECKER      **" <<endl;
    gotoxy(28,8);cout << "**                         **" <<endl;
    gotoxy(28,9);cout << "----------------------------" <<endl;
    gotoxy(28,11);cout << "[1] SPELL CHECK\n";
    gotoxy(28,12);cout << "[2] LIBRARY TREE\n";
    gotoxy(28,13);cout << "[3] VIEW LIBRARY\n";
    gotoxy(28,14);cout << "[0] EXIT\n";
    gotoxy(28,15);cout << "Masukan pilihan : "; cin >> pil;
    cout << endl;
    switch(pil){
        case 1 :
            MenuEditDistance();
            break;
        case 2:
            char pass[10];
            system("cls");
            gotoxy(0,2);cout << "==============================================================================" << endl;
            gotoxy(28,5);cout << "-----------------------------" <<endl;
            gotoxy(28,6);cout << "**                         **" <<endl;
            gotoxy(28,7);cout << "**      SPELL CHECKER      **" <<endl;
            gotoxy(28,8);cout << "**                         **" <<endl;
            gotoxy(28,9);cout << "----------------------------" <<endl;
            gotoxy(28,11);cout <<"Masukan Password: "; cin >> pass;
            if(strcmp(pass,"a")==0){
                MenuTree();
            }
            else{
                gotoxy(28,13);cout << "PASSWORD SALAH ! ";
            }
            break;
        case 3:
            system("cls");
            gotoxy(0,2);cout << "==============================================================================" << endl;
            gotoxy(28,5);cout << "-----------------------------" <<endl;
            gotoxy(28,6);cout << "**                         **" <<endl;
            gotoxy(28,7);cout << "**      SPELL CHECKER      **" <<endl;
            gotoxy(28,8);cout << "**                         **" <<endl;
            gotoxy(28,9);cout << "----------------------------" <<endl;
            gotoxy(28,11);preorder(root(t));
            getch();
            MenuUtama();
            break;
        case 0:
            exit(0);
            break;
        default:
                gotoxy(28,19);cout << "MENU TIDAK TERSEDIA !";
                gotoxy(28,20);cout << endl;
                getch();
                MenuUtama();
                break;
    }
}

void MenuEditDistance(){
    system("cls");
    char a[40]; int i;
    gotoxy(0,2);cout << "==============================================================================" << endl;
    gotoxy(28,5);cout << "-----------------------------" <<endl;
    gotoxy(28,6);cout << "**                         **" <<endl;
    gotoxy(28,7);cout << "**      SPELL CHECKER      **" <<endl;
    gotoxy(28,8);cout << "**                         **" <<endl;
    gotoxy(28,9);cout << "----------------------------" <<endl;
    gotoxy(28,11);cout << "Masukan Kata : \n";
    gotoxy(28,12);cin>>a;
    gotoxy(28,14);cout<<"Kata yang relevan : \n";
    gotoxy(28,15);i = cekPakeEditDistance(root(t),a);
    if(i==0){
        gotoxy(28,16);cout<<"TIDAK ADA DALAM DAFTAR!!";
    }
    getch();
    MenuUtama();

}

void MenuTree(){
        int pil;
        char a[40];
        system("cls");
        gotoxy(0,2);cout << "==============================================================================" << endl;
        gotoxy(28,5);cout << "-----------------------------" <<endl;
        gotoxy(28,6);cout << "**                         **" <<endl;
        gotoxy(28,7);cout << "**      SPELL CHECKER      **" <<endl;
        gotoxy(28,8);cout << "**                         **" <<endl;
        gotoxy(28,9);cout << "----------------------------" <<endl;
        gotoxy(28,11);cout << "[1] INSERT STRING\n";
        gotoxy(28,12);cout << "[2] PREORDER\n";
        gotoxy(28,13);cout << "[3] INORDER\n";
        gotoxy(28,14);cout << "[4] POSTORDER\n";
        gotoxy(28,15);cout << "[5] DELETE \n";
        gotoxy(28,16);cout << "[0] BACK\n";
        gotoxy(28,17);cout << "Masukan pilihan : "; cin >> pil;
        cout << endl;
        switch(pil){
        case 1: system("cls");
                gotoxy(0,2);cout << "==============================================================================" << endl;
                gotoxy(28,5);cout << "-----------------------------" <<endl;
                gotoxy(28,6);cout << "**                         **" <<endl;
                gotoxy(28,7);cout << "**      SPELL CHECKER      **" <<endl;
                gotoxy(28,8);cout << "**                         **" <<endl;
                gotoxy(28,9);cout << "----------------------------" <<endl;
                gotoxy(28,11);cout << "Masukan kata :";
                gotoxy(28,12);cin >> a;
                 if (cek(root(t),a)==false){
                        if(Insert(&(root(t)),a)){
                            inputToFile(a);
                        }
                 }else{
                    gotoxy(35,14);cout<<"KATA SUDAH ADA !";
                 }
                getch();
                MenuTree();
                break;
            case 2:
                system("cls");
                gotoxy(0,2);cout << "==============================================================================" << endl;
                gotoxy(28,5);cout << "-----------------------------" <<endl;
                gotoxy(28,6);cout << "**                         **" <<endl;
                gotoxy(28,7);cout << "**      SPELL CHECKER      **" <<endl;
                gotoxy(28,8);cout << "**        PREORDER         **" <<endl;
                gotoxy(28,9);cout << "----------------------------" <<endl;
                if(isEmpty(root(t))){
                    gotoxy(28,11);cout<<"MASIH KOSONG";
                }
                else{
                    gotoxy(0,11);preorder(root(t));
                }
                getch();
                MenuTree();
                break;
            case 3:
                system("cls");
                gotoxy(0,2);cout << "==============================================================================" << endl;
                gotoxy(28,5);cout << "-----------------------------" <<endl;
                gotoxy(28,6);cout << "**                         **" <<endl;
                gotoxy(28,7);cout << "**      SPELL CHECKER      **" <<endl;
                gotoxy(28,8);cout << "**         INORDER         **" <<endl;
                gotoxy(28,9);cout << "----------------------------" <<endl;
                if(isEmpty(root(t))){
                    gotoxy(28,11);cout<<"MASIH KOSONG";
                }
                else{
                    gotoxy(0,11);inorder(root(t));
                }
                getch();
                MenuTree();
                break;
            case 4:
                system("cls");
                gotoxy(0,2);cout << "==============================================================================" << endl;
                gotoxy(28,5);cout << "-----------------------------" <<endl;
                gotoxy(28,6);cout << "**                         **" <<endl;
                gotoxy(28,7);cout << "**      SPELL CHECKER      **" <<endl;
                gotoxy(28,8);cout << "**        POSTORDER        **" <<endl;
                gotoxy(28,9);cout << "----------------------------" <<endl;
                if(isEmpty(root(t))){
                    gotoxy(28,11);cout<<"MASIH KOSONG";
                }
                else{
                    gotoxy(0,11);postorder(root(t));
                }
                getch();
                MenuTree();
                break;
            case 5:
                    system("cls");
                    gotoxy(0,2);cout << "==============================================================================" << endl;
                    gotoxy(28,5);cout << "-----------------------------" <<endl;
                    gotoxy(28,6);cout << "**                         **" <<endl;
                    gotoxy(28,7);cout << "**      SPELL CHECKER      **" <<endl;
                    gotoxy(28,8);cout << "**                         **" <<endl;
                    gotoxy(28,9);cout << "----------------------------" <<endl;
                    gotoxy(28,11);cout << "Masukan kata :"; cin >> a;
                    if(cek(root(t),a)){
                        gotoxy(28,12);deleteElem(&(root(t)), a);
                    }
                    getch();
                    MenuTree();
                    break;
            case 0:
                MenuUtama();
                break;
            default :
                gotoxy(28,19);cout << "MENU TIDAK TERSEDIA !";
                gotoxy(28,20);cout << endl;
                getch();
                MenuTree();
                break;
        }
}

int main()
{
    CreateTree(&t);
    refresh(&(root(t)));
    MenuUtama();
}
