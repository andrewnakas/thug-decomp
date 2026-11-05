extern void* D_0038FC78;
extern "C" int func_00100030(int n);
extern "C" int func_0022CBF8(void* g, int r);

struct Base_00203DF0 {
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void Play(int id, int a);
};

struct Obj_00203DF0 : Base_00203DF0 {
    char m_pad[0x228];
    int m234;
    void PlayRandom();
};

void Obj_00203DF0::PlayRandom()
{
    int tries = 0;
    void* g = D_0038FC78;
    int id;
    do {
        tries++;
        id = func_0022CBF8(g, func_00100030(8));
    } while (id == m234 && tries < 20);
    m234 = id;
    if (id != -1)
        Play(id, 0);
}
