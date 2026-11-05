struct Heap_0012F828 {
    char pad[0xE4];
    int mE4;
};

class Mgr_0012F828 {
public:
    char pad[0x2C];
    virtual void V1();
    virtual void Add(void* obj);
};

extern Heap_0012F828* D_00388A70;
extern Mgr_0012F828* D_00389A30;
extern char D_0035D2A8[];
extern "C" void func_0010A950(Heap_0012F828* heap, int v);
extern "C" void func_0010A9B0(Heap_0012F828* heap);
extern "C" void* func_001046B0(int size);
extern "C" void* func_0012AE58(void* p);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_00183E90(void* obj, unsigned int name);

extern "C" int func_0012F828()
{
    func_0010A950(D_00388A70, D_00388A70->mE4);
    void* obj = func_0012AE58(func_001046B0(0x1B0));
    func_0010A9B0(D_00388A70);
    func_00183E90(obj, func_001F0D78(D_0035D2A8));
    D_00389A30->Add(obj);
    return 1;
}
