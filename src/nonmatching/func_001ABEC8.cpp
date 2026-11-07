/* fuzzy: 73.7 */
extern "C" unsigned int func_0010FC30();
extern "C" int func_00183330(int i);

struct Event_001ABEC8 {
    int m0;
    int m4;
    int m8;
};

struct Obj_001ABEC8;
extern "C" Event_001ABEC8* func_001AB8A0(Obj_001ABEC8* o, int type);

struct Obj_001ABEC8 {
    char pad[0x9AC];
    float m9AC[22];
    int mA04[22];
    int mA5C;
    int mA60[1];
    void Method(int i, int on);
};

void Obj_001ABEC8::Method(int i, int on)
{
    if (m9AC[i] != 0.0f) {
        if (!on || m9AC[i] < (float)func_0010FC30())
            m9AC[i] = 0.0f;
        else
            return;
    }
    if (mA04[i] != on) {
        mA04[i] = on;
        int id = func_00183330(i);
        for (int k = 0; k < mA5C; k++)
            if (mA60[k] == id)
                return;
        if (on)
            func_001AB8A0(this, 1)->m8 = id;
        else
            func_001AB8A0(this, 2)->m8 = id;
    }
}
