#ifndef ML_DATA_POINT_H
#define ML_DATA_POINT_H

template <class DT, class LT>
class Data_point {

private:
	typedef DT data_type;
	
	data_type 	_data;
	LT 			_label;

public:
	Data_point() {}

	Data_point(const data_type data, const LT label) :
	_data(data), _label(label)
	{}

	void set_data(const data_type data) {
		_data = data;
	}

	void set_label(const LT label) {
		_label = label;
	}

	data_type get_data() const {
		return _data;
	}

	LT get_label() const {
		return _label;
	}

 
};


// template <typename DT>
// std::ostream& operator<<(std::ostream& os, const DT& obj)
// {
//     os << "[" << obj.first << ", " << obj.second << "]";
//     return os;
// }

template <class DT, class LT>
std::ostream& operator<<(std::ostream& os, const Data_point<DT,LT>& obj)
{
    os << "Class: " << obj.get_label() << ", Data: " << obj.get_data();
    return os;
}


#endif // ML_DATA_POINT_H