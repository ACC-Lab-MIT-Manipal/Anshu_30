#include<bits/stdc++.h>
using namespace std;

// Define Key values of a and b
const int a = 5;
const int b = 8;

// Define encryption function
string encryption(string m)
{
	string c = "";
	int n = m.length();
	for (int i=0;i<n;i++)
	{
		// Avoid space
		if(m[i]==' ')
		c += m[i];
		else
		c += ((char) ((( (a * (m[i]-'A')) + b) % 26) + 'A'));
	}

	// Return cipherText
	return c;
}

// Define decryption function
string decrypion(string c)
{
	string m = "";
	int aInverse = 0;
	int temp = 0;

	// Find value of a inverse
	for (int i=0;i<26;i++)
	{
		temp = (a*i)%26;
		// Check the condition (a*i)%26 == 1
		if (temp == 1)
		aInverse = i;
	}

	int n = c.length();
	for (int i = 0;i<n;i++)
	{

    	// Avoid space
		if(c[i]==' ')
		m += c[i];
		else
		m += ((char) (((aInverse * ((c[i]+'A' - b)) % 26)) + 'A'));
	}

	// Return Message
	return m;
}

int main()
{
	string message = "THE POINT";

	// Call encryption function
	string c = encryption(message);
	cout << "Encrypted Message is : " << c<<endl;

	//Calling Decryption function
	message = decrypion(c);
	cout << "Decrypted Message is: " <<message;

	return 0;
}