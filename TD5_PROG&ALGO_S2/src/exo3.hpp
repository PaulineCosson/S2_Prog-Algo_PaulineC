#pragma once
#include <cstddef>
#include <vector>
#include <stdlib.h>
#include <string>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    //1
    bool operator==(const Card& otherCard) const {
        return kind == otherCard.kind && value == otherCard.value;
    }

    //2
    size_t hash() const;
};

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size);
std::string card_name(Card const& card);