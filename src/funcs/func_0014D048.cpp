/* sym: __12Obj_0014D048 = 0x0013C258 */
/* sym: _vt$12Ent_0014D048 = 0x0035F640 */
struct Mtx_0014D048 {
    float m[4][4];
    void Identity()
    {
        m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
        m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
        m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
        m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
    }
};

class Obj_0014D048 {
public:
    int m0;
    int m_4;
    int m_8;
    int m_C;
    int m_10;
    virtual void V0();
    Obj_0014D048();
};

class Ent_0014D048 : public Obj_0014D048 {
public:
    void* m18;
    int m1C;
    void* m20;
    char pad24[0xC];
    Mtx_0014D048 m30;
    int m70;
    Ent_0014D048();
    virtual void V0();
};

Ent_0014D048::Ent_0014D048()
{
    m18 = 0;
    m20 = 0;
    m70 = 0;
    m30.Identity();
}
