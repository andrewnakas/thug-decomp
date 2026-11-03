struct Obj_002A7820 {
    char pad0[0x44];
    bool m44;
    bool m48;
    bool m4C;
    void ToggleM4C();
};

void Obj_002A7820::ToggleM4C() {
    m4C ^= true;
}
