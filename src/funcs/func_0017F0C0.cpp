extern int D_0038C10C;
extern int D_0038C110;
extern "C" void func_0017F578(void* p, int* list);
extern "C" void func_0017F520(void* p, int* list);

class Prim_0017EF58 {
public:
    int m0;
    int m4;
    float m8;
    unsigned int mC;
    int* m10;
    int m14;

    virtual void Key();
    void SetColor(unsigned int color);
};

void Prim_0017EF58::SetColor(unsigned int color)
{
    if (mC == color) {
        return;
    }
    mC = color;
    if (!m4 && !m0) {
        func_0017F578(this, &D_0038C10C);
        func_0017F520(this, &D_0038C110);
    }
    m8 = 0.0f;
    m4 = 1;
}
