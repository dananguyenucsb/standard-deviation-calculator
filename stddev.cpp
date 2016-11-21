#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <math.h>

//precondition: list is a reference to a vector of doubles
//postcondition: List is unchanged. I never modified it.
double average(double array[]);
double stddev(std::vector<double>& list);

//computes the average of the numbers in the list vector
double average(std::vector<double>& list) {
	double sum = 0;
	for (double val : list) {
		sum += val;
	}
	return sum / (double) list.size();
}

//computes the standard deviation of the numbers in the list vector
double stddev(std::vector<double>& list) {
	double avg = average(list);
	double numerator = 0;
	for (double x : list) {
		numerator += (x - avg) * (x - avg);
	}
	double res = numerator / (double) (list.size() - 1);
	return res;
}



int main(){
	using namespace std;
	char in_file_name[100];
	ifstream fin;

	//using vectors to store the numbers into num for computing the averages and standard deviations
	vector<double> num;
	double next = 0;

	cout << "Enter filename:" << endl;
	cin >> in_file_name;
	fin.open(in_file_name);

	while (fin >> next){
		num.push_back(next);
	}

	double stddevRes = stddev(num);

	double stdd = 0;
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(3);

	cout << "The standard deviation is " << sqrt(stddevRes) << endl;

	fin.close();
	return 0;
}


