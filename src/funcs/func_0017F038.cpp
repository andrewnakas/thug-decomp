extern int D_0038C10C;
extern int D_0038C110;
extern "C" void func_0017F578(void* p, int* list);
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
    void SetPriority(float pri);
};

void Prim_0017EF58::SetPriority(float pri)
{
    if (m8 == pri) {
        return;
    }
    m8 = pri;
    if (!m0) {
        if (m4) {
            func_0017F578(this, &D_0038C110);
        } else {
            func_0017F578(this, &D_0038C10C);
        }
        func_0017F4C0(this, &D_0038C10C);
    }
    m4 = 0;
    mC = 0xFFFFFF;
}
