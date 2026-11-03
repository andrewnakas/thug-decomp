extern char D_00391DE0[];
extern char D_00391DE8[];
extern char D_00391DF0[];
extern char D_00391DF8[];

extern "C" void* func_00292108(unsigned int v);
extern "C" void* func_00292238(unsigned int v);
extern "C" unsigned int func_00292090(void* p, int i);
extern "C" void func_001E6AC8(void* s, void* q);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E70C0(void* s, unsigned int name, char* v);
extern "C" void func_001E9170(void* arr, int i, void* s);
extern "C" void func_001E7720(void* s, unsigned int name, void* arr);
extern "C" void* func_001E55B8(unsigned int id, int v);
extern "C" void func_001E66C0(void* arr, void* src);
extern "C" void* func_001E9378(void* a, int i);
extern "C" void func_001E7200(void* p, unsigned int key, int v);

struct Obj_002929B0;
extern "C" void func_00294240(Obj_002929B0* o, void* s, int v);
extern "C" char* func_00292708(Obj_002929B0* o);

struct Obj_002929B0 {
    char pad0[4];
    char m4[0x36 - 4];
    char m36[0x4B - 0x36];
    char m4B[0xAF - 0x4B];
    char mAF[0x114 - 0xAF];
    unsigned int m114;
    char pad118[0x2A8 - 0x118];
    void* m2A8;
    int m2AC;
    unsigned int m2B0;
    void Write(void* s);
};

void Obj_002929B0::Write(void* s)
{
    func_001E6AC8(s, func_00292108(m114));
    func_001E6AC8(s, func_00292238(m114));
    func_001E7360(s, 0x02D7E03D, func_00292090(m2A8, 0));
    func_001E7360(s, 0x3494F170, func_00292090(m2A8, 1));
    switch (m114) {
    case 0x54166ACD:
        func_001E7360(s, 0xBA54BD5C, func_00292090(m2A8, 2));
        func_001E7360(s, 0x150A97C2, func_00292090(m2A8, 3));
        func_001E7360(s, 0x84CA8B0A, func_00292090(m2A8, 4));
        func_001E7360(s, 0xB091B445, func_00292090(m2A8, 5));
        func_001E7360(s, 0x008085F0, func_00292090(m2A8, 6));
        break;
    case 0x4EC3CFB5: {
        void* arr = func_001E8DD0(func_00122CF8(16));
        func_001E8E98(arr, 5, 10);
        void* t;
        t = func_001E6978(func_001190D0(8));
        func_001E7360(t, 0x99F6CCBB, func_00292090(m2A8, 2));
        func_001E70C0(t, 0xC4745838, D_00391DE0);
        func_001E9170(arr, 0, t);
        t = func_001E6978(func_001190D0(8));
        func_001E7360(t, 0x99F6CCBB, func_00292090(m2A8, 3));
        func_001E70C0(t, 0xC4745838, D_00391DE8);
        func_001E9170(arr, 1, t);
        t = func_001E6978(func_001190D0(8));
        func_001E7360(t, 0x99F6CCBB, func_00292090(m2A8, 4));
        func_001E70C0(t, 0xC4745838, D_00391DF0);
        func_001E9170(arr, 2, t);
        t = func_001E6978(func_001190D0(8));
        func_001E7360(t, 0x99F6CCBB, func_00292090(m2A8, 5));
        func_001E70C0(t, 0xC4745838, D_00391DF8);
        func_001E9170(arr, 3, t);
        t = func_001E6978(func_001190D0(8));
        func_001E7360(t, 0x99F6CCBB, func_00292090(m2A8, 6));
        func_001E70C0(t, 0xC4745838, D_00391DE8);
        func_001E9170(arr, 4, t);
        func_001E7720(s, 0xB3C7F1B2, arr);
        break;
    }
    }
    func_00294240(this, s, 1);
    if (m4B[0])
        func_001E70C0(s, 0x0C5D7E6B, m4B);
    if (mAF[0]) {
        void* src = func_001E55B8(0x8070C110, 1);
        void* arr = func_001E8DD0(func_00122CF8(16));
        func_001E66C0(arr, src);
        func_001E70C0(func_001E9378(arr, 0), 0xA7AB3B6D, mAF);
        void* e = func_001E9378(arr, 0);
        func_001E7360(e, 0x531E4D28, func_00292090(m2A8, 0));
        func_001E7720(s, 0x27CD32E1, arr);
    }
    func_001E70C0(s, 0xBFECC45B, func_00292708(this));
    if (m4[0])
        func_001E70C0(s, 0x4BC5229D, m4);
    if (m36[0])
        func_001E70C0(s, 0x243B9C3B, m36);
    func_001E7200(s, 0x906B67BA, m2AC);
    func_001E7360(s, 0x81CFF663, m2B0);
    func_001E7360(s, 0, 0x981D3AD0);
}
