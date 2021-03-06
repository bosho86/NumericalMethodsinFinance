/*
 * EuroCall.cpp
 *
 *  Created on: Oct 30, 2020
 *      Author: paulina
 */
#include "EuroCall.h"
#include <cmath>
#include <vector>

double N(double x){
	double a1 = 0.319381530;
	double a2 = -0.356563782;
	double a3 = 1.781477937;
	double a4 = -1.821255978;
	double a5 = 1.3302744429;
	double gamma = 0.2316419;
	double k = 1.0/(1.0 + gamma*x);
	double term = k * (a1 + a2 + a3 + a4 + a5);

	if (x>=0){
		return 1 -(1/ sqrt(2*M_PI)) * exp(-0.5 * pow(x,2)) * term;
	}
	else return 1 - N(-x);
}

double EuroCall::dplus(double S0, double sigma, double r){
	return (log(S0/K) + r + pow(sigma,2)/T) / (sigma * sqrt(T));
}

double EuroCall::dminus(double S0, double sigma, double r){
  return dplus(S0, sigma, r) - sigma * sqrt(T);
}

double EuroCall::PricebyBS(double S0, double sigma, double r){
	return S0 * N(dplus(S0, sigma, r)) - K * exp(-r*T)*N(dminus(S0, sigma, r));
}

double EuroCall::PricebyVega(double S0, double sigma, double r){
	return (1 / sqrt(2*M_PI)) * S0 * exp(- pow(dplus(S0, sigma, r),2.0)/2.0);
}






