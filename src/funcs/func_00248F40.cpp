extern "C" void* func_0022E368(int id, int a);
extern "C" char* func_002624F0(void* p);
extern "C" char* func_003364D8(const char* s, const char* sub);
extern "C" char* func_00331A9C(char* dst, const char* src);

extern int D_0038FC78;
extern char D_00390078[];
extern char D_003900A0[];

static inline void CopyWord_00248F40(char* out, char** pp)
{
    while (**pp != ' ') {
        *out++ = **pp;
        (*pp)++;
    }
    *out = 0;
}

struct Obj_00248F40 {
    void GetName(char* out);
};

void Obj_00248F40::GetName(char* out)
{
    char* p = func_002624F0(func_0022E368(D_0038FC78, 0));
    char** pp = &p;
    out[0] = D_003900A0[0];
    if (!func_003364D8(p, D_00390078)) {
        func_00331A9C(out, p);
        return;
    }
    CopyWord_00248F40(out, pp);
}
