struct Vec_001E4C80 {
    float m0;
    float m4;
    float m8;
    Vec_001E4C80* Clear();
};

Vec_001E4C80* Vec_001E4C80::Clear()
{
    m4 = m8 = 0.0f;
    return this;
}
