#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
    //在source中欧你查找target，返回首字母位置，不存在返回-1
    int static strStr(const string source,const string target);

    /*
     * 求给定集合的子集如[1,2,3]的子集有
     * [],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]
     * 由于
     */
    void static subSet(const )

};
int Solution::strStr(const string source,const string target){
    int ret = -1;
    if( source == "" || target == "" ){
        return ret;
    }
    int j = 0;
    for(int i = 0; i < source.length()-target.length()+1; i++){
        for(j = 0; j < target.length(); j++){
            if( source[i+j] != target[j] ) break;
        }
        if( j == target.length() ){
            ret = i;
            break;
        }
    }
    return ret;
}


int main(){
    string str("Hello world! I'm guoyaowen.");
    cout<<"index: "<<Solution::strStr(str,"I'm")<<endl;
    return 0;
}
