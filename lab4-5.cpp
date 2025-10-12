#include <iostream> 
class mc{
    private:
        int architecture;
        int Frequency;
        int ports;
    public:
    mc(){
        architecture = 8;
        Frequency = 16;
        ports = 23;
    }
    void input(){
        std::cout <<"Enter architecture";
        std::cin >>architecture;
        while (architecture< 0 ){
            std::cout << " Invalid , enter again " << '\n';
            std::cin >> architecture ;
        }

        std::cout <<"Enter Frequancy";
        std::cin >>Frequency;
        while (Frequency< 0 ){
            std::cout << " Invalid , enter again " << '\n';
            std::cin >> Frequency ;
        }

        std::cout <<"Enter ports";
        std::cin >>ports;
        while (ports< 0 ){
            std::cout << " Invalid , enter again " << '\n';
            std::cin >> ports ;
        }
    }  
    void show(){
        std::cout << " Type :" << architecture << '\n' ;
        std::cout << " coefficient " << Frequency << '\n' ; 
        std::cout << " Max current " << ports << '\n' ;
    }




};

int main() {

    mc mc1;
    mc1.input();
    mc1.show();

  

  return 0;
}