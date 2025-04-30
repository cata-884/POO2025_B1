#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<queue>
#include<map>
void htol(std::string& mesaj) {
    for(int i=0; i<mesaj.size(); i++) {
        if(mesaj[i]>='A' && mesaj[i]<='Z') {
            mesaj[i] = mesaj[i]-'A'+'a';
        }
    }
}
std::vector<std::string> cuvinte(std::string& mesaj) {
    std::string cuv_pot;
    std::vector<std::string> res;
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
    bool operator()(std::pair<std::string, int> &str1, std::pair<std::string, int> &str2) {
        if(str1.second == str2.second) return str1.first[0] > str2.first[0];
        return str1.second < str2.second;
    }
};
int main() {
    std::string mesaj;
    std::map<std::string, int> mp;
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, comp> pq;
    std::getline(std::cin, mesaj);
    htol(mesaj);
    std::vector<std::string> cuvint = cuvinte(mesaj);
    for(int i=0; i<cuvint.size(); i++) {
        mp[cuvint[i]]++;
    }
    for(auto it = mp.begin(); it!=mp.end(); it++) {
        pq.push({it->first, it->second});
    }
    while(!pq.empty()) {
        std::cout<<pq.top().first<<" => "<<pq.top().second;
        pq.pop();
        std::cout<<"\n";
    }
    return 0;
}
