#include <iostream>
using namespace std;

// EREN DUMRUL TARAFINDAN YARATILDI

// Sayı asalsa 1, yoksa 0 döndüren basit fonksiyon
int asal_mi(int sayi) {
    if (sayi < 2) return 0;

    // Program hızlansın diye sayının kareköküne kadar bakıyoruz
    for (int i = 2; i * i <= sayi; i++) {
        if (sayi % i == 0) {
            return 0; // Bölünüyorsa asal değil
        }
    }
    return 1; // Bölünmediyse asaldır
}

int main() {
    // Soruda verilen 10 milyon rota
    int sinir = 10000000;

    cout << "Safe Prime Sayilar hesaplaniyor..." << endl;

    // p sayısı sınırına kadar deniyoruz.
    // q = 2p+1 olduğu için p, sınırın yarısında geçince q sınırı aşar.
    for (int p = 2; p < sinir / 2; p++) {

        // 1. Adım: P sayısı asal mı?
        if (asal_mi(p) == 1) {

            // 2. Adım: Q miktarı hesapla
            int q = (2 * p) + 1;

            // 3. Adım: Q sayısı da asal mı? (Safe Prime kontrolü)
            if (asal_mi(q) == 1) {
                // Burada safe prime buldun, istersen ekrana yazdırabilirsin
                // cout << p << " -> " << q << endl;
            }
        }
    }
    
    return 0;
}
