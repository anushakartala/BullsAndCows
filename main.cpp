#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

int main() {

	srand(std::chrono::duration_cast<std::chrono::milliseconds>
	     (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000);


	int code;
	int digits;
	int numCode;
	int codeArray[9];
	int randDigit;
	bool found;
	bool negativeNumber;
	int numGuess;
	int guess;
	int guessArray[9];
	int guessDigits;
	int x=0;
	int y=0;

	cout << "Enter number of digits in code (3, 4 or 5): ";
	cin >> digits;

	if (digits == 0)
	{
		cout << "Enter code: ";
		cin >> numCode;
		cout << "Enter number of digits in code: ";
		cin >> digits;
		cout << "Number to guess: ";


		for (int i=digits-1; i>=0; i--)
		{
			code = numCode % 10;
			numCode = numCode / 10;
			codeArray[i] = code;
		}


	}

	else
	{
		for (int i=0; i < digits; i++)
		{
			found = false;
		    do {
				randDigit = rand() % 10;

				for (int j=0; j < i; j++)
				{
					if (randDigit != codeArray[j])
						found = false;
					else {
						found = true;
					break;
					}
				}


			 } while (found == true);

		  codeArray[i] = randDigit;
		}
		}

	    for (int i=0; i < digits; i++)
	    {
		if (i == digits-1)
			cout << codeArray[i] << endl;
		else
			cout << codeArray[i] << "-";
	     }

  do {
	    do {
	    cout << "Enter Guess: ";
	    cin >> numGuess;
	    found = false;
	    negativeNumber = false;
	    if(numGuess<0)
	    {
	    	cout<<"You must guess a positive integer"<<endl;
	    	negativeNumber = true;
	    }
	    else
	    {
	    for (int i=digits-1; i>=0; i--)
	    {
	    	guess = numGuess % 10;
	    	numGuess = numGuess / 10;
	    	guessArray[i] = guess;
	    }


	    if (numGuess > 0)
        	cout << "You can only enter " << digits << " digits." << endl;

        else
        {
        	for (int i=0; i < digits; i++)
        	{
	    		for (int j=0; j < i; j++)
	    		{
	    			if (guessArray[i] == guessArray[j])
	    			{
	    				cout << "Each number must be different." << endl;
	    				found = true;
	    			}

	    		}
	    		if (found == true)
	    			break;
        	}
        }
	    }
       // cout<<"numGuess = "<<numGuess<<endl<<"found = "<<found<<endl;
	    }
        while (numGuess > 0 || found == true || negativeNumber == true);

	    x=0;
	    y=0;

	    	for (int i=0; i < digits; i++)
	            	{
	    	    		for (int j=0; j < digits; j++)
	    	    		{
	    	    			if (guessArray[i] == codeArray[j])
	    	    			{
	    	    				if (i == j)
	    	    				{
	    	    					x = x + 1;
	    	    				}
	    	    				else
	    	    				{
	    	    					y = y + 1;
	    	    				}
	    	    				break;
	    	    			}
	    	    		}
	            	}

	    if (x != digits)
	    {
	    cout << x << " bulls" << endl << y << " cows" << endl;
	    }
}
while (x != digits);

  if (x == digits)
  {
	  cout << digits << " bulls... ";
	  for (int i=0; i < digits; i++)
	  	    {
	  		if (i == digits-1)
	  			cout << codeArray[i];
	  		else
	  			cout << codeArray[i] << "-";
	  	     }
	  cout << " is correct!" << endl;
  }
}
