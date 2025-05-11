#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<queue>
#include<map>
using namespace std;
void htol(string& mesaj) {
    for(int i=0; i<mesaj.size(); i++) {
        if(mesaj[i]>='A' && mesaj[i]<='Z') {
            mesaj[i] = mesaj[i]-'A'+'a';
        }
    }
}
vector<string> cuvinte(string& mesaj) {
    string cuv_pot;
    vector<string> res;
    for(int i=0; i<mesaj.size(); i++) {
        while(mesaj[i] == ' ' && i<mesaj.size() && i+1<mesaj.size() && mesaj[i+1] == ' ') i++;
        if(mesaj[i] == ',' || mesaj[i] == '.' || mesaj[i] == '?' || mesaj[i] == '!' || mesaj[i] == ' ') {
            if(!cuv_pot.empty()) {
                res.push_back(cuv_pot);
                cuv_pot = "";
            }
            continue;
        }
        cuv_pot += mesaj[i];
    }
    if(!cuv_pot.empty()) {
        res.push_back(cuv_pot);
    }
    return res;
}
struct comp {
    bool operator()(pair<string, int> &str1, pair<string, int> &str2) {
        if(str1.second == str2.second) return str1.first[0] > str2.first[0];
        return str1.second < str2.second;
    }
};
int main() {
    string mesaj;
    map<string, int> mp;
    priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq;
    getline(cin, mesaj);
    htol(mesaj);
    vector<string> cuvint = cuvinte(mesaj);
    for(int i=0; i<cuvint.size(); i++) {
        mp[cuvint[i]]++;
    }
    for(auto it = mp.begin(); it!=mp.end(); it++) {
        pq.push({it->first, it->second});
    }
    while(!pq.empty()) {
        cout<<pq.top().first<<" => "<<pq.top().second;
        pq.pop();
        cout<<"\n";
    }
    return 0;
}
