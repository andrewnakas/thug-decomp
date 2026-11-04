struct Obj_002D6858 {
    char pad0[0x1C];
    void (*m1C)(Obj_002D6858* self);
    void Call();
};

void Obj_002D6858::Call() {
    m1C(this);
}
