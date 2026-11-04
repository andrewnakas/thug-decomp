struct Node_002913C0 { char pad[0x14]; void* m14; };
extern "C" void* func_00121960(int);
extern "C" void* func_001EE428(void*);
extern "C" int func_001E8180(void* params, unsigned int name, int* out, int required);
extern "C" float func_00203B20(Node_002913C0*, int);
extern "C" void func_001A1560(void*, float*, int);

struct Obj_002913C0 {
    char pad0[0xC];
    Node_002913C0* m_node;
    char pad1[0x230 - 0x10];
    void* m230;
    void Apply(void* params);
};

void Obj_002913C0::Apply(void* params)
{
    Node_002913C0* n = m_node;
    if (!n->m14) n->m14 = func_001EE428(func_00121960(0xF4));
    float v[5];
    int id = 0;
    func_001E8180(params, 0xFD266A26, &id, 1);
    v[0] = func_00203B20(m_node, id);
    func_001E8180(params, 0x642F3B9C, &id, 1);
    v[1] = func_00203B20(m_node, id);
    func_001E8180(params, 0x0F43FD49, &id, 1);
    v[2] = func_00203B20(m_node, id);
    func_001E8180(params, 0x964AACF3, &id, 1);
    v[3] = func_00203B20(m_node, id);
    func_001E8180(params, 0xF90B0824, &id, 1);
    v[4] = func_00203B20(m_node, id);
    func_001A1560(m230, v, 1);
}
