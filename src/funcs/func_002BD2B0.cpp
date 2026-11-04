struct Pkt_002BD2B0 {
    char pad0[6];
    unsigned short m6;
    char pad8[0x1C - 8];
    char m1C[0x20];
};

struct Obj_002BD2B0 {
    char pad0[0x6A60];
    Pkt_002BD2B0* m6A60;
    int m6A64;
    char m6A68[0x20];
};

extern "C" char* func_00331A9C(char* dst, const char* src);

extern "C" void func_002BD2B0(Obj_002BD2B0* o, char* name)
{
    Pkt_002BD2B0* p = o->m6A60;
    if (p && p->m6 == 0x4E24) {
        func_00331A9C(p->m1C, name);
        func_00331A9C(o->m6A68, name);
    }
}
