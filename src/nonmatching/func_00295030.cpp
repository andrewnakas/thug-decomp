/* fuzzy: 60.0 */
extern "C" void* func_00229668(void* p, int v);
extern "C" void* func_00229DF0(void* node);
extern "C" void func_001E7410(void* s, unsigned int name, float x, float y, float z);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int value);
extern "C" void func_001E70C0(void* p, unsigned int name, char* s);
extern "C" unsigned int func_00291FB8(void* p, int i);
extern "C" char* func_00291EE0(void* p, int i);

struct Item_00295030 {
    float x;
    float y;
    float z;
    float w;
    float m10;
    float m14;
    char pad18[0x30 - 0x18];
};

struct Obj_00295030 {
    char pad0[0x114];
    void* m114;
    char pad118[0x130 - 0x118];
    Item_00295030 items[8];
    void Fill(unsigned int idx, void* node);
};

void Obj_00295030::Fill(unsigned int idx, void* node)
{
    void* s = func_00229DF0(func_00229668(node, 1));
    func_001E7410(s, 0x7F261953, items[idx].x, items[idx].y + items[idx].m10, items[idx].z);
    func_001E7410(s, 0x9D2D0915, 0.0f, items[idx].m14 - 3.1415927f, 0.0f);
    if (idx >= 2) {
        func_001E7360(s, 0x7321A8D6, func_00291FB8(m114, idx - 2));
        func_001E70C0(s, 0x286A8D26, func_00291EE0(m114, idx - 2));
    }
}
