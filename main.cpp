#include "ListaSequencialDupla.h"
#include <iostream>

using namespace std;

int main(){
    DoubleVector db(3);
    DoubleVector pd;

    cout << "testa o push_back" << endl;
    db.push_back(1);
    db.push_back(2);
    db.push_back(3);
    db.push_back(4);
    db.push_back(5);
    db.push_back(6);
    db.push_back(7);
    db.push_back(8);
    db.push_back(9);
    db.push_back(10);
    db.push_back(11);
    db.push_back(12);
    db.push_back(13);
    db.push_back(14);

    cout << "esperado: 1 2 3 4 5 6 7 8 9 10 11 12 13 14" << endl;
    cout << "Recebido: "; db.print();

    cout << "testa o pop_back" << endl;
    cout << "esperado: 14 13 12 removidos" << endl;
    cout << "saida: "; for (int i = 1; i <= 3; i++) cout << db.pop_back() << " "; cout << "removidos" << endl;

    cout << "testa o pop_front" << endl;
    db.push_front(100);
    db.push_front(99);
    db.push_front(98);
    db.push_front(97);
    db.push_front(96);
    db.push_front(95);
    db.push_front(94);
    db.push_front(93);
    db.push_front(92);
    db.push_front(91);
    db.push_front(90);
    db.push_front(89);
    db.push_front(88);
    db.push_front(87);

    cout << "esperado: 87 88 89 90 91 92 93 94 95 96 97 98 99 100 1 2 3 4 5 6 7 8 9 10 11" << endl;
    cout << "saida: "; db.print();

    cout << "testa o pop_front" << endl;
    cout << "esperado: 87 88 89 90 91 removidos" << endl;
    cout << "saida: "; for (int i = 1; i <= 5; i++) cout << db.pop_front() << " "; cout << "removidos" << endl;

    cout << "testa o remove" << endl;
    cout << "esperado:  92 1 2 3 4 5 6 7 8 9 10 11" << endl;
    // for (int i = 3; i <= 5; i++){
    //     db.remove(i);
    // }
    db.remove(1);
    db.remove(1);
    db.remove(1);
    db.remove(1);
    db.remove(1);
    db.remove(1);
    db.remove(1);
    db.remove(1);
    cout << "saida: "; db.print();

    cout << "testa o removeAll" << endl;

    db.push_back(10);
    db.push_back(11);
    db.push_back(12);
    db.push_back(13);
    db.push_back(10);
    db.push_back(14);
    db.push_back(15);
    db.push_back(10);

    cout << "esperado:  92 1 2 3 4 5 6 7 8 9 11 11 12 13 14 15" << endl;
    db.removeAll(10);  
    cout << "saida: "; db.print();

    cout << "testa o concat" << endl;
    pd.concat(db);
    db.concat(pd);
    cout << "esperado:  92 1 2 3 4 5 6 7 8 9 11 11 12 13 14 15 92 1 2 3 4 5 6 7 8 9 11 11 12 13 14 15" << endl;
    cout << "saida : "; db.print();

    cout << "testa size" << endl;
    cout << "esperado: 32" << endl;
    cout << "recebido: " << db.size() << endl;
    


    DoubleVector cn;
    cn.concat(db);
    cout << "testa o equal" << endl;
    cout << "esperado: 1" << endl;
    cout  << "recebido: " << db.equal(cn) << endl;
    cout << "esperado: 0" << endl;
    cout  << "recebido: " << db.equal(pd) << endl;

    cn.push_front(100);
    cn.print();

    //apenas checando m_tail e m_head e resize
    DoubleVector ch(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);
    ch.push_front(2);

    ch.removeAll(2);

    ch.print();
    cout << ch.size() << endl;         






    // db.remove(0);
    // db.pop_back();
    // db.pop_back();
    // db.pop_back();
    // cout << "printa o vetor" << endl;
    // db.printVet();
    // db.push_front(4);
    // db.push_front(4);
    // db.push_front(4);
    // db.push_front(4);
    // db.push_front(5);
    // db.push_front(6);
    // // db.push_back(4);

    // // db.push_back(4);
    // // db.push_back(4);
    // // db.push_back(5);
    // // db.push_back(5);
    // // db.push_back(6);
    // // db.push_back(7);
    // cout << "printa o vetor" << endl;
    // db.printVet();
    // cout << "printa o vetor" << endl;
    // db.printVet();
  
    

    // cout << "printa o vetor" << endl;
    // db.pop_front();
    // db.printVet();
    // db.print();
    

    // db.print();
    // cout << "testa o push_front" << endl;
    // db.push_front(10);
    // db.push_front(2);
    // db.push_front(2);
    // db.push_front(2);
    // db.push_front(9);
    // db.push_front(9);
    

    // db.printVet();
    // db.print();

    // pd.push_front(2);
    // pd.push_front(2);
    // pd.push_front(2);
    // pd.push_front(2);
    // pd.push_front(2);
    // pd.push_front(2);
    // pd.push_front(2);
    // db.print();
    // cout << "testa o equal:" << endl;
    // cout << db.equal(pd);
    // cout << endl;

    // cout << "testa a função concat" << endl;
    // db.concat(pd);
    // db.print();

    // cout << "testa a função removeAll" << endl;
    // db.removeAll(2);
    // db.print();

    // cout << "testa a função printVet" << endl;
    // db.printVet();


    // cout << "testa o pop_back" << endl;
    // for (int i = 0; i < 2; i++){
    //     cout << db.pop_back() << " ";
    // }
    // cout << endl;
    // cout << "testa o remove" << endl;
    // db.print();
    // db.remove(4);
    // db.print();

    // cout << "testa a função at(4): " << db.at(4) << endl;

    // cout << "testa o pop_front" << endl;
    // for (int i = 0; i < 2; i++){
    //     cout << db.pop_front() << " ";
    // }
    // cout << endl;
    // db.print();
}