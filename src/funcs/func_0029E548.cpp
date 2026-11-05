extern unsigned int D_00377740[];
extern "C" void func_001E7360(void* p, unsigned int key, unsigned int v);
extern "C" void func_001E72B0(void* p, unsigned int key, float v);
extern "C" void func_00184EB0(void* o, void* p);

struct Obj_0029E548 {
    char pad0[0x1C];
    int m1C;
    float m20;
    void Save(void* p);
};

void Obj_0029E548::Save(void* p)
{
    func_001E7360(p, 0x109B9260, D_00377740[m1C]);
    func_001E72B0(p, 0xD9D89E81, m20);
    func_00184EB0(this, p);
}
