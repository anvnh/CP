#include <bits/stdc++.h>
using namespace std;
class nv{
    public:
        char *hoten;
        char *quequan;
        int thamnien;
        float heso;
        static float luongcoban;
        nv(){
            hoten = nullptr;
            quequan = nullptr;
            thamnien = 0;
            heso = 0.0f;
        }
        ~ nv(){
            delete[] hoten;
            delete[] quequan;
        }
        void nv :: nhap()
        {
            cin >> hoten >> quequan >> thamnien >> heso >> luongcoban;
        }
        void nv :: xuat()
        {
            cout << hoten << " " << quequan << " " << thamnien << " " << heso << " " << luongcoban;
        }
};
class nvkythuat{
    public:
        nvkythuat(){
            thunhap = phucap = 0.0f;
            cadem = 0;
            hesocadem = 0.0f;
            phong = nullptr;
        }
        ~ nvkythuat(){
            delete[] phong;
        }
        void nvkythuat :: nhap()
        {
            cin >> phucap >> cadem >> hesocadem >> phong;
        }
        void nvkythuat:: xuat()
        {
            cout << thunhap << " " << phucap << " " << cadem << " " << hesocadem << " " << phong;
        }
        void nvkythuat :: tinhthunhap()
        {
            thunhap = (nv().luongcoban + phucap) * nv().heso + cadem * hesocadem;
        }
    private:
        float thunhap, phucap;
        int cadem;
        float hesocadem;
        char *phong;
};
int main()
{
}