/* sym: __12Tab_00142650i = 0x00142950 */
/* sym: _vt$12Obj_00142650 = 0x0035EDC0 */
extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, unsigned int size, int a, int b);

class Tab_00142650 {
public:
    int m0[6];
    Tab_00142650(int n);
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

class Obj_00142650 {
public:
    Tab_00142650* m_tab;
    Obj_00142650();
    virtual void V0();
};

Obj_00142650::Obj_00142650()
{
    m_tab = new Tab_00142650(8);
}
