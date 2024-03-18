#include "pch.h"
#include "CppUnitTest.h"
#include "../Queue/queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueTests
{
	TEST_CLASS(QueueTests)
	{
	public:
		
		TEST_METHOD(IsEmptyIsAnyTest)
		{
			Queue Q;
			Assert::IsTrue(Q.isEmpty());

			Q.addToQueue(12);
			Assert::IsTrue(Q.isAny());
		}

		TEST_METHOD(IsFullTest)
		{
			Queue Q(2);
			Q.addToQueue(12);
			Q.addToQueue(2);
			
			Assert::IsTrue(Q.isFull());
		}

		TEST_METHOD(AddTest)
		{
			Queue Q(2);
			Q.addToQueue(12);

			Assert::AreEqual(12, Q.peek());
		}

		TEST_METHOD(RemoveTest)
		{
			Queue Q(2);
			Q.addToQueue(12);
			Q.addToQueue(11);

			Q.removeFromQueue();
			Assert::AreEqual(Q.peek(), 11);
		}

		TEST_METHOD(CheckSizeTest)
		{
			Queue Q(12);
			Assert::AreEqual(12, Q.checkSize());
		}
	};

	TEST_CLASS(PriorityQueueTest)
	{
	public:

		TEST_METHOD(FillTest)
		{
			PriorityQueue P;
			P.fillQueue(4, 5);

			Assert::AreEqual(P.peekItem(), 4);
		}

		TEST_METHOD(RemoveItemTest)
		{
			PriorityQueue P;
			P.fillQueue(4, 5);
			P.fillQueue(6, 8);

			Assert::AreEqual(P.removeItem(), 6);
		}

		TEST_METHOD(NoItemsTest)
		{
			PriorityQueue P;
			Assert::IsTrue(P.noItems());
		}

		TEST_METHOD(AtLeastOneTest)
		{
			PriorityQueue P;
			P.fillQueue(6, 8);

			Assert::IsTrue(P.atLeastOne());
		}
	};
}
