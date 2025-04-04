#include <string>
#include <vector>

using namespace std;

string nearestPalindromic(string num) {
    size_t szNum = size(num);
    bool isEven = szNum % 2  == 0;
    int firstHalflen = isEven ? szNum/2 : szNum/2 + 1;
    long firstHalf = stol(num.substr(0, firstHalflen));

    //1. Add candidates

    vector<long> candidates; //Eg: 12345;  fH  = 123
    candidates.emplace_back(getPalindrome(firstHalf + 1, isEven)); //12421
    candidates.emplace_back(getPalindrome(firstHalf, isEven)); //12321
    candidates.emplace_back(getPalindrome(firstHalf - 1, isEven)); //12221
    candidates.emplace_back(pow(10, szNum) + 1); //100001
    candidates.emplace_back(pow(10, szNum)- 1); //9999

    //2. Find minDiff
    long minDiff = numeric_limits<long>::max(), longNum = stol(num);
    long minResult;

    for (auto candidate : candidates) {
        if (candidate == longNum) continue;
        
      if ( abs(longNum - candidate) < minDiff) {
        minDiff = abs(longNum - candidate);
        minResult = candidate;
        } else if (abs(longNum - candidate) == minDiff) {
            minResult = min(minResult, candidate);
        }
    }

    return to_string(minResult);

}

long getPalindrome(long left, bool isEven) {

    long result = left;

    if (isEven == false) { //Eg  left = 123, return  12321 
       left /= 10;
    }

    while (left) {
        result = result * 10 + left % 10;
        left /= 10;
    }
    
    return result;
}
