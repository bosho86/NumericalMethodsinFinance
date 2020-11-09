/*
 * Solver03.h
 *
 *  Created on: Oct 27, 2020
 *      Author: paulina
 */

#ifndef SOLVER03_H_
#define SOLVER03_H_
#include <iostream>

// function templates
template<typename Function> double SolverByBisect(Function *Fct, double a, double b, double c, double Acc){
double l0 = a;
double r0 = b;
double lnext = l0;
double rnext = (l0 + r0) /2;
double yleft = Fct->Value(lnext) - c;
double ymid = Fct->Value(rnext) - c;
while (rnext - lnext > Acc){
	if((yleft > 0 && ymid > 0)||(yleft < 0 && ymid < 0))
	{l0=ymid, yleft = ymid;}
	else r0 = rnext;
	rnext = (lnext + r0) /2;
	ymid = Fct->Value(rnext) - c;

	}
return rnext;
}

template<typename Function> double SolverByNR(Function *Fct, double xo, double c, double Acc){
	double x0 = xo;
	double xnext = x0 -(Fct->Value(x0)-c)/(Fct->Deriv(x0));
	double error = xnext - x0;
	double error1 = x0 - xnext;
	while (error > Acc || error1 > Acc)
	{
		x0 = xnext;
		std::cout << "x0" << x0 <<std::endl;
		xnext = x0 -((Fct->Value(x0)-c) / (Fct->Deriv(x0)));
	}
	return xnext;

}

#endif /* SOLVER03_H_ */
