/* fuzzy: 95.4 */
typedef int qword_001D5078 __attribute__((mode(TI)));

struct Vec_001D5078 {
    union {
        struct { float x, y, z, w; };
        qword_001D5078 q;
    };
};

struct Packed_001D5078 {
    unsigned short x, y, z;
};

struct Mesh_001D5078 {
    char pad0[0xB];
    unsigned char mB;
    char padC[0x4];
    Vec_001D5078 m10;
    char pad20[0x10];
    void* m30;
    Vec_001D5078 GetRaw(int i)
    {
        Vec_001D5078 v;
        if (mB) {
            v = m10;
            v.x += ((Packed_001D5078*)m30)[i].x * 0.0625f;
            v.y += ((Packed_001D5078*)m30)[i].y * 0.0625f;
            v.z += ((Packed_001D5078*)m30)[i].z * 0.0625f;
            v.w = 0.0f;
        } else {
            v.x = ((float*)m30)[i * 3 + 0];
            v.y = ((float*)m30)[i * 3 + 1];
            v.z = ((float*)m30)[i * 3 + 2];
            v.w = 0.0f;
        }
        return v;
    }
};

struct Obj_001D5078 {
    int m0;
    int m4;
    Mesh_001D5078* m8;
    Vec_001D5078 GetVertex(int i);
};

Vec_001D5078 Obj_001D5078::GetVertex(int i)
{
    Vec_001D5078 r = m8->GetRaw(i);
    r.w = 1.0f;
    return r;
}
