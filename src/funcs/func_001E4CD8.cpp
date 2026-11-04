struct Ent_001E4CD8 {
    unsigned int hash;
    char* str;
};

extern Ent_001E4CD8* D_0038E404;
extern unsigned int D_0038E408;
extern char* D_0038E3FC;
extern "C" int func_00331BB8(const char* s);
extern "C" unsigned int func_001053C8(const char* s, int len);
extern "C" char* func_00331A9C(char* d, const char* s);

extern "C" char* func_001E4CD8(const char* s)
{
    int len = func_00331BB8(s);
    unsigned int h = func_001053C8(s, len);
    Ent_001E4CD8* e = D_0038E404;
    for (unsigned int i = 0; i < D_0038E408; i++, e++) {
        if (e->hash == h) return e->str;
    }
    char* p = D_0038E3FC;
    func_00331A9C(p, s);
    D_0038E3FC = D_0038E3FC + len + 1;
    D_0038E404[D_0038E408].hash = h;
    D_0038E404[D_0038E408].str = p;
    D_0038E408 = D_0038E408 + 1;
    return p;
}
