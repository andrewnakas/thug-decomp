typedef int qword __attribute__((mode(TI)));
union Vec_002B71C0 {
    qword q;
    struct { float x, y, z, w; } f;
};

struct Data_002B71C0 {
    char pad[0x10];
    float m10;
    float m14;
    float m18;
};

struct Obj_002B71C0 {
    char pad[0x14];
    Data_002B71C0* m14;
    char pad18[0x18];
    unsigned int m30;
    Vec_002B71C0 GetPos();
};

Vec_002B71C0 Obj_002B71C0::GetPos()
{
    Vec_002B71C0 v;
    if (m30 & 1) {
        v.f.x = m14->m18;
        v.f.z = m14->m10;
    } else {
        v.f.x = m14->m10;
        v.f.z = m14->m18;
    }
    v.f.y = m14->m14;
    return v;
}
