#include <bits/stdc++.h>

using namespace std;

struct {
        bool operator()(string a, string b) const {
            cout<<"1) "<<a<<endl;
            cout<<"VS"<<endl;
            cout<<"2) "<<b<<endl;
            cout<<"Elije tu nombre favorito ingresando '1' o '2' >>> ";
            char choice;
            cin>>choice;
            return choice=='1' ? true:false; 
        }
} fav;

int main(){
    vector<string> names{};
    string aux;
    ifstream file("names.txt");
    int i=0;
    while(getline(file,aux)){
        //cout<<aux<<endl;
        names.insert(names.begin()+i,aux);
        i++;
    }

    sort(names.begin(),names.end(),fav);

    ofstream outFile("sortedNames.txt",ofstream::trunc);

    cout << "Nombres ordenados:"<<endl;
    for(int i=0; i<names.size();i++){
        cout <<i+1<<"°:\t"<< names[i] << endl;
        outFile << names[i] << endl;
    }

    return 0;
}