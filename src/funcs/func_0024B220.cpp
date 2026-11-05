struct Game_0024B220 {
    char m_pad[0x394];
    void* m394;
};

extern Game_0024B220* D_0038FC78;
extern "C" bool func_00252150(void* p, int level);

struct Obj_0024B220 {
    char m_pad0[0x78];
    int m78;
    char m_pad7C[0x2C];
    int mA8;
    int mAC;
    int mB0;
    void Init();
};

void Obj_0024B220::Init()
{
    void* s = D_0038FC78->m394;
    if (func_00252150(s, 1)) {
        mA8 = 1;
        mAC = 1;
        mB0 = 1;
    } else if (func_00252150(s, 2)) {
        mAC = 1;
        mB0 = 1;
    } else if (func_00252150(s, 3)) {
        mB0 = 1;
    }
    m78 = 1;
}
