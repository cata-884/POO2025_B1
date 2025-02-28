#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
bool esteVocala(char c){
    string vocale="aeiouăîâAEIOUĂÎÂ";
    for(int i=0;i<vocale.length();i++){
        if(c==vocale[i])return true;
    }
    return false;
}
bool esteConsoana(char c){
    return !esteVocala(c);
}
bool esteGrupSpecial(string& cuvant,int poz){
    if(poz+1<cuvant.length()){
        string grup=cuvant.substr(poz,3);
        return(grup=="ce"||grup=="ci"||grup=="ge"||grup=="gi"||
               grup=="che"||grup=="chi"||grup=="ghe"||grup=="ghi");
    }
    return false;
}
bool esteGrupConsonanticSpecial(string& cuvant,int poz){
    bool condition=false;
    if(poz+1<cuvant.length()){
        char prima=cuvant[poz];
        char aDoua=cuvant[poz+1];
        string speciale="bcdgfhptv";
        for(int i=0;i<speciale.size();i++){
            if(prima==speciale[i])condition=true;
        }
        return(condition&&(aDoua=='p'||aDoua=='r'));
    }
}

string desparteSilabe(string& cuvant){
    string rezultat;
    int lungime=cuvant.length();
    for(int i=0;i<lungime;i++){
        rezultat+=cuvant[i];
        if(esteVocala(cuvant[i])&&esteConsoana(cuvant[i+1])&&i+2<lungime&&esteVocala(cuvant[i+2])){
            if(!esteGrupSpecial(cuvant,i+1)){
                rezultat+='-';
            }
        }
        if(i+2<lungime&&esteVocala(cuvant[i])&&esteConsoana(cuvant[i+1])&&esteConsoana(cuvant[i+2])&&i+3<lungime&&esteVocala(cuvant[i+3])){
            if(esteGrupConsonanticSpecial(cuvant,i+1)){
                rezultat+='-';
                i++;
            }else{
                rezultat+='-';
                rezultat+=cuvant[i+1];
                i++;
            }
        }
        if(i+3<lungime&&esteVocala(cuvant[i])&&esteConsoana(cuvant[i+1])&&esteConsoana(cuvant[i+2])&&esteConsoana(cuvant[i+3])){
            rezultat+='-';
            rezultat+=cuvant[i+1];
            i+=2;
        }
        if(i+1<lungime&&esteVocala(cuvant[i])&&esteVocala(cuvant[i+1])){
            rezultat+='-';
        }
    }
    return rezultat;
}

int main(){
    string cuvant;
    cin>>cuvant;
    string cuvantSilabe=desparteSilabe(cuvant);
    cout<<cuvantSilabe<<endl;
    return 0;
}

