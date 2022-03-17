#include <iostream>
#include <ctime>
using namespace std;
void computerguess();
int main()
{
	computerguess();
	system("pause");
	return 0;
}

void computerguess()
{
	int numA, numB, max, min = 1, tries = 0, maxnew = 0, minnew = 0;
	cout << "Enter the maximum and I will try to guess the randomized number:";
	cin >> max;
	unsigned number;
	number = time(0);
	srand(number);
	numA = rand() % max + min;
	numB = rand() % max + min;
	cout << numA << "  " << numB << endl;
	time_t t1 = clock();
	while (numA != numB)
	{
		if (numB > numA)
		{
			if (numB < max)
			{
				max = max - numB;
			}
			max = numB;
			maxnew++;
		}
		else if (numB < numA)
		{
			if (numA > min)
			{
				min = numA;
			}
			min = numB;
			minnew++;
		}
		numB = rand() % max + 1;
		cout << numA << "  " << numB << endl;
		tries++;
		
	}
	if (numA == numB)
	{
		long int timer = clock() - t1;
		cout << "# of new minimum: " << minnew << endl;
		cout << "# of new maximum: " << maxnew << endl;
		cout << "It took " << tries << " tries to get both numbers to equal " << numA << endl;
		cout << "Time Lapsed: " << timer/1000 << " seconds and " << timer%1000 << " Milliseconds \n" << endl;
	}

}