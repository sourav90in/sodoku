//============================================================================
// Name        : sodoku.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "sdk.h"
using namespace std;
using namespace sdk;

sdk_sol::sdk_sol()
{
	cout<<"Initial State: \n";
	this->print_sol();

	cout<<"\n"<<"\n";

}

void sdk_sol::print_sol()
{
	for(int i=0; i< 9; i++)
	{
		for(int j=0; j < 9; j++)
		{
			cout<<this->arr[i][j];
		}
		cout<<"\n";
	}
}

bool sdk_sol::isSafe(int x, int y, int data )
{
	/* first check is for data is within 1-9 range */
	if( (data < 1) || ( data > 9 ) ||
		(x < 0 ) || (x > 8) || (y < 0) || ( y > 8) )
		return false;

	/* Third check is if the data being set at y is safe for the whole col */
	for(int i= 0; i< 9; i++)
	{
		if(this->arr[i][y] == data ) return false;
	}

	/* Second check is if data being set at x is safe for the whole row */
	for(int i=0; i <9; i++)
	{
		if( this->arr[x][i] == data ) return false;
	}

	/* Fourth check is to identify the sub-region it belongs to and if its safe
	 * for the sub-region
	 */
	/*Define the subregion first */
	int rowstart = getsubregion(x);
	int colstart = getsubregion(y);
	for( int i=rowstart; i < rowstart+3; i++ )
	{
		for( int j=colstart; j < colstart+3; j++ )
		{
			if( this->arr[i][j] == data )
				return false;
		}
	}

	return true;
}

int sdk_sol::getsubregion(int coord)
{
	if( (coord <= 2) ) return 0;
	else if( ( coord > 2 ) & (coord <= 5 ) ) return 3;
	else return 6;

}

void sdk::SodSolver()
{
	sdk_sol* sd_ptr = new sdk_sol;

	//Read data from file and populate the givens into the array.
	//for now trying a test data

	//Start processing
	for(int i=1; i <=9; i++)
	{
		if( sd_ptr->SolFinder(0,0,i) == true )
			break;
		else
		{
			sd_ptr->resetDataatPos(0,0);
		}
	}

	sd_ptr->print_sol();
}

bool sdk_sol::SolFinder(int x, int y, int data )
{
	if( this->isSafe(x,y,data) == false ) return false;
	else this->arr[x][y] = data;

	for(int j=x; j<9; j++ )
	{
		for(int k=y+1; k<9; k++ )
		{
			if( this->arr[j][k] == 0)
			{
				int i;
				for(i=1; i <=9; i++)
				{
					if( SolFinder(j,k,i) == true ) break;
				}
				/* If i has become 10 it means all numbers 1-9 were tried at
				 * pos j,k of the array but nothing worked so backtrack to j,k-1
				 */
				if( i ==10 )
				{
					this->resetDataatPos(x,y);
					return false;
				}
			}
		}
	}

	return true;
}

int main() {

	SodSolver();

}
