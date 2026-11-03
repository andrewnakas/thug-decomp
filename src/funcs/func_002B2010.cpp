struct Obj_002B1FC8 {
    char pad0[0x14C];
    unsigned int m14C;
    void SetFlag8000();
};

void Obj_002B1FC8::SetFlag8000() {
    m14C |= 0x8000;
}
