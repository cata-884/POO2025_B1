#include <iostream>

using namespace std;

void afiseaza_triplete(int n) {
    bool exista_triplete = false;

    for (int x = 1; x < n - 2; x++) {
        for (int y = x + 1; y < n - 1; y++) {
            int z = n - x - y;
            if (z > y && x + y + z == n && n % x == 0 && n % y == 0 && n % z == 0) {
                cout << x << " " << y << " " << z << endl;
                exista_triplete = true;
            }
        }
    }

    if (!exista_triplete) {
        cout << "nu exista" << endl;
    }
}
int main() {
    int n;
    cout << "Introduceti un numar natural n: ";
    cin >> n;
    afiseaza_triplete(n);
    return 0;
}
//edit pentru ca cum drq ar trebui sa stiu asta
/*
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%6==0) cout<<n/6<<" "<<n/3<<" "<<n/2;
    else cout<<"nu exista";
    return 0;
}
*/
