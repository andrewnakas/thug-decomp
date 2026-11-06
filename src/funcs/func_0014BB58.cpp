/* sym: __12Obj_0014BB58ii = 0x0014B828 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

class Obj_0014BB58 {
public:
    char pad[0x28];
    Obj_0014BB58(int a, int b);
    static void* operator new(unsigned int n) { return func_0010A638(D_00388A70, n, 1, 0); }
};

Obj_0014BB58* Create_0014BB58(int a, int b)
{
    return new Obj_0014BB58(a, b);
}
