struct Heap_002616E0 {
    char m_pad[0xEC];
    void* m_heap;
};

extern Heap_002616E0* D_00388A70;

extern "C" void func_0010A950(Heap_002616E0* mem, void* heap);
extern "C" void func_0010A9B0(Heap_002616E0* mem);
extern "C" int func_0011FC60(void* p, char* buf, int size, int a);
extern "C" void* func_00262330(void* self, unsigned int name);
extern "C" void* func_00262358(void* self);
extern "C" int func_001E9B08(void* params, char* buf, int size, int a);
extern "C" int func_00261890(void* self, char* buf, int size);

int func_002616E0(char* self, char* buf, int size, int a)
{
    func_0010A950(D_00388A70, D_00388A70->m_heap);
    int total = func_0011FC60(self + 4, buf, size, a);
    size -= total;
    buf += total;
    int n = func_001E9B08(func_00262330(self, 0xD544AA2D), buf, size, 1);
    buf += n;
    size -= n;
    total += n;
    n = func_001E9B08(func_00262358(self), buf, size, 1);
    buf += n;
    size -= n;
    total += n;
    total += func_00261890(self, buf, size);
    func_0010A9B0(D_00388A70);
    return total;
}
