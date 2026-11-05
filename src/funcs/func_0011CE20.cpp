/* sym: __13Base_0011CE20 = 0x0011AB88 */
/* sym: _vt$12Obj_0011CE20 = 0x0035C8A8 */
struct Quat_0011CE20 {
    float x, y, z, w;
    Quat_0011CE20()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 1.0f;
    }
};

struct Vec_0011CE20 {
    float x, y, z, w;
    Vec_0011CE20() {}
};

class Base_0011CE20 {
public:
    char pad[0x14];
    Base_0011CE20();
    virtual ~Base_0011CE20();
};

class Obj_0011CE20 : public Base_0011CE20 {
public:
    int m18;
    int m1C;
    Quat_0011CE20 m_rot[64];
    Vec_0011CE20 m_pos[64];
    Obj_0011CE20();
    virtual void Run();
};

Obj_0011CE20::Obj_0011CE20()
{
}
