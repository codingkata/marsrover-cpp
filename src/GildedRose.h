//
// Created by qiao liang on 2019-11-17.
//

#ifndef GILDEDROSE_GILDEDROSE_H
#define GILDEDROSE_GILDEDROSE_H


#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality)
    {}
};

class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);

    void updateQuality();
};


#endif //GILDEDROSE_GILDEDROSE_H
