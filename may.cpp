#include<iostream>
#include<math.h>
#include <stack>
#include<cmath>
#include <string.h>

using namespace std;

bool isOperator(char c){// H�m `isOperator(char c)` d�ng d? ki?m tra xem m?t k� t? c� ph?i l� m?t to�n t? hay kh�ng.
    if(c=='+'|| c=='-'||c=='*'||c=='/'||c == '^'){
        return true;
    }
    else{
        return false;
    }
}

int Priority(char c){ // H�m `priority(char c)` d�ng d? x�c d?nh d? uu ti�n c?a to�n t?:
    if(c=='^')// N?u to�n t? l� `^` th� tr? v? 5.
        return 5;
    else if(c=='*' || c=='/')// N?u to�n t? l� `*` ho?c `/` th� tr? v? 4.
        return 4; 
    else if(c=='+' || c=='-')// N?u to�n t? l� `+` ho?c `-` th� tr? v? 3.
        return 3;
    else
        return 2;// Ngu?c l?i, tr? v? 2.
}

string TrungToSangHauTo(string st){ // H�m `TrungToSangHauTo(string st)` d�ng d? chuy?n bi?u th?c trung t? sang bi?u th?c h?u t?.
    stack<char> s;// �?u ti�n, khai b�o m?t stack `s` v� m?t chu?i `res` d? luu k?t qu?.
    string res= "";

    for(int i=0;i<st.length();i++){// Duy?t t?ng k� t? trong chu?i trung t? `st`.
        char c = st[i];
        if(isdigit(c) || c == '.' || c == ' '){// N?u k� t? d� l� m?t ch? s? ho?c d?u ch?m ho?c kho?ng tr?ng, th�m n� v�o chu?i h?u t? `res`.
            res += c;
        }
        else if(c=='('){// N?u k� t? d� l� m?t d?u m? ngo?c `(`, th�m n� v�o stack `s`.
            s.push(c);
        }
        else if(c==')'){// N?u k� t? d� l� m?t d?u d�ng ngo?c `)`. 
            while(!s.empty() && s.top()!='('){
                res+=s.top(); // l?y ph?n t? tr�n d?nh c?a `s` v� th�m n� v�o chu?i `postfix`, l?p l?i cho d?n khi g?p ph?i d?u m? ngo?c `(`
                s.pop();
            }
            if(!s.empty() && s.top() =='('){
                s.pop();//  Sau d� lo?i b? d?u ngo?c`(` t? stack `s`.
            }
        }
        else if(isOperator(c)){// N?u k� t? d� l� m?t to�n t?, x? l� nhu sau:
            res += ' ';// Th�m m?t kho?ng tr?ng v�o chu?i `res`.
            while(!s.empty() && Priority(c) <= Priority(s.top())){// L?y ph?n t? tr�n d?nh c?a `s`. N?u d? uu ti�n c?a to�n t? tr�n d?nh `s` l?n hon ho?c b?ng d? uu ti�n c?a to�n t? hi?n t?i. Cu?i c�ng th�m to�n t? hi?n t?i v�o `s`.
                res+= s.top();//  th� l?y ph?n t? d� ra kh?i `s` v� th�m v�o chu?i `res`, l?p l?i qu� tr�nh tr�n cho d?n khi `s` r?ng ho?c d? uu ti�n c?a to�n t? tr�n d?nh `s` nh? hon d? uu ti�n c?a to�n t? hi?n t?i.
                res += ' ';
                s.pop();
            }
            s.push(c);// Cu?i c�ng th�m to�n t? hi?n t?i v�o `s`.
        }
// L?p l?i qu� tr�nh cho d?n khi duy?t h?t chu?i trung t? `st`.
    }

    while (!s.empty()) {
        res += ' ';// Th�m m?t kho?ng tr?ng v�o chu?i `res`.
        res += s.top();// L?y h?t c�c ph?n t? c�n l?i trong `s` ra v� th�m v�o chu?i `res`.
        s.pop();
    }

    return res;// Tr? v? chu?i h?u t? `res`.
}

double TinhGiaTriHauTo(string res){// H�m `TinhGiaTriHauTo(string postfix)` d�ng d? t�nh gi� tr? c?a bi?u th?c h?u t?.
    stack<double> s;// �?u ti�n, khai b�o m?t stack `s`.

    for(int i=0;i<res.length();i++){// Duy?t t?ng k� t? trong chu?i h?u t? `res`.
        char c = res[i];
        if(isdigit(c) || c == '.' || c == ' '){// N?u k� t? d� l� m?t ch? s? ho?c d?u ch?m ho?c kho?ng tr?ng, dua n� v�o stack `s`.
            if (c == ' ') // N?u k� t? l� kho?ng tr?ng, b? qua.
                continue;
            double num = 0;// Kh?i t?o bi?n `num` d? luu gi� tr? c?a s?.
            double decimal = 10;// Kh?i t?o bi?n `decimal` d? t�nh to�n ph?n th?p ph�n c?a s?.
            bool isDecimal = false;// Bi?n `isDecimal` d�ng d? x�c d?nh xem c� ph?i l� s? th?p ph�n hay kh�ng.

            while (isdigit(c) || c == '.') {// L?p l?i cho d?n khi k?t th�c s?.
                if (c == '.') {// N?u l� d?u ch?m th� x�c d?nh d� l� s? th?p ph�n.
                    isDecimal = true;
                }
                else if (!isDecimal) {// N?u chua t?i ph?n th?p ph�n c?a s?.
                    num = num * 10 + (c - '0');// Nh�n `num` v?i 10 v� c?ng v?i ch? s? dang x�t.
                }
                else {// N?u dang ? ph?n th?p ph�n c?a s?.
                    num = num + (c - '0') / decimal;// Chia `c - '0'` cho `decimal` r?i c?ng v�o `num`.
                    decimal *= 10;// Tang `decimal` l�n 10 l?n d? x? l� ch? s? ti?p theo.
                }
                i++;// Ti?p t?c d?c k� t? ti?p theo trong chu?i h?u t?.
                c = res[i];
            }
            i--;// Tr? l?i k� t? cu?i c�ng c?a s? v�o chu?i.

            s.push(num);// �ua gi� tr? c?a s? v�o stack `s`.
        }
        else if(isOperator(c)){// N?u k� t? d� l� m?t to�n t?, l?y hai ph?n t? tr�n d?nh c?a stack `s`, th?c hi?n ph�p to�n tuong ?ng v� dua k?t qu? v�o stack `s`.
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();

            switch (c) {
                case '+':
                    s.push(b + a);
                    break;
                case '-':
                    s.push(b - a);
                    break;
                case '*':
                    s.push(b * a);
                    break;
                case '/':
if (a == 0) {
                        cout << "Error: Divide by zero" << endl;
                        return 0;
                    }  
                    s.push(b / a);
                    break;
                case '^':
                    s.push(pow(b,a));
                    break;
            }
        }
    // L?p l?i qu� tr�nh cho d?n khi duy?t h?t chu?i h?u t? `res`.
    }
    //L?y ph?n t? cu?i c�ng tr�n d?nh c?a `s` l� k?t qu? c?a bi?u th?c h?u t?.
    return s.top();// Tr? v? k?t qu?.
}

int main(){
    string bt;
    cout<<"Nhap bieu thuc can tinh: ";
    getline(cin, bt);
    string res = TrungToSangHauTo(bt);// S? d?ng h�m `TrungToSangHauTo()` d? chuy?n bi?u th?c trung t? sang bi?u th?c h?u t?.
    cout << "Bieu thuc hau to: " << res << endl;
    double kq = TinhGiaTriHauTo(res);// S? d?ng h�m `TinhGiaTriHauTo()` d? t�nh gi� tr? c?a bi?u th?c h?u t?.
    cout<<bt<<"= "<<kq;// Xu?t k?t qu? ra m�n h�nh.

    return 0;
}
