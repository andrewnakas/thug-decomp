/* sym: __13Quad_0014A168i = 0x0013B840 */
/* sym: _vt$12Spr_0014A168 = 0x0035F270 */
/* sym: __13Anim_0014A168f = 0x0017F5C0 */
/* sym: Refresh__12Spr_0014A168 = 0x0014A230 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

class Anim_0014A168 {
public:
    char pad[0x18];
    Anim_0014A168(float t);
    virtual ~Anim_0014A168();
    char pad1C[0x28];
    static void* operator new(unsigned int n) { return func_0010A638(D_00388A70, n, 1, 0); }
};

class Quad_0014A168 {
public:
    char pad[0x3C];
    Quad_0014A168(int a);
    virtual ~Quad_0014A168();
};

class Spr_0014A168 : public Quad_0014A168 {
public:
    Anim_0014A168* m40;
    Spr_0014A168(int a);
    virtual void V1();
    virtual ~Spr_0014A168();
    void Refresh();
};

Spr_0014A168::Spr_0014A168(int a) : Quad_0014A168(a)
{
    m40 = new Anim_0014A168(0.0f);
    Refresh();
}
