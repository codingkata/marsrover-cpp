#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Person.h"
#include "demo.h"

namespace {
    class RoverExecutionTest : public testing::Test {
    public:
        mars_practice::CMarsHandle cMarsHandle;
        int iXmax, iYmax;
        int iXinput, iYinput;
        char cDirectionInput;
        std::string strOperation;
        std::vector<mars_practice::STParaGroup> vecUserInput;

        RoverExecutionTest(){
            cMarsHandle.Init();
            iXmax = 5, iYmax = 5;               // 最大边界X值/Y值
            iXinput = 1, iYinput = 1;           // 用户输入位置
            cDirectionInput = 'N';              // 用户输入方向
            strOperation = "M";                 // 具体操作内容
        }
    };
}

TEST_F(RoverExecutionTest, test_Rover_should_move_one_step_toward_N){
    mars_practice::STParaGroup stUserPara(iXinput, iYinput, cDirectionInput, strOperation);
    vecUserInput.push_back(stUserPara); // 写入用户的多组输入

    std::string result=execute(cMarsHandle,iXmax,iYmax,vecUserInput);

    ASSERT_EQ("1 2 N\n", result);
}

TEST_F(RoverExecutionTest, test_GIVEN_rover_toward_N_WHEN_turn_L_THEN_toward_W){
    cDirectionInput = 'N';              // 用户输入方向
    strOperation = "L";  // 具体操作内容
    mars_practice::STParaGroup stUserPara(iXinput, iYinput, cDirectionInput, strOperation);
    vecUserInput.push_back(stUserPara); // 写入用户的多组输入

    std::string result=execute(cMarsHandle,iXmax,iYmax,vecUserInput);

    ASSERT_EQ("1 1 W\n", result);
}

TEST_F(RoverExecutionTest, test_multiple_rovers_run){
    std::string firstOperation = "LMLMLMLMM";
    mars_practice::STParaGroup firstRover(1, 2, 'N', firstOperation);
    vecUserInput.push_back(firstRover);

    std::string secondOperation = "MMM";
    mars_practice::STParaGroup secondRover(3, 3, 'E', secondOperation);
    vecUserInput.push_back(secondRover);

    std::string result=execute(cMarsHandle,iXmax,iYmax,vecUserInput);

    ASSERT_EQ("1 3 N\n5 3 E RIP\n", result);
}
TEST_F(RoverExecutionTest, test_SAFE_after_RIP){
    std::string firstOperation = "MMM";
    mars_practice::STParaGroup firstRover(3, 3, 'E', firstOperation);
    vecUserInput.push_back(firstRover);

    std::string secondOperation = "MMM";
    mars_practice::STParaGroup secondRover(3, 3, 'E', secondOperation);
    vecUserInput.push_back(secondRover); // 写入用户的多组输入

    std::string result=execute(cMarsHandle,iXmax,iYmax,vecUserInput);

    ASSERT_EQ("5 3 E RIP\n5 3 E\n", result);
}
