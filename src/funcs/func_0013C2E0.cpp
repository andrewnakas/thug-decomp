extern "C" int func_001E5648(char* name, int a);
extern char D_0035E7B0[];

struct Res_0013C2E0 {
    int m0;
    int m4;
    void* m8;
    int mC;
};

class Mgr_0013C2E0 {
public:
    int m0;
    int m4;
    void* m8;
    int mC;
    int m10;
    virtual ~Mgr_0013C2E0();
    virtual Res_0013C2E0* V1(int a, int b);
    Res_0013C2E0* Create(int a, int b);
};

Res_0013C2E0* Mgr_0013C2E0::Create(int a, int b)
{
    if (func_001E5648(D_0035E7B0, 0))
        a = 1;
    Res_0013C2E0* r = V1(a, b);
    if (r) {
        r->m4 = a ? 1 : 2;
        if (m8)
            r->m8 = m8;
        r->mC = 0;
    }
    return r;
}
