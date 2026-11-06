struct Heap_00189CE0 {
    char pad[0xEC];
    int mEC;
};

extern Heap_00189CE0* D_00388A70;
extern "C" void func_0010A950(void* heap, int v);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_001046B0(int size);
extern "C" void* func_00189E30(void* p);
extern "C" void* func_0018AE38(void* table, int* key, int a);
extern "C" void func_0018AEA0(void* table, int* key, void* e);
extern "C" void func_00189E60(void* e, void* item);

class Mgr_00189CE0 {
public:
    char pad0[0x10];
    void* m_table;

    void Register(int key, void* item);
};

void Mgr_00189CE0::Register(int key, void* item)
{
    func_0010A950(D_00388A70, D_00388A70->mEC);
    void* e = func_0018AE38(m_table, &key, 1);
    if (!e) {
        e = func_00189E30(func_001046B0(0x1C));
        func_0018AEA0(m_table, &key, e);
    }
    func_00189E60(e, item);
    func_0010A9B0(D_00388A70);
}
