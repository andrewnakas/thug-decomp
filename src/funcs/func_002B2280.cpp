struct Obj_002B1FC8 {
    char pad0[0x14C];
    unsigned int m14C;
    bool IsFlag21() const;
};

bool Obj_002B1FC8::IsFlag21() const {
    return (m14C & 0x21) != 0;
}
