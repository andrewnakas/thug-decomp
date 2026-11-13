typedef int qword_001B7D50 __attribute__((mode(TI)));

struct Vec_001B7D50 {
    union {
        qword_001B7D50 q;
        struct {
            float x, y, z, w;
        };
    };
    float operator[](int i) const { return (&x)[i]; }
    Vec_001B7D50& operator-=(const Vec_001B7D50& b)
    {
        x -= b[0];
        y -= b[1];
        z -= b[2];
        w -= b[3];
        return *this;
    }
    Vec_001B7D50& operator+=(const Vec_001B7D50& b)
    {
        x += b[0];
        y += b[1];
        z += b[2];
        w += b[3];
        return *this;
    }
};

struct Mat_001B7D50 {
    Vec_001B7D50 row[4];
};

struct Node_001B7D50 {
    char pad[0x20];
    Node_001B7D50* m_next;
};

struct Skel_001B7D50 {
    int m0;
    Node_001B7D50* m_first;
};

class Anim_001B7D50 {
public:
    char pad[0x18];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual Skel_001B7D50* GetSkeleton();
};

struct Obj_001B7D50 {
    char pad[0x50];
    Vec_001B7D50 m_pos;
    char pad60[0x10];
    Mat_001B7D50 m_mat;
};

extern "C" void func_0026B5B8(Skel_001B7D50* s, Mat_001B7D50* m);
/* func_0026B6A8 reads $a2 (0x0026B6C8 daddu $a0,$a2 -> func_0026B6A0): the node is its third argument. */
extern "C" Vec_001B7D50 func_0026B6A8(Skel_001B7D50* s, Node_001B7D50* n);
extern "C" void func_001016A8(Vec_001B7D50* v, Vec_001B7D50* m);

struct C_001B7D50 {
    char pad[0xC];
    Obj_001B7D50* mC;
    char pad10[0x10];
    Anim_001B7D50* m20;
    bool GetBonePos(Vec_001B7D50* out, int index);
};

bool C_001B7D50::GetBonePos(Vec_001B7D50* out, int index)
{
    Obj_001B7D50* obj = mC;
    if (m20 && obj) {
        Skel_001B7D50* skel = m20->GetSkeleton();
        if (skel) {
            Mat_001B7D50 m = obj->m_mat;
            m.row[0].w = 0.0f;
            m.row[1].w = 0.0f;
            m.row[2].w = 0.0f;
            m.row[3] = obj->m_pos;
            m.row[3].w = 1.0f;
            func_0026B5B8(skel, &m);
            int i = 0;
            for (Node_001B7D50* n = skel->m_first; n; n = n->m_next) {
                if (i == index) {
                    Vec_001B7D50 p = func_0026B6A8(skel, n);
                    p -= obj->m_pos;
                    func_001016A8(&p, &obj->m_mat.row[1]);
                    p += obj->m_pos;
                    *out = p;
                    break;
                }
                i++;
            }
            return true;
        }
    }
    return false;
}
