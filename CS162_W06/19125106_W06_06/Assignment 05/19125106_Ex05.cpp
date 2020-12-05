#include <iostream>
#include "Header.h"
#include <string>

using namespace std;

int main()
{
	Stack s;
	int x;
	string hex, bin;

	cout << "Convert a decimal into a binary number, enter the decimal number: ";
	cin >> x;
	dec_to_bin(s, x);

	while (1)
	{
		bool check = true;
		cout << "Convert a binary into a decimal number, enter the binary number: ";
		cin >> bin;
		for (int i = 0; i < bin.length(); ++i)
		{
			if (!(bin[i] == '0' || bin[i] == '1'))
			{
				check = false;
				break;
			}
		}
		if (check)
			break;
	}

	cout << bin_to_dec(s, bin) << endl;
	cout << "Convert a decimal into a hex number, enter the decimal number: ";
	cin >> x;
	dec_to_hex(s, x);
	cout << endl;

	cout << "Convert a hex into a decimal number, enter the hex number: ";
	cin >> hex;
	cout << hex_to_dec(s, hex) << endl;
	return 0;
}