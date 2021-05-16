#include<iostream>

using namespace std;

int main()
{
	int ttt_arr[10][10]{ 0 };
	int high = 10;
	int low = 3;
	int n = 0;
	while (true)
	{
		cout << "How big would you like your grid to be?  Choose from between [" << low << "-" << high << "]:  ";
		cin >> n;
		if (n >= low && n <= high)
			break;
	}

	int verify = 0;

	int row_start[100];
	int col_start[100];
	int row_dir[100];
	int col_dir[100];

	for (int i = 0; i < n; ++i)
	{
		row_start[verify] = i;
		col_start[verify] = 0;
		row_dir[verify] = 0;
		col_dir[verify] = 1;
		verify++;
	}
	for (int i = 0; i < n; ++i)
	{
		row_start[verify] = 0;
		col_start[verify] = i;
		row_dir[verify] = 1;
		col_dir[verify] = 0;
		verify++;
	}
	row_start[verify] = 0;
	col_start[verify] = 0;
	row_dir[verify] = 1;
	col_dir[verify] = 1;
	verify++;

	row_start[verify] = 0;
	col_start[verify] = n - 1;
	row_dir[verify] = 1;
	col_dir[verify] = -1;
	verify++;

	int moves = 0;
	int turn = 0;

	while (true)
	{
		if (moves == n * n) {
			cout << "Game tied!\n";
			return 0;
		}
		char player = 'o';
		if (turn != 0)
			player = 'x';

		cout << "Player " << player << ", it's your turn to move." << endl;
		cout << "Enter your play (row, col):  ";
		int row_entry = 0;
		int col_entry = 0;
		cin >> row_entry >> col_entry;
		if (row_entry<1 || col_entry<1 || row_entry>n || col_entry>n)
		{
			cout << "Move outside the parameters.  Try again, you buffoon!\n";
			continue;
		}

		row_entry -= 1;
		col_entry -= 1;

		if (ttt_arr[row_entry][col_entry])
		{
			cout << "Move already played!" << endl;
			continue;
		}

		ttt_arr[row_entry][col_entry] = turn + 1;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (ttt_arr[i][j] == 0)
					cout << '.';
				else if (ttt_arr[i][j] == 1)
					cout << 'o';
				else
					cout << 'x';
			}
			cout << endl;
		}

		for (int i = 0; i < verify; ++i)
		{
			int row = row_start[i];
			int col = col_start[i];
			int row_di = row_dir[i];
			int col_di = col_dir[i];
			int start = ttt_arr[row][col];
			int count = 0;

			if (ttt_arr[row][col] == 0)
				continue;
			else
			{
				for (int j = 0; j < n; ++j)
				{
					if (ttt_arr[row][col] == start)
					{
						count++;
						row += row_di;
						col += col_di;
					}
				}
			}
			if (count == n)
			{
				cout << "The winner is player " << player << "!  Congratulations!" << endl;
				return 0;
			}
		}

		turn = !turn;
		moves++;
	}
	return 0;
}
