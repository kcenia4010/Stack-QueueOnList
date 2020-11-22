#include <iostream>
#include <../list_lib/StackList.h>
#include <../list_lib/QueueList.h>

using namespace std;
int main()
{
	TStackList<int> S;
	S.push(10);
	S.push(20);
	S.push(30);

	cout << S.pull() << endl;

	TQueueList<int> Q;
	Q.push(10);
	Q.push(20);
	Q.push(30);

	cout << Q.pull();

	return 0;
}
