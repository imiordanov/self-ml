
#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include "src/utility.h"
#include "src/data_point.h"
#include "src/gaussian_naive_bayes.h"

using namespace std;

#define SAMPLE_SIZE 10000
#define TEST_SIZE   100
#define N_CLASSES   500

typedef double 			NT;
typedef unsigned int 	Label;

typedef Data_point<NT, Label>  	Point;


int main(void) {
	std::vector<Point> sample;	
	std::vector<Point> test;	
	srand(time(NULL));

	std::default_random_engine generator;

	for (Label cl = 0; cl < N_CLASSES; cl++) {
		std::normal_distribution<NT> distribution(cl, 1./(1.+cl));
		for (int i = 0; i < SAMPLE_SIZE; i++) {
			NT xc = distribution(generator);
			sample.push_back( Point( xc, cl ) );
		}	
		for (int i = 0; i < TEST_SIZE; i++) {
			NT xc = distribution(generator);
			test.push_back( Point( xc, cl ) );
		}	
	}

	cout << "Sample size: " << sample.size() << endl;
	cout << "Test size:   " << test.size()   << endl;

	Gaussian_naive_bayes<NT, Label> Gauss;
	Gauss.fit(sample);

	double correct = 0.;
	for (int i = 0; i < test.size(); i++) {
		if (Gauss.classify(test[i].get_data()) == test[i].get_label()) {
			correct++;
		}
	}
	double perc = correct/test.size()*100;
	cout << "Testing completed! Correct matches: " << perc << "%" << endl;

}