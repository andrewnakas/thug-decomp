/* sym: __12Ent_001E4F50 = 0x001E4EF8 */

extern void* D_00388A70;

extern "C" void* func_0010A638(void* heap, unsigned int size, int a, int b);

struct Ent_001E4F50 {
    char m_pad0[0x14];
    Ent_001E4F50();
    static void* operator new[](unsigned int size, void* heap, int a, int b) { return func_0010A638(heap, size, a, b); }
};

extern Ent_001E4F50* D_0038E47C;

extern "C" void func_001E4F50()
{
    D_0038E47C = new (D_00388A70, 1, 0) Ent_001E4F50[4096];
}
