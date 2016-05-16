/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"
 
class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}


TEST(GoalUndoTest, goalGetTest)
{
    GoalUndo x;
    x.addOperation("Get Fit", "Go for jogging");
    ASSERT_TRUE(x.getGoal() == "Get Fit");
}

TEST(GoalUndoTest, operationGetTest)
{
    GoalUndo x;
    x.addOperation("Get Fit", "Go for jogging");
    ASSERT_TRUE(x.getOperations() == "Go for jogging");
}

TEST(GoalUndoTest, addNonStringGoalGetGoal)
{
    GoalUndo x;
    x.addOperation("", "Go for jogging");
    ASSERT_TRUE(x.getGoal() == "");         //returns non string goal
}

TEST(GoalUndoTest, addNonStringGoalGetOperation)
{
    GoalUndo x;
    x.addOperation("", "Go for jogging");
    ASSERT_FALSE(x.getOperations() == "Go for jogging"); //returns non string operation as nothing was added.
}

TEST(GoalUndoTest, addNonStringOperationGetGoal)
{
    GoalUndo x;
    x.addOperation("Get fit", "");
    ASSERT_FALSE(x.getGoal() == "Get fit");         //returns non string goal
}

