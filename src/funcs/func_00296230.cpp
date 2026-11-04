struct Vec_00296230 {
    float x, y, z, w;
};

struct Ctl_00296230 {
    char pad[0x14];
    int m14;
};

struct Board_00296230 {
    int m0;
    char pad4[0x2A3 - 4];
    unsigned char m2A3;
};

struct Obj_00296230;

extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int a, int b);
extern "C" void func_0026FDC8(Ctl_00296230* c);
extern "C" void func_00295AF0(Obj_00296230* o, Vec_00296230* v, float* a, float* b);
extern "C" int func_00294AE0(Board_00296230* b);
extern "C" int func_002960A8(Obj_00296230* o, Vec_00296230* v, int id, int mode, float a);
extern "C" int func_002948A0(Board_00296230* b, Vec_00296230* v, float a, float c);
extern "C" int func_00294B08(Board_00296230* b, Vec_00296230* v, float a, float c);
extern "C" void func_002959D8(Obj_00296230* o);
extern "C" void func_00295EB0(Obj_00296230* o);
extern "C" void func_00295F30(Obj_00296230* o);

struct Obj_00296230 {
    char pad0[0xC];
    void* mC;
    char pad10[0xA5C0 - 0x10];
    Board_00296230* mA5C0;
    char* mA5C4;
    void Update();
};

void Obj_00296230::Update()
{
    if (mA5C0) {
        char* base = mA5C4;
        Ctl_00296230* c = (Ctl_00296230*)(base + 0x1FC);
        char* base2 = base + 0x24;
        if (c->m14) {
            func_0026FDC8(c);
            Vec_00296230 v;
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = 0.0f;
            v.w = 1.0f;
            float a = v.x;
            float b = v.x;
            func_00295AF0(this, &v, &a, &b);
            if ((func_00294AE0(mA5C0) == 2 && func_002960A8(this, &v, mA5C0->m0, 0, a)) ||
                (func_00294AE0(mA5C0) == 1 && func_002960A8(this, &v, mA5C0->m0, 1, a))) {
                func_001F0210(0xAEBC7020, 0, mC, 0, 0);
            } else if (func_002948A0(mA5C0, &v, a, b)) {
                func_001F0210(0x718B071B, 0, mC, 0, 0);
                func_002959D8(this);
                func_00295EB0(this);
            } else {
                func_001F0210(0xAEBC7020, 0, mC, 0, 0);
            }
            if (mA5C0->m2A3) {
                func_001F0210(0x89119628, 0, mC, 0, 0);
            }
        }
        c = (Ctl_00296230*)(base2 + 0x1B4);
        if (c->m14) {
            func_0026FDC8(c);
            Vec_00296230 v;
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = 0.0f;
            v.w = 1.0f;
            float a = v.x;
            float b = v.x;
            func_00295AF0(this, &v, &a, &b);
            if ((func_00294AE0(mA5C0) == 2 && func_002960A8(this, &v, mA5C0->m0, 0, a)) ||
                (func_00294AE0(mA5C0) == 1 && func_002960A8(this, &v, mA5C0->m0, 1, a))) {
                func_001F0210(0xADE100D6, 0, mC, 0, 0);
            } else if (func_00294B08(mA5C0, &v, a, b)) {
                func_001F0210(0xFA275CC5, 0, mC, 0, 0);
                func_002959D8(this);
                func_00295EB0(this);
            } else {
                func_001F0210(0xADE100D6, 0, mC, 0, 0);
            }
        }
    }
    func_00295F30(this);
}
