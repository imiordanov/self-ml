#ifndef ML_LEARNED_CLASS_H
#define ML_LEARNED_CLASS_H

template <class DT, class LT>
class Learned_class {

private:
	typedef 	DT data_type;
	data_type 	_mean;
	data_type 	_stdv;
	LT 			_label;

public:
	Learned_class() :
	_mean(DT(0)), _stdv(DT(0)), _label(LT(0))
	{}

	Learned_class(DT mean, DT stdev, LT lbl) :
	_mean(mean), _stdv(stdev), _label(lbl)
	{}

	void set_mean(const data_type mean) {
		_mean = mean;
	}

	void set_stdev(const data_type stdev) {
		_stdv = stdev;
	}

	void set_label(const LT label) {
		_label = label;
	}

	data_type get_mean() const {
		return _mean;
	}

	data_type get_stdev() const {
		return _stdv;
	}

	LT get_label() const {
		return _label;
	}

 
};


template <class DT, class LT>
std::ostream& operator<<(std::ostream& os, const Learned_class<DT,LT>& obj)
{
    os << "Class: " << obj.get_label() << ", mean: " << obj.get_mean() << ", stdev: " << obj.get_stdev();
    return os;
}


#endif // ML_LEARNED_CLASS_H