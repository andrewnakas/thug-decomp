extern char D_00371C78[];

struct Iter_002AD950 {
    int m0;
    int m4;
    void* m8;
    Iter_002AD950() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002AD950() { m8 = D_00371C78; }
};

struct Msg_002AD950 {
    unsigned char type;
    char pad1[0xB];
    int mC;
    unsigned char m10;
    char pad11[0xF];
};

struct Item_002AD950 {
    char pad0[0x18];
    int m18;
    int m1C;
    char pad20[0x14];
    char m34[0x10];
};

struct Mgr_002AD950;
struct Script_002AD950;
extern "C" int func_001F0D78(char* s);
extern "C" void func_001E7A30(Script_002AD950* s, int name, int type, int v);
extern "C" void func_001E7A68(Script_002AD950* s, int name, int type, int v);
extern "C" void func_001E73C8(Script_002AD950* s, char* name, int v);
extern "C" void func_001F0370(char* s, ...);

struct Script_002AD950 {
    void AddStruct(char* name, int v) { func_001E7A30(this, func_001F0D78(name), 3, v); }
    void AddName(char* name, int crc) { func_001E73C8(this, name, crc); }
};

inline void Print_002AD950(char* fmt, void* a) { func_001F0370(fmt, a, 0, 0); }

extern void* D_0038FC78;
extern char D_00378DD8[];
extern char D_00378E28[];
extern char D_00379020[];
extern char D_00379050[];
extern char D_00379068[];
extern char D_00379078[];
extern char D_00379090[];
extern char D_003790A0[];
extern char D_003790B8[];
extern char D_003790D0[];
extern char D_003790E0[];
extern char D_003790F8[];
extern char D_00379108[];
extern char D_00379118[];
extern char D_00379128[];
extern char D_00379138[];
extern char D_00379148[];
extern char D_00379160[];
extern char D_00379170[];
extern char D_00379188[];
extern char D_00379198[];
extern char D_003791B0[];
extern char D_003791C0[];
extern char D_003791D0[];
extern char D_003791E0[];
extern char D_003791F8[];
extern char D_00379210[];
extern char D_00379228[];
extern char D_00379238[];
extern char D_00379248[];
extern char D_00379258[];
extern char D_00379268[];
extern char D_00392270[];
extern char D_003922B8[];
extern char D_003922C0[];
extern char D_003922C8[];
extern char D_003922D0[];
extern char D_003922D8[];
extern char D_003922E0[];
extern "C" Item_002AD950* func_002A5780(Mgr_002AD950* m);
extern "C" void* func_002A6070(Mgr_002AD950* m);
extern "C" void* func_001190D0(int size);
extern "C" Script_002AD950* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" int func_002A6080(Mgr_002AD950* m, char* name, int v);
extern "C" int func_002A6150(Mgr_002AD950* m, char* name, int v, unsigned int key);
extern "C" void func_00203068(void* p, int key, Script_002AD950* s);
extern "C" Item_002AD950* func_002A53F8(Mgr_002AD950* m, Iter_002AD950* it, int a);
extern "C" Item_002AD950* func_002A5490(Mgr_002AD950* m, Iter_002AD950* it, int a);
extern "C" int func_00336228(char* a, char* b);
extern "C" int func_002B1FE8(Item_002AD950* e);
extern "C" void func_002A5A88(Mgr_002AD950* m, Item_002AD950* e, int v);
extern "C" void func_0022CF98(void* g, int v);
extern "C" void func_002A8630(Mgr_002AD950* m, int a, int b);
extern "C" char* func_001E5548(int v, int a);
extern "C" void* func_00240850();
extern "C" void func_0023D4B0(void* p, int v);
extern "C" void func_001FA800(Msg_002AD950* m);
extern "C" void* func_002A39D8(Mgr_002AD950* m);
extern "C" int func_002B1FC8(Item_002AD950* e);
extern "C" int func_002B3080(Item_002AD950* e);
extern "C" void func_001FF970(void* q, int id, Msg_002AD950* m);
extern "C" void func_001E7200(Script_002AD950* p, unsigned int key, int v);
extern "C" void func_001E7138(Script_002AD950* s, char* name, char* v);
extern "C" void func_002A9728(Script_002AD950* s, int v);

struct Cmd_002AD950 {
    void* m0;
    unsigned char m4;
    char pad5[0x14 - 0x5];
    int m14;
    char pad18[4];
    Mgr_002AD950* m1C;
    int Run();
};

int Cmd_002AD950::Run()
{
    Mgr_002AD950* m = m1C;
    Script_002AD950* s;
    Item_002AD950* e = func_002A5780(m);
    if (!e || e->m1C != m14) return 3;
    switch (m4) {
    case 0x60: {
        int* p = (int*)m0;
        void* prefs = func_002A6070(m);
        int v;
        int t;
        s = func_001E6978(func_001190D0(8));
        v = func_002A6080(m, D_00379050, p[0]);
        s->AddStruct(D_00378E28, v);
        func_001E7A68(s, func_001F0D78(D_00379020), 0xD, p[0]);
        func_00203068(prefs, func_001F0D78(D_00379068), s);
        if (s) func_001E6AE8(s, 3);
        s = func_001E6978(func_001190D0(8));
        v = func_002A6080(m, D_00379078, p[2]);
        s->AddStruct(D_00378E28, v);
        func_001E7A68(s, func_001F0D78(D_00379020), 0xD, p[2]);
        func_00203068(prefs, func_001F0D78(D_00379090), s);
        if (s) func_001E6AE8(s, 3);
        s = func_001E6978(func_001190D0(8));
        {
            v = func_002A6080(m, D_003790A0, p[3]);
            func_002A6150(m, D_003790A0, p[3], 0xCE87E4E3);
            s->AddStruct(D_00378E28, v);
        }
        func_001E7A68(s, func_001F0D78(D_00379020), 0xD, p[3]);
        func_00203068(prefs, func_001F0D78(D_003790B8), s);
        if (s) func_001E6AE8(s, 3);
        s = func_001E6978(func_001190D0(8));
        v = func_002A6080(m, D_003790D0, p[4]);
        s->AddStruct(D_00378E28, v);
        func_001E7A68(s, func_001F0D78(D_00379020), 0xD, p[4]);
        func_00203068(prefs, func_001F0D78(D_003790E0), s);
        if (s) func_001E6AE8(s, 3);
        s = func_001E6978(func_001190D0(8));
        v = func_002A6080(m, D_003790D0, p[5]);
        s->AddStruct(D_00378E28, v);
        func_001E7A68(s, func_001F0D78(D_00379020), 0xD, p[5]);
        func_00203068(prefs, func_001F0D78(D_003790F8), s);
        if (s) func_001E6AE8(s, 3);
        s = func_001E6978(func_001190D0(8));
        v = func_002A6080(m, D_00379108, p[8]);
        s->AddStruct(D_00378E28, v);
        func_001E7A68(s, func_001F0D78(D_00379020), 0xD, p[8]);
        func_00203068(prefs, func_001F0D78(D_00379118), s);
        if (s) func_001E6AE8(s, 3);
        s = func_001E6978(func_001190D0(8));
        v = func_002A6080(m, D_00379128, p[9]);
        s->AddStruct(D_00378E28, v);
        func_001E7A68(s, func_001F0D78(D_00379020), 0xD, p[9]);
        func_00203068(prefs, func_001F0D78(D_00379138), s);
        if (s) func_001E6AE8(s, 3);
        s = func_001E6978(func_001190D0(8));
        {
            v = func_002A6080(m, D_00379148, p[1]);
            t = func_002A6150(m, D_00379148, p[1], 0x906B67BA);
            s->AddStruct(D_00378E28, v);
            func_001E7A68(s, func_001F0D78(D_00379020), 0xD, p[1]);
            func_001E7A68(s, func_001F0D78(D_003922B8), 1, t);
        }
        func_00203068(prefs, func_001F0D78(D_00379160), s);
        if (s) func_001E6AE8(s, 3);
        s = func_001E6978(func_001190D0(8));
        {
            v = func_002A6080(m, D_00379170, p[7]);
            t = func_002A6150(m, D_00379170, p[7], 0xCD66C8AE);
            if (!v) {
                v = func_002A6080(m, D_00379188, p[7]);
                t = func_002A6150(m, D_00379188, p[7], 0xCD66C8AE);
                if (!v) {
                    v = func_002A6080(m, D_00379148, p[7]);
                    t = func_002A6150(m, D_00379148, p[7], 0x906B67BA) * 1000;
                }
            }
            s->AddStruct(D_00378E28, v);
            func_001E7A68(s, func_001F0D78(D_00379020), 0xD, p[7]);
            if (t > 0) func_001E7A68(s, func_001F0D78(D_00392270), 1, t);
        }
        func_00203068(prefs, func_001F0D78(D_00378DD8), s);
        if (s) func_001E6AE8(s, 3);
        func_001F0370(D_00379198, 0, 0, 0);
        return 1;
    }
    case 0x61: {
        signed char* q = (signed char*)m0;
        Iter_002AD950 it;
        int i = 0;
        Item_002AD950* found = 0;
        for (Item_002AD950* x = func_002A53F8(m, &it, 1); x; x = func_002A5490(m, &it, 1), i++) {
            if (q[1] == i) {
                found = func_00336228((char*)q + 2, x->m34) ? 0 : x;
                break;
            }
        }
        if (!found) return 3;
        if (q[0] == 1) {
            int obj = found->m18;
            int r = func_002B1FE8(found);
            func_002A5A88(m, found, 3);
            if (!r) func_0022CF98(D_0038FC78, obj);
        } else {
            int obj = found->m18;
            int r = func_002B1FE8(found);
            func_002A5A88(m, found, 4);
            if (!r) func_0022CF98(D_0038FC78, obj);
        }
        break;
    }
    case 0x62: {
        int* q = (int*)m0;
        s = func_001E6978(func_001190D0(8));
        func_001E7A68(s, func_001F0D78(D_003922C0), 0xD, q[0]);
        s->AddName(D_003791B0, func_001F0D78(D_003791B0));
        s->AddName(D_003791C0, func_001F0D78(D_003791C0));
        func_001F0370(D_003791D0, s, 0, 0);
        if (s) func_001E6AE8(s, 3);
        break;
    }
    case 0x63: {
        int* q = (int*)m0;
        func_002A8630(m, ((signed char*)q)[4], q[0]);
        func_001F0370(D_003791E0, func_001E5548(q[0], 1), 0, 0);
        func_001F0370(D_003791F8, func_001E5548(q[0], 1), 0, 0);
        break;
    }
    case 0x64:
        func_0023D4B0(func_00240850(), *(int*)m0);
        return 1;
    case 0x65: {
        Iter_002AD950 it;
        Msg_002AD950 msg;
        func_001FA800(&msg);
        void* q = func_002A39D8(m);
        func_001F0370(D_00379210, 0, 0, 0);
        msg.type = 0x6A;
        msg.mC = 2;
        msg.m10 = 8;
        for (e = func_002A53F8(m, &it, 1); e; e = func_002A5490(m, &it, 1)) {
            if (!func_002B1FC8(e)) func_001FF970(q, func_002B3080(e), &msg);
        }
        break;
    }
    case 0x66: {
        signed char* q = (signed char*)m0;
        Script_002AD950* a = func_001E6978(func_001190D0(8));
        func_001E7200(a, 0, q[0]);
        s = func_001E6978(func_001190D0(8));
        switch (q[0]) {
        case 0:
            func_001E7138(s, D_00378E28, D_003922C8);
            func_001E73C8(s, D_00379020, func_001F0D78(D_00379228));
            break;
        case 2:
            func_001E7138(s, D_00378E28, D_003922D0);
            func_001E73C8(s, D_00379020, func_001F0D78(D_00379238));
            break;
        case 3:
            func_001E7138(s, D_00378E28, D_003922D8);
            func_001E73C8(s, D_00379020, func_001F0D78(D_00379248));
            break;
        case 4:
            func_001E7138(s, D_00378E28, D_003922E0);
            func_001E73C8(s, D_00379020, func_001F0D78(D_00379258));
            break;
        }
        func_00203068(func_002A6070(m), func_001F0D78(D_00379268), s);
        if (s) func_001E6AE8(s, 3);
        func_002A9728(a, 0);
        if (a) func_001E6AE8(a, 3);
        break;
    }
    }
    return 1;
}
