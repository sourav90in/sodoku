/*
 * sdk.h
 *
 *  Created on: Nov 12, 2017
 *      Author: Sourav
 */

#ifndef SDK_H_
#define SDK_H_

namespace sdk
{
class sdk_sol;
void SodSolver();
};

class sdk::sdk_sol
{
private:
int arr[9][9] = { {0,6,0,1,0,4,0,5,0},
        {0,0,8,3,0,5,6,0,0},
		{2,0,0,0,0,0,0,0,1},
		{8,0,0,4,0,7,0,0,6},
		{0,0,6,0,0,0,3,0,0},
		{7,0,0,9,0,1,0,0,4},
		{5,0,0,0,0,0,0,0,2},
		{0,0,7,2,0,6,9,0,0},
		{0,4,0,5,0,8,0,7,0} };
int getsubregion(int coord);
bool SolFinder(int x, int y, int data );

public:
sdk_sol();
bool isSafe(int x, int y, int data );
void resetDataatPos(int x, int y) { arr[x][y] = 0; }
void print_sol();
friend void sdk::SodSolver();
};



#endif /* SDK_H_ */
