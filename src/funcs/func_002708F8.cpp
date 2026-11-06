struct Obj_002708F8 {
    char pad[0x8C];
    float m8C;
    void SetLevel(float f);
};

void Obj_002708F8::SetLevel(float f)
{
    m8C = f;
    if (f > 1.0f)
        m8C = 1.0f;
}
