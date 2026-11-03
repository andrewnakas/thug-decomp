struct Node_00290720 { char pad[0x31C]; int m31C; };
extern void* D_0038FC78;
extern "C" void* func_0022E358(void*);
extern "C" int func_0024F2C0(void*);
extern "C" void func_001848F0(void*, unsigned int, int);
extern "C" void func_001F0210(unsigned int, int, Node_00290720*, int, int);

struct Obj_00290720 {
    char pad0[0xC];
    Node_00290720* m_node;
    char pad1[0x1C - 0x10];
    int m1C;
    void Start(int force);
};

void Obj_00290720::Start(int force)
{
    if (force || func_0024F2C0(func_0022E358(D_0038FC78))) {
        if (m1C & 4) return;
        if (m1C & 2) return;
        m1C |= 4;
        if (m_node->m31C) func_001F0210(0xF4CE3E97, 0, m_node, 0, 0);
    } else {
        func_001848F0(m_node, 0x822E13A9, 0);
        m1C &= ~2;
    }
}
