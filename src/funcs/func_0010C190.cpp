/* sym: _vt$13Heap_0010C190 = 0x0035B510 */
extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);

class Heap_0010C190;
extern "C" void func_0010C020(Heap_0010C190* self, char* start, char* end);

class Heap_0010C190 {
public:
    int m0;
    char* m_mem;
    char pad8[0x10];
    Heap_0010C190(unsigned int size);
    virtual ~Heap_0010C190();
};

Heap_0010C190::Heap_0010C190(unsigned int size)
{
    size &= 0xFFFFFFF0;
    m_mem = (char*)func_0010A638(D_00388A70, size, 1, 0);
    func_0010C020(this, m_mem, m_mem + size);
}
