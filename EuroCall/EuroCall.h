/*
 * EuroCall.h
 *
 *  Created on: Oct 27, 2020
 *      Author: paulina
 */

#ifndef EUROCALL_H_
#define EUROCALL_H_

class EuroCall{
public:
	double K;
	double T;
	EuroCall(double T_, double K_){
		T=T_;
		K=K_;
	}
	//S0 initial strike price
	double dminus(double S0, double sigma, double r);
	double dplus(double S0, double sigma, double r);
	double PricebyBS(double S0, double sigma, double r);
	double PricebyVega(double S0, double sigma, double r);

};

#endif /* EUROCALL_H_ */
