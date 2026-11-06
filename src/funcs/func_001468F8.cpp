struct Rgba_001468F8 {
    unsigned char r, g, b, a;
    Rgba_001468F8() {}
    Rgba_001468F8(const Rgba_001468F8& o) { *this = o; }
};

struct Obj_001468F8 {
    char pad[0x80];
    Rgba_001468F8 m_80;
    Rgba_001468F8 GetColor();
};

Rgba_001468F8 Obj_001468F8::GetColor()
{
    return m_80;
}
