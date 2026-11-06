struct Elem_00189628 {
    char pad0[0x44];
    int m_refs;
};

extern "C" Elem_00189628* func_0018A8C0(void* table, int* key, int a);
extern "C" void func_0018A928(void* table, int* key);
extern "C" void func_0018AA18(void* table, int* key, Elem_00189628* e);

class Obj_00189628 {
public:
    char pad0[0xC];
    void* m_table;

    void Put(int key, Elem_00189628* e);
};

void Obj_00189628::Put(int key, Elem_00189628* e)
{
    Elem_00189628* old = func_0018A8C0(m_table, &key, 1);
    if (old) {
        if (old->m_refs > 0) {
            old->m_refs--;
        }
        func_0018A928(m_table, &key);
    }
    e->m_refs++;
    func_0018AA18(m_table, &key, e);
}
