typedef int qword __attribute__((mode(TI)));

class Node_0014AF70 {
public:
    int m0;
    int m4;
    int m8;
    Node_0014AF70* mC;
    Node_0014AF70* m10;
    Node_0014AF70* Valid() { if (m4 == -1) return 0; return this; }
    virtual ~Node_0014AF70();
};

struct Vec_0014AF70 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
};

extern Node_0014AF70 D_003CBDC8;
extern "C" void func_00137B70(int id, Vec_0014AF70* v, int a);

extern "C" void func_0014AF70()
{
    Vec_0014AF70 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    v.w = 1.0f;
    for (Node_0014AF70* n = D_003CBDC8.mC->Valid(); n; n = n->mC->Valid()) {
        func_00137B70(n->m4, &v, 1);
    }
}
