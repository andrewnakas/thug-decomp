class Child_00138E90 {
public:
    int m0;
    int m4;
    virtual ~Child_00138E90();
};

extern "C" void func_001397F0(void* list);
extern "C" Child_00138E90* func_00139800(void* list, int a);
extern "C" int func_00138918(Child_00138E90* c);
extern "C" void func_001398B0(void* list, int* key);

class Node_00138E90 {
public:
    int m0;
    short m4;
    void* m8;
    int mC;
    virtual ~Node_00138E90();
    void Clear(int all);
};

void Node_00138E90::Clear(int all)
{
    if (!m8)
        return;
    func_001397F0(m8);
    Child_00138E90* c = func_00139800(m8, 0);
    while (c) {
        Child_00138E90* next = func_00139800(m8, 0);
        if (all || c->m4 == 0) {
            int key = func_00138918(c);
            delete c;
            func_001398B0(m8, &key);
        }
        c = next;
    }
}
