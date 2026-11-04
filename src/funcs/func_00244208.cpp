struct Link_00244208 {
    int m0;
    Link_00244208* m4;
    int m8;
    bool Contains(int id)
    {
        bool found = false;
        Link_00244208* p = this;
        while (p && p->m0) {
            if (p->m0 == id) {
                found = true;
                break;
            }
            p = p->m4;
        }
        return found;
    }
};

struct Pool_00244208;
extern Pool_00244208* D_00388A70;
extern "C" void* func_0010A638(Pool_00244208* p, int size, int a, int b);
extern "C" Link_00244208* func_00243D70(void* p);

struct Node_00244208 {
    char pad0[0x2C];
    Link_00244208* m2C;
    void AddLink(int id);
};

void Node_00244208::AddLink(int id)
{
    Link_00244208* l = m2C;
    if (!l->m0) {
        l->m0 = id;
        return;
    }
    if (!l->Contains(id)) {
        Link_00244208* n = func_00243D70(func_0010A638(D_00388A70, 0xC, 1, 0));
        n->m0 = id;
        n->m4 = m2C;
        m2C = n;
    }
}
