struct Mgr_00240120 {
    char pad[0x5C];
    void* m_5C;
    int Get(int flag);
};

extern void* D_0038FC78;
extern "C" void* func_0022E358(void* self);
extern "C" unsigned int func_0024F938(void* a);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

int Mgr_00240120::Get(int flag)
{
    unsigned int name;
    if (flag) {
        name = 0x4DA4937B;
    } else {
        name = func_0024F938(func_0022E358(D_0038FC78));
    }
    int v;
    if (!func_001E7DE8(m_5C, name, &v, 0)) {
        v = 1;
    }
    int r = 1;
    switch (v) {
    case 0:
        r = 0;
        break;
    case 1:
        break;
    case 2:
        r = 2;
        break;
    }
    return r;
}
