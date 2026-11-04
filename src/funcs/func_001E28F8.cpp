struct Req_001E28F8 {
    int m0;
    int m4;
    int m8;
    int m_id;
    int m_a;
    int m_b;
    int m_c;
    int m_d;
};

extern int D_0038E290;
extern int D_0038E294;
extern volatile int D_00394100;
extern int D_00351E08[];
extern Req_001E28F8 D_003F2DE0[];

extern "C" int func_0031C040(int);
extern "C" int func_0031D2E8(int, Req_001E28F8*, int, int, int, int);

void func_001E28F8(int a, int b, int c, int d)
{
    int next = (D_0038E290 + 1) % 10;
    Req_001E28F8* req = &D_003F2DE0[D_0038E290];
    if (D_00351E08[D_0038E290]) {
        while (func_0031C040(D_00351E08[D_0038E290]) >= 0) {
        }
    }
    req->m_a = a;
    req->m_id = D_0038E294++;
    req->m_b = b;
    req->m_c = c;
    req->m_d = d;
    D_00394100 = 0;
    D_00351E08[D_0038E290] = func_0031D2E8(0, req, 0x20, 0, 0, 0);
    D_0038E290 = next;
}
