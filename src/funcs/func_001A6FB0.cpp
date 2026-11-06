typedef int qword_001A6FB0 __attribute__((mode(TI)));

struct Vec_001A6FB0 {
    union {
        struct { float x, y, z, w; };
        qword_001A6FB0 q;
    };
    Vec_001A6FB0() {}
    Vec_001A6FB0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Row_001A6FB0 {
    qword_001A6FB0 q;
};

struct Mat_001A6FB0 {
    Row_001A6FB0 r[4];
};

struct Obj_001A6FB0;
extern "C" int func_001E7FA8(void* params, unsigned int name, Vec_001A6FB0* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void func_001019E0(Vec_001A6FB0* v);
extern "C" void func_00101978(Vec_001A6FB0* v);
extern "C" void func_00101238(Mat_001A6FB0* m, Vec_001A6FB0* ang);
extern "C" void func_00100200(Mat_001A6FB0* m, float x, float y, float z);
extern "C" void func_001A6EF0(Obj_001A6FB0* o, void* params, Mat_001A6FB0* target);

struct Model_001A6FB0 {
    char pad[0x70];
    Mat_001A6FB0 m70;
};

struct Obj_001A6FB0 {
    char pad[0xC];
    Model_001A6FB0* mC;
    void Method(void* params);
};

void Obj_001A6FB0::Method(void* params)
{
    Vec_001A6FB0 v(0.0f, 0.0f, 0.0f, 1.0f);
    if (func_001E7FA8(params, 0x91A4C826, &v, 0)) {
        if (func_001E8708(params, 0x26AF9DC9)) {
            v.z = -v.z;
            func_001019E0(&v);
        }
        func_00101978(&v);
        Mat_001A6FB0 m = mC->m70;
        func_00101238(&m, &v);
        func_001A6EF0(this, params, &m);
    } else if (func_001E7FA8(params, 0x592089A9, &v, 0)) {
        if (func_001E8708(params, 0x26AF9DC9)) {
            v.z = -v.z;
            func_001019E0(&v);
        }
        func_00101978(&v);
        Mat_001A6FB0 m;
        func_00100200(&m, v.x, v.y, v.z);
        func_001A6EF0(this, params, &m);
    }
}
