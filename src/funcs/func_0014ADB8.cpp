/* sym: __13Menu_0014ADB8 = 0x0014B0C8 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

class Menu_0014ADB8 {
public:
    char pad[0x20];
    Menu_0014ADB8();
    static void* operator new(unsigned int n) { return func_0010A638(D_00388A70, n, 1, 0); }
};

extern "C" bool func_0014AE70(Menu_0014ADB8* m);

Menu_0014ADB8* Create_0014ADB8()
{
    Menu_0014ADB8* m = new Menu_0014ADB8;
    if (m)
        func_0014AE70(m);
    return m;
}
