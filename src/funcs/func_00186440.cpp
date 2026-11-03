struct Obj186440 {
    char m_pad[0x2C];
    virtual ~Obj186440();
};

extern Obj186440* D_0038C608;
extern unsigned int D_0038C60C;

extern "C" void func_00186440()
{
    if (D_0038C60C >= 2) {
        D_0038C60C--;
        return;
    }
    if (D_0038C608) {
        delete D_0038C608;
    }
    D_0038C608 = 0;
    D_0038C60C = 0;
}
