#include <../gtest/gtest.h>
#include <../list_lib/QueueList.h>

TEST(queue_list, can_create_queue_list)
{
	ASSERT_NO_THROW(TQueueList<int> S);
}

TEST(queue_list, can_push)
{
	TQueueList<int> Q;
	ASSERT_NO_THROW(Q.push(1));
}

TEST(queue_list, can_pull)
{
	TQueueList<int> Q;
	Q.push(1);
	ASSERT_NO_THROW(Q.pull());
}

TEST(queue_list, can_push_and_pull_many_times)
{
	TQueueList<int> Q;
	Q.push(1);
	Q.push(2);
	Q.push(3);
	EXPECT_EQ(1, Q.pull());
	EXPECT_EQ(2, Q.pull());
	EXPECT_EQ(3, Q.pull());
}

TEST(queue_list, can_not_pull_from_empty_queue)
{
	TQueueList<int> Q;
	ASSERT_ANY_THROW(Q.pull());
}

TEST(queue_list, can_use_operator_equal)
{
	TQueueList<int> Q;
	Q.push(1);
	Q.push(2);
	Q.push(3);

	TQueueList<int> Q2;
	Q2 = Q;
	EXPECT_EQ(Q.pull(), Q2.pull());
	EXPECT_EQ(Q.pull(), Q2.pull());
	EXPECT_EQ(Q.pull(), Q2.pull());
}

TEST(queue_list, insert_sort)
{
	TQueueList<int> Q;
	Q.push(1);
	Q.push(5);
	Q.push(3);
	Q.InsertSort(2);
	EXPECT_EQ(1, Q.pull());
	EXPECT_EQ(2, Q.pull());
	EXPECT_EQ(3, Q.pull());
	EXPECT_EQ(5, Q.pull());
}