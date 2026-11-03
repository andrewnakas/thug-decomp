struct Obj_002C3250 {
    char pad0[0x6ADC];
    int m6ADC[9];
    void SetSlot(int i, int v);
};

void Obj_002C3250::SetSlot(int i, int v) {
    if (i >= 1 && i <= 8) {
        m6ADC[i] = v;
    }
}
