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


TEST(GoalUndoTest, addNonStringOperationGetOperation)
{
    GoalUndo x;
    x.addOperation("Get fit", "");
    ASSERT_TRUE(x.getOperations() == ""); //returns non string operation as nothing was added.
}

TEST(GoalUndoTest, addMultipleOperationTest)
{
    GoalUndo x;
    x.addOperation("Get Fit", "Go for jogging,");
    x.addOperation("Lift weight");
    ASSERT_TRUE(x.getOperations() == "Go for jogging, Lift weight");
}


TEST(GoalUndoTest, addMultipleOperationNonStringTest)
{
    GoalUndo x;
    x.addOperation("Get Fit", "Go for jogging,");
    x.addOperation("Lift weight,");
    x.addOperation("");
    ASSERT_TRUE(x.getOperations() == "Go for jogging, Lift weight,");
}

TEST(GoalUndoTest, addMultipleGoalGetGoal)
{
    GoalUndo x;
    x.addOperation("Get Fit", "Go for jogging,");
    x.addOperation("Buy a car", "Look in craigslist.com");
    ASSERT_TRUE(x.getGoal() == "Buy a car");
}

TEST(GoalUndoTest, addMultipleGoalGetOperation)
{
    GoalUndo x;
    x.addOperation("Get Fit", "Go for jogging,");
    x.addOperation("Buy a car", "Look in craigslist.com");
    ASSERT_TRUE(x.getOperations() == "Look in craigslist.com");
}

TEST(GoalUndoTest, addMultipleGoalNonStringGoalGetOperation)
{
    GoalUndo x;
    x.addOperation("Get Fit", "Go for jogging,");
    x.addOperation("", "Look in craigslist.com");
    ASSERT_FALSE(x.getOperations() == "Look in craigslist.com");         //returns non string goal
    ASSERT_TRUE(x.getOperations() == "Go for jogging,");         //returns prevously added goal
}















