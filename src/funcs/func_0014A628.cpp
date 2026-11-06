/* sym: __13Quad_0014A628i = 0x001359D0 */
/* sym: _vt$12Spr_0014A628 = 0x0035F2B0 */
/* sym: __13Anim_0014A628f = 0x001733B8 */
/* sym: Refresh__12Spr_0014A628 = 0x0014A6F0 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

class Anim_0014A628 {
public:
    char pad[0x18];
    Anim_0014A628(float t);
    virtual ~Anim_0014A628();
    char pad1C[0x20];
    static void* operator new(unsigned int n) { return func_0010A638(D_00388A70, n, 1, 0); }
};

class Quad_0014A628 {
public:
    char pad[0x38];
    Quad_0014A628(int a);
    virtual ~Quad_0014A628();
};

class Spr_0014A628 : public Quad_0014A628 {
public:
    Anim_0014A628* m40;
    Spr_0014A628(int a);
    virtual void V1();
    virtual ~Spr_0014A628();
    void Refresh();
};

Spr_0014A628::Spr_0014A628(int a) : Quad_0014A628(a)
{
    m40 = new Anim_0014A628(0.0f);
    Refresh();
}
