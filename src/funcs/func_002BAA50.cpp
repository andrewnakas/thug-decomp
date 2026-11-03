struct Obj_002BAA50 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    void Update();
};

void Obj_002BAA50::Update() {
    m4 = 0x7F - m1;
}
