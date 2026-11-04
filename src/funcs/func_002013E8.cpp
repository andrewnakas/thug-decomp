extern "C" void* func_00200EC0(void* self, void* it);
extern "C" void* func_00200EF8(void* self, void* it);
extern "C" int func_00202778(void* o);
extern "C" int func_001F9570(void* a);
extern char D_00366B58[];

struct It_002013E8 {
    int m0;
    void* cur;
    void* vt;
    It_002013E8() { vt = D_00366B58; cur = 0; }
    ~It_002013E8() { vt = D_00366B58; }
};

struct Mgr_002013E8 {
    int Total();
};

int Mgr_002013E8::Total()
{
    int sum = 0;
    It_002013E8 it;
    char* o = (char*)func_00200EC0(this, &it);
    while (o) {
        if (func_00202778(o)) {
            sum += func_001F9570(o + 0x34FC);
        }
        o = (char*)func_00200EF8(this, &it);
    }
    return sum;
}
