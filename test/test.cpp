#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Person.h"

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        Person obj;
        ClassDeclaration(){
            obj;
        }
    };
}

TEST_F(ClassDeclaration, getAge){
    obj.setAge(30);
    ASSERT_EQ(obj.getAge(),30);
}

TEST_F(ClassDeclaration, getName){
    obj.setName("Peter");
    ASSERT_NE("David",obj.getName());
    ASSERT_EQ("Peter",obj.getName());
}