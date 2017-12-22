#ifndef ML_UTILITY_H
#define ML_UTILITY_H

#include <vector>
#include <cassert>
#include "data_point.h"
#include "learned_class.h"


template <typename DT>
static DT dot_product(const std::vector<DT>& x, 
					  const std::vector<DT>& y) {
	assert(x.size() == y.size());
	DT res = 0;
	for (int i = 0; i < x.size(); i++) {
		res += x[i]*y[i];
	}
	return res;
} 


template <typename DT>
static DT average(const std::vector<DT>& x) {
	DT sum = 0;
	for (int i = 0; i < x.size(); i++) {
		sum += x[i];
	}
	return (sum/x.size());
}


template <typename DT>
static DT variance(const std::vector<DT>& v) {
	DT avg = average(v);
	DT var = 0;
	for (int i = 0; i < v.size(); i++) {
		var +=  (v[i] - avg) * (v[i] - avg) / v.size();
	}
	return var;
}


template <typename DT>
static DT stdev(const std::vector<DT>& v) {
	return sqrt(variance(v));
}


template <typename DT, typename LT>
static double proba(const DT point,
					const Learned_class<DT, LT>& cl) {
	DT mean = cl.get_mean();
	DT stdev = cl.get_stdev();
	DT fct = (point - mean)/stdev;
	DT pi(3.141592653589793);
	return (1./(stdev*2.*pi))*exp(-(fct*fct)/2.);
}

#endif // ML_UTILITY_H