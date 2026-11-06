extern char D_0037AE00[];
extern char D_0037AE20[];
extern char D_0037AE48[];
struct Obj_002C4BC0;
extern "C" void func_002BA9E0();
extern "C" void func_00187DC8(void* p, int v);
extern "C" void func_00182A10(Obj_002C4BC0* o, void* a);

struct Obj_002C4BC0 {
    char pad[0x14];
    void* m14;
    char m18[0x30 - 0x18];
    void* m30;
    char pad34[0x84 - 0x34];
    void* m84;
    void Init(void* a);
};

void Obj_002C4BC0::Init(void* a)
{
    m30 = D_0037AE00;
    m14 = D_0037AE20;
    m84 = D_0037AE48;
    func_002BA9E0();
    func_00187DC8(m18, 0);
    func_00182A10(this, a);
}
