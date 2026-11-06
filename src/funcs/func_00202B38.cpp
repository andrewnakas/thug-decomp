struct Obj_00202B38 {
    char m_pad0[0x492C];
    int m_mode;
    void SetMode(int mode);
};

extern "C" void func_00202BB8(Obj_00202B38* self, int rate);

void Obj_00202B38::SetMode(int mode)
{
    m_mode = mode;
    switch (mode) {
    case 1:
        func_00202BB8(this, 0x1068);
        break;
    case 0:
        func_00202BB8(this, 400000);
        break;
    case 2:
        func_00202BB8(this, 800000);
        break;
    }
}
