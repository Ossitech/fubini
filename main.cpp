#include <iostream>
#include <map>
#include <stdlib.h>

/*
Dieser Header bietet eine Integerimplementierung, welche unendlich wachsen kann, um größere Zahlen darzustellen.
*/
#include "InfInt.h"

/*
Die eigentliche Fubinifunktion
*/
InfInt orderings(int n, InfInt** f){
    f[1][0] = 1;
    int factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = 1;
        factorial *= i;
        f[i][i - 1] = factorial;
        for (int k = 1; k < n; k++)
        {
            InfInt tmp = (k + 1);
            f[i][k] = tmp * (f[i - 1][k - 1] + f[i - 1][k]);
        }
    }
    InfInt answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer += f[n][i];
    }
    return answer;
}

int main(int argc, char** argv){

    //Standardmäßig wird für n 0 gewählt.
    int n = 100;

    //Übergabeparameter verwenden
    if(argc > 1) n = std::atoi(argv[1]);

    //Array enthält Zwischen- und Endergebnisse

    InfInt** f = new InfInt*[n+1];
    for (int i = 0; i < n+1; i++)
    {
        f[i] = new InfInt[n];
        for (int j = 0; j < n; j++)
            f[i][j] = 0;
    }

    //Berechnung starten
    InfInt answer = orderings(n, f);

    std::cout << "[";

    for(int i = 0; i < n; i++){
            InfInt tmp = 0;
            for(int j = 0; j < i; j++){
                tmp += f[i][j];
            }
            if(tmp == 0) tmp = 1;
            std::cout << tmp << ", ";
    }

    std::cout << answer << "]" << std::endl;

    for(int i = 0; i < n + 1; i++){
        delete[] f[i];
    }

    return 0;
}
