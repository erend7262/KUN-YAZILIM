# Auto detect text files and perform LF normalization
* text=auto
#include <iostream>
using namespace std;
//CREATED BY EREN DUMRUL

// Sayı asalsa 1, değilse 0 döndüren basit fonksiyon
int asal_mi(int sayi) {
    if (sayi < 2) return 0;
    
    // Program hızlansın diye sayının kareköküne kadar bakıyoruz
    for (int i = 2; i * i <= sayi; i++) {
        if (sayi % i == 0) {
            return 0; // Bölünüyorsa asal değildir
        }
    }
    return 1; // Bölünmediyse asaldır
}

int main() {
    // Soruda verilen 10 milyon sınırı
    int sinir = 10000000;

    cout << "Safe Prime Sayilar hesaplaniyor..." << endl;

    // p sayısını sınıra kadar deniyoruz.
    // q = 2p+1 olduğu için p, sınırın yarısını geçince q sınırı aşar.
    for (int p = 2; p < sinir / 2; p++) {

        // 1. Adım: p sayısı asal mı?
        if (asal_mi(p) == 1) {
            
            // 2. Adım: q sayısını hesapla
            int q = (2 * p) + 1;

            // 3. Adım: q hem sınırdan küçük mü hem de asal mı?
            if (q <= sinir && asal_mi(q) == 1) {
                cout << p << " -> " << q << endl;
            }
        }
    }

    cout << "Islem bitti Hocam." << endl;
    
    // Pencerenin hemen kapanmaması için bekletme komutu:
    system("pause");

    return 0;
}
