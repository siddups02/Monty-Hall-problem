#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIMULATION_COUNT = 100;

int randnum()
{
   return  (rand() % 3+1) ; //Generating random numbers
}

//Function Declarations
void simulate(int i, int&win1, int& win2);
int opendoor( int car_here, int first_choice );
int makeSecondChoice( int opened_door, int first_choice );

int main()
{
	srand((unsigned)time(0)); // Generates random numbers as per System Clock
    int win1 = 0, win2 = 0;

    //Creating Output Syntax as per professor Rule
    cout << "#	Car		First		Opened		Second		Win		Win" << endl;
    cout << "	here		choice		door		choice	       first	      second" << endl << endl;

    // Run the simulations.
    for (int i = 1; i <= SIMULATION_COUNT; i++)
    {

    	simulate(i, win1, win2); // Calling the Function Simulate
    }

    // Prints out Number of Wins for First Choice and Second Choice
    cout << endl << win1 << "  wins if stay with the first choice" << endl;
    cout << win2 << "  wins if switch to the second choice"<< endl;

    // Calculates ratio of First Choice Over Second Choice
    double ratiocal = (win2/win1);
    cout << endl << "Win ratio of switch over stay: " << ratiocal << endl;
    return 0;
}

void simulate(int i, int& win1, int& win2 )
{
	int opened_door = 0;
	int second_choice = 0;
	int car_here = randnum(); // Assigning Random Number to Car Hide
	int first_choice = randnum(); // Assigning Random Number to First Choice of the Contestant

	//To find Open door
	opened_door = opendoor(car_here, first_choice); //Calls Function opendoor that Calculates the Open Door Number

	//To find Second Choice
	second_choice = makeSecondChoice( opened_door, first_choice ); // Calls Function that Calculates the Second Choice of the Contestant

	cout << i << "	  "<< car_here << "	  	" << first_choice << " 	  	" << opened_door << "	  	" << second_choice ; // Each time Prints out the
																														 // Car Hide, First Choice and Second Choice of the user

	// Calculates the Number of Wins for User First Choice and Second Choice as Win1 and Win2 respectively
	if(first_choice == car_here)
	{
		win1++;
		cout <<"		Yes" << endl;
	}
	if(second_choice == car_here)
	{
		win2++;
		cout <<"				Yes" << endl;
	}




}

// Function to Calculate Open Door Depending on the first choice and Car Hidden Place, return's the same choice made
int opendoor( int car_here, int first_choice )
{

	if (car_here == first_choice)
		{
			int temp = randnum();
			while(1) // Generates random number and compares to the Car Hidden and First Choice, for every random number generated
			{

				if(temp == car_here)
					temp = randnum();
				else
					break;
			}
			return temp;
		}

		else
		{
			int temp = randnum();
			while(1) // Generates random number and compares to the Car Hidden and First Choice, for every random number generated
			{

				if( (temp == car_here) || (temp == first_choice) )
					temp = randnum();
				else
					break;
			}
			return temp;
		}
}

