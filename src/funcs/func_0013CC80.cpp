extern "C" int func_0011D9E8(void* src);
extern "C" int func_0011D9E0(void* src);

class Mesh_0013CC80 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[0x1A8];
    virtual ~Mesh_0013CC80();
    virtual void V1(int a);
    bool Init(void* src);
};

bool Mesh_0013CC80::Init(void* src)
{
    if (!mC) {
        m8 = func_0011D9E8(src);
        V1(func_0011D9E8(src));
        mC = func_0011D9E0(src);
    }
    return true;
}
