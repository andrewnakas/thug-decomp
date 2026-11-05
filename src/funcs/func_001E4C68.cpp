struct Vec_001E4C68 {
    float m0;
    float m4;
    float m8;
    float mC;
    Vec_001E4C68* Clear();
};

Vec_001E4C68* Vec_001E4C68::Clear()
{
    m4 = m8 = mC = 0.0f;
    return this;
}
