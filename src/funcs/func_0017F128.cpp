extern int D_0038C10C;
extern int D_0038C110;
extern "C" void func_0017F578(void* p, int* list);
extern "C" void func_0017F520(void* p, int* list);
extern "C" void func_0017F4C0(void* p, int* list);

class Prim_0017EF58 {
public:
    int m0;
    int m4;
    float m8;
    unsigned int mC;
    int* m10;
    int m14;

    virtual void Key();
    virtual void SetHidden(int hidden);
};

void Prim_0017EF58::SetHidden(int hidden)
{
    if (m0 == hidden) {
        return;
    }
    m0 = hidden;
    if (m4) {
        if (hidden) {
            func_0017F578(this, &D_0038C110);
        } else {
            func_0017F520(this, &D_0038C110);
        }
    } else {
        if (hidden) {
            func_0017F578(this, &D_0038C10C);
        } else {
            func_0017F4C0(this, &D_0038C10C);
        }
    }
}
