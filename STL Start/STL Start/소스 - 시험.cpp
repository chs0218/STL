#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>
#include <array>
using namespace std;


// �ݺ��� ������ ���ڷ� �޾� ���� ����ϴ� �Լ��̴�. 
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

// [���α׷� ȯ��] Release, x64, ������Ʈ �Ӽ� C++ ���: �̸� ���� - �ֽ� C++ �ʾ��� ���(/std:c++latest)

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
    // "���ڵ�.txt" ���Ͽ��� �� ������ �𸣴� ���ĺ� �ҹ��ڿ� ���� ���ڰ� ��ϵǾ� �ִ�.

    ifstream in{ "���ڵ�.txt" };

    vector<char> v;

    // [���� 1] "���ڵ�.txt"�� ����� ���� �߿��� �ҹ��ڸ��� ��� �о� ���� v�� �����϶�.  
    // v�� ����� ������ ���� ȭ�鿡 ����ϰ� �������� �����.            (15, 5)
    // (����) v�� �̹� �����Ǿ��ִ�.
    char c;
    while (in >> c)
        v.push_back(c);

    cout << v.size() << endl;

    // [���� 2] ���� v�� ����Ǿ� �ִ� ���ڵ鿡�� ���� 's' 't' 'l' �� ���ӵ� ����  
    // ��� �� ���ΰ� ����ϰ� �������� �����.                           (25, 5)
    // (��) mnqsorhzhybjgbkstlksuuqunebcpoannstljkvdndcyfipievtfwsak
    // �� ���ڵ鿡�� 's' 't' 'l' �� ���ӵ� ���� �� ���̴�.
    
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
    
    sort( v.begin( ), v.end( ) );       // v�� ������������ �����Ͽ���

    array<int, 26> a;

    // [���� 3] ������������ ���ĵ� ���� v���� �� ���ĺ��� ������ array<int, 26> a�� �����϶�. 		
    // a[0]���� 'a', a[1]���� 'b' ... , a[25]���� 'z'�� ������ ����ǵ��� �϶�.
    // �� ���ĺ��� ������ ȭ�鿡 ����ϰ� 'c'�� ������ ��������� �����.  (25, 5)
    // (����) O(n) �˰����� ����ϸ� ������. ���ĵǾ� �ִٴ� ���� Ȱ���� �� 

    for (int i = 0; i < 26; ++i)
    {
        auto start = lower_bound(v.begin(), v.end(), char(i + 97));
        auto end = upper_bound(v.begin(), v.end(), char(i + 97));
        a[i] = end - start;
        cout << "a[" << i << "] - " << a[i] << endl;
    }

    shuffle( v.begin( ), v.end( ), dre );      // ���ĵ� ���͸� ���´�

    print( v.begin( ), v.begin( ) + 10, " - " );        // 10���� ����� ����
    cout << endl;

    // print ���� ��� (����)
    // a - p - t - v - e - k - k - v - k - i -

    // [���� 4] ���� ������ �����ϸ� ȭ�鿡 [1, 11)���� ���ڰ� ��µǵ��� �ʿ��� �ڵ��� �϶�.   (40)
    // (����) main() ���� �ڵ带 �������� �ʰ� �ذ��Ͽ��� �Ѵ�.  

    print( NUM( 1 ), NUM( 11 ), " " );        // ��� 1 2 3 4 5 6 7 8 9 10 
}
