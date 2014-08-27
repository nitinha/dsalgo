#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main(){
    int num;
    cin >> num;

    vector <int> num_arr_rev = vector<int>();
    int temp_num = num;
    while(temp_num > 0){
        num_arr_rev.push_back(temp_num % 10);
        temp_num /= 10;
    }

    vector <int> num_arr = vector<int>();
    for (vector<int>::reverse_iterator it = num_arr_rev.rbegin() ; it != num_arr_rev.rend(); ++it)
        num_arr.push_back(*it);

    int larger_num_index = num_arr.size() - 1;
    int smaller_num_index = num_arr.size() - 2;

    for(int i = num_arr.size() - 1; i > 0; i-= 1){
        if(num_arr[i] > num_arr[i - 1]){
            larger_num_index = i - 1;
            smaller_num_index = i;
        }
        else{
            larger_num_index = i;
            smaller_num_index = i - 1;
        }


        if(larger_num_index < smaller_num_index)
            break;
    }

    if(larger_num_index < smaller_num_index){
        int temp = num_arr[smaller_num_index];
        num_arr[smaller_num_index] = num_arr[larger_num_index];
        num_arr[larger_num_index] = temp;
    }

    int larger_num = 0;
    int num_len = 0;
    while(num_len < num_arr.size()){
            larger_num = larger_num*10 + num_arr[num_len];
            num_len += 1;
    }

    cout << "larger_number = " << larger_num << endl;
    return 0;
}
