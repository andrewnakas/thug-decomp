extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" int func_0023B000(void* list);
extern "C" void* func_0023AFE8(void* list, int index);
extern "C" void func_0023B418(void* list);

struct Owner_0023B420 {
    void* m_list;
    void DeleteAll();
};

void Owner_0023B420::DeleteAll()
{
    int n = func_0023B000(m_list);
    for (int i = 0; i < n; i++) {
        func_0010A8D8(D_00388A70, func_0023AFE8(m_list, i));
    }
    func_0023B418(m_list);
}
