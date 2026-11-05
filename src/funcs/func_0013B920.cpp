extern "C" short func_00138920(void* tex);
extern "C" short func_00138948(void* tex);

class Quad_0013B920 {
public:
    void* m0;
    char pad4[0x24];
    short m28;
    short m2A;
    char pad2C[0x10];
    virtual ~Quad_0013B920();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    void SetTexture(void* tex);
};

void Quad_0013B920::SetTexture(void* tex)
{
    m0 = tex;
    if (tex) {
        m28 = func_00138920(tex);
        m2A = func_00138948(tex);
    }
    V3();
}
