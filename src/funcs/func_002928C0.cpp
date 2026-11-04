struct Entry_002928C0 {
    int m0;
    char pad[0xC];
    struct { struct { float x, y, z, w; } pos; float h; char pad2[0xC]; } s;
};
struct Struct_002928C0 { char pad[0x10]; };
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E73C8(void* p, char* s, int v);
extern "C" void func_001E74C0(void* p, char* s, float x, float y, float z);
extern "C" void func_001F0210(unsigned int, void*, int, int, int);
extern char D_00391DD0[];
extern char D_00391DD8[];

struct Obj_002928C0;
extern "C" void func_00292770(Obj_002928C0*, int);
extern "C" int func_00292EC8(Obj_002928C0*, int);

struct Obj_002928C0 {
    char pad0[0x120];
    Entry_002928C0 m120[8];
    char pad2A0;
    unsigned char m2A1;
    void Refresh();
};

void Obj_002928C0::Refresh()
{
    for (int i = 0; i < m2A1; i++) {
        func_00292770(this, i);
        Struct_002928C0 s;
        func_001E6978(&s);
        func_001E73C8(&s, D_00391DD0, func_00292EC8(this, i));
        float* f = &m120[i].s.pos.x;
        func_001E74C0(&s, D_00391DD8, f[0], f[1] + f[4], f[2]);
        func_001F0210(0x79582240, &s, 0, 0, 0);
        func_001E6AE8(&s, 2);
    }
}
