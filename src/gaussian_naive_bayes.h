#ifndef ML_GAUSSIAN_NAIVE_BAYES_H
#define ML_GAUSSIAN_NAIVE_BAYES_H

#include <vector>
#include <cassert>
#include <map>
#include "utility.h"
#include "data_point.h"
#include "learned_class.h"

template <class DT, class LT>
class Gaussian_naive_bayes {

typedef Data_point<DT,LT> 		Data;
typedef Learned_class<DT,LT> 	LClass;

private:
	std::vector<LClass>		 	_classes;

public:
	Gaussian_naive_bayes() {}

	void fit(const std::vector<Data>& data) {
		std::map<LT, std::vector<DT> > sep;
		for (int i = 0; i < data.size(); i++) {
			if (sep.find(data[i].get_label()) == sep.end())  { // not found
				std::vector<DT> dv;
				dv.push_back(data[i].get_data());
				sep.insert( std::pair<LT, std::vector<DT> >(data[i].get_label(), dv) );
			} else {
				sep[data[i].get_label()].push_back(data[i].get_data());
			}
		} 

		for (typename std::map<LT, std::vector<DT> >::iterator it = sep.begin(); it != sep.end(); it++) {
			DT mean = average((*it).second);
			DT stdv  = stdev((*it).second);
			_classes.push_back(LClass(mean, stdv, (*it).first));
		}
	}


	LT classify(DT point) {
		LClass cmax = _classes[0];
		DT pmax = proba(point, cmax);
		for (int i = 1; i < _classes.size(); i++) {
			DT pb = proba(point, _classes[i]);
			if (pb > pmax) {
				pmax = pb;
				cmax = _classes[i];
			}
		}
		return cmax.get_label();
	}


};



#endif // ML_GAUSSIAN_NAIVE_BAYES_H