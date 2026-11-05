/* sym: _vt$13Mesh_0013CB68 = 0x0035E9A8 */
typedef int qword __attribute__((mode(TI)));

struct Vec_0013CB68 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0013CB68() {}
    Vec_0013CB68(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_0013CB68& operator=(const Vec_0013CB68& o)
    {
        q = o.q;
        return *this;
    }
};

class Mesh_0013CB68;
extern "C" void func_0013D8B0(Mesh_0013CB68* m, int n);

class Mesh_0013CB68 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[0xE0];
    Vec_0013CB68 mF0;
    int m100;
    char pad104[0x90];
    unsigned int m194;
    char pad198[0x18];
    unsigned long b0 : 1;
    unsigned long b1 : 1;
    unsigned long b2 : 1;
    unsigned long b3 : 1;
    unsigned long b4 : 1;
    unsigned long b5 : 1;
    short m1B2;
    int m1B4;
    Mesh_0013CB68();
    virtual ~Mesh_0013CB68();
};

Mesh_0013CB68::Mesh_0013CB68()
{
    m8 = 0;
    mC = 0;
    func_0013D8B0(this, 6);
    m1B2 = 0;
    m194 = 0x6607DD3E;
    mF0 = Vec_0013CB68(1.0f, 1.0f, 1.0f, 1.0f);
    b1 = 1;
    b2 = 0;
    b3 = 0;
    b4 = 0;
    b5 = 0;
    b0 = 0;
    m100 = 0;
}
