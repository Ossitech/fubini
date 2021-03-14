#include <iostream>
#include <map>
#include <stdlib.h>

/*
Dieser Header bietet eine Integerimplementierung, welche unendlich wachsen kann, um größere Zahlen darzustellen.
*/
#include "InfInt.h"

/*
Fakultätsfunktion
*/
InfInt fac(InfInt n){
    if (n == 0) return 1;
    return n * fac(n - 1);
}

/*
Funktion "n über k" oder Binomialkoeffizient
*/
InfInt over(InfInt n, InfInt k){
    return fac(n) / (fac(k) * fac(n - k));
}
/*
Enthält am Ende die Ergebnisse
*/
std::map<int, InfInt> m;

/*
Die eigentliche Fubinifunktion
*/
InfInt f(int n){
    if (n == 0){
            m[n] = 1;
            return 1;
    }

    //Erst schauen ob wir das schomal berechnet haben
    if (m[n] != 0) return m[n];

    InfInt s = 0;
    for(int k = 1; k <= n; k++){
        s += over(n, k) * f(n - k);
    }
    m[n] = s;
    return s;
}

int main(int argc, char** argv){
    //Standardmäßig wird für n 0 gewählt.
    int n = 0;

    //Übergabeparameter verwenden
    if(argc > 1) n = std::atoi(argv[1]);

    f(n);

    //Ausgabe der Liste

    std::map<int, InfInt>::iterator it;
    int i = 0;

    std::cout << "[";

    for(it = m.begin(); it != m.end(); it++){
        if(i != 0) std::cout << ", ";

        std::cout << it->second;

        i++;
    }

    std::cout << "]" << std::endl;

    return 0;
}
