// ------------------------------------
// Date:2018/ 1/28
//
// ------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

class Convert {
public:
  map<string,int> bwt(string str)
  {
    map<string,int> dic;
    int size,ans;
    string mS,mString;
    vector<string> shiftStr;
    size = str.size();

    // 巡回シフトした文字列をvector<string> shiftStrに格納
    REP(i,size) {
      mS = str;
      mString = str.substr(0,i);
      mS.erase(0,i);
      mS += mString;
      shiftStr.push_back(mS);
    }
    mS.clear();
    sort(shiftStr.begin(),shiftStr.end());

    REP(i,size) {
      //cout << i << ":" << shiftStr[i] << endl;
      if (str==shiftStr[i]) ans = i+1;
      mS += shiftStr[i][size-1];
    }
    dic[mS] = ans;
    return dic;
  }
  
  vector<int> mtf(string str,string bwt)
  {
    int size,mSize;
    string mStr,mS;
    vector<int> ans;
    mStr = str;
    size = str.size();

    // MTFのためのリストを作成
    sort(mStr.begin(),mStr.end());
    mStr.erase(unique(mStr.begin(),mStr.end()),mStr.end());
    mSize = mStr.size();
    //cout << mStr << endl;
    
    REP(i,size) {
      REP(j,mSize) {
	if (bwt[i]==mStr[j]) {
	  ans.push_back(j+1);

	  // 出力されたアルファベットを先頭に移動
	  mS = mStr.substr(0,j);
	  //cout << "first:" << mStr << endl;
	  mStr[0] = mStr[j];
	  //cout << "second:" << mStr << endl;
	  mStr.replace(1,j,mS);
	  //cout << j << ":if:" << mStr << endl;
	}
      }
    }
    return ans;
  }
};

int main()
{
  Convert c;
  vector<int> ans;
  string mStr,str,sBwt;
  map<string,int> dic;
  while(cin >> mStr) {
    if (mStr==".") {
      str.pop_back();
      break;
    }
    str += mStr;
    str += " ";
  }
  dic = c.bwt(str);
  cout << "↓BTF"<< endl;
  for (auto d : dic) {
    sBwt = d.first;
    cout << d.first << " " << d.second << endl;
  }
  ans = c.mtf(str,sBwt);
  cout << "↓MTF"<< endl;
  for (auto i : ans) {
    cout << i;
  }
  cout << endl;
  return 0;
}

