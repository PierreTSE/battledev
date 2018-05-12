#include <iostream>
#include "dijkstra.hpp"
#include <sstream>
#include <iomanip>


std::istringstream get_input_example();

int main()
{
    /* 
     * Exemple, on a une map 2D avec du sol et des murs
     */
    
    char map[10][11] = 
        {
            "xxxxxxxxxx",
            "x   x    x",
            "x x x x  x",
            "x x   x  x",
            "xAxxxxx  x",
            "xxx      x",
            "x   xxxxxx",
            "x x x    x",
            "x x   x Bx",
            "xxxxxxxxxx"
        };
    
    // Ici les noeuds du problèmes sont les cases, on les représente par des pair<int,int>
    std::set<std::pair<int, int>> noeuds;
    
    
    std::pair<int, int> debut, fin;
    // Seuls les sols (et les positions de A et B) sont traversables
    for(size_t i = 0; i < 10; ++i)
        for(size_t j = 0; j < 10; ++j)
        {
            if(map[i][j] == 'A')
                debut.first = i, debut.second = j;
            if(map[i][j] == 'B')
                fin.first = i, fin.second = j;
            if(map[i][j] != 'x')
                noeuds.insert({i, j});
        }
    
    // On prépare les données pour l'algorithme avec des pair<int,int> comme type de
    // noeud et double comme type de distance
    Dijkstra_data<std::pair<int, int>, double> data;
    data.set(noeuds)
        .length_function([](std::pair<int,int> a, std::pair<int,int> b) // On fourni la fonction qui donne la distance entre deux noeuds
                        // Elle prend en paramètre deux variables du type spécifié comme noeuds et retourne le type spécifié comme distance
                         { if(a.first == b.first and abs(a.second - b.second) == 1
                             or a.second == b.second and abs(a.first - b.first) == 1)
                             // Dans notre cas, les cases adjacentes sont espacées de 1
                               return 1.0;
                           else
                             // Les autres sont inaccessibles directement
                               return std::numeric_limits<double>::infinity();})
        .near_value(0) // La valeur qui représente la proximité
        .far_value(std::numeric_limits<double>::infinity()) // La valeur qui représente l'éloignement
        .combinaison_op(std::plus<double>()) // La fonction pour avoir la distance entre deux noeuds à partir des distances entre un noeud A et un noeud B et entre le noeud B et un noeud C
        .shorter_than_op(std::less<double>()) // La fonction qui compare deux distance et dit la quelle est la meilleure
        .start_node(debut);
    
    // Quand on a toutes les données, on lance l'algorithme en lui fournissant les données
    Dijkstra_solver<std::pair<int, int>, double> solver(data);
    solver.solve();
    
    std::cout << "Distance entre A et B : " << solver.d(fin) << std::endl;
    
    int nb = 0;
    for(auto p : solver.path_to(fin))
        if(map[p.first][p.second] == ' ') // Pour pas effacer A et B
            map[p.first][p.second] = (++nb % 10) + '0';
    
    for(auto& s : map)
        std::cout << s << std::endl;
    
    std::cout << std::endl << std::endl;
    
    
    
    return 0;
}

