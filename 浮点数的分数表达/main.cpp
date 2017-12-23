//
//  main.cpp
//  hello
//
//  Created by 陈树沛 on 09/11/2017.
//  Copyright © 2017 supiccc. All rights reserved.
//

#include <iostream>
#include "math.h"
#include "string.h"

using namespace std;

string number;

long long getGreatestCommonDivisor(long long molecule, long long denominator) {
	/*if (molecule <= denominator) {
		for (long long i = molecule; i > 0; i--) {
			if (molecule % i == 0 && denominator % i == 0) {
				return i;
			}
		}
	} else {
		for (long long i = denominator; i > 0; i--) {
			if (molecule % i == 0 && denominator % i == 0) {
				return i;
			}
		}
	}
	return 0;
	速度太慢 跑不过
	*/
	if (molecule < denominator)
	{
		long long tmp = molecule;
		molecule = denominator;
		denominator = tmp;
	}
	if (denominator == 0)
		return molecule;
	else
	return getGreatestCommonDivisor(molecule % denominator, denominator);
}
//求分子
long long getMolecule(long long numOfTerminate, long long numOfInfinate) {
	if (numOfTerminate && !numOfInfinate) {
		//纯有限小数转换为整数
		long long molecule = 0;
		for (int i = 2; i < numOfTerminate + 2; i++) {
			molecule = 10 * molecule + (number[i] - 48);
		}
		return molecule;
	} else if (!numOfTerminate && numOfInfinate) {
		//纯无限小数转换为整数
		long long molecule = 0;
		for (int i = 3; i < 3 + numOfInfinate; i++) {
			molecule = 10 * molecule + (number[i] - 48);
		}
		return molecule;
	} else {
		//有限小数和无限小数混合转换为整数
		long long a = 0;
		long long b = 0;
		long long molecule = 0;
		for (int i = 2; i < numOfTerminate + 2; i++) {
			a = (10 * a + (number[i] - 48));
		}
		for (long long i = numOfTerminate + 3; i < 3 + numOfTerminate + numOfInfinate ; i++) {
			b = (10 * b + (number[i] - 48));
		}
		molecule = a * (pow(10, numOfInfinate) - 1) + b;
		return molecule;
	}
}
int main(int argc, char *argv[]) {
	cin >> number;
	long long numOfInfinate = 0; //无限小数位数
	long long numOfTerminate = 0; //有限小数位数
	long long molecule = 0; //分子
	long long denominator = 0; //分母
	
	if (number[2] == '(') {
		//无限小数
		numOfInfinate = number.length() - 4;
		molecule = getMolecule(numOfTerminate, numOfInfinate);
	} else if (number[number.length() - 1] == ')') {
		//混合小数
		for (int i = 2; i < number.length(); i++) {
			if (numOfTerminate == 0 && number[i] == '(') {
				numOfTerminate = i - 2;
			}
			if (number[i] == ')') {
				numOfInfinate = i - 3 - numOfTerminate;
			}
		}
		molecule = getMolecule(numOfTerminate, numOfInfinate);
	} else {
		//纯小数
		numOfTerminate = number.length() - 2;
		molecule = getMolecule(numOfTerminate, numOfInfinate);
	}
	
	denominator = pow(10, numOfTerminate);
	if (numOfInfinate != 0) {
		denominator *= (pow(10, numOfInfinate) - 1);
	}
	
	long long res = getGreatestCommonDivisor(molecule, denominator);
	cout << molecule / res << " " << denominator / res;
	
	return 0;
}
