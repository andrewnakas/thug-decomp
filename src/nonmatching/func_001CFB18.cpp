/* fuzzy: 92.0 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001CFB18 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001CFB18() {}
    Vec_001CFB18(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Mat_001CFB18 {
    Vec_001CFB18 r[4];
    void Zero()
    {
        r[0].x = 0.0f; r[0].y = 0.0f; r[0].z = 0.0f; r[0].w = 0.0f;
        r[1].x = 0.0f; r[1].y = 0.0f; r[1].z = 0.0f; r[1].w = 0.0f;
        r[2].x = 0.0f; r[2].y = 0.0f; r[2].z = 0.0f; r[2].w = 0.0f;
        r[3].x = 0.0f; r[3].y = 0.0f; r[3].z = 0.0f; r[3].w = 0.0f;
    }
    void Set(float m00, float m01, float m02, float m03,
             float m10, float m11, float m12, float m13,
             float m20, float m21, float m22, float m23,
             float m30, float m31, float m32, float m33)
    {
        r[0].x = m00; r[0].y = m01; r[0].z = m02; r[0].w = m03;
        r[1].x = m10; r[1].y = m11; r[1].z = m12; r[1].w = m13;
        r[2].x = m20; r[2].y = m21; r[2].z = m22; r[2].w = m23;
        r[3].x = m30; r[3].y = m31; r[3].z = m32; r[3].w = m33;
    }
};

struct Bone_001CFB18 {
    char pad0[0x10];
    Mat_001CFB18 m;
    Mat_001CFB18 GetMatrix() { return m; }
};

struct Skel_001CFB18 {
    char pad0[0x50];
    Bone_001CFB18 root;
    Bone_001CFB18 bones[4];
};

struct Comp_001CFB18 {
    char pad0[0x260];
    void* m260;
};

extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" Skel_001CFB18* func_0013EF50(void* p);
extern "C" void* func_0019EBD0(void* p);
extern "C" Mat_001CFB18* func_0011D9E0(void* p);
extern "C" int func_0011D9E8(void* p);

struct Obj_001CFB18 {
    int m0;
    int m4;
    int m8;
    void* mC;
    void SetupBones();
};

void Obj_001CFB18::SetupBones()
{
    Skel_001CFB18* skel = func_0013EF50(((Comp_001CFB18*)func_00185578(mC, 0x286A8D26))->m260);
    Vec_001CFB18 pts[4];
    int i = 4;
    while (i--) {
        Mat_001CFB18 m = skel->bones[i].GetMatrix();
        pts[i].x = -m.r[3].x;
        pts[i].y = m.r[3].z;
        pts[i].z = -m.r[3].y;
        pts[i].w = 1.0f;
    }
    Mat_001CFB18 m = skel->root.m;
    Vec_001CFB18 root;
    root.x = -m.r[3].x;
    root.y = m.r[3].z;
    root.z = -m.r[3].y;
    root.w = 1.0f;
    void* comp = func_00185578(mC, 0x222756D5);
    Mat_001CFB18* out = func_0011D9E0(func_0019EBD0(comp));
    for (int j = 0; j < func_0011D9E8(func_0019EBD0(comp)); j++) {
        if (j == 0) {
            out->Zero();
        } else if (j == 1) {
            out->Zero();
            out->r[0].x = 1.0f;
            out->r[1].z = -1.0f;
            out->r[2].y = 1.0f;
            out->r[3] = root;
        } else {
            out->Zero();
            out->r[0].x = -1.0f;
            out->r[1].z = 1.0f;
            out->r[2].y = 1.0f;
            out->r[3] = pts[j - 2];
        }
        out++;
    }
}
