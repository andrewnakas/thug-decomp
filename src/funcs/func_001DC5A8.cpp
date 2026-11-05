struct Obj_001DC5A8 {
    float m0[5];
    int m14;
    void Scale(float s);
};

void Obj_001DC5A8::Scale(float s)
{
    unsigned int n = (m14 == 2) ? 5 : 2;
    for (unsigned int i = 0; i < n; i++)
        m0[i] = m0[i] * s * 0.01f;
}
