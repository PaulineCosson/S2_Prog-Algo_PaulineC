#include "exo1.hpp"
#include "exo2.hpp"
#include "exo3.hpp"

#include <iostream>
#include <ctime>



int main()
{
    //exo 1
    std::string s1 {"abc"};
    std::string s2 {"cba"};
    size_t hash1{0};
    size_t hash2 {0};

    size_t max{1000000009};
    hash1 = folding_string_hash_sum(s1,max);
    hash2 = folding_string_hash_sum(s2,max);
    std::cout << "hachage simple chaine 1 : " << hash1 << " chaine 2 : " << hash2 << std::endl;

    hash1 = folding_string_ordered_hash(s1,max);
    hash2 = folding_string_ordered_hash(s2,max);
    std::cout << "hachage ordonné chaine 1 : " << hash1 << " chaine 2 : " << hash2 << std::endl;

    size_t p {31};
    hash1 = polynomial_rolling_hash(s1,p,max);
    hash2 = polynomial_rolling_hash(s2,p,max);
    std::cout << "polynomial rolling hash : chaine 1 : " << hash1 << " chaine 2 : " << hash2 << std::endl;

    
    //exo 2
    // Mon programme est très très lent (il tourne à l'infini) même en baissant le nombre d'observation à 10
    // Je n'ai pas trouvé la solution, le reste de l'exo à donc été fait à l'aveugle

    //2/
    size_t number_of_observations {10};
    std::vector<float> expected_insect_probabilities {probabilities_from_count(expected_insect_counts)};

    auto insectPairs {get_insect_observations(number_of_observations,expected_insect_probabilities)};

    std::unordered_map<Insect, int> insect_counts;
    for(Insect insectType : insect_values){
        insect_counts[insectType] = 0;
    }

    for(auto pair : insectPairs){
        Insect insect {pair.first};
        int number {pair.second};
        insect_counts[insect] += number;
    }
    
    for (const auto& [insect, count] : insect_counts) {
        std::cout << insect_to_string.at(insect) << ": " << count << std::endl;
    }

    //3/
    std::vector<int> observed_counts_vector;
    for(Insect insect : insect_values){
        int insect_count {insect_counts[insect]};
        observed_counts_vector.push_back(insect_count);
    }
    auto observed_insect_probabilities {probabilities_from_count(observed_counts_vector)};

    //4/
    for (size_t i {0}; i < insect_values.size(); i++){
        const std::string& insect_name = insect_to_string.at(insect_values[i]);
        float observed = observed_insect_probabilities[i];
        float expected = expected_insect_probabilities[i];
        std::cout << insect_name << " : " << observed << " vs " << expected;

        if (std::abs(observed - expected) > 0.01) {
            std::cout << " BAD";
        } else {
            std::cout << " OK";
        }
        std::cout << std::endl;
    }

    //exo 3
    int nbr {100};
    std::vector<Card> cards {get_cards(nbr)};
    
    std::unordered_map<Card, int> cardFreq;
    for (int i{0}; i < nbr; i++) {
        cardFreq[cards[i]]++;
    }

    for (const auto& [card, count] : cardFreq) {
        std::cout << card_name(card) << " : " << count << std::endl;
    }

    return 0;
}