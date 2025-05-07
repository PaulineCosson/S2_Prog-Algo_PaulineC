#include "utils.hpp"

//3/4
void findNum (std::vector <int> vect){
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
}