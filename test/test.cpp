#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Person.h"
#include "demo.h"
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

TEST(TestExecution, test_Rover_should_move_one_step_toward_N){
    mars_practice::CMarsHandle cMarsHandle;
    cMarsHandle.Init();
    int iXmax = 5, iYmax = 5;                // 最大边界X值/Y值
    int iXinput = 1, iYinput = 1;            // 用户输入位置
    char cDirectionInput = 'N';              // 用户输入方向
    std::string strOperation = "M";  // 具体操作内容
    std::vector<mars_practice::STParaGroup> vecUserInput;// 用户输入参数组
    mars_practice::STParaGroup stUserPara(iXinput, iYinput, cDirectionInput, strOperation);
    vecUserInput.push_back(stUserPara); // 写入用户的多组输入
    std::string result=execute(cMarsHandle,iXmax,iYmax,vecUserInput);
    ASSERT_EQ("1 2 N\n", result);
}