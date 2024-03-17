#include<iostream>
#include<math.h>
#include <stack>
#include<cmath>
#include <string.h>

using namespace std;

bool isOperator(char c){// Hàm `isOperator(char c)` dùng d? ki?m tra xem m?t ký t? có ph?i là m?t toán t? hay không.
    if(c=='+'|| c=='-'||c=='*'||c=='/'||c == '^'){
        return true;
    }
    else{
        return false;
    }
}

int Priority(char c){ // Hàm `priority(char c)` dùng d? xác d?nh d? uu tiên c?a toán t?:
    if(c=='^')// N?u toán t? là `^` thì tr? v? 5.
        return 5;
    else if(c=='*' || c=='/')// N?u toán t? là `*` ho?c `/` thì tr? v? 4.
        return 4; 
    else if(c=='+' || c=='-')// N?u toán t? là `+` ho?c `-` thì tr? v? 3.
        return 3;
    else
        return 2;// Ngu?c l?i, tr? v? 2.
}

string TrungToSangHauTo(string st){ // Hàm `TrungToSangHauTo(string st)` dùng d? chuy?n bi?u th?c trung t? sang bi?u th?c h?u t?.
    stack<char> s;// Ð?u tiên, khai báo m?t stack `s` và m?t chu?i `res` d? luu k?t qu?.
    string res= "";

    for(int i=0;i<st.length();i++){// Duy?t t?ng ký t? trong chu?i trung t? `st`.
        char c = st[i];
        if(isdigit(c) || c == '.' || c == ' '){// N?u ký t? dó là m?t ch? s? ho?c d?u ch?m ho?c kho?ng tr?ng, thêm nó vào chu?i h?u t? `res`.
            res += c;
        }
        else if(c=='('){// N?u ký t? dó là m?t d?u m? ngo?c `(`, thêm nó vào stack `s`.
            s.push(c);
        }
        else if(c==')'){// N?u ký t? dó là m?t d?u dóng ngo?c `)`. 
            while(!s.empty() && s.top()!='('){
                res+=s.top(); // l?y ph?n t? trên d?nh c?a `s` và thêm nó vào chu?i `postfix`, l?p l?i cho d?n khi g?p ph?i d?u m? ngo?c `(`
                s.pop();
            }
            if(!s.empty() && s.top() =='('){
                s.pop();//  Sau dó lo?i b? d?u ngo?c`(` t? stack `s`.
            }
        }
        else if(isOperator(c)){// N?u ký t? dó là m?t toán t?, x? lý nhu sau:
            res += ' ';// Thêm m?t kho?ng tr?ng vào chu?i `res`.
            while(!s.empty() && Priority(c) <= Priority(s.top())){// L?y ph?n t? trên d?nh c?a `s`. N?u d? uu tiên c?a toán t? trên d?nh `s` l?n hon ho?c b?ng d? uu tiên c?a toán t? hi?n t?i. Cu?i cùng thêm toán t? hi?n t?i vào `s`.
                res+= s.top();//  thì l?y ph?n t? dó ra kh?i `s` và thêm vào chu?i `res`, l?p l?i quá trình trên cho d?n khi `s` r?ng ho?c d? uu tiên c?a toán t? trên d?nh `s` nh? hon d? uu tiên c?a toán t? hi?n t?i.
                res += ' ';
                s.pop();
            }
            s.push(c);// Cu?i cùng thêm toán t? hi?n t?i vào `s`.
        }
// L?p l?i quá trình cho d?n khi duy?t h?t chu?i trung t? `st`.
    }

    while (!s.empty()) {
        res += ' ';// Thêm m?t kho?ng tr?ng vào chu?i `res`.
        res += s.top();// L?y h?t các ph?n t? còn l?i trong `s` ra và thêm vào chu?i `res`.
        s.pop();
    }

    return res;// Tr? v? chu?i h?u t? `res`.
}

double TinhGiaTriHauTo(string res){// Hàm `TinhGiaTriHauTo(string postfix)` dùng d? tính giá tr? c?a bi?u th?c h?u t?.
    stack<double> s;// Ð?u tiên, khai báo m?t stack `s`.

    for(int i=0;i<res.length();i++){// Duy?t t?ng ký t? trong chu?i h?u t? `res`.
        char c = res[i];
        if(isdigit(c) || c == '.' || c == ' '){// N?u ký t? dó là m?t ch? s? ho?c d?u ch?m ho?c kho?ng tr?ng, dua nó vào stack `s`.
            if (c == ' ') // N?u ký t? là kho?ng tr?ng, b? qua.
                continue;
            double num = 0;// Kh?i t?o bi?n `num` d? luu giá tr? c?a s?.
            double decimal = 10;// Kh?i t?o bi?n `decimal` d? tính toán ph?n th?p phân c?a s?.
            bool isDecimal = false;// Bi?n `isDecimal` dùng d? xác d?nh xem có ph?i là s? th?p phân hay không.

            while (isdigit(c) || c == '.') {// L?p l?i cho d?n khi k?t thúc s?.
                if (c == '.') {// N?u là d?u ch?m thì xác d?nh dó là s? th?p phân.
                    isDecimal = true;
                }
                else if (!isDecimal) {// N?u chua t?i ph?n th?p phân c?a s?.
                    num = num * 10 + (c - '0');// Nhân `num` v?i 10 và c?ng v?i ch? s? dang xét.
                }
                else {// N?u dang ? ph?n th?p phân c?a s?.
                    num = num + (c - '0') / decimal;// Chia `c - '0'` cho `decimal` r?i c?ng vào `num`.
                    decimal *= 10;// Tang `decimal` lên 10 l?n d? x? lý ch? s? ti?p theo.
                }
                i++;// Ti?p t?c d?c ký t? ti?p theo trong chu?i h?u t?.
                c = res[i];
            }
            i--;// Tr? l?i ký t? cu?i cùng c?a s? vào chu?i.

            s.push(num);// Ðua giá tr? c?a s? vào stack `s`.
        }
        else if(isOperator(c)){// N?u ký t? dó là m?t toán t?, l?y hai ph?n t? trên d?nh c?a stack `s`, th?c hi?n phép toán tuong ?ng và dua k?t qu? vào stack `s`.
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
    // L?p l?i quá trình cho d?n khi duy?t h?t chu?i h?u t? `res`.
    }
    //L?y ph?n t? cu?i cùng trên d?nh c?a `s` là k?t qu? c?a bi?u th?c h?u t?.
    return s.top();// Tr? v? k?t qu?.
}

int main(){
    string bt;
    cout<<"Nhap bieu thuc can tinh: ";
    getline(cin, bt);
    string res = TrungToSangHauTo(bt);// S? d?ng hàm `TrungToSangHauTo()` d? chuy?n bi?u th?c trung t? sang bi?u th?c h?u t?.
    cout << "Bieu thuc hau to: " << res << endl;
    double kq = TinhGiaTriHauTo(res);// S? d?ng hàm `TinhGiaTriHauTo()` d? tính giá tr? c?a bi?u th?c h?u t?.
    cout<<bt<<"= "<<kq;// Xu?t k?t qu? ra màn hình.

    return 0;
}
