struct Col_00134F88 {
    unsigned char r, g, b, a;
    Col_00134F88() {}
    Col_00134F88(unsigned char ar, unsigned char ag, unsigned char ab, unsigned char aa)
    {
        r = ar;
        g = ag;
        b = ab;
        a = aa;
    }
};

extern "C" Col_00134F88 func_0013C4A0(void* model);

class Obj_00134F88 {
public:
    char pad0[0x20];
    void* m_model;
    Col_00134F88 GetColor();
};

Col_00134F88 Obj_00134F88::GetColor()
{
    if (m_model) {
        return func_0013C4A0(m_model);
    }
    return Col_00134F88(0, 0, 0, 0);
}
