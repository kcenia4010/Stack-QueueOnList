#include <../gtest/gtest.h>
#include <../list_lib/StackList.h>

TEST(stack_list, can_create_stack_list)
{
	ASSERT_NO_THROW(TStackList<int> S);
}

TEST(stack_list, can_push)
{
	TStackList<int> S;
	ASSERT_NO_THROW(S.push(1));
}

TEST(stack_list, can_pull)
{
	TStackList<int> S;
	S.push(1);
	ASSERT_NO_THROW(S.pull());
}

TEST(stack_list, can_push_and_pull_many_times)
{
	TStackList<int> S;
	S.push(1);
	S.push(2);
	S.push(3);
	EXPECT_EQ(3, S.pull());
	EXPECT_EQ(2, S.pull());
	EXPECT_EQ(1, S.pull());
}

TEST(stack_list, can_not_pull_from_empty_stack)
{
	TStackList<int> S;
	ASSERT_ANY_THROW(S.pull());
}

TEST(stack_list, can_use_operator_equal)
{
	TStackList<int> S;
	S.push(1);
	S.push(2);
	S.push(3);

	TStackList<int> S2;
	S2 = S;
	EXPECT_EQ(S.pull(), S2.pull());
	EXPECT_EQ(S.pull(), S2.pull());
	EXPECT_EQ(S.pull(), S2.pull());
}
