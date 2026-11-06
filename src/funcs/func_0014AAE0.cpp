/* sym: __12Win_0014AAE0iiii = 0x0014A998 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

class Win_0014AAE0 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    Win_0014AAE0* m10;
    int m14;
    int m18;
    Win_0014AAE0(int x, int y, int w, int h);
    static void* operator new(unsigned int n) { return func_0010A638(D_00388A70, n, 1, 0); }
    static void InitPool();
};

extern Win_0014AAE0* D_0038A07C;

void Win_0014AAE0::InitPool()
{
    for (int i = 0; i < 10; i++) {
        Win_0014AAE0* w = new Win_0014AAE0(0, 0, 640, 448);
        w->m10 = D_0038A07C;
        D_0038A07C = w;
    }
}
