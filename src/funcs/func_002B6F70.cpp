struct Mat_002B6F70 {
    float m[16];
};

extern "C" void* func_001317D0(void* p);
extern "C" void* func_00134F18(void* p);
extern "C" Mat_002B6F70* func_00100928(Mat_002B6F70* out, float angle);
extern "C" void func_00323318(Mat_002B6F70* a, Mat_002B6F70* b, Mat_002B6F70* out);
extern "C" void func_0013C690(void* p, Mat_002B6F70* m);

struct Obj_002B6F70 {
    void* m0;
    void SetRotation(float deg);
};

void Obj_002B6F70::SetRotation(float deg)
{
    void* q = func_00134F18(func_001317D0(m0));
    if (q) {
        Mat_002B6F70 m;
        Mat_002B6F70 rot;
        m.m[0] = 1.0f; m.m[1] = 0.0f; m.m[2] = 0.0f; m.m[3] = 0.0f;
        m.m[4] = 0.0f; m.m[5] = 1.0f; m.m[6] = 0.0f; m.m[7] = 0.0f;
        m.m[8] = 0.0f; m.m[9] = 0.0f; m.m[10] = 1.0f; m.m[11] = 0.0f;
        m.m[12] = 0.0f; m.m[13] = 0.0f; m.m[14] = 0.0f; m.m[15] = 1.0f;
        func_00323318(&m, func_00100928(&rot, deg * 0.01745329425f), &m);
        func_0013C690(q, &m);
    }
}
