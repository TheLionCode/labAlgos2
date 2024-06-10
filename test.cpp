#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void swap(char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int partition(string& str, int low, int high) {
    char pivot = str[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (str[j] <= pivot) {
            swap(&str[i], &str[j]);
            i++;
        }
    }
    swap(&str[i], &str[high]);
    return i;
}

void quickSort(string& str, int low, int high) {
    if (low < high) {
        int pivot = partition(str, low, high);
        quickSort(str, low, pivot - 1);
        quickSort(str, pivot + 1, high);
    }
}

int main() {
    string num = "[ ]";

    string sex;
    vector<string> nums = {"julian","lol","julian"};


	// quickSort(num, 0, num.size()-1);

	// for(int i = 0; i <= num.size() ; i++)
	// {
	// 	cout << num[i] << " ";
	// }
    // if(num[0] == sex[0]){
    //     cout << "yes";
    // }

    bool jam = ("julian" == nums.back());

    cout << jam << endl;
	
	return 0;
}