#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>
#include <array>
using namespace std;


// 반복자 구간을 인자로 받아 값을 출력하는 함수이다. 
template <class Iter, class Seperator>
void print( Iter b, Iter e, Seperator s )
{
    while (b != e) {
        cout << *b << s;
        ++b;
    }
    cout << endl;
}


default_random_engine dre;

// [프로그램 환경] Release, x64, 프로젝트 속성 C++ 언어: 미리 보기 - 최신 C++ 초안의 기능(/std:c++latest)

std::vector<int>  v { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

class NUM {
private:
    vector<int>::iterator p;
public:
    NUM(int i) {
        p = find(v.begin(), v.end(), i);
    }
    NUM& operator++() {
        ++p;
        return *this;
    }
    auto operator<=>(const NUM& rhs) const = default;
    int& operator*() const {
        return *p;
    }
};

//--------
int main( )
//--------
{
    // "글자들.txt" 파일에는 몇 개인지 모르는 알파벳 소문자와 공백 문자가 기록되어 있다.

    ifstream in{ "글자들.txt" };

    vector<char> v;

    // [문제 1] "글자들.txt"에 저장된 문자 중에서 소문자만을 모두 읽어 벡터 v에 저장하라.  
    // v에 저장된 원소의 수를 화면에 출력하고 답지에도 적어라.            (15, 5)
    // (주의) v는 이미 생성되어있다.
    char c;
    while (in >> c)
        v.push_back(c);

    cout << v.size() << endl;

    // [문제 2] 벡터 v에 저장되어 있는 글자들에서 글자 's' 't' 'l' 이 연속된 경우는  
    // 모두 몇 번인가 출력하고 답지에도 적어라.                           (25, 5)
    // (예) mnqsorhzhybjgbkstlksuuqunebcpoannstljkvdndcyfipievtfwsak
    // 위 글자들에서 's' 't' 'l' 이 연속된 경우는 두 번이다.
    
    string str{ v.begin(), v.end() };
    string toFind{ "stl" };

    int num = 0;
    auto p = str.begin();
    while (true)
    {
        p = search(p, str.end(), toFind.begin(), toFind.end());
        if (p != str.end())
        {
            ++num;
            p = p + 3;
        }
        else
            break;
    }
    
    cout << num << endl;
    
    sort( v.begin( ), v.end( ) );       // v를 오름차순으로 정렬하였다

    array<int, 26> a;

    // [문제 3] 오름차순으로 정렬된 벡터 v에서 각 알파벳의 개수를 array<int, 26> a에 저장하라. 		
    // a[0]에는 'a', a[1]에는 'b' ... , a[25]에는 'z'의 개수가 저장되도록 하라.
    // 각 알파벳의 개수를 화면에 출력하고 'c'의 개수는 답안지에도 적어라.  (25, 5)
    // (주의) O(n) 알고리즘을 사용하면 감점함. 정렬되어 있다는 점을 활용할 것 

    for (int i = 0; i < 26; ++i)
    {
        auto start = lower_bound(v.begin(), v.end(), char(i + 97));
        auto end = upper_bound(v.begin(), v.end(), char(i + 97));
        a[i] = end - start;
        cout << "a[" << i << "] - " << a[i] << endl;
    }

    shuffle( v.begin( ), v.end( ), dre );      // 정렬된 벡터를 섞는다

    print( v.begin( ), v.begin( ) + 10, " - " );        // 10개를 출력해 본다
    cout << endl;

    // print 실행 결과 (예시)
    // a - p - t - v - e - k - k - v - k - i -

    // [문제 4] 다음 문장을 실행하면 화면에 [1, 11)까지 숫자가 출력되도록 필요한 코딩을 하라.   (40)
    // (주의) main() 안의 코드를 수정하지 않고 해결하여야 한다.  

    print( NUM( 1 ), NUM( 11 ), " " );        // 출력 1 2 3 4 5 6 7 8 9 10 
}
