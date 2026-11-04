extern char D_0037AF18[];
extern char D_00392950[];

struct Player_002CC668 {
    int m0;
    int m4[2];
    char padC[0x1C - 0xC];
    char m1C[0xE0 - 0x1C];
    int mE0;
    char padE4[0xEC - 0xE4];
    int mEC;
};

struct Comp_002CC668 {
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual void Send(int crc, void* s, void* o);
};

struct Obj2_002CC668 {
    char pad[0xBC];
    Comp_002CC668* mBC;
};

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* s, unsigned int name, int v);
extern "C" void func_001E7200(void* p, unsigned int key, int v);
extern "C" void func_001E70C0(void* s, unsigned int name, char* v);
extern "C" int func_001E53A0(unsigned int a, int b);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001E6AE8(void* p, int v);

struct Obj_002CC668 {
    int m0;
    Player_002CC668* m4[0x20];
    int m84[2];
    void Report(int side, Obj2_002CC668* o);
};

void Obj_002CC668::Report(int side, Obj2_002CC668* o)
{
    for (int i = 0; i < 2; i++) {
        int k = i;
        if (!m84[side])
            k = 1 - i;
        void* s = func_001E6978(func_001190D0(8));
        func_001E7360(s, 0x3B442E26, m4[side]->m4[k]);
        func_001E7200(s, 0xCD66C8AE, m4[side]->mE0);
        func_001E70C0(s, 0xC4745838, m4[side]->m1C);
        if (i == 0) {
            int v = m4[side]->mEC;
            if (!v)
                v = func_001E53A0(0x9A27E74D, 0);
            func_001E7360(s, 0x2760DE9E, v);
            o->mBC->Send(func_001F0D78(D_0037AF18), s, o);
        } else {
            o->mBC->Send(func_001F0D78(D_00392950), s, o);
        }
        if (s)
            func_001E6AE8(s, 3);
    }
}
