struct S_0029F8D8 {
    char pad[0x188];
    unsigned int m188;
    int m18C;
    int m190;
};

extern void* D_0038FC78;
extern unsigned int D_00394170;
extern char D_00377D78[];
extern char D_00377D88[];
extern char D_00377DA0[];
extern "C" unsigned int func_0010FC30();
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_001F0D78(char* s);
extern "C" int func_002A39F8(S_0029F8D8* s);
extern "C" void func_001F0370(char* s, int a, int b, int c);

static inline bool Elapsed_0029F8D8(unsigned int ms, unsigned int now, unsigned int start)
{
    return now - start > ms;
}

struct Obj_0029F8D8 {
    char pad[0x20];
    S_0029F8D8* m20;
    void Update();
};

void Obj_0029F8D8::Update()
{
    S_0029F8D8* s = m20;
    void* q = D_0038FC78;
    if (func_0010FC30() - D_00394170 < 2000)
        return;
    if (func_0024F938(func_0022E358(q)) != func_001F0D78(D_00377D78))
        return;
    if (func_002A39F8(s) < 2)
        return;
    if (s->m190)
        return;
    if (Elapsed_0029F8D8(5000, func_0010FC30(), s->m188)) {
        func_001F0370(D_00377D88, 0, 0, 0);
        func_001F0370(D_00377DA0, 0, 0, 0);
        s->m190 = 1;
    }
}
