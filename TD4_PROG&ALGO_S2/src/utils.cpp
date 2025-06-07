#include "utils.hpp"
//exo 1
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
        std::cout << num << " est present dans le tableau " << std::endl;

        //4/
        const int num_items = std::count(vect.cbegin(), vect.cend(), num);
        std::cout << "Le nombre " << num << " est présent " << num_items << " fois" << '\n';
    }
    else
    {
        std::cout << "Nombre non present dans le tableau " << std::endl;
    }
}

//exo 2
//1/
int firstWordLength (std::string const& str){
    auto const is_space = [](char letter){ return letter == ' '; };

    auto firstLetter = std::find_if_not(str.begin(), str.end(), is_space);
    auto lastLetter = std::find_if(firstLetter, str.end(), is_space);

    return (std::distance (firstLetter,lastLetter));
}

//2/
std::vector<std::string> split_string(std::string const& str){
    auto const is_space = [](char letter){ return letter == ' '; };
    std::vector<std::string> wordsTab{};
    auto startWord {str.begin()};

    while (startWord != str.end()){
        startWord = std::find_if_not(startWord, str.end(), is_space);
        auto endWord = std::find_if(startWord, str.end(), is_space);

        if(startWord != str.end()){
            wordsTab.emplace_back(startWord,endWord);
        }
        startWord = endWord;
    }
    return wordsTab;
}


//exo 3
bool isPalindrome (std::string const& str){
    return (std::equal(str.begin(), str.end(), str.rbegin(), str.rend()));
}