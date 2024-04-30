/*
Aluno: PAULO MARCELO CABRAL ARAÚJO
Matrícula: 536813
*/
//=========================================================================================================================================================================================================================================================
    #include "ListaSequencialDupla.h"
    #include <iostream>

    using namespace std;

    DoubleVector::DoubleVector(){ //constroi a lista dando uma capacidade default
        m_capacity = 16;
        m_list = new int [m_capacity];
        m_size = 0;
        m_head = 7;            //m_head e m_tail já são inicializados no meio do vetor
        m_tail = 8;
    }

    DoubleVector::DoubleVector(int n){ //constroi a lista pegando a capacidade do usuário
        m_capacity = n;
        m_list = new int [m_capacity];
        m_head = (n-1)/2;         //calcula o meio da lista e joga pra m_head
        m_tail = m_head + 1;
        m_size = 0;
    }

    DoubleVector::~DoubleVector(){ //desaloca a memória da lista
        delete[] m_list;
    }

    int DoubleVector::size(){ //retorna o tamanho da lista
        return m_size;
    }

    bool DoubleVector::empty(){ //checa se a lista está vazia
        return m_size == 0;
    }

    int DoubleVector::at(int k){ //retorna o valor de uma posicao k, da lista
        if (k >= 0 && k < size()){
            int posicao = m_head+1+k; //converte para um indice válido da lista
            return m_list[posicao];
        }
        return -1;  //retorna -1, caso k não seja um indice válido para a lista
    }




    /*Exemplo que dá uma visão intuitiva de (int m_headAux = ((m_capacity*2)-1)/4) que está no método resize;
    *Usando um exemplo de um vetor de 16 posições preenchido:
    
    [1][2][3][4][5][6][7][8][9][10][11][12][13][14][15][16]

    Ele está preenchido, ok! preciso alocar mais memória, mas pensando em deixar os espaços vazios proporcionais (ou quase) para a direita e a esquerda
    da lista, posso fazer a seguinte marmota, pego o valor dobrado da capacidade-1 e divido por 4, o valor será dado so m_head, no caso se o tamanho era 16
    então devo fazer o dobro que é 32 menos 1 e divido por 2 ,ou seja, m_head = 31/4 = 7,..., arrendondando pra baixo fica 7, isso indica o indice onde o novo m_head vai estar.
    A partir desse ponto, posso ir adicionando todos os elementos de minha antiga lista para a nova e, ao mesmo tempo, conseguir o novo valor de m_tail

    mh = m_heaad e 
                          mh                                                         mt
    [ ][ ][ ][ ][ ][ ][ ][  ][1][2][3][4][5][6][7][8][9][10][11][12][13][14][15][16][  ][ ][ ][ ][ ][ ][ ][ ]

    *Como você pode ver, o número de espaços é proporcional. (testei várias vezes, e todos deram bom! )
    *Nem todos os espaços podem ser divididos de forma proporcional, e isso é péssimo.
    */



    void DoubleVector::resize(){
        int* NewList = new int[m_capacity*2]; //aloco memoria para uma nova lista com a 2* a capacidade da anterior
        int m_headAux = ((m_capacity*2)-1)/4; //com isso consigo meu novo m_head. Esse cálculo é útil, pois com ele eu posso repartir de maneira quase proporcional os elementos que serão vagos na minha lista para ambos os dois lados da lista
        int m_tailAux = m_headAux+1; //esse será meu futuro m_tail, uso ele para que, a partir da primeira posição da lista eu possa copiar todos os elemntos da antiga lista

        for (int i = m_head+1; i < m_tail; i++){
            NewList[m_tailAux++] = m_list[i]; //pego os elementos da lista antiga e copio para a nova a partir da minha nova posição
        }
        delete[] m_list;
        m_list = NewList;
        m_capacity *= 2;
        m_head = m_headAux;
        m_tail = m_tailAux;
    }

    /*Nota sobre os shifts: Para que não haja problemas, quando há apenas um espaço vazio (que pode se encontrar no comeco ou no final do vetor,
    Exemplo indice 0 ou indice m_capacity-1 como o último espaço vago, eu darei esse espaço para quem está necessitando), então é por isso que eu trato
    ambos os casos em left_shift e right_shift(), com isso, é possível que o vetor inteiro seja preenchido e resize seja acionado
     */

    void DoubleVector::left_shift(){
        if (m_head == 0){ //trata o caso em que m_head primeiro elemento do vetor, ou seja, quando m_head é o único indice vago e está na posição 0
            
            int * newList = new int[m_capacity]; //aloco memoria para uma nova lista com a mesma capacidade da anterior
            for (int i = 0; i < m_tail-1; i++){
                newList[i] = m_list[i+1]; //faço um shift a esquerda de todos os elementos, com isso, o meu espaço vazio agora estará nas mãos de _tail
            }
            delete[] m_list;
            m_list = newList;
            m_head--;
            m_tail = m_tail-1;
        }else{
            int m_headAux = m_head / 2; //m_head agora vai iniciar a partir do ponto dado pelo calculo, isso me garante uma proporcionalidade(ou quase) de espaços vazios no vetor
            int * newList = new int[m_capacity];
            int newTail = m_headAux+1; //meu novo m_tail, que será dado após o shift total a esquerda acontecer
            for (int i = m_head+1; i < m_tail; i++){
                newList[newTail++] = m_list[i]; //jogo todos os elementos para a esquerda
            }
            delete[] m_list;
            m_list = newList;
            m_head = m_headAux;
            m_tail = newTail;
        }
    }
    
    void DoubleVector::right_shift(){
        if (m_tail == m_capacity-1){ //trata o caso em que m_tail é o ultimo indice da lista, ou seja, o último indice vago da lista
            
            int * newList = new int[m_capacity]; //aloco memoria para uma nova lista com a mesma capacidade da anterior
            for (int i = m_tail; i > 0; i--){ 
                newList[i] = m_list[i-1]; //o objetivo aqui é sobrescrever a posição i com o elemento do inidice anterior i-1, isso se extende até o penultimo anterior
            }
            m_list = newList;
            m_head = 0;  //feito isso, o ultimo indice vago da lista agora é a primeira posição
            m_tail = m_capacity;
        }else{ // para os casos em que não é o último indice vago

            int m_tailAux = (m_tail + m_capacity-1)/2; //com isso obtenho meu novo m_tail, esse cálculo serve para eu repartir o espaço vago para a outra parte da lista que não tem espaço 
            if (m_tailAux == m_tail) m_tailAux++; //isso é para um caso partiicular em que m_tailAux seja == m_tail, isso acontece com o penúltimo elemento da lista, acredito que seja algum erro de lógica meu

            int *newList = new int[m_capacity];
            int newM_head = m_tailAux-1;        //isso será meu futuro m_head, uso ele como indice para sobrescrever os elementos e, no fim, consigo o valor real de m_head
            for (int i = m_tail-1; i > m_head; i--){
                newList[newM_head--] = m_list[i];   //faço um shift a direita copiando os cada um dos elementos para uma posição á frente
            }
            delete[] m_list;
            m_list = newList;
            m_head = newM_head;
            m_tail = m_tailAux;
        }
    }

    void DoubleVector::push_back(int value){
        if (m_size == m_capacity){ //se o vetor estiver cheio, redimensiona
            resize();
        }
        //veja bem, se eu sei que o vetor não está cheio, então preciso testar apenas a checagem abaixo
        if (m_tail == m_capacity){ //testa se não há espaços vagos na direita da lista, caso sim, peço um shift a esquerda
            left_shift();
        }
        m_list[m_tail++] = value; //adiciona o elemento onde m_tail aponta atualmente
        m_size++;
    }
    

    void DoubleVector::push_front(int value){
        if (m_size == m_capacity){
            resize(); //se o vetor estiver cheio, redimensiona
        }
        if (m_head < 0){
            right_shift(); //testa se não há espaços vagos na esquerda da lista, caso sim, peço um shift a direita
        }
        m_list[m_head--] = value; //adiciona o elemento onde m_head aponta atualmente
        m_size++;
    }

    int DoubleVector::pop_back(){
        if (empty()){return -1;} //se a lista estiver vazia, então retorno -1 para sinalizar um erro
        int removedValue = m_list[m_tail - 1];// pega o elemento que vai ser removido e guarda

        if (m_head+1 < (m_capacity-1)-(m_tail-1)){ //checa se o espaço livre a esquerda do vetor é menor que o da direita, caso sim, então farei um shift para beneficiar o espaço a esquerda
            int newHead = m_head+1; 
            for (int i = m_tail-1; i > newHead; i--){
                m_list[i] = m_list[i-1]; //o deslocamento
            }
            m_head = newHead;
            m_size--;
            return removedValue;
        }
        //else, se o espaço livre a esquerda do vetor for maior ou igual ao espaço livre da direita, então eu beneficio o espaço a direita, dando a ele mais uma posição livre
        m_tail--;
        m_size--;
        return removedValue;
    }

    int DoubleVector::pop_front(){
        if (empty()){return -1;} //se a lista estiver vazia, então retorno -1 para sinalizar um erro
        int removedValue = m_list[m_head+1]; // elemento a ser removido
        if (m_head+1 > (m_capacity-1)-(m_tail-1)){ //checa se espaço livre a esquerda é maior que o da direita, caso sim, então faço um shift para beneficiar o lado da direita com mais uma posição livre
            int newTail = m_tail-1;
            for (int i = m_head+1; i < newTail; i++){
                m_list[i] = m_list[i+1]; //o deslocamento
            }
            m_tail = newTail;
            m_size--;   
            return removedValue;
        }
        //else, se o espaço livre a esquerda do vetor for menor ou igual ao espaço livre da direita, então eu beneficio o lado da esquerda
        m_head++;
        m_size--;
        return removedValue;
    }

    void DoubleVector::remove(int k){
        // if (empty()){return;} //se a lista estiver vazia, então eu não faço nada
        int removedValue = m_list[m_head+1];
        if (at(k) != -1){ //checa se index é válido

            if (k == 0){pop_front(); return;} //caso k seja 0 eu uso o push_front
            
            else if (k == m_size-1){pop_back(); return;} //caso k seja igual ao ultimo indice da lista, entáo eu uso o pop_back
            
            if (m_head+1 < (m_capacity-1)-(m_tail-1)){ //checa se o espaço livre a esquerda do vetor é menor que o da direita, caso sim, então farei um shift para beneficiar o espaço a esquerda
                for (int i =  m_head+1+k; i > m_head + 1; i--){
                    m_list[i] = m_list[i-1]; //o deslocamento
                }
                m_head++;
                m_size--;
            }
            else if (m_head+1 >= (m_capacity-1)-m_tail){ // caso contrario, então eu beneficio a parte da direita
                for (int i = m_head+1+k; i < m_tail-1; i++){
                    m_list[i] = m_list[i+1]; //o deslocamento
                }
                m_size--;
                m_tail--;
            }
        }
    }

    void  DoubleVector::removeAll(int value){
        if(empty()){return;}
        for (int i = 0; i < size(); i++){ 
            if (at(i) == value){ //procura o elemento value percorrendo toda a lista
                remove(i); //chamo remove() passando o indice do elemento encontrado
                i--; //basicamente, quando temos sequencias do mesmo valor na lista, devemos ficar na mesma posicao até todos os elementos dessa sequencia serem na mesma posicao até todos dessa sequencia serem eliminados. Considere isso uma gambiarra :()
            }
        }   
    }

    void DoubleVector::print(){
        for (int i = 0; i < m_size; i++){ //printa os elementos do vetor na ordem da lista
            cout << at(i) << " ";
        }
        cout << endl;
    }

    void DoubleVector::printReverse(){  //irá imprimir os elementos em ordem reversa a da lista
        for (int i = size()-1; i >= 0; i--){ 
            cout << at(i) << " "; //at irá retornar o indice especificado
        }
        cout << endl;
    }

    void DoubleVector::concat(DoubleVector& lst){
        for (int i = 0; i < lst.size(); i++){
            push_back(lst.at(i));   //a concatenação reaproveita o push_back. Além disso, para pegar o valor de cada indice de lst, eu uso o método at
        }
    }

    bool DoubleVector::equal(DoubleVector& lst){    //compara duas listas
        if (m_size == lst.m_size){      //se elas tiverem o mesmo tamanho, faça
            for (int i = 0; i < m_size; i++){
                if (at(i) != lst.at(i)) return false;  //se encontrar um elemento diferente na posição especificada para as duas listas, retorna false
            }
            return true; //caso contrario, retorna true
        }
        return false; //retorna falso caso as duas listas não tenham o mesmo tamanho
    }