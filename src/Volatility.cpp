/*
 * Volatility.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: paulina
 */


#include "EuroCall.h"
#include "Solver03.h"
#include <iostream>

class function_sigma : public EuroCall{
private:
	double S0; //Stock price
	double r; //interest rate
public:
	function_sigma(double S0_, double r_, double T_, double K_) : EuroCall(T_,K_){
		S0 = S0_;
		r = r_;
	}
double Value(double sigma){
	return PricebyBS(S0, sigma, r);
}
double Deriv(double sigma){
	return PricebyBS(S0, sigma, r);
}

};

int main(){
	double S0 =100.0; //price at strike T0
	double r = 0.1; // simple interest rate
	double T = 1.0; // period
	double K = 100.0; // price at which you sell??
	function_sigma Call(S0, r, T, K);// initialize the object

	double Acc = 0.001;//acuraccy;
	double a = 0.01;
	double b = 1.0;
	double c= 12.56;

	std::cout<<"Implied volatity by bisect method: "
			<< SolverByBisect(&Call, c, a, b, Acc)<< std::endl;

	double x0 = 0.23;
	std::cout<<"Implied volatility by Newton Rapson:"
			<< SolverByNR(&Call, x0, c, Acc) << std::endl;

}
