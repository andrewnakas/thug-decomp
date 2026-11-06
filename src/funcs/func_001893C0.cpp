struct Elem_001893C0 {
    char pad0[0x18];
    int m_id;
    char pad1C[0x28];
    int m_refs;
};

struct Iter_001893C0 {
    int m[4];
};

extern "C" void func_0018AAD0(void* list);
extern "C" Elem_001893C0* func_0018AAE0(void* list, Iter_001893C0* it);
extern "C" void func_0018A928(void* list, Iter_001893C0* it);

class Obj_001893C0 {
public:
    char pad0[0xC];
    void* m_list;

    void Release(Elem_001893C0* item);
};

void Obj_001893C0::Release(Elem_001893C0* item)
{
    Iter_001893C0 it;
    for (;;) {
        func_0018AAD0(m_list);
        Elem_001893C0* e;
        do {
            e = func_0018AAE0(m_list, &it);
            if (!e) {
                return;
            }
        } while (e->m_id != item->m_id);
        if (e->m_refs > 0) {
            e->m_refs--;
        }
        func_0018A928(m_list, &it);
    }
}
