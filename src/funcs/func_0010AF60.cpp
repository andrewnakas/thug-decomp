/* sym: __12Obj_0010AF60Pvii = 0x0010D0B0 */
extern "C" void* func_001046B0(int size);

class Obj_0010AF60 {
public:
    char pad[0x84];
    Obj_0010AF60(void* region, int dir, int name); /* = Heap_0010D0B0's constructor */
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

struct List_0010AF60 {
    int m0;
    Obj_0010AF60* m_items[32];
    int m_count;
    Obj_0010AF60* Add(void* region, int dir, int name);
};

/* Returns the new entry: game leaves it in v0 (callers func_0010B6F0/func_0010B0E8 use v0 after the jal). */
Obj_0010AF60* List_0010AF60::Add(void* region, int dir, int name)
{
    Obj_0010AF60* p = new Obj_0010AF60(region, dir, name);
    m_items[m_count++] = p;
    return p;
}
