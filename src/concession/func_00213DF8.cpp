/* force: {"kind": "sched", "pass": 2, "block": 21, "clock": 1, "first": 137} */
struct Obj_00213DF8;
struct Msg_00213DF8 {
    int m0;
    int m4;
    int m8;
    int mC;

};
struct Arg_00213DF8 {
    Obj_00213DF8* m0;
    Msg_00213DF8 m4;
};

extern void* D_0038FC78;
extern "C" void func_00213C50(Msg_00213DF8* m, int a, int b);
extern "C" void* func_001E55B8(unsigned int name, int n);
extern "C" void* func_001E9378(void* a, Obj_00213DF8* self);
extern "C" int func_0022EEC0(void* g, void* s);
extern "C" int func_001E8398(void* s, unsigned int name, unsigned int* out, int req);
extern "C" void* func_0022E040(void* g);
extern "C" void func_00187900(void* list, void* cb, Arg_00213DF8* a);
extern "C" void func_00213B60();
extern "C" void* func_00131E48();
extern "C" void* func_00132FD0(void* p, unsigned int id);
extern "C" unsigned int func_00135020(void* o);
extern "C" void func_00134FD8(void* o, unsigned int v);

struct Obj_00213DF8 {
    int m0;
    int Run(int on, int flag);
};

int Obj_00213DF8::Run(int on, int flag)
{
    void* g = D_0038FC78;
    void* s = func_001E9378(func_001E55B8(0xC472ECC5, 0), this);
    if (func_0022EEC0(g, s)) return 1;
    unsigned int type = 0;
    func_001E8398(s, 0x12B4E660, &type, 0);
    switch (type) {
    case 0x9E7D469E:
    case 0x061A741E:
    case 0x19B1E241:
    case 0x5B8AB877:
    case 0xA0DFAC98:
    case 0xE47F1B79:
    case 0xEF59C100: {
        Arg_00213DF8 a;
        a.m0 = this;
        if (on) {
            func_00213C50(&a.m4, 4, 3);
        } else {
            func_00213C50(&a.m4, 4, 4);
        }
        a.m0 = this;
        func_00187900(func_0022E040(g), (void*)func_00213B60, &a);
        return 1;
    }
    case 0xBF4D3536:
    case 0xB7B3BD86: {
        unsigned int id = 0;
        if (!func_001E8398(s, 0xA1DC81F9, &id, 0)) return 1;
        void* o = func_00132FD0(func_00131E48(), id);
        unsigned int m = func_00135020(o);
        unsigned int bit = flag == 1 ? 2 : 1;
        if (on) {
            func_00134FD8(o, m & ~bit);
        } else {
            func_00134FD8(o, m | bit);
        }
        return 1;
    }
    case 0x30C19600:
        return 0;
    case 0x60000000:
        break;
    }
    return 0;
}
