typedef int qword __attribute__((mode(TI)));

union Vec_00294B08 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Node_00294B08 {
    Vec_00294B08 pos;
    float a;
    float b;
    char pad18[0x30 - 0x18];
};

struct Obj_00294B08;
extern "C" int func_002932E8(Obj_00294B08* o, Vec_00294B08* p, float a);
extern "C" void func_00292F40(Obj_00294B08* o, int i);
extern "C" void func_00293108(Obj_00294B08* o, int i);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" void func_001F0210(unsigned int, void*, int, int, int);
extern "C" void func_001E6AE8(void* p, int v);

struct Obj_00294B08 {
    char pad0[0x130];
    Node_00294B08 m130[7];
    char pad[0x2A1 - 0x130 - 0x30 * 7];
    unsigned char m2A1;
    unsigned char m2A2;
    bool Place(Vec_00294B08* pos, float a, float b);
};

bool Obj_00294B08::Place(Vec_00294B08* pos, float a, float b)
{
    if (!m2A2) return false;
    if (!func_002932E8(this, pos, a)) return false;
    m130[m2A2].pos = *pos;
    m130[m2A2].a = a;
    m130[m2A2].b = b;
    func_00292F40(this, m2A2);
    if (m2A2 == m2A1) m2A1++;
    m2A2--;
    func_00293108(this, m2A2);
    if (m2A2) return true;
    void* s = func_001E6978(func_001190D0(8));
    func_001E7360(s, 0, 0x7F1538E0);
    func_001F0210(0xD066A889, s, 0, 0, 0);
    if (s) func_001E6AE8(s, 3);
    return true;
}
