#ifndef GILDEDROSE_PERSON_H
#define GILDEDROSE_PERSON_H


class Person {
public:
    int getAge() const {
        return age;
    }
    void setAge(int age) {
        Person::age = age;
    }
public:
    const std::string &getName() const {
        return name;
    }
    void setName(const std::string &name) {
        Person::name = name;
    }

private:
    int age;
    std::string name;
};


#endif //GILDEDROSE_PERSON_H
