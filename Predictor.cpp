// -------------------------------------------- 
//---------------------------------------------
//README
//
//The version_1 is finished in 2021/05/14
//
//---------------------------------------------
//
//Input,Output Example:
//Input
/*
TTTTNNTNTNTNTNTNT
*/
//
//Output
//
//(00,SN,SN,SN,SN) wrong
//(01, WN, SN, SN, SN) wrong
//(11, WN, WN, SN, SN) wrong
//(11, WN, WN, SN, WN) wrong
//(11, WN, WN, SN, WT) wrong
//(10, WN, WN, SN, WN) correct
//(00, WN, WN, SN, WN) wrong
//(01, WT, WN, SN, WN) wrong
//(10, WT, WT, SN, WN) wrong
//(01, WT, WT, WN, WN) wrong
//(10, WT, WN, WN, WN) wrong
//(01, WT, WN, WT, WN) wrong
//(10, WT, WT, WT, WN) correct
//(01, WT, WT, ST, WN) wrong
//(10, WT, WN, ST, WN) correct
//(01, WT, WN, ST, WN) wrong
//(10, WT, WT, ST, WN) correct
//(01, WT, WT, ST, WN) correct
//
//---------------------------------------------
#include <math.h>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void ChangePredictor(string predictor[],int i, int PredictFlag);
void main() {
	int i;
	int BCnum;
	int PredictFlag = 0;
	int misprediction = 0;
	string outcome;
	string predict;
	string state = { "00" };
	string ANS = "TTTTNNTNTNTNTNTNT";
	cout << "Input: ";
	getline(cin, ANS);
	string predictor[4]= { "SN","SN","SN","SN" };

	for (i = 0; i < ANS.size(); i++)
	{
		//capture
		outcome = ANS[i];
		if (state == "00")
		{
			predict = predictor[0][1];
			BCnum = 0;
		}
		else if (state == "01")
		{
			predict = predictor[1][1];
			BCnum = 1;
		}
		else if (state == "10")
		{
			predict = predictor[2][1];
			BCnum = 2;
		}
		else  if (state == "11")
		{
			predict = predictor[3][1];
			BCnum = 3;
		}
		cout << "(" << state <<","<< predictor[0] << "," ;
		cout << predictor[1] << "," << predictor[2];
		cout<< "," << predictor[3] <<") ";
		//examine, change predictor
		if (outcome == predict)
		{
			PredictFlag = 1;
			ChangePredictor(predictor,BCnum,PredictFlag);
			cout <<"correct " << endl;
		}
		else
		{
			PredictFlag = 0;
			ChangePredictor(predictor,BCnum, PredictFlag);
			cout << "wrong "<< endl;
			misprediction = misprediction + 1;
		}
		//decide state
		if (outcome == "T")
		{
			state[0] = state[1];
			state[1] = '1';
		}
		else
		{
			state[0] = state[1];
			state[1] = '0';
		}

	}
	cout <<endl<<"misprediction=" <<misprediction;

	system("pause");

}
void ChangePredictor(string predictor[],int i,int PredictFlag)
{
	if (PredictFlag == 0)
	{
		if (predictor[i] == "SN")
		{
			predictor[i] = "WN";
		}
		else if (predictor[i] == "WN")
		{
			predictor[i] = "WT";
		}
		else if (predictor[i] == "WT")
		{
			predictor[i] = "WN";
		}
		else if (predictor[i] == "ST")
		{
			predictor[i] = "WT";
		}
	}
	else
	{
		if (predictor[i] == "WN")
		{
			predictor[i] = "SN";
		}
		else if (predictor[i] == "WT")
		{
			predictor[i] = "ST";
		}
	}
}