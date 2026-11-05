struct Rect_00125798 {
    char pad[0x20];
    float m20;
    float m24;
    float m28;
    float m2C;
    float m30;
    float m34;
    float m38;
};

struct Obj_00125798 {
    char pad[0x180];
    float m180;
    float m184;
    float m188;
    float m18C;
    void Layout(Rect_00125798* r);
};

void Obj_00125798::Layout(Rect_00125798* r)
{
    float w = r->m34 * m188 * (m180 + 1.0f) * 0.5f;
    float h = r->m38 * m18C * (m184 + 1.0f) * 0.5f;
    r->m2C = r->m20 - w;
    r->m30 = r->m24 - h;
}
