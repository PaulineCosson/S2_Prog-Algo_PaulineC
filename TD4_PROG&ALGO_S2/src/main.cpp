#include <print>
#include <random>

#include "utils.hpp"

int main()
{
    //Exercice 1 : 
    //1/
    std::random_device rd {}; // Objet permettant de générer une graine aléatoire (similaire à srand(time(nullptr)))
    std::mt19937 gen(rd()); // Générateur de nombres pseudo-aléatoires Mersenne Twister (un des générateurs les plus performants)
    std::uniform_int_distribution<> dis(0, 100); // Distribution uniforme entre 0 et 100

    int random_number { dis(gen) }; // Génération d'un nombre aléatoire

    std::vector <int> vect{};

    for (int i{0}; i< 20; i++){
        vect.push_back(dis(gen));
    }

    //2/
    std::vector<int>::iterator end_iterator { vect.end() };
    // Parcours du vecteur avec l'itérateur
    for (std::vector<int>::iterator it { vect.begin() }; it != end_iterator; ++it) {
        std::cout << *it << ' ';
    }

    //3/
    std::cout << std::endl;
    int num {};
    while (true)
    {
        std::cout << "Entrez un nombre : ";
        std::cin >> num;
        
        if (num < 0)
        {
            std::cout << "Erreur : votre nombre ne peut pas être négatif " << std::endl;
        }
        else if (std::cin.fail())
        {
            std::cin.clear(); // On remet std::cin dans un état fonctionnel.
            std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
            std::cout << "Erreur : votre nombre ne peut pas être une lettre " << std::endl;
        }
        else{
            break;
        }
    } 
    
    auto it {std::find(vect.begin(), vect.end(), num)};
    if (it != vect .end())
    {
        std::cout << "Nombre est present dans le tableau " << std::endl;

        //4/
        const int num_items = std::count(vect.cbegin(), vect.cend(), num);
        std::cout << "Le nombre " << num << " est présent " << num_items << " fois" << '\n';
    }
    else
    {
        std::cout << "Nombre non present dans le tableau " << std::endl;
    }

    //5/
    std::sort(vect.begin(), vect.end());

    for(const int element : vect){
        std::cout << element << ' ';
    }

    //6/

    int sum { std::accumulate(vect.begin(), vect.end(), 0, [](int acc, int current_element) { return acc + current_element; }) };
    std::cout << '\n' << "La somme des éléments du vecteur est " << sum << std::endl;




    //exercice 2
    //1/

    std::string str {"J\'aime beaucoup la prog, c'est super rigolo"};

    // int numLettres (std::string const & str){
    //     auto const is_space = [](char letter){ return letter == ' '; };
    
    //     auto it (std::find_if (vect.begin(), vect.end(), is_space));
    // }



    
}