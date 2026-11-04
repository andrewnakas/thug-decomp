extern char D_00371C78[];

struct Iter_002A6DA8 {
    int m0;
    int m4;
    void* m8;
    Iter_002A6DA8() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A6DA8() { m8 = D_00371C78; }
};

struct Pkt_002A6DA8 {
    unsigned char m0;
    char name[0x10];
    unsigned char m11;
    char pad12[2];
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
};

struct Skater_002A6DA8 {
    char pad0[0x18];
    void* m18;
    int m1C;
    char pad20[0x28 - 0x20];
    int m28;
    int m2C;
    char pad30[0x34 - 0x30];
    char name[0x10];
    char pad44[0x44 - 0x44];
    int m44;
    int m48;
    char pad4C[0x14C - 0x4C];
    int m14C;
};

struct Heap_002A6DA8 {
    char pad[0x3EC];
    int m3EC;
};

extern Heap_002A6DA8* D_00388A70;

struct Obj_002A6DA8 {
    void Run();
};

extern "C" Skater_002A6DA8* func_002A53F8(Obj_002A6DA8* self, Iter_002A6DA8* it, int a);
extern "C" Skater_002A6DA8* func_002A5490(Obj_002A6DA8* self, Iter_002A6DA8* it, int a);
extern "C" void func_002B3100(Pkt_002A6DA8* p);
extern "C" void func_002B3168(Pkt_002A6DA8* p, int f);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_002A50D8(Obj_002A6DA8* o);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_002610C0(int a, int b);
extern "C" void func_002A47D8(Obj_002A6DA8* o, Skater_002A6DA8* s);
extern "C" void func_002A44C0(Obj_002A6DA8* o, Pkt_002A6DA8* p, int delay);
extern "C" int func_002B1FC8(Skater_002A6DA8* s);
extern "C" void func_00206968(void* p);
extern "C" void func_00206920(void* p);

void Obj_002A6DA8::Run()
{
    Iter_002A6DA8 it;
    Skater_002A6DA8* p = func_002A53F8(this, &it, 1);
    int n = 1;
    if (p) {
    do {
        Skater_002A6DA8* next = func_002A5490(this, &it, 1);
        if (p->m14C & 8) {
            Pkt_002A6DA8 pkt;
            n++;
            func_002B3100(&pkt);
            func_00331A9C(pkt.name, p->name);
            pkt.m11 = func_002A50D8(this);
            pkt.m14 = p->m1C;
            pkt.m20 = 0x10;
            pkt.m2C = p->m28;
            pkt.m30 = p->m2C;
            pkt.m38 = p->m44;
            func_0010A950(D_00388A70, D_00388A70->m3EC);
            func_002610C0(pkt.m1C, p->m48);
            func_0010A9B0(D_00388A70);
            func_002A47D8(this, p);
            func_002A44C0(this, &pkt, n * 10);
            func_002B3168(&pkt, 2);
        }
        p = next;
    } while (p);
    }
    for (p = func_002A53F8(this, &it, 0); p; p = func_002A5490(this, &it, 0)) {
        if (!func_002B1FC8(p)) {
            func_00206968(p->m18);
            func_00206920(p->m18);
        }
    }
}
