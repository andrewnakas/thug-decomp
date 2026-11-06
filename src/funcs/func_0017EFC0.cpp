/* sym: _vt$13Prim_0017EF58 = 0x00361290 */

extern int D_0038C10C;
extern int D_0038C110;
extern void* D_00388A70;
extern "C" void func_0017F578(void* p, int* list);
extern "C" void func_0010A8D8(void* heap, void* p);

class Prim_0017EF58 {
public:
    int m0;
    int m4;
    float m8;
    unsigned int mC;
    int* m10;
    int m14;

    virtual void Key();
    virtual ~Prim_0017EF58();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Prim_0017EF58::~Prim_0017EF58()
{
    if (m4) {
        func_0017F578(this, &D_0038C110);
    } else {
        func_0017F578(this, &D_0038C10C);
    }
}
