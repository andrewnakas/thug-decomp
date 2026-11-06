struct Obj_001BA3B8 {
    char pad[0xC0];
    float mC0;
    float mC4;
    float mC8;
    float mCC;
    float mD0;
    float mD4;
    void Method();
};

void Obj_001BA3B8::Method()
{
    if (mC4 > 0.0f) {
        mC4 -= 0.016666668f;
        mC0 += mC8;
    } else {
        mC4 = 0.0f;
    }
    if (mD0 > 0.0f) {
        mD0 -= 0.016666668f;
        mCC += mD4;
    } else {
        mD0 = 0.0f;
    }
}
