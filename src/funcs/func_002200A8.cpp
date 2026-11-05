struct Heap_002200A8 {
    char pad[0x3EC];
    int m_3EC;
};

struct Mgr_002200A8 {
    char pad[0x394];
    void* m_obj;
};

extern Heap_002200A8* D_00388A70;
extern Mgr_002200A8* D_0038FC78;
extern "C" void func_0010A950(Heap_002200A8* heap, int ctx);
extern "C" void func_0010A9B0(Heap_002200A8* heap);
extern "C" void func_00252178(void* obj);

bool Cmd_002200A8(void* params, void* script)
{
    func_0010A950(D_00388A70, D_00388A70->m_3EC);
    func_00252178(D_0038FC78->m_obj);
    func_0010A9B0(D_00388A70);
    return true;
}
