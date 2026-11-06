/* sym: __12Spr_00146440i = 0x0014A168 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

class Spr_00146440 {
public:
    char pad[0x44];
    Spr_00146440(int a);
    static void* operator new(unsigned int n) { return func_0010A638(D_00388A70, n, 1, 0); }
};

Spr_00146440* Create_00146440(int a)
{
    return new Spr_00146440(a);
}
