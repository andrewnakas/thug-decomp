extern char D_00366B58[];
extern char D_00378408[];
extern void* D_0038EB78;
extern void* D_0038FC78;

struct Heap_002A3EA8 {
    char pad0[0xF4];
    int mF4;
    char pad1[4];
    int mFC;
};
extern Heap_002A3EA8* D_00388A70;

struct Ref_002A3EA8 {
    int m0;
    int m4;
    void* m8;
    Ref_002A3EA8() { m8 = D_00366B58; m4 = 0; }
    ~Ref_002A3EA8() { m8 = D_00366B58; }
};

struct Elem_002A3EA8 {
    char pad[0x164];
    char* m164;
};

struct Sess_002A3EA8 {
    int m0;
    char m4[4];
};

struct Obj_002A3EA8;
extern "C" int func_001FA648(void* g);
extern "C" Sess_002A3EA8* func_0022E3C8(void* g, int a);
extern "C" void* func_001200E0(void* p);
extern "C" int func_00123420(void* f);
extern "C" int func_002A1A38(Obj_002A3EA8* o);
extern "C" Elem_002A3EA8* func_002A56E0(Obj_002A3EA8* o);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" char* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_00122F88(void* f, char* buf, int n);
extern "C" void* func_002A39E0(Obj_002A3EA8* o, int a);
extern "C" int func_00200EC0(void* w, Ref_002A3EA8* r);
extern "C" int func_00202B30(int id);
extern "C" void func_00200B30(void* w, int type, int size, char* buf, char* s, int a, int b, int c);

struct Obj_002A3EA8 {
    bool SendInfo();
};

bool Obj_002A3EA8::SendInfo()
{
    if (func_001FA648(D_0038EB78) == 1) return false;
    bool ok = false;
    void* f = func_001200E0(func_0022E3C8(D_0038FC78, 0)->m4);
    if (f && func_00123420(f)) {
        if (func_002A1A38(this)) {
            ok = true;
            Elem_002A3EA8* e = func_002A56E0(this);
            func_0010A950(D_00388A70, D_00388A70->mFC);
            e->m164 = func_0010A638(D_00388A70, 0x4499, 1, 0);
            func_0010A9B0(D_00388A70);
            e->m164[0] = 0;
            func_00122F88(f, e->m164 + 1, 0x4498);
        } else {
            Ref_002A3EA8 r;
            if (!func_00202B30(func_00200EC0(func_002A39E0(this, 0), &r))) {
                func_0010A950(D_00388A70, D_00388A70->mF4);
                char* buf = func_0010A638(D_00388A70, 0x4498, 1, 0);
                func_0010A9B0(D_00388A70);
                func_00122F88(f, buf, 0x4498);
                func_00200B30(func_002A39E0(this, 0), 0x7E, 0x4498, buf, D_00378408, 9, 0, 0);
                if (buf) func_0010A8D8(D_00388A70, buf);
                ok = true;
            }
        }
    }
    return ok;
}
