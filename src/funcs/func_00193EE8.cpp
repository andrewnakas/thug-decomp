typedef int qword __attribute__((mode(TI)));

struct Vec_00193EE8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00193EE8() {}
    Vec_00193EE8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_00193EE8& operator+=(const Vec_00193EE8& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
    Vec_00193EE8& operator-=(const Vec_00193EE8& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
};

struct Mat_00193EE8 {
    Vec_00193EE8 r[4];
    const Vec_00193EE8& operator[](int i) const { return r[i]; }
    Mat_00193EE8& operator=(const Mat_00193EE8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

struct Bone_00193EE8 {
    char pad0[0x10];
    Mat_00193EE8 m_mat;
};

struct Skel_00193EE8 {
    char pad0[0x50];
    Bone_00193EE8 m_body;
    Bone_00193EE8 m_bones[4];
};

struct Node_00193EE8 {
    char pad0[0x50];
    Vec_00193EE8 m50;
    char pad60[0x70 - 0x60];
    Mat_00193EE8 m_mat;
    Vec_00193EE8 mB0;
    Mat_00193EE8 m_lastMat;
};

struct Wheel_00193EE8 {
    char pad0[0xC0];
    Vec_00193EE8 m_pos;
    int m_type;
    int mD4;
    float mD8;
    float mDC;
    float mE0;
    float mE4;
    float mE8;
    char padEC[0x220 - 0xEC];
};

struct Box_00193EE8 {
    Vec_00193EE8 m_pos;
    Vec_00193EE8 m_a;
    Vec_00193EE8 m_b;
    char pad30[0x90 - 0x30];
};

struct Comp_00193EE8 {
    char pad0[0x260];
    void* m260;
};

extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" Skel_00193EE8* func_0013EF50(void* p);
extern "C" void* func_0022DD38(void* mgr);
extern "C" void func_00185128(void* self, bool on);
extern void* D_0038FC78;

struct Obj_00193EE8;
extern "C" void func_00196BE0(Obj_00193EE8* self);
extern "C" void func_0019BBB0(Obj_00193EE8* self);

struct Obj_00193EE8 {
    char pad0[0xC];
    Node_00193EE8* m_node;
    char pad10[0x20 - 0x10];
    Vec_00193EE8 m20;
    char pad30[0x70 - 0x30];
    Mat_00193EE8 m_mat;
    Vec_00193EE8 mB0;
    char padC0[0x180 - 0xC0];
    float m180;
    char pad184[0x1C4 - 0x184];
    unsigned int m_numWheels;
    char pad1C8[0x1D0 - 0x1C8];
    float m1D0;
    float m1D4;
    char pad1D8[0x1E0 - 0x1D8];
    Box_00193EE8 m_boxes[2];
    Vec_00193EE8 m300;
    char pad310[0x318 - 0x310];
    Wheel_00193EE8* m_wheels;
    char pad31C[0x1330 - 0x31C];
    int m1330;
    char pad1334[0x1340 - 0x1334];
    Vec_00193EE8 m1340;
    char pad1350[0x1378 - 0x1350];
    void* m1378;
    void* m137C;
    char pad1380[0x1388 - 0x1380];
    void* m1388;
    void* m138C;
    void* m1390;
    void* m1394;
    void Init();
};

void Obj_00193EE8::Init()
{
    m1378 = func_00185578(m_node, 0x27D7CD28);
    m137C = func_00185578(m_node, 0x286A8D26);
    int i1 = 4;
    Skel_00193EE8* skel = func_0013EF50(((Comp_00193EE8*)func_00185578(m_node, 0x286A8D26))->m260);

    while (i1--) {
        Wheel_00193EE8* w = &m_wheels[i1];
        Bone_00193EE8* b = &skel->m_bones[i1];
        Mat_00193EE8 m = b->m_mat;
        w->m_pos.x = -m.r[3].x;
        w->m_pos.y = m.r[3].z;
        w->m_pos.z = -m.r[3].y;
        w->m_pos.w = 1.0f;
    }

    Mat_00193EE8 m = skel->m_body.m_mat;
    m300.w = 1.0f;
    m300.y = m.r[3].z;
    m300.x = -m.r[3].x;
    m300.z = -m.r[3].y;

    int rear = -1;
    int side = -1;
    int front = -1;
    int i2 = 4;
    while (i2--) {
        switch (m_wheels[i2].m_type) {
        case 0:
            front = i2;
            break;
        case 1:
            rear = i2;
            break;
        case 2:
            side = i2;
            break;
        }
    }
    m1D0 = __builtin_fabsf(skel->m_bones[rear].m_mat[3].y - skel->m_bones[front].m_mat[3].y);
    m1D4 = __builtin_fabsf(skel->m_bones[rear].m_mat[3].x - skel->m_bones[side].m_mat[3].x);

    int i3 = m_numWheels;
    while (i3--) {
        Wheel_00193EE8* w = &m_wheels[i3];
        float y = w->m_pos.y;
        w->m_pos.y = y + w->mE0 * 2.0f;
        w->mD8 = (y - w->m_pos.y) - 386.4f / (m180 * m_numWheels * w->mE8);
    }

    float minY = m_boxes[0].m_pos.y;
    void* mgr = D_0038FC78;
    int i4 = 2;
    while (i4--) {
        Box_00193EE8* b = &m_boxes[i4];
        float y = b->m_pos.y;
        minY = y < minY ? y : minY;
        float a = y + b->m_a.y;
        float c = y + b->m_b.y;
        minY = a < minY ? a : minY;
        minY = c < minY ? c : minY;
    }

    m1388 = func_0022DD38(mgr);
    m1390 = func_00185578(m1388, 0x5BD63B29);
    m1394 = func_00185578(m1388, 0xE594F0A2);
    if (m1330 == 0) {
        func_00185128(m1388, 1);
    } else {
        m138C = func_00185578(m1388, 0x72AD7B23);
    }

    Vec_00193EE8 c(0.0f, 0.0f, 0.0f, 0.0f);
    int i5 = m_numWheels;
    while (i5--) {
        c += m_wheels[i5].m_pos;
    }
    float inv = 1.0f / m_numWheels;
    c.x *= inv;
    c.z *= inv;
    c.y = minY;
    c.w = 0.0f;
    int i6 = m_numWheels;
    while (i6--) {
        m_wheels[i6].m_pos -= c;
    }
    int i7 = 2;
    while (i7--) {
        m_boxes[i7].m_pos -= c;
    }
    m300 -= c;
    m1340 -= c;
    func_00196BE0(this);
    m_node->m50 = m20;
    m_node->mB0 = mB0;
    m_node->m_mat = m_mat;
    m_node->m_lastMat = m_node->m_mat;
    func_0019BBB0(this);
}
